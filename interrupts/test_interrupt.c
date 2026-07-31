#include <assert.h>
#include "interrupt.h"

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
int test_interrupt_cycle(state *processor, size_t testingCycles) {
    printf("Test processorLoop()...  seconds expected: %lf. ", (double) testingCycles/60);
    setupCPU(&processor->currentOp);
    double r = processorLoop(processor, testingCycles);

    assert(testingCycles/60 > r-0.5);
    assert(testingCycles/60 < r+0.5);

    printf("Seconds elapsed: %lf. Test passed\n", r);
    return 0;
}


int main (void) {

    test_trigger_interrupt(&myCpu.currentOp);
    test_process_interrupt(&myCpu.currentOp);
    test_interrupt_cycle(&myCpu, 60);
    test_interrupt_cycle(&myCpu, 120);
    test_interrupt_cycle(&myCpu, 1200);

    return 0;
}