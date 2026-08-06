#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL_events.h>
#include "../video/video.h"

#define MENU_SELECTION_ROM_1 0
#define MENU_SELECTION_QUIT 1
#define MAX_TITLE_LENGTH

typedef struct {
    int menuSize;
    int currentSelection;
    int quit;
    char selectionTitle[MAX_TITLE_LENGTH + 1];
} Menu_t;



int mainMenu(Media_t *mBucket);

#endif //MENU_H
