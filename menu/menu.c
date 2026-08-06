#include "menu.h"


int processUserInput(Menu_t *menuState) {
    SDL_Event event;
    // printf("tst1\n");
    while (SDL_PollEvent(&event)) {
        // printf("tst2\n");

        switch (event.type) {
            case SDL_QUIT:
                printf("Quitting switch selection made...\n");
                return MENU_SELECTION_QUIT;
            case SDL_KEYDOWN:
                // check info at SDL documentation page: https://wiki.libsdl.org/SDL2/SDL_Event
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_DOWN:
                        if (menuState->currentSelection < MENU_SELECTION_QUIT) {
                            menuState->currentSelection += 1;
                        }
                        printf("down.. cs: %d\n", menuState->currentSelection);
                        return -1;
                        break;
                    case SDL_SCANCODE_UP:
                        if (menuState->currentSelection > MENU_SELECTION_ROM_1) {
                            menuState->currentSelection -= 1;
                        }
                        printf("up.. cs: %d\n", menuState->currentSelection);
                        return -1;
                        break;
                    case SDL_SCANCODE_RETURN:
                        printf("return\n");
                        printf("returning.. cs: %d\n", menuState->currentSelection);
                        return menuState->currentSelection;
                        break;
                    case SDL_SCANCODE_Q:
                    case SDL_SCANCODE_ESCAPE:
                        printf("esc\n");

                        return MENU_SELECTION_QUIT;
                    default:
                        // printf("step 111111\n");
                        break;
                }
                break;
// TODO: KEY_UP doesn't add value... omit?
            // case SDL_KEYUP:
            //     // check info at SDL documentation page: https://wiki.libsdl.org/SDL2/SDL_Event
            //     switch (event.key.keysym.scancode) {
            //     case SDL_SCANCODE_C:
            //
            //
            //             break;
            //     case SDL_SCANCODE_1:
            //
            //             break;
            //     case SDL_SCANCODE_SPACE:
            //             // p1 shoot
            //             break;
            //     case SDL_SCANCODE_LEFT:
            //             // p1 move left
            //             break;
            //     case SDL_SCANCODE_RIGHT:
            //             // p1 move right
            //             break;
            //     case SDL_SCANCODE_ESCAPE:
            //             // TODO: keep for testing; this will close the window by tapping ESC key
            //
            //             printf("release escape\n");
            //
            //             return 11;
            //     default:
            //             printf("step 222222\n");
            //             break;
            //     }
            //
            //     break;
            // default:
            //     printf("step 33333 MYSTERER WEA RFA RFEWA FTRAE TFGEA: %02x\n", event.type);
            //     // return -1;
            //     break;
        }
    }

    // printf("step 44444\n");
    return -1;
}





int mainMenu(Media_t *mBucket) {


    Menu_t menuState = {};
    // initialize menu size
    // menuState.currentSelection = MENU_SIZE;


    initializeMenuRender(mBucket);
    printf("after initializeMenuRender\n");

    int menuStatus = -1;
    while (menuStatus == -1) {
        // printf("in main loop...\n");
        // get user input
        // int userInput = processUserInput(&menuState);
        // printf("MS: %d", menuStatus);
        int userInput = processUserInput(&menuState);

        // printf("MS: %d", menuStatus);
        // // return userInput;

        if (userInput == MENU_SELECTION_QUIT) {
            printf("Selected QUIT\n");
            return MENU_SELECTION_QUIT;
        }
        if (userInput != -1 ) {
            printf("Selected Option %d\n", userInput);


            return menuState.currentSelection;
        }


        // if (userInput == MENU_SELECTION_QUIT) {
        //     printf("Selected QUIT\n");
        //     return 1;
        // }
        //
        // if (userInput == MENU_SELECTION_ROM_1) {
        //     printf("Selected ROM 1\n");
        // }
        //
        // // call draw screen with curentSelection
        updateMenuRender(mBucket, menuState.currentSelection);

        // draw screen


    }

    return menuStatus;

    return 0;
}