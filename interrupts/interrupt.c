#include "interrupt.h"

// declare threads for the interrupt loop
pthread_t threadpool[20];

pthread_t interruptLoop, t3;
int r1, r2;

/*
* function simulates a time delay before the CPU calls EI instruction
*/
void test_enable_cycle(struct cpu* cpu) {
    enableInterrupt(cpu);
}

/*
* fuction: enableInterrupt
* start or enable interrupt cycle in the CPU
*/
void enableInterrupt(struct cpu* cpu) {

    // change: void enableInterrupt(struct cpu* cpu)

     // start interrupt loop if needed
    if (((struct cpu*) cpu)->interruptInit == 0) {

        // printf("enable interrupt called start loop\n");

        ((struct cpu*)cpu)->interruptInit = 1;

        if (pthread_create(&t3, NULL, startInterruptLoop, (void *) cpu)) {
            perror("Error: spinning off thread for startInterruptLoop\n");
        }
        
        pthread_detach(t3);
    } 
    
    // otherwise, release mutex lock
    else {
        pthread_mutex_unlock(&((struct cpu*)cpu)->enableInt);
    }

}


/*
* start and detach the CPU's interrupt loop
* this also locks the mutex, starting the loop in locked mode
*/
void* startInterruptLoop(void* cpu) {

    // clear the shutdownCondition for interrupt loop
    ((struct cpu*) cpu)->shutdownCondition = 0;
 
    // spin off thread to run interrupts
    if (pthread_create(&interruptLoop, NULL, interruptCycle, (void *) cpu)) {
        perror("ERROR creating thread: interrupt loop\n");
    }

    // detatch thread and return
    pthread_detach(interruptLoop);
    return NULL;
}

/*
*  set the CPU's shutdownCondition to 1 [true]
*  stops the interrupt loop
*/
void stopInterruptLoop(struct cpu* cpu) {

    cpu->shutdownCondition = 1;
}

/*
*   function: callMidscreenInterrupt
*       Execute midscreen interrupt
*       vector path: opcode 0xCF [RST 1]
*/
void* callMidscreenInterrupt(void *args) {

    // obtain lock (this is locked when interrupts are disabled)
    pthread_mutex_lock(&((struct cpu*) args)->enableInt);

    // TESTING -- TODO: remove and replace relevant assert
    ((struct cpu*) args)->mid_call+=1;

    // todo: insert instruction into CPU
    sleep(.001);

    // TODO: remove. Interrupts should not be enabled until EI command is processed
    test_enable_cycle((struct cpu*) args);
    return NULL;
}


/*
*   function: callVblankInterrupt
*       Executes VBLANK interrupt
*       vector path: opcode 0xD7 [RST 2]
*/
void* callVblankInterrupt(void *args) {

    // obtain lock (this is locked when interrupts are disabled)
    pthread_mutex_lock(&((struct cpu*) args)->enableInt);

    // for testing TODO: remove this and rewrite test
    ((struct cpu*) args)->vblank_call+=1;

    // todo: insert instruction into CPU
    sleep(.001);

    // TODO: remove. Interrupts should not be enabled until EI command is processed
    test_enable_cycle((struct cpu*) args);

    return NULL;
}


