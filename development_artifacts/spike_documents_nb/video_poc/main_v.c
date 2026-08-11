// Citations:
//      SDL event switch structure and game/initialize pattern adapted from tutorial at:
//      https://www.youtube.com/watch?v=ibVihn77SY4&list=PLO02jwa2ZaiCgilk8EEVnfnGWA0LNu4As&index=1

#include "video_startup.h"

int main(void) {
    // define game view state
    Game game = {
        .window = NULL,
        .renderer = NULL,
        .texture = NULL
    };

    // try to initialize
    if (sdlVideoInit(&game)) {
        sdlVideoCleanup(&game, EXIT_FAILURE);
    }

    // update the points array
    // TODO: connect to source memory array and update per emulator cycle
    const int pCount = updatePoints(&game.points);

    // rectangle dimensions to scale the texture to
    // will paint to a smaller texture, then use this rectangle to scale it up
    // to the full screen this will allow us to make the pixels larger. without
    // scaling, the 256x240 resolution is too small to play
    const SDL_Rect screenRect = {0,0,SCREEN_WIDTH, SCREEN_HEIGHT };


    // endless loop for testing...
    while (true) {
        // handle events
        // if any event types... follow the switch
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    sdlVideoCleanup(&game, EXIT_SUCCESS);
                    break;
                case SDL_KEYDOWN:
                    // https://wiki.libsdl.org/SDL2/SDL_Event
                    // a key was pressed down (can also do keyup); can read input pin info from here?
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            // TODO: keeping for testing; example showed how to exit with escape key
                            sdlVideoCleanup(&game, EXIT_SUCCESS);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        // if no points to draw (may need to remove)
        if (!pCount) {
            continue;
        }

        // clear the background
        SDL_RenderClear(game.renderer);

        // set drawing target to texture
        if (SDL_SetRenderTarget(game.renderer, game.texture)) {
            fprintf(stderr, "Error setting render target: %s\n", SDL_GetError());
            sdlVideoCleanup(&game, EXIT_FAILURE);
        }

        // draw white to texture
        SDL_SetRenderDrawColor(game.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoints(game.renderer, game.points.white, game.points.wCount);

        // draw green to texture
        SDL_SetRenderDrawColor(game.renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoints(game.renderer, game.points.green, game.points.gCount);

        // draw red to texture
        SDL_SetRenderDrawColor(game.renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoints(game.renderer, game.points.red, game.points.rCount);

        // reset brush to black
        SDL_SetRenderDrawColor(game.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

        // set draw target to window
        SDL_SetRenderTarget(game.renderer, NULL);

        // stretch texture out to full screen
        if (SDL_RenderCopy(game.renderer, game.texture, NULL, &screenRect)) {
            fprintf(stderr, "Error applying texture to screen: %s\n", SDL_GetError());
            sdlVideoCleanup(&game, EXIT_FAILURE);
        }
        SDL_RenderPresent(game.renderer);
    }

    // clean up and exit
    sdlVideoCleanup(&game, EXIT_SUCCESS);
}
