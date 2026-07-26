//
// Created by nick on 7/23/26.
//

#include "control_test.h"

#include "video.h"
#include "../core/cpu.h"


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
                        setPort(cpuState, 1, 1, 0x01);
                        setReg8(cpuState, A , 0x01);

                        break;
                    case SDL_SCANCODE_1:
                        // p1 start button
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