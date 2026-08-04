#include "interrupt.h"

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
//    clock_nanosleep(CLOCK_MONOTONIC, 0, &cycleWait, NULL);
    // remove when not compiling with Apple libc - it doesn't have clock_nanosleep
    nanosleep(&cycleWait, NULL);


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
*
*   @param: cpu, a pointer to the subsection of the state struct that holds interrupt
*           enable boolean, interrupt ready boolean, buffer for interrupt vector, 
*           and current opcode.
*/
int processInterrupt(process_r *cpu) {

    // check if there is an interrupt ready.
    // if so, place the vector into the current opcode position
    // and then clear buffer
    if (cpu->interruptReady != 0x00){
        memset(&cpu->currentOpcode, cpu->interruptBuffer, sizeof(uint8_t));
        memset(&cpu->interruptBuffer, 0x00, sizeof(uint8_t));
        memset(&cpu->interruptReady, 0x00, sizeof(uint8_t));

        // disable interrupts
        cpu->interruptEnabled = 0x00;
    }

    return 0;
}

/* 
*   function: stepOrQuit
*   poll for single-character input from keyboard for debugger control
*
*   @param: disassembler, a pointer to the secondary instruction structure
*           used for debug/diassembly
*   @param: inputBuffer, a small pointer to a string buffer
*   @param: bufferSize: the size of the string buffer, an integer
*
*   @returns: 1 if user wants to quit, 3 to continue, 0 for set a breakpoint, 2 otherwise
*/
int stepOrQuit(struct instructionData *disassembler, char *inputBuffer, int bufferSize) {

    // clear buffer
    memset(inputBuffer, '\0', bufferSize);

    printf("press 'n' to step to next instruction, 'b' to enter breakpoint, 'c' to continue, 'q' to quit: ");

    // while buffer remains an empty string, poll for input
    while(1) {
        fgets(inputBuffer, bufferSize, stdin);

        if (inputBuffer[0] == 'n' || inputBuffer[0] == 'q' || inputBuffer[0] == 'c') {
            break;
        }
        else if (inputBuffer[0] == 'b') {
            setLoopBreakpoint(&disassembler->breakpoint);
            printf("\rPress 'n' to step to next instruction, 'c' to continue, 'q' to quit: ");
        }
    }

    switch(inputBuffer[0]) {
        case 'q': return 1;
        case 'c': 
            // turn off step control
            printf("case c triggered\n");
            handleContinue(disassembler);
            return 3;
        case 'b': return 0;
    }

    return 2;
}

/*
*   function: copyOperands
*   Sets up disassembler, a pointer to a secondary instruction structure used only for
*       debug/disassembly. This initialization syncs it with the primary instruction struct,
*       then steps ahead so that assembly and help strings are available.
*/
void copyOperands (struct instructionData *currentIns, struct instructionData *disassembler) {
    disassembler->instruction = currentIns->s->currentOp.currentOpcode;
    uint16_t pc = getReg16(currentIns->s, PC);
    disassembler->operand1 = memFetch(currentIns->s, highFrom16Bit(pc+1), lowFrom16Bit(pc+1));
    disassembler->operand2 = memFetch(currentIns->s, highFrom16Bit(pc+2), lowFrom16Bit(pc+2));

    dispatchLevel2(disassembler);

    return;
}

/*
*   function: setLoopBreakpoint
*   Handles setting a breakpoint for the debugger
*   @param: breakpoint, a pointer to the breakpoint data member in the disassembler
*           secondary instruction object.
*/
void setLoopBreakpoint(uint16_t *breakpoint) {

    // CRASH OUT: can't dereference null pointer
    if (breakpoint == NULL) {
        perror("Error: breakpoint pointer was NULL\n");
        exit(EXIT_FAILURE);
    }

    // set and clear input buffer
    char inputBuffer[10];
    
    printf("Please enter breakpoint in hexadecimal: ");

    while (1) {
        memset(&inputBuffer, '\0', 10);
        fgets(inputBuffer, 10, stdin);
        sscanf(inputBuffer, "%hx", breakpoint);
        if (*breakpoint < 0x2000) {
            fflush(stdout);
            break;
        }
        else {
            printf("Enter memory address between 0x0000 and 0x1FFF: ");
        }
    }
    memset(&inputBuffer, '\0', 10);
    fflush(stdout);
    return;
}

/*
*   function: handleContinue
*   Turns off step control to allow the program to run unhindered. Sets 
*   breakpoint in the disassembler struct. Processing should stop when
*   program counter reaches this point
*
*   @param: disassembler, a pointer to the secondary instruction structure
*           (used only for debug/disassembly)
*/
void handleContinue(struct instructionData *disassembler) {
    if (disassembler->breakpoint != 0) {
        disassembler->stepControl = 0;
    }
    else {
        printf("Breakpoint not set. ");
        setLoopBreakpoint(&disassembler->breakpoint);
    }
    return;
}

