// Citations:
//      SDL event switch structure and game/initialize pattern adapted from tutorial at:
//      https://www.youtube.com/watch?v=ibVihn77SY4&list=PLO02jwa2ZaiCgilk8EEVnfnGWA0LNu4As&index=1

#include "video.h"
#include <sys/time.h>

long getCurrentMilliseconds() {
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);

    // sum up the seconds and microseconds of the current time, after normalizing both to ms
    long timeInMs = currentTime.tv_sec * 1000L;
    timeInMs += currentTime.tv_usec / 1000L;
    return timeInMs;
}

int sendVideoInterrupt(state *s, long *lastMs) {
    long currentMs = getCurrentMilliseconds();
    // each 1000 ms / 60 hz = 16.667 ms/hz

    // if (currentMs - *lastMs >= 16.6667) {
    if (currentMs - *lastMs >= 8.33333) {
        *lastMs = currentMs;
        return 1;
    }
    return 0;
}

Media_t *initMedia(void) {
    Media_t *mBucket = calloc(1, sizeof(Media_t));
    mBucket->window = NULL;
    mBucket->texture = NULL;
    mBucket->renderer = NULL;
    mBucket->menu.font = NULL;
    // mBucket->text.color = calloc(1, sizeof(*mBucket->text.color));
    mBucket->menu.fontColor = malloc(sizeof(*mBucket->menu.fontColor));
    mBucket->menu.fontColor->a = 0xff;
    mBucket->menu.fontColor->b = 0xff;
    mBucket->menu.fontColor->g = 0xff;
    mBucket->menu.fontColor->r = 0xff;

    mBucket->menu.headerTexture = NULL;
    mBucket->menu.cursorTexture = NULL;


    return mBucket;
}

void sdlVideoCleanup(Media_t *mBucket, int exit_status) {
    // note this has to be in the reverse order of how things were initialized in the sdl_initialize function

    // menu
    SDL_DestroyTexture(mBucket->menu.headerTexture);
    SDL_DestroyTexture(mBucket->menu.rom1Texture);
    SDL_DestroyTexture(mBucket->menu.quitTexture);
    SDL_DestroyTexture(mBucket->menu.cursorTexture);
    free(mBucket->menu.headerRect);
    free(mBucket->menu.rom1Rect);
    free(mBucket->menu.quitRect);
    free(mBucket->menu.cursorRect);
    TTF_CloseFont(mBucket->menu.font);
    free(mBucket->menu.fontColor);

    // game emulation
    SDL_DestroyTexture(mBucket->texture);
    SDL_DestroyRenderer(mBucket->renderer);
    SDL_DestroyWindow(mBucket->window);
    free(mBucket);
    SDL_Quit();
    exit(exit_status);
}

int sdlVideoInit(Media_t *mBucket) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    // creates the window that was created or NULL
    mBucket->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                    SCREEN_HEIGHT, 0);
    if (!mBucket->window) {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return 1;
    }

    mBucket->renderer = SDL_CreateRenderer(mBucket->window, -1, 0);
    if (!mBucket->renderer) {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return 1;
    }

    // create the texture that the mBucket screen will be drawn on
    // (using a texture allows resizing)
    mBucket->texture = SDL_CreateTexture(mBucket->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, PIXEL_WIDTH, PIXEL_HEIGHT);
    if (!mBucket->texture) {
        fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());
        return 1;
    }

    // initialize text support
    if (TTF_Init()) {
        fprintf(stderr, "Error initializing text support: %s\n", SDL_GetError());
        return 1;
    }

    // try to load font
    mBucket->menu.font = TTF_OpenFont(FONT_LOCATION, FONT_SIZE);
    if (!mBucket->menu.font) {
        fprintf(stderr, "Error loading file '%s': %s\n", FONT_LOCATION, SDL_GetError());
        return 1;
    }

    return 0;
}

Points_t *getClearPoints(void) {
    int pixelCount = (MEM_RAM_MIRROR_START - MEM_VIDEO_START) * 8;
    Points_t *bPts = calloc(1, sizeof(Points_t));

    for (int i=0; i<pixelCount; i++) {
        const int y = PIXEL_HEIGHT - (i % PIXEL_HEIGHT);
        const int x = i / PIXEL_HEIGHT;
        bPts->black[i].x=x;
        bPts->black[i].y=y;
    }

    bPts->bCount = pixelCount;

    return bPts;
}


