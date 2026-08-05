
#ifndef VIDEO_STARTUP_H
#define VIDEO_STARTUP_H
#include <SDL2/SDL_rect.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
// #include "../cpu/cpu.h"
#include "../core/cpu.h"


#define WINDOW_TITLE "Intel 8080 - Space Invaders" // TODO: temp placeholder name
#define PIXEL_WIDTH 224
#define PIXEL_HEIGHT 256
#define SCREEN_WIDTH 672 // 940 // test scaling
#define SCREEN_HEIGHT 768 // 1272 // test scaling

#define BYTE_SIZE 8
#define SET_BIT '1'
#define CLEAR_BIT '0'


typedef struct {
    SDL_Point white[6800];  // TODO: test sizing.. calc specific values for each color
    SDL_Point green[6800];  // TODO: test sizing.. calc specific values for each color
    SDL_Point red[6800];    // TODO: test sizing.. calc specific values for each color
    SDL_Point black[520192];    // TODO: test sizing.. calc specific values for each color
    int wCount;
    int gCount;
    int rCount;
    int bCount;
} Points_t;

typedef struct  {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Points_t points;
} Media_t;


/**
 * Initialize and return a media bucket struct to house A/V structs created to work with SDL2.
 * @return an allocated media bucket struct
 */
Media_t *initMedia(void);

// int sendVideoInterrupt(long *lastMs);
int sendVideoInterrupt(state *s, long *lastMs);

/**
 * Call to initialize the video module.
 * @param game the current game's SDL data struct
 * @return 0 if no error; non-zero for error
 */
int sdlVideoInit(Media_t *game);

/**
 * Call to safely shut down the video module.
 * @param game the current game's SDL data struct
 * @param exit_status status / error code to exit with
 */
void sdlVideoCleanup(Media_t *game, int exit_status);

/**
 * Update the three color group's points arrays and counts.
 * @param points the Points_t struct containing point info for the renderer
 * @return count of points created
 */
int updatePoints(state *s, Points_t *points);

Points_t *getClearPoints(void);

int drawScreen(state *s, Media_t *game);

#endif //VIDEO_STARTUP_H
