#include <assert.h>
#include "interrupt.h"
#include "../helpers/helpers.h"

struct instructionData ins;
struct instructionData dis;
state myCpu;
state disCpu;

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

/*
*   Test timing of the processorLoop interrupt cycle function
*/
int test_interrupt_cycle(struct instructionData *currentIns, size_t testingCycles) {
    
    // setup up instructionData struct
    setupMemory(currentIns->s, 0x00);
    setupCPU(&currentIns->s->currentOp);
    currentIns->s->currentOp.interruptEnabled = 0x00;

    // begin timed test
    printf("Test processorLoop()...  seconds expected: %lf. ", (double) testingCycles/60);
    state *processor = currentIns->s;
    setupCPU(&processor->currentOp);
    double r = timingTestLoop(currentIns->s, testingCycles);

    assert(testingCycles/60 > r-0.5);
    assert(testingCycles/60 < r+0.5);

    printf("Seconds elapsed: %lf. Test passed\n", r);
    return 0;
}

/*
*   Test processor loop with interrupts enabled
*/
int test_processor_step(struct instructionData *currentIns, struct instructionData *disassembler, int inpoint, int steps) {
    setupMemory(currentIns->s, inpoint);
    setupCPU(&currentIns->s->currentOp);

    setupMemory(disassembler->s, inpoint);
    setupCPU(&disassembler->s->currentOp);

    currentIns->s->currentOp.interruptEnabled = 0x01;
    currentIns->s->inp[1] = 0x88;
    currentIns->s->inp[2] = 0x80;


    double r = processorLoop(currentIns, disassembler, 1, steps);

    return 0;
}

int main (void) {

    ins.s = &myCpu;
    dis.s = &disCpu; // set up object used for disassembler
    dis.breakpoint = 0x00;

    /* component interrupt functions */
    test_trigger_interrupt(&myCpu.currentOp);
    test_process_interrupt(&myCpu.currentOp);

    /* interrupt timing */
    test_interrupt_cycle(&ins, 60);
    test_interrupt_cycle(&ins, 120);
    test_interrupt_cycle(&ins, 60);

    /* full processor step-through */
    test_processor_step(&ins, &dis, 0x00, -1);


    return 0;
}