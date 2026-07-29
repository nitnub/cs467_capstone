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
    return mBucket;
}

void sdlVideoCleanup(Media_t *mBucket, int exit_status) {
    // note this has to be in the reverse order of how things were initialized in the sdl_initialize function
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

    return 0;
}

int drawScreen(state *s, Media_t *mBucket) {
    // if no points to draw, skip draw
    if (!updatePoints(s, &mBucket->points)) {
        return 0;
    }

    // clear the background
    // SDL_RenderClear(mBucket->renderer);

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