/*
*   function: processStep
*   Processes an instruction in the CPU. This modifies the CPU as desired depending on the
*           opcode being processed.
*
*   @param: currentIns, a pointer to the current struct instructionData object
*/
void processStep(struct instructionData *currentIns) {

    // prep instruction for dispatch
    state *processor = currentIns->s;
    currentIns->instruction = processor->currentOp.currentOpcode;

    // set operands from two addresses following program counter
    uint16_t currentPC = getReg16(processor, PC);
    currentIns->operand1 = memFetch(processor, highFrom16Bit(currentPC + 1), lowFrom16Bit(currentPC + 1));
    currentIns->operand2 = memFetch(processor, highFrom16Bit(currentPC + 2), lowFrom16Bit(currentPC + 2));

    // clear assembly, help and cycles
    memset(currentIns->assembly, '\0', sizeof(currentIns->assembly));
    memset(currentIns->help, '\0', sizeof(currentIns->help));
    currentIns->cycles = 0;
    currentIns->cyclesFalse = 0;

    // increment program counter by 1
    aluAddImm16NoFlags(processor, PC, 0x01);

    // execute opcode
    int operands = dispatchLevel2(currentIns);

    // CRASH OUT: program counter error
    if (getReg16(currentIns->s, PC) > 0x1FFF) {
        printf("ERROR: program counter above 0x2000 at %02X\n", currentPC);
        exit(EXIT_FAILURE);
    }

    // CRASH OUT: stack pointer error
    if (getReg16(currentIns->s, SP) < 0x2000 && getReg16(currentIns->s, SP) != 0x00) {
        printf("ERROR: stack pointer below 0x2000 at %02X\n", currentPC);
        exit(EXIT_FAILURE);
    }

    // advance program counter if necessary to account for operands
    aluAddImm16NoFlags(processor, PC, operands);

    // populate next opcode from PC
    currentPC = getReg16(processor, PC);
    processor->currentOp.currentOpcode = memFetch(processor, highFrom16Bit(currentPC), lowFrom16Bit(currentPC));

    return;
}

/*
*   function: debuggerControl
*   a component of the processor loop that provides a debugging infrastructure that allows us 
*       to step through the code as it executes, tracking down problems.
*
*   @param: currentIns, a pointer to the current active instruction object
*   @param: disassembler, a pointer to a partial mirror that we can disassemble early to get instruction info
*   @param: loopControl, a pointer to an integer where we store return values (this allows us to quit
*                       the main loop if we desire to do so)
*   @param: inputBuffer, a simple string buffer that we can use to get terminal input from the debugger
*   @param: bufferSize, the size of the string buffer (inputBuffer)
*
*   @returns: 0 when completed successfully
*/
int debuggerControl(struct instructionData *currentIns, 
                    struct instructionData *disassembler, 
                    int *loopControl, 
                    char* inputBuffer, 
                    int bufferSize) 
{
    // print registers & flags
    printCPUState(currentIns->s);
    
    // disassemble upcoming instruction
    copyOperands(currentIns, disassembler);

    // print disassembly information
    printInstruction(disassembler);

    // handle debugger control (stepping in, set breakpoint, continue, next)
    if (disassembler->stepControl == 1 || getReg16(currentIns->s, PC) == disassembler->breakpoint) {

        // turn step control back on
        disassembler->stepControl = 1;

        // inquire about next step
        *loopControl = stepOrQuit(disassembler, inputBuffer, 3);
    }

    return 0;
}

/*
*   function: processorLoop
*   Simulating the following portions of the main game loop: CPU state, interrupts, debugger
*
*   @param: struct instructionData *currentIns, a pointer to the current instruction object
*   @param: struct instructionData *disassembler, a parallel object we can use to disassemble in advance
*
*   @returns: 0 when loop has ended and exited gracefully
*/
int processorLoop(struct instructionData *currentIns, struct instructionData *disassembler) {

    // grab the cpu (state) from current instruction
    state *processor = currentIns->s;

    // simulate nanoseconds passing
    long ticks = 0;

    // turn on midscreen interrupt
    uint8_t needMidscreen = 1;

    // input buffer & variables for stepwise loop control
    char inputBuffer[3];
    int loopControl = 0;
    disassembler->stepControl = 1; // turn on step control until it's turned off

    while (loopControl != 1) {

        /* process CPU instruction */
        processStep(currentIns);

        /* keep accounting of nanoseconds "spent" */
        ticks += (STATETIME*currentIns->cycles);

        /* check for interrupts.... is it time? */
        if (ticks > VBLANK) 
        {
            /* trigger VBLANK interrupt*/
            triggerInterrupt(&processor->currentOp, 0xD7);
            waitCycles();
            ticks = 0; // resets "timer" count
            needMidscreen = 1;  
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

        // run debugger control
        // TODO: turn this off
        debuggerControl(currentIns, disassembler, &loopControl, inputBuffer, sizeof(inputBuffer));
    }
    return 0;
}

// -----------

/*
*   function: timingTestLoop
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
double timingTestLoop(state *processor, size_t testingCycles) {

    // simulate nanoseconds passing
    long ticks = 0;

    // turn on midscreen interrupt
    uint8_t needMidscreen = 1;

    // intialize and start clock for testing
    struct timespec startTime, loopTime; 
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
