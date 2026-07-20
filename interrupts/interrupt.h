#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define CYCLETIME 16660000                 // interrupts at 60 hz
#define SECONDS 0                               // seconds
#define MIDSCREEN_SLEEP_NANOSECONDS 7200000     // nanoseconds before midscreen interrupt
#define WORKTIME 140500                         // pad time for work to execute (estimate)

/*
*   Interrupts currently work with a cpu struct called testCPU
*   these have several critical components:
*       -- pthread_mutex_t enableInt  --  mutex lock simulates interrupt enable pin
*       -- int interruptInit   --  0 if interrupts have not started yet
*       -- int shutdownCondition -- 0 while interrupt cycle is ongoing
*
*       both interruptInit and shutdownCondition should be initialized to 0
*
*   The following functions should be modified once opcode processing is available:
*       -- callMidscreenInterrupt should not directly enable interrupts through test_interrupt_cycle()
*       -- callVblankInterrupt should not directly enable interrupts through test_interrupt_cycle()
*
*       ( in both cases, processing the EI instruction should result in a call to the
*         enableInterupt function )
*
*   Finally, the CPU structure contains several variables and a mutex lock that can track 
*   refresh cycles, and whether the interrupt handlers were touched for testing:
*
*       -- uint64_t refresh_cycles   // initialize to 0 for testing
*       -- uint64_t mid_call         // intialize to 0 for testing
*       -- uint64_t vblank_call      // initialize to 0 for testing
*/

// test cpu object containing only data members needed for interrupts
// instead of this the regular cpu object should be imported
struct cpu {
    pthread_mutex_t enableInt;
    pthread_mutex_t cyclesAccess;
    int interruptInit;
    int shutdownCondition;
    uint64_t refresh_cycles;         // for testing
    uint64_t mid_call;                   // for testing
    uint64_t vblank_call;                // for testing
};

void* callMidscreenInterrupt(void *args);
void* callVblankInterrupt(void *args);
// void* enableInterrupt(void* cpu);
void enableInterrupt(struct cpu* cpu);
void* interruptCycle(void *cpu);
void* startInterruptLoop(void* cpu);
void stopInterruptLoop(struct cpu* cpu);

void test_enable_cycle(struct cpu* cpu);    // for testing


#endif