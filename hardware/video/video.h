
#ifndef VIDEO_STARTUP_H
#define VIDEO_STARTUP_H

#include <stdio.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../../core/cpu.h"

#define WINDOW_TITLE "Intel 8080 Emulator"     // TODO: temp placeholder name
#define WINDOW_TITLE_SPACE_INVADERS "Space Invaders"
#define SAFE_SHUTDOWN_MESSAGE "Thank you for playing!"
#define PIXEL_WIDTH 224
#define PIXEL_HEIGHT 256
#define SCREEN_WIDTH 672 // 940 // test scaling
#define SCREEN_HEIGHT 768 // 1272 // test scaling
#define POINTS_ARR_SIZE 6800
#define POINTS_ARR_MAX 520192
#define BYTE_SIZE 8
#define SET_BIT '1'
#define CLEAR_BIT '0'

// menu support
#define FONT_LOCATION "hardware/video/fonts/PressStart2P-Regular.ttf"
#define FONT_SIZE 24
#define CURSOR_IMAGE_LOCATION "game_files/images/alien_cursor.bmp"
#define CURSOR_IMAGE_LOCATION_DEFAULT "menu/images/default_cursor.bmp"
#define X_OFFSET_MENU (SCREEN_WIDTH / 2)
#define MENU_ELEMENT_HEIGHT 75
#define MENU_ELEMENT_CURSOR_SPACING 75
#define Y_OFFSET_MENU (SCREEN_HEIGHT / 2) - 150          // set slightly above mid-screen
#define Y_OFFSET_HEADER  Y_OFFSET_MENU
#define Y_OFFSET_OPTION_1  Y_OFFSET_MENU + MENU_ELEMENT_HEIGHT * 1
#define Y_OFFSET_OPTION_2  Y_OFFSET_MENU + MENU_ELEMENT_HEIGHT * 2
#define Y_OFFSET_CURSOR Y_OFFSET_MENU + 50
#define CURSOR_STEP_DISTANCE 75
#define LABEL_HEADER "Welcome!"
#define LABEL_ROM_1 "Launch Space Invaders"
#define LABEL_QUIT "Quit"
#define LABEL_SETTINGS "Settings"


typedef struct {
    SDL_Point white[POINTS_ARR_SIZE];                  // TODO: test sizing.. calc specific values for each color
    SDL_Point green[POINTS_ARR_SIZE];                  // TODO: test sizing.. calc specific values for each color
    SDL_Point red[POINTS_ARR_SIZE];                    // TODO: test sizing.. calc specific values for each color
    SDL_Point black[POINTS_ARR_MAX];                   // TODO: test sizing.. calc specific values for each color
    int wCount;
    int gCount;
    int rCount;
    int bCount;
} Points_t;

typedef struct {
    TTF_Font *font;
    SDL_Color *fontColor;
    SDL_Rect *headerRect;
    SDL_Texture *headerTexture;
    SDL_Rect *rom1Rect;
    SDL_Texture *rom1Texture;
    SDL_Rect *quitRect;
    SDL_Texture *quitTexture;
    SDL_Rect *cursorRect;
    SDL_Texture *cursorTexture;
} MenuUI_t;

typedef struct  {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    Points_t points;
    MenuUI_t menu;
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

/**
 * Draw the currently emulated ROM's video memory to the screen.
 * @param s pointer to the current program's CPU state struct
 * @param game the currently running program's SDL data struct
 * @return count of RBG points drawn
 */
int drawScreen(state *s, Media_t *game);

/**
 * Set up initial A/V state to draw the title menu to the screen.
 * @param mBucket pointer to the current program's media struct
 * @return 0 if no error; non-zero for error
 */
int initializeMenuRender(Media_t *mBucket);

/**
 * Redraw the current menu state to the screen.
 * @param mBucket pointer to the current program's media struct
 * @param selection index of the currently selected menu item (zero-based)
 */
void updateMenuRender(Media_t *mBucket, int selection);

#endif //VIDEO_STARTUP_H
