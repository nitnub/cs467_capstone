// Temp logic to manage closing / advancing the window for testing

#include "windowManager_temp.h"


int readControls(state *cpuState) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return 1;

            case SDL_KEYDOWN:
                // check info at SDL documentation page: https://wiki.libsdl.org/SDL2/SDL_Event
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_C:
                        // coin: bit set to 1 while C is held, cleared to 0 on keyup (see SDL_KEYUP below)
                        setClearBit(cpuState->inp, 1, COIN, 1); 
                        break;
                    case SDL_SCANCODE_1:
                        // p1 start button
                        setClearBit(cpuState->inp, 1, ONEP_START, 1);
                        break;
                    case SDL_SCANCODE_2:
                        // p2 start button
                        setClearBit(cpuState->inp, 1, TWOP_START, 1);
                        break;
                    case SDL_SCANCODE_SPACE:
                        // p1 shoot
                        setClearBit(cpuState->inp, 1, ONEP_FIRES, 1);
                        break;
                    case SDL_SCANCODE_LEFT:
                        // p1 move left
                        setClearBit(cpuState->inp, 1, ONEP_LEFT, 1);
                        break;
                    case SDL_SCANCODE_RIGHT:
                        // p1 move right
                        setClearBit(cpuState->inp, 1, ONEP_RIGHT, 1);
                        break;
                    case SDL_SCANCODE_A:
                        // p2 move left
                        setClearBit(cpuState->inp, 2, TWOP_LEFT, 1);
                        break;
                    case SDL_SCANCODE_D:
                        // p2 move right
                        setClearBit(cpuState->inp, 2, TWOP_RIGHT, 1);
                        break;
                    case SDL_SCANCODE_RETURN:
                        // p2 shoot
                        setClearBit(cpuState->inp, 2, TWOP_FIRES, 1);
                        break;
                    case SDL_SCANCODE_T:
                        // tilt
                        setClearBit(cpuState->inp, 2, TILT, 1);
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        // TODO: keep for testing; this will close the window by tapping ESC key
                        return 1;
                    default:
                        break;
                }
                break;
            
            // keyup added
            case SDL_KEYUP:
                // check info at SDL documentation page: https://wiki.libsdl.org/SDL2/SDL_Event
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_C:
                        setClearBit(cpuState->inp, 1, COIN, 0);
                        break;
                    case SDL_SCANCODE_1:
                        setClearBit(cpuState->inp, 1, ONEP_START, 0);
                        break;
                    case SDL_SCANCODE_2:
                        setClearBit(cpuState->inp, 1, TWOP_START, 0);
                        break;
                    case SDL_SCANCODE_SPACE:
                        setClearBit(cpuState->inp, 1, ONEP_FIRES, 0);
                        break;
                    case SDL_SCANCODE_LEFT:
                        setClearBit(cpuState->inp, 1, ONEP_LEFT, 0);
                        break;
                    case SDL_SCANCODE_RIGHT:
                        setClearBit(cpuState->inp, 1, ONEP_RIGHT, 0);
                        break;
                    case SDL_SCANCODE_A:
                        setClearBit(cpuState->inp, 2, TWOP_LEFT, 0);
                        break;
                    case SDL_SCANCODE_D:
                        setClearBit(cpuState->inp, 2, TWOP_RIGHT, 0);
                        break;
                    case SDL_SCANCODE_RETURN:
                        setClearBit(cpuState->inp, 2, TWOP_FIRES, 0);
                        break;
                    case SDL_SCANCODE_T:
                        setClearBit(cpuState->inp, 2, TILT, 0);
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        // TODO: keep for testing; this will close the window by tapping ESC key
                        return 1;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
