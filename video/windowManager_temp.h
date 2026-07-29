
#ifndef CONTROL_TEST_H
#define CONTROL_TEST_H

#include <SDL2/SDL_events.h>

#include "../core/cpu.h"

/**
 * Test controller input to manage screen closure. Event polling is
 * mandatory to use the SDL window's 'X' close button
 * @param cpuState pointer to the current program's CPU state struct
 * @return 1 on close, 0 otherwise
 */
int readControls(state *cpuState);

#endif //CONTROL_TEST_H
