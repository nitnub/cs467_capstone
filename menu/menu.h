#ifndef MENU_H
#define MENU_H

#include <dirent.h>
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


/**
 * Check if the root project directory has a game_files folder.
 * @return 1 if directory exists, 0 if not
 */
int gameFilesExist();
#endif //MENU_H