/*
*   function: interruptCycle
*   timed 60hz interrupt cycle spins off two interrupts in their own thread
*           a midscan interupt to vector 0xCF
*           an end-of-scan (VBLANK) interrupt to vector 0xD7
*
*   this function uses nanosleep in the time.h library to pause
*/
void* interruptCycle (void* cpu) {

    //printf("interruptCycle called\n");
    //((struct cpu*) cpu)->refresh_cycles = 0;

    double run_seconds = 0.0;
    double run_rate;
    int totalNano = 0;
    struct timespec startTime, finishTime;          // CRITICAL: for interrupt timing
    struct timespec monitorStart, monitorEnd;       // TESTING:  for timing cycle

    // TESTING: variable is changed by interrupt handler call
    // TODO: should be changed to something relevant when functions implemented
    ((struct cpu*) cpu)->mid_call = 0;
    ((struct cpu*) cpu)->vblank_call = 0; 

    while (((struct cpu*) cpu)->shutdownCondition == 0) {

        clock_gettime(CLOCK_MONOTONIC, &monitorStart);

        // get thread index
        pthread_mutex_lock(&((struct cpu*) cpu)->cyclesAccess);
        int index1 = ((struct cpu*) cpu)->refresh_cycles % 20;
        pthread_mutex_unlock(&((struct cpu*) cpu)->cyclesAccess);
        int index2 = (index1 + 10) % 20;

        // timing for pause between start of screen refresh and midcycle interrupt
        struct timespec m_rem, midscreen_wait = {0,MIDSCREEN_SLEEP_NANOSECONDS};

        // start timing midcycle interrupt
        clock_gettime(CLOCK_MONOTONIC, &startTime);

            // pause for MIDSCREEN_SLEEP_NANOSECONDS (defined in header)
            while (nanosleep(&midscreen_wait, &m_rem) == -1) {
                midscreen_wait = m_rem;
            }
        
            // call midscreen interrupt handler & spin off thread
            r1 = pthread_create(&threadpool[index1], NULL, callMidscreenInterrupt, cpu);

        // finish timing midcycle interrupt & save
        clock_gettime(CLOCK_MONOTONIC, &finishTime);
        long elapsed = finishTime.tv_nsec - startTime.tv_nsec + (finishTime.tv_sec - startTime.tv_sec) * 1e9;
        
        // timing for pause between midcycle interrupt and VBLANK / end of refresh interrupt
        struct timespec v_rem, vblank_wait = {0, CYCLETIME - elapsed};

        // pause for CYCLETIME - elapsed nanoseconds [CYCLETIME is defined in header]
        while (nanosleep(&vblank_wait, &v_rem) == -1) {
            vblank_wait = v_rem;
        }

        // call VBLANK interrupt handler and spin off thread
        r2 = pthread_create(&threadpool[index2], NULL, callVblankInterrupt, cpu);

        // increment number of refresh cycles (for testing)
        pthread_mutex_lock(&((struct cpu*) cpu)->cyclesAccess);
        ((struct cpu*) cpu)->refresh_cycles += 1;
        pthread_mutex_unlock(&((struct cpu*) cpu)->cyclesAccess);

        // detach threads
        pthread_detach(threadpool[index1]);
        pthread_detach(threadpool[index2]);

        clock_gettime(CLOCK_MONOTONIC, &monitorEnd);
 
        /*
        * ******************************************************** 
        * utility time information for testing and diagnostics 
        * for timed timing: test_interrupt_cycle() located in test_interrupt.c
        *
        * printf("%ld\n", ((struct cpu*) cpu)->refresh_cycles);
        * int nseconds = ((monitorEnd.tv_nsec - monitorStart.tv_nsec) + (1e9 * (monitorEnd.tv_sec - monitorStart.tv_sec)));
        * run_seconds += (nseconds/1e9);
        * run_rate = ((struct cpu*) cpu)->refresh_cycles / run_seconds;
        * **********************************************************
        */
    }

    // set shutdownCondition and interruptInit to 0
    // will allow loop to be restarted with EI call
    // ((struct cpu* ) cpu)->shutdownCondition = 0;
    //((struct cpu* ) cpu)->interruptInit = 0;

    // return
    return NULL;
}

/*
int main (void) {

    // start test cpu object with pthread mutex
    // initialize the pthread mutex 
    // start cpu with interruptInit set to 0
    struct cpu my_cpu;

    pthread_mutex_init(&my_cpu.enableInt, NULL);
    my_cpu.interruptInit = 0;

    // time the main function
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    enableInterrupt(&my_cpu);
    sleep(10);
    stopInterruptLoop(&my_cpu);

    sleep(4);


    clock_gettime(CLOCK_MONOTONIC, &end);

    double total_time = (end.tv_nsec - start.tv_nsec + (end.tv_sec - start.tv_sec) * 1e9) / 1e9;

    printf("%f\n", total_time);

return 0;    
}
*/