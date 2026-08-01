#ifndef HANDLE_SEGMENT_H
#define HANDLE_SEGMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpu.h"
#include "opcodes.h"

#define REGISTERS 8
#define CATEGORIES 0x10

struct instructionData {
    int instruction;
    int cycles;
    int cyclesFalse;
    int operand1;
    int operand2;
    char assembly[30];
    char help[255];
    uint16_t breakpoint; // for debugger
    uint16_t stepControl;
    state *s;
};

typedef int (* const hfv_i)(struct instructionData*);
extern char* CPURegisters[9];
extern char *CPURegisterPairs[4];
extern char *rotateInstructions[8];
extern char *ALUInstructions[8];
extern char *ALUImmInstructions[8];
extern char *flagConditionals[8];

int printInstruction(struct instructionData *currentIns);

/* 
****************** SEGMENT 0 ******************
*   INSTRUCTION % 16 = 
*             0           NOP at 0x00 or undefined
*             1           load immediate (2 bytes) into register pair
*             2           store accumulator at address in register pair
*             3           increment value in register pair
*             4           increment value in high-order byte of register pair
*             5           decrement value in high-order byte of register pair
*             6           load immediate (1 byte) into high order register
*             7           rotate accumulator (various instructions)
*                               0. rotate left
*                               1. rotate left through carry bit
*                               2. decimal adjust accumulator
*                               3. set carry flag
*             8           undefined
*             9           double addition (HL += value in register pair)
*             A           load accumulator from address in register pair, various
*                               0. load accumulator from address in BC
*                               1. load accumulator from address in DE
*                               2. load registers H and L from memory 
*                                  (imm1: low memory address, imm2: high address)
*                               3. load accumulator directly from memory 
*                                  (N+1 low  address, N+2 high address)
*             B           decrement value in register pair
*             C           increment value in low-order byte of register pair
*             D           decrement value in low-order byte of register pair
*             E           load immediate (1 byte) into low order register
*             F           rotate accumulator (various instructions)
*                               0. rotate right
*                               1. rotate right through carry bit
*                               2. complement accumulator
*                               3. complement carry flag
*/

char* getSeqRegister(struct instructionData *currentIns);
char* getSeqRegisterPair(struct instructionData *currentIns);
void modifyRegisterPair(char* registerPair, char** pairToPrint);
int getModIndex_16(struct instructionData *currentIns);
int getModIndex_8(struct instructionData *currentIns);
int getSeqIndex_8(struct instructionData *currentIns);
int getSeqIndex_16(struct instructionData *currentIns);
int handleALUHelp(struct instructionData *currentIns, int *opIndex, int *sourceIndex);

int segment0_0(struct instructionData*);
int segment0_1(struct instructionData*);
int segment0_2(struct instructionData*);
int segment0_3(struct instructionData*);
int segment0_4(struct instructionData*);
int segment0_5(struct instructionData*); 
int segment0_6(struct instructionData*);
int segment0_7(struct instructionData*);
int segment0_8(struct instructionData*);
int segment0_9(struct instructionData*);
int segment0_A(struct instructionData*);
int segment0_B(struct instructionData*);
int segment0_C(struct instructionData*);
int segment0_D(struct instructionData*);
int segment0_E(struct instructionData*);
int segment0_F(struct instructionData*);

static hfv_i seg0Array[] = {
                                segment0_0, 
                                segment0_1, 
                                segment0_2, 
                                segment0_3, 
                                segment0_4, 
                                segment0_5, 
                                segment0_6, 
                                segment0_7, 
                                segment0_8, 
                                segment0_9, 
                                segment0_A,
                                segment0_B,
                                segment0_C,
                                segment0_D,
                                segment0_E,
                                segment0_F
                            };


int segment1(struct instructionData *currentIns);
int segment2(struct instructionData *currentIns);

/*
***************** SEGMENT 3 *************************
*   INSTRUCTION % 16 = 
*             0           return if relevant flag is clear
*             1           pop from stack into register pair
*             2           jump if relevant flag is clear
*             3           various
*             4           call subroutine if relevant flag is clear
*             5           push register pair onto the stack
*             6           ALU operations w/ immediate value & accumulator
*             7           built in restart calls
*             8           return if relevant flag is set
*             9           various
*             A           jump if relevant flag is set
*             B           various
*             C           call subroutine if relevant flag is set
*             D           various
*             E           ALU operations w/ immediate value & accumulator
*             F           built in restart calls
*/

int segment3_0(struct instructionData*);
int segment3_1(struct instructionData*);
int segment3_2(struct instructionData*);
int segment3_3(struct instructionData*);
int segment3_4(struct instructionData*);
int segment3_5(struct instructionData*); 
int segment3_6(struct instructionData*);
int segment3_7(struct instructionData*);
int segment3_8(struct instructionData*);
int segment3_9(struct instructionData*);
int segment3_A(struct instructionData*);
int segment3_B(struct instructionData*);
int segment3_C(struct instructionData*);
int segment3_D(struct instructionData*);
int segment3_E(struct instructionData*);
int segment3_F(struct instructionData*);

static hfv_i seg3Array[] = {
                                segment3_0, 
                                segment3_1, 
                                segment3_2, 
                                segment3_3, 
                                segment3_4, 
                                segment3_5, 
                                segment3_6, 
                                segment3_7, 
                                segment3_8, 
                                segment3_9, 
                                segment3_A,
                                segment3_B,
                                segment3_C,
                                segment3_D,
                                segment3_E,
                                segment3_F
                            };

#endif
