#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "../core/handler.h"    // handler.h -> handleSegment.h -> cpu.h & opcodes.h
#include "../helpers/helpers.h"

#define CONVERSIONFACTOR 2                      // magic number, accounts for real processing time
#define STATETIME 500    // nanosecond duration of a processor state
#define MIDSCREEN 8333333                       // nanoseconds before midscreen interrupt
#define VBLANK 16666667                         // nanoseconds before VBLANK intrupt

/*
*   Interrupts will work with a structure within the CPU state of type process_r
*   this has three components
*       -- uint8_t currentOpcode -- the current opcode being processed
*       -- uint8_t interruptBuffer -- a one byte pseudo-register where the interrupt vector can go
*       -- uint8_t interruptReady -- an unsigned 8-bit integer imitating a boolean: 
*                                       * zero: no interrupt vector is ready
*                                       * nonzero: an interrupt vector is ready
*       -- uint8_t interruptEnable -- an unsigned 8-bit integer representing a boolean:
*                                       * zero: interrupts are disabled
*                                       * nonzero: interrupts are enabled.
*
*       both interruptBuffer, interruptReady, and interruptEnable should be initialized to 0
*
*/

// cpu interrupts
int triggerInterrupt(process_r *cpu, uint8_t vector);
int processInterrupt(process_r *cpu);

// cpu instruction processing
void processStep(struct instructionData *currentIns);
int processorLoop(struct instructionData *currentIns, struct instructionData *disassembler);
double timingTestLoop(state *processor, size_t testingCycles);

// debugger control
int stepOrQuit(struct instructionData *disassembler, char *inputBuffer, int bufferSize);
void setLoopBreakpoint(uint16_t *breakpoint);
void handleContinue(struct instructionData *disassembler);
int debuggerControl(struct instructionData *currentIns, 
                    struct instructionData *disassembler, 
                    int *loopControl, 
                    char* inputBuffer, 
                    int bufferSize);

#endif