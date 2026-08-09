#include "menu.h"


int processUserInput(Menu_t *menuState, Audio *audio) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return MENU_SELECTION_QUIT;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_DOWN:
                        if (menuState->currentSelection < MENU_SELECTION_QUIT) {
                            menuState->currentSelection += 1;
                            playSound(audio->shot_sound);
                        }
                        return -1;
                    case SDL_SCANCODE_UP:
                        if (menuState->currentSelection > MENU_SELECTION_ROM_1) {
                            menuState->currentSelection -= 1;
                            playSound(audio->shot_sound);
                        }
                        return -1;
                    case SDL_SCANCODE_RETURN2:
                    case SDL_SCANCODE_KP_ENTER:
                    case SDL_SCANCODE_RETURN:
                        if (menuState->currentSelection == MENU_SELECTION_QUIT) {
                            playSound(audio->player_death_sound);
                        } else {
                            playSound(audio->invader_death_sound);
                        }
                        return menuState->currentSelection;                        return menuState->currentSelection;
                    case SDL_SCANCODE_Q:
                    case SDL_SCANCODE_ESCAPE:
                        playSound(audio->player_death_sound);
                        return MENU_SELECTION_QUIT;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return -1;
}

int mainMenu(Media_t *mBucket, Audio *audio) {
    Menu_t menuState = {};

    // initialize the main menu display
    initializeMenuRender(mBucket);

    int menuStatus = -1;
    while (menuStatus == -1) {
        // get user input
        int userInput = processUserInput(&menuState, audio);

        // return userInput;
        if (userInput == MENU_SELECTION_QUIT) {
            return MENU_SELECTION_QUIT;
        }
        if (userInput != -1 ) {
            return menuState.currentSelection;
        }
        // updte screen with current selection
        updateMenuRender(mBucket, menuState.currentSelection);
    }
    return menuStatus;
}
