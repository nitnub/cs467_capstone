#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL_events.h>
#include "../hardware/video/video.h"
#include "../hardware/audio/audio.h"

#define MENU_SELECTION_ROM_1 0
#define MENU_SELECTION_QUIT 1


typedef struct {
    int menuSize;
    int currentSelection;
    int quit;
} Menu_t;


/**
 * Run the interactive main menu loop.
 * @param mBucket pointer to the current program's media struct
 * @return integer representation of the user's selection
 */
int mainMenu(Media_t *mBucket, Audio *audio); //added audio for FX
#endif //MENU_H
