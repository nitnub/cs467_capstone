// Temp logic to manage closing / advancing the window for testing

#include "windowManager_temp.h"
#include "video.h"
#include "../core/cpu.h"
// #include "../../yigit_keyboard_demo/controller_renamed.h"
#include "../spike_documents_nb/video_demo/controller_renamed.h"

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
                        // coin (0 when active?)
                        // // port testing to advance splash screen - not currently working
                        // setPort(cpuState, 1, 1, 0x01);
                        // setReg8(cpuState, A , 0x01);
                        printf("down: C\n");
                        // coin(cpuState->inp);
                        // coin(cpuState->outp);

                        setClearBit(cpuState->inp, 1, COIN, 1);
                        setClearBit(cpuState->outp, 1, COIN, 1);

                        break;
                    case SDL_SCANCODE_1:
                        // p1 start button
                        printf("down: C\n");
                        // coin(cpuState->inp);
                        // coin(cpuState->outp);

                        setClearBit(cpuState->inp, 1, ONEP_START, 1);
                        setClearBit(cpuState->outp, 1, ONEP_START, 1);

                        break;
                    case SDL_SCANCODE_SPACE:
                        // p1 shoot
                        break;
                    case SDL_SCANCODE_LEFT:
                        // p1 move left
                        break;
                    case SDL_SCANCODE_RIGHT:
                        // p1 move right
                        break;
                    case SDL_SCANCODE_ESCAPE:
                        // TODO: keep for testing; this will close the window by tapping ESC key
                        return 1;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                // check info at SDL documentation page: https://wiki.libsdl.org/SDL2/SDL_Event
                switch (event.key.keysym.scancode) {
                case SDL_SCANCODE_C:
                        // coin (0 when active?)
                        // // port testing to advance splash screen - not currently working
                        // setPort(cpuState, 1, 1, 0x01);
                        // setReg8(cpuState, A , 0x01);
                        printf("up: C\n");

                        // coin(cpuState->inp);
                        // coin(cpuState->outp);

                        setClearBit(cpuState->inp, 1, COIN,       0);
                        setClearBit(cpuState->outp, 1, COIN,       0);

                        break;
                case SDL_SCANCODE_1:
                        // p1 start button

                        setClearBit(cpuState->inp, 1, ONEP_START, 0);
                        setClearBit(cpuState->outp, 1, ONEP_START, 0);
                        break;
                case SDL_SCANCODE_SPACE:
                        // p1 shoot
                        break;
                case SDL_SCANCODE_LEFT:
                        // p1 move left
                        break;
                case SDL_SCANCODE_RIGHT:
                        // p1 move right
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