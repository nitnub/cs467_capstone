#include <stdio.h>
#include <string.h>
#include "cpu_timing.h"

long dbg_int_fired = 0, dbg_int_dropped = 0;

// pushes PC and jumps to the RST vector, uses interruptEnabled directly
static void generate_interrupt(state *cpuState, int rst_num) {
    if (!cpuState->currentOp.interruptEnabled) {
        dbg_int_dropped++;
        return;
    }

    stackPushFromRegister(cpuState, PC);
    setReg16(cpuState, PC, 8 * (uint16_t)rst_num);
    cpuState->currentOp.interruptEnabled = 0;
    dbg_int_fired++;

    // PC just moved, refetch so the next processStep() isn't stale
    uint16_t pc = getReg16(cpuState, PC);
    cpuState->currentOp.currentOpcode =
        memFetch(cpuState, highFrom16Bit(pc), lowFrom16Bit(pc));
}

// runs one half frame of instructions via processStep(), then fires an interrupt
int run_half_frame(state *cpuState, int *next_interrupt,
                    post_instruction_hook hook, void *userdata) {
    long cycles_run = 0;

    struct instructionData currentIns;
    memset(&currentIns, 0, sizeof(currentIns));  // clear stale fields before first use
    currentIns.s = cpuState;

    // step until this half frame's cycle budget is spent
    while (cycles_run < CYCLES_PER_HALF_FRAME) {
        processStep(&currentIns);
        cycles_run += currentIns.cycles;

        if (hook) hook(cpuState, userdata);
    }

    generate_interrupt(cpuState, *next_interrupt);
    *next_interrupt = (*next_interrupt == 1) ? 2 : 1;

    return 0;
}
