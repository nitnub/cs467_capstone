#ifndef CPU_TIMING_H
#define CPU_TIMING_H
#include "../interrupts/interrupt.h"   // pulls in processStep, handler.h -> cpu.h

// real 8080 hardware: ~2MHz clock, 60Hz frame, two interrupts per frame
#define CYCLES_PER_HALF_FRAME 16667

// called after every instruction; pass NULL if not needed
typedef void (*post_instruction_hook)(state *cpuState, void *userdata);

/**
 * Runs instructions via processStep() until a half-frame's worth of real
 * cycles have elapsed, calls hook after every instruction, then fires
 * the next interrupt in the RST1/RST2 alternation.
 *
 * @param cpuState 
 * @param next_interrupt pointer to the alternating- 1/2 counter updated in place
 * @param hook called after every instruction- pass NULL if not needed
 * @param userdata passed thru to hook unchanged
 * @return 
 */
int run_half_frame(state *cpuState, int *next_interrupt,
                    post_instruction_hook hook, void *userdata);

#endif //CPU_TIMING_H
