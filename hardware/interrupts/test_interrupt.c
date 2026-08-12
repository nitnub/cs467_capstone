#include <assert.h>
#include "interrupt.h"
#include "../helpers/helpers.h"

struct instructionData ins;
state myCpu;

/*
* setup CPU for testing
*/
int setupCPU(process_r *cpu) {
    cpu->interruptBuffer = (uint8_t) 0x00;
    cpu->interruptEnabled = (uint8_t) 0x01; // start with interrupts enabled
    cpu->interruptReady = (uint8_t) 0x00;

    return 0;
}

/*
*   setup game for testing
*/
int setupMemory(state *processor, int start) {

    // clear memory
    memset(processor->memory, 0, MEM_SIZE);

    // load game ROM into memory
    char romName[] = "../invaders.combined";
    loadRomToMemory(processor, romName);

    // point to first instruction
    processor->currentOp.currentOpcode = start;

    return 0;
}

/*
*   Test trigger interrupt: sets buffer to 0xCF
*   sets interruptReady to 0x01
*/
int test_trigger_interrupt(process_r *cpu) {
    printf("Test triggerInterrupt()...  ");
    setupCPU(cpu);
    triggerInterrupt(cpu, 0xCF);

    assert(cpu->interruptBuffer == 0xCF);
    assert(cpu->interruptReady == 0x01);

    printf("success\n");
    return 0;
}

int test_process_interrupt(process_r *cpu) {
    printf("Test processInterrupt()... ");
    setupCPU(cpu);
    // set buffer for interrupt
    cpu->interruptBuffer = 0xCF;
    // set interruptReady
    cpu->interruptReady = 0x01;

    processInterrupt(cpu);

    assert(cpu->currentOpcode == 0xCF);
    assert(cpu->interruptReady == 0x00);
    assert(cpu->interruptBuffer == 0x00);

    printf("success\n");
    return 0;
}

int main (void) {

    ins.s = &myCpu;

    /* component interrupt functions */
    test_trigger_interrupt(&myCpu.currentOp);
    test_process_interrupt(&myCpu.currentOp);

    return 0;
}