#include <assert.h>
#include "interrupt.h"

int test_interrupt_cycle (struct cpu* cpu, int seconds);
pthread_t test1, test2;

struct cpu my_cpu;                 // this is a test CPU structure specific to interrupts

/*
* setup CPU for testing
*/
int setup_cpu(struct cpu* cpu) {

    cpu->interruptInit = 0;         // interrupt loop has not started
    cpu->shutdownCondition = 0;     // it is not time to shut down processor

    // for testing
    cpu->refresh_cycles=0;          // tracks refresh cycles from time of interrupt init
                                    // NOTE: after this point refresh_cycles is protected by a mutex lock

    // for testing
    cpu->mid_call = 0;              // touching the midscreen interrupt handler function will set to 1
    cpu->vblank_call = 0;           // touching the VBLANK interrupt handler function will set to 1

    return 0;
}

/*
* teardown CPU object after testing
*/
int teardown_cpu(struct cpu* cpu) {

    printf("teardown...\n");

    /* this is a dummy function in case of future needs */
    return 0;
}

/*
*   Name: test_interrupt_cycle
*   description: test for approx 60hz timing for a set amount of time
*       param: seconds (int) - the number of seconds the test will run
*
*       assert: refresh rate range is between: 56 < refresh_rate < 62
*       assert: handler for midscreen interrupt is called
*       assert: handler for VBLANK interrupt is called
*/
int test_interrupt_cycle (struct cpu* cpu, int seconds) {

    setup_cpu(cpu);

    // intro test
    printf("%d-second trial:\n", seconds);

    // time the main function
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // run interrupts for [seconds] seconds
    // note this is running in the main thread
    // but enable interrupt spins off a thread for the interrupt cycle
    enableInterrupt(cpu);

    // after (seconds) seconds, we fire off a command
    // to shut down interrupt cycle
    sleep(seconds);
    stopInterruptLoop(cpu);

    // get time it took (confirm near 1 second)
    clock_gettime(CLOCK_MONOTONIC, &end);
    uint64_t nseconds = ((end.tv_nsec - start.tv_nsec) + (1e9 * (end.tv_sec - start.tv_sec)) );
    double run_seconds = (nseconds/ 1e9);

    // calculate refresh rate
    pthread_mutex_lock(&((struct cpu*) cpu)->cyclesAccess);
    double refresh_rate = cpu->refresh_cycles / run_seconds;
    
    // display refresh rate
    printf("%d second run: cycles: %ld, time: %f, refresh rate: %f\n", 
            seconds, cpu->refresh_cycles, run_seconds, refresh_rate);
    pthread_mutex_unlock(&((struct cpu*) cpu)->cyclesAccess);
    
    //assert that refresh rate near 60 hz
    assert(refresh_rate < 62);
    assert(refresh_rate > 56);

    // assert that interrupt handlers are touched
    assert(cpu->mid_call !=0);
    assert(cpu->vblank_call !=0);

    // teardown and return
    teardown_cpu(cpu);
    return 0;
}

/*
*   Name: runInterruptTest
*   Description: runs several timed tests using test_interrupt_cycle to assess interrupt loop
*                Checks for refresh frame rate reasonably close to 60 hz
*                Current acceptable range is set from 56 - 62 hz 
*/
int runInterruptTest(struct cpu* cpu) {
    // initialize mutex lock for 'enable interrupt'
    pthread_mutex_init(&cpu->enableInt, NULL);

    // initialize mutex lock for 'refresh_cycles'
    // this prevents race conditions during testing
    pthread_mutex_init(&cpu->cyclesAccess, NULL);

    // run first test: 1 second
    test_interrupt_cycle(cpu, 1);

    sleep(4);

    // run second test: 45 seconds
    test_interrupt_cycle(cpu, 45);

    sleep(4);

    // run third test: 180 seconds
    test_interrupt_cycle(cpu, 180);

    return 0;
}


int main (void) {

    // setup a CPU object
    runInterruptTest(&my_cpu);

   return 0;
}