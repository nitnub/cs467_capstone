#include "interrupt.h"

pthread_mutex_t timelock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t timer = PTHREAD_COND_INITIALIZER;


/* 
*   function: waitCycles
*   delays to make up the extra time the Intel 8080 would have taken for each cycle state
*/
int waitCycles(void) {
    
    // initialize wait time
    struct timespec cycleWait;
    cycleWait.tv_sec = 0;
    cycleWait.tv_nsec = MIDSCREEN;

    // wait the time expected for half of screen refresh cycle
    clock_nanosleep(CLOCK_MONOTONIC, 0, &cycleWait, NULL);

    return 0;
}

/*
*   function: triggerInterrupt
*   Trigger and interrupt when we reach roughly the middle and end of screen refresh
*   For space invaders, interrupts are: 
*           -- Midscreen: 0xCF [RST 1] 
*           -- VBLANK: 0xD7 [RST 2]
*/
int triggerInterrupt(process_r *cpu, uint8_t vector) {

    if (cpu->interruptEnabled != 0) {
        // place vector into the buffer
        memset(&cpu->interruptBuffer, vector, sizeof(uint8_t));
        memset(&cpu->interruptReady, 0x01, sizeof(uint8_t));
    }

    return 0;
}

/* 
*   function: processInterrupt
*   When an interrupt vector is ready, move it into the currentOpcode slot for processing.
*   Then clear the buffer and turn off the ready flag.
*/
int processInterrupt(process_r *cpu) {

    // check if there is an interrupt ready.
    // if so, place the vector into the current opcode position
    // and then clear buffer
    if (cpu->interruptReady != 0x00){
        //printf("interrupt ran for %02X\n", cpu->interruptBuffer);
        memset(&cpu->currentOpcode, cpu->interruptBuffer, sizeof(uint8_t));
        memset(&cpu->interruptBuffer, 0x00, sizeof(uint8_t));
        memset(&cpu->interruptReady, 0x00, sizeof(uint8_t));
    }

    return 0;
}

/*
*   function: processorLoop
*   simulates the timing of a main game loop (60hz monitor refresh with 2 Mhz processor
*   by setting interrupts at set intervals
*
*   @param: state *processor, a pointer to the cpu structure
*   @param: size_t testingCycles: the number of screen refresh cycles we plan to test
*
*   @returns: double elapsed, the number of seconds it took to process testingCycles
*
*   NOTE: processor timing
*       The intel 8080 runs at 2 Mhz (2 million cpu states per second)
*
*       1 processor state should take 500 nanoseconds. It is difficult to wait such a granular time,
*       so this loop adds up the number of states passed and waits when an interrupt is called
*
*   NOTE: monitor refresh rate:
*       The Space Invaders arcade game monitor refreshed at a rate of 60 hz.
*       This is why VBLANK is set for 16,666,667 nanoseconds (this is equivalent to 1/60 seconds)
*
*/
double processorLoop(state *processor, size_t testingCycles) {

    // simulate nanoseconds passing
    long ticks = 0;

    // turn on midscreen interrupt
    uint8_t needMidscreen = 1;

    // intialize and start clock for testing
    struct timespec startTime, loopTime, instructionStart; 
    double elapsed = 0;
    clock_gettime(CLOCK_MONOTONIC, &startTime);

    // initialize number of refresh cycles for testing
    size_t i = testingCycles;

    while (i > 0) {
      
        /* toy instruction execution -- simulates stepCPU or similar */
        int cycles = 10;    // after dispatch, we get cycles from struct instructionData
        ticks += (STATETIME*cycles); // ticks keeps track of nanoseconds "spent"

        if (ticks > VBLANK) 
        {
            /* trigger VBLANK interrupt*/
            triggerInterrupt(&processor->currentOp, 0xD7);
            waitCycles();
            ticks = 0; // resets "timer" count
            needMidscreen = 1;

            i -= 1; // count down the screen refresh cycles for testing    
        }

        else if (ticks > MIDSCREEN && needMidscreen == 1) 
        {
            /* trigger midscreen interrupt */
            triggerInterrupt(&processor->currentOp, 0xCF);
            waitCycles();
            needMidscreen = 0;   
        }
        
        /* run interrupt if one is ready */
        processInterrupt(&processor->currentOp);
    }

    /* get return value to check timing */
    clock_gettime(CLOCK_MONOTONIC, &loopTime);
    elapsed = (loopTime.tv_nsec - startTime.tv_nsec + (loopTime.tv_sec - startTime.tv_sec) * 1e9) / 1e9;
    return elapsed;
}