int drawScreen(state *s, Media_t *mBucket) {
    // if no points to draw, skip draw
    if (!updatePoints(s, &mBucket->points)) {
        return 0;
    }

    // get blankPoints
    Points_t *bPts = getClearPoints();

    // try updating points every time
    //updatePoints(s, &mBucket->points);

    // clear the background
    //SDL_RenderClear(mBucket->renderer);

    // clear the background
    if (SDL_RenderClear(mBucket->renderer)) {
        fprintf(stderr, "Error clearing the video backgroundt: %s\n", SDL_GetError());
        sdlVideoCleanup(mBucket, EXIT_FAILURE);
    }

    // set drawing target to texture
    if (SDL_SetRenderTarget(mBucket->renderer, mBucket->texture)) {
        fprintf(stderr, "Error setting render target: %s\n", SDL_GetError());
        sdlVideoCleanup(mBucket, EXIT_FAILURE);
    }

    // draw bpoints
    SDL_SetRenderDrawColor(mBucket->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoints(mBucket->renderer, bPts->black, bPts->bCount);

    // draw white to texture
    SDL_SetRenderDrawColor(mBucket->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoints(mBucket->renderer, mBucket->points.white, mBucket->points.wCount);

    // draw green to texture
    SDL_SetRenderDrawColor(mBucket->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoints(mBucket->renderer, mBucket->points.green, mBucket->points.gCount);

    // draw red to texture
    SDL_SetRenderDrawColor(mBucket->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoints(mBucket->renderer, mBucket->points.red, mBucket->points.rCount);

    // reset brush to black
    SDL_SetRenderDrawColor(mBucket->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    // set draw target to window
    SDL_SetRenderTarget(mBucket->renderer, NULL);

    // stretch texture out to full screen
    // if (SDL_RenderCopy(mBucket->renderer, mBucket->texture, NULL, &screenRect)) {
    if (SDL_RenderCopy(mBucket->renderer, mBucket->texture, NULL, NULL)) {
        fprintf(stderr, "Error applying texture to screen: %s\n", SDL_GetError());
        sdlVideoCleanup(mBucket, EXIT_FAILURE);
    }
    SDL_RenderPresent(mBucket->renderer);
    free(bPts);
    return 11;
}


// populate in reverse for correct bit order!
void updateBitBuffer(char **result, uint16_t number) {
    int pos = 0;
    // reset all values to terminators
    memset(*result, '\0', BYTE_SIZE);

    // update
    while (number > 0) {
        (*result)[pos] = number % 2 == 0 ? CLEAR_BIT : SET_BIT;
        pos++;
        number /= 2;
    }
}

int updatePoints(state *s, Points_t *points) {

    // TODO: can create new arrays or free each time.. have not tested yet..
    memset(points, 0, sizeof(Points_t));

    // allocate memory for binary buffer
    char *binBuffer = (char*) malloc(BYTE_SIZE);

    // cycle through bytes, creating a point for each individual set bit
    for (int i = 0; i < MEM_RAM_MIRROR_START - MEM_VIDEO_START; i++) {

        // skip bytes with no set bits
        if (s->memory[MEM_VIDEO_START + i] == 0) {
            continue;;
        }

        // within each byte, check each bit to see if set
        updateBitBuffer(&binBuffer, s->memory[MEM_VIDEO_START + i]);
        for (int j = 0; j < BYTE_SIZE; j++) {
            if (binBuffer[j] == SET_BIT) {
                // get positions
                const int pos = (i * BYTE_SIZE) + j;
                const int y = PIXEL_HEIGHT - (pos % PIXEL_HEIGHT);
                const int x = pos / PIXEL_HEIGHT;

                // populate each point set by color grouping
                // color ranges pulled from chart at https://www.emutalk.net/threads/space-invaders.38177/
                if (y > 32 && y <= 64) {
                    // is red
                    points->red[points->rCount].x = x;
                    points->red[points->rCount].y = y;
                    points->rCount++;
                } else if ((y > 184 && y <= 240) || (y > 240 && x >= 16 && x < 134)) {
                    // is green
                    points->green[points->gCount].x = x;
                    points->green[points->gCount].y = y;
                    points->gCount++;
                } else {
                    // is white
                    points->white[points->wCount].x = x;
                    points->white[points->wCount].y = y;
                    points->wCount++;
                }
            }
        }
    }

    free(binBuffer);
    return points->wCount + points->gCount + points->rCount;
}


    //////////////////
    // Mwnu Support //
    //////////////////

int initializeMenuRender(Media_t *mBucket) {
    // mBucket->text.color = ;

    SDL_Surface *cursorSurface = SDL_LoadBMP(CURSOR_IMAGE_LOCATION);

    SDL_Surface *headerSurface = TTF_RenderText_Blended(mBucket->menu.font, "Welcome!", *mBucket->menu.fontColor);
    SDL_Surface *optionOneSurface = TTF_RenderText_Blended(mBucket->menu.font, "Launch Space Invaders", *mBucket->menu.fontColor);
    SDL_Surface *optionQuitSurface = TTF_RenderText_Blended(mBucket->menu.font, "Quit", *mBucket->menu.fontColor);



    // verify surfaces were created

    if (!cursorSurface) {
        fprintf(stderr, "Error rendering cursor image: %s\n", SDL_GetError());
        return 1;
    }

    if (!headerSurface) {
        fprintf(stderr, "Error rendering menu text: %s\n", SDL_GetError());
        return 1;
    }
    if (!optionOneSurface) {
        fprintf(stderr, "Error rendering menu option text: %s\n", SDL_GetError());
        return 1;
    }
    if (!optionQuitSurface) {
        fprintf(stderr, "Error rendering menu quittext: %s\n", SDL_GetError());
        return 1;
    }

    // int xOffset = 450;
    // int xOffset = (SCREEN_WIDTH ) / 2;

    // allocate and set initial position for cursor
    mBucket->menu.cursorRect = calloc(1, sizeof(SDL_Rect));
    mBucket->menu.cursorRect->x = X_OFFSET_MENU - (optionOneSurface->w / 2) - 75;
    mBucket->menu.cursorRect->y = Y_OFFSET_CURSOR; // (SCREEN_HEIGHT / 2) - 100;


    // allocate and position header
    mBucket->menu.headerRect = calloc(1, sizeof(SDL_Rect));
    mBucket->menu.headerRect->x =  X_OFFSET_MENU - (headerSurface->w / 2);
    mBucket->menu.headerRect->y = Y_OFFSET_HEADER; //  (SCREEN_HEIGHT / 2) - 150;

    // allocate and position option 1
    mBucket->menu.rom1Rect = calloc(1, sizeof(SDL_Rect));
    mBucket->menu.rom1Rect->x =  X_OFFSET_MENU - (optionOneSurface->w / 2);
    mBucket->menu.rom1Rect->y = Y_OFFSET_OPTION_1; // (SCREEN_HEIGHT / 2) -75;

    // allocate and position quit
    mBucket->menu.quitRect = calloc(1, sizeof(SDL_Rect));
    mBucket->menu.quitRect->x = X_OFFSET_MENU - (optionQuitSurface->w / 2);
    mBucket->menu.quitRect->y = Y_OFFSET_OPTION_2;  //(SCREEN_HEIGHT / 2);


    // printf("##########\n");
    printf("W: %d\n", headerSurface->w);
    printf("W: %d\n", optionOneSurface->w);
    printf("W: %d\n", optionQuitSurface->w);




    // set width and height to the surface of the original text
    // t_rect.w = surface->w;
    // t_rect.h = surface->h;

    // set rectangle heights and widths
    mBucket->menu.cursorRect->h = cursorSurface->h;
    mBucket->menu.cursorRect->w = cursorSurface->w;

    mBucket->menu.headerRect->h = headerSurface->h;
    mBucket->menu.headerRect->w = headerSurface->w;

    mBucket->menu.rom1Rect->h = optionOneSurface->h;
    mBucket->menu.rom1Rect->w = optionOneSurface->w;

    mBucket->menu.quitRect->h = optionQuitSurface->h;
    mBucket->menu.quitRect->w = optionQuitSurface->w;


    // convert surface to texture
    mBucket->menu.cursorTexture = SDL_CreateTextureFromSurface(mBucket->renderer, cursorSurface);


    mBucket->menu.headerTexture = SDL_CreateTextureFromSurface(mBucket->renderer, headerSurface);
    mBucket->menu.rom1Texture = SDL_CreateTextureFromSurface(mBucket->renderer, optionOneSurface);
    mBucket->menu.quitTexture = SDL_CreateTextureFromSurface(mBucket->renderer, optionQuitSurface);

    // free no-longer needed surface
    SDL_FreeSurface(cursorSurface);
    SDL_FreeSurface(headerSurface);
    SDL_FreeSurface(optionOneSurface);
    SDL_FreeSurface(optionQuitSurface);


    if (!mBucket->menu.cursorTexture) {
        fprintf(stderr, "Error creating cursor texture: %s\n", SDL_GetError());
        return 1;
    }

    if (!mBucket->menu.headerTexture) {
        fprintf(stderr, "Error creating menu texture: %s\n", SDL_GetError());
        return 1;
    }



    // draw to screen
    // null source gets the entire source... draw to the text rectangle


    return 0;

}


int updateMenuRender(Media_t *mBucket, int selectionIdx) {
    // int menuStatus = 0;

    // if in location 0

    mBucket->menu.cursorRect->y = Y_OFFSET_CURSOR + CURSOR_STEP_DISTANCE * selectionIdx;

    // if in location 1
    printf("Drawing...y_o_c = %d , c_s_d = %d,, idx = %d cursor y at %d\n", Y_OFFSET_CURSOR, CURSOR_STEP_DISTANCE, selectionIdx, mBucket->menu.cursorRect->y);

    // while (!menuStatus) {
    // clear previous render
    SDL_RenderClear(mBucket->renderer);
    // readControls(&cpuState);
    // render menu item 1 text
    // SDL_RenderCopy(mBucket->renderer, mBucket->menu.menuImage, NULL, &t_rect);

    SDL_RenderCopy(mBucket->renderer, mBucket->menu.cursorTexture, NULL, mBucket->menu.cursorRect);


    SDL_RenderCopy(mBucket->renderer, mBucket->menu.headerTexture, NULL, mBucket->menu.headerRect);
    SDL_RenderCopy(mBucket->renderer, mBucket->menu.rom1Texture, NULL, mBucket->menu.rom1Rect);
    SDL_RenderCopy(mBucket->renderer, mBucket->menu.quitTexture, NULL, mBucket->menu.quitRect);

    // display to the screen
    SDL_RenderPresent(mBucket->renderer);

    // delay for ~60 FPS
    SDL_Delay(17);
    // }



    // clean up menu


    return 0;
}
