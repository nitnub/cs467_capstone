// Temp logic to manage closing / advancing the window for testing

#include "windowManager_temp.h"
#include "video.h"
#include "../core/cpu.h"
#include"../controller/controller.h"

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
                        // port testing to advance splash screen - not currently working
                        setControllerPort(cpuState->inp, _COIN);
                        // setReg8(cpuState, A , 0x01);

                        break;
                    case SDL_SCANCODE_1:
                        setControllerPort(cpuState->inp, _START1PLAYER);
                        // p1 start button
                        break;
                    case SDL_SCANCODE_SPACE:
                        setControllerPort(cpuState->inp, _FIRE1);
                        // p1 shoot
                        break;

                    case SDL_SCANCODE_LEFT:
                        setControllerPort(cpuState->inp, _LEFT1);
                        // p1 move left
                        break;

                    case SDL_SCANCODE_RIGHT:
                        // p1 move right
                        setControllerPort(cpuState->inp, _RIGHT1);
                        break;
                    case SDL_SCANCODE_2:
                        setControllerPort(cpuState->inp, _START2PLAYER);
                        break;
                    case SDL_SCANCODE_J:
                        setControllerPort(cpuState->inp, _LEFT2);
                        break;
                    case SDL_SCANCODE_K:
                        setControllerPort(cpuState->inp, _FIRE2);
                        break;
                    case SDL_SCANCODE_L:
                        setControllerPort(cpuState->inp, _RIGHT2);
                        break;
                    case SDL_SCANCODE_3:
                        setControllerPort(cpuState->inp, _TILT);
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