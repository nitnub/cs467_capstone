#include "handleSegment.h"

/*
******************* REGISTERS & ASSEMBLY MNEMONICS **************
*/

char* CPURegisters[] = {"B", "C", "D", "E", "H", "L", "M", "A", "immediate"};
char *CPURegisterPairs[] = {"BC", "DE", "HL", "SP"};
char *rotateInstructions[] = {"RLC", "RRC", "RAL", "RAR", "DAA", "CMA", "STC", "CMC"};
char *ALUInstructions[] = {"ADD","ADC","SUB","SBB","ANA","XRA","ORA","CMP"};
char *ALUImmInstructions[] = {"ADI", "ACI", "SUI", "SBI", "ANI", "XRI", "ORI", "CPI"};
char *flagConditionals[] = {"NZ", "Z", "NC", "C", "PO", "PE", "P", "M"};

/*
******************* SEGMENT 0 *******************
*/

/*
* name: getSeqRegister
* description: returns the name of the current register by sequence
* calculation: instruction / REGISTERS
*/
char* getSeqRegister(struct instructionData *currentIns) {

    if (currentIns == NULL) {
        printf("error: instruction data not available\n");
        return NULL;
    }
    int quotientIndex = currentIns->instruction / REGISTERS;
    return CPURegisters[quotientIndex];
}

/*
* name: getSeqRegisterPair
* description: returns the name of the current register pair by sequence
* calculation: instruction / CATEGORIES
*/
char* getSeqRegisterPair(struct instructionData *currentIns) {

    if (currentIns == NULL) {
        printf("error: instruction data not available\n");
        return NULL;
    }

    int pairIndex = currentIns->instruction / CATEGORIES;
    return CPURegisterPairs[pairIndex];

}

/*
* name: modifyRegisterPair
* description: modify printable version of register pair to single letter (except SP)
*/
void modifyRegisterPair(char* registerPair, char** pairToPrint) {

    if (pairToPrint != NULL && registerPair != "SP") {
        sprintf(*pairToPrint, "%c", registerPair[0]);
    }
    else if (pairToPrint != NULL) {
        sprintf(*pairToPrint, "%s", registerPair);
    }
    return;
}

/*
* name: getModIndex_16
* description: get the index value: modulo division by 16
*/
int getModIndex_16(struct instructionData *currentIns) {

    // check for NULL pointers
    if (currentIns == NULL) {
        printf("error: instruction data not available\n");
        return -1;
    }
    int modIndex = currentIns->instruction % 16;
    return modIndex;
}

int getModIndex_8(struct instructionData *currentIns) {
    
    // check for NULL pointers
    if (currentIns == NULL) {
        printf("error: instruction data not available\n");
        return -1;
    }

    int modIndex = currentIns->instruction % 8;
    return modIndex;
}

int getSeqIndex_8(struct instructionData *currentIns) {
    if (currentIns == NULL) {
        printf("error: instruction data not available\n");
        return -1;
    }

    int seqIndex = (currentIns->instruction % 0x40) / 8;
    return seqIndex;
}

/*
* name: getSeqIndex_16
* description: get the sequential index value: integer division by 16
*/
int getSeqIndex_16(struct instructionData *currentIns) {
    if (currentIns == NULL) {
        printf("error: instruction data not available\n");
        return -1;
    }

    int seqIndex = (currentIns->instruction %0x40) / 16;
    return seqIndex;
}

int handleALUHelp(struct instructionData *currentIns, int *opIndex, int *sourceIndex) {

    if (opIndex == NULL || sourceIndex == NULL) {
        printf("Error generating help for ALU instruction: index data not available.\n");
        return -1;
    }

    switch (*opIndex) {

        case 0:
            sprintf(currentIns->help, "Add data in %s to data in A, store in A", CPURegisters[*sourceIndex]);
            break;

        case 1:

            sprintf(currentIns->help, "Add data in %s and carry bit to data in A, store in A", CPURegisters[*sourceIndex]);
            break;

        case 2:
            sprintf(currentIns->help, "Subtract data in %s from data in A, store in A", CPURegisters[*sourceIndex]);
            break;

        case 3:
            sprintf(currentIns->help, "Subtract data in %s and carry bit from data in A, store in A", CPURegisters[*sourceIndex]);
            break;

        case 4:
            sprintf(currentIns->help, "Bitwise logical operation: %s AND A", CPURegisters[*sourceIndex]);
            break;

        case 5:
            sprintf(currentIns->help, "Bitwise logical operation: %s XOR (exclusive 'or') A", CPURegisters[*sourceIndex]);
            break;

        case 6:
            sprintf(currentIns->help, "Bitwise logical operation: %s OR (inclusive 'or') A", CPURegisters[*sourceIndex]);
            break;

        case 7:
            sprintf(currentIns->help, "Compares by subtracting data in %s from data in A, modifies flags but does not store result", 
                    CPURegisters[*sourceIndex]);
            break;
    }

    return 0;
}

/*
* segment 0: mod 0
* No instruction (0x00 only) or undefined
*/
int segment0_0(struct instructionData *currentIns) {

    if (currentIns->instruction == 0x00) {

        // store assembly
        sprintf(currentIns->assembly, "NOP");

        // store help
        sprintf(currentIns->help, "No instruction");

        // set clock cycles
        currentIns->cycles = 4;
    }
    else {
        // undefined instruction
        sprintf(currentIns->assembly, "Undefined instruction");
        return -1;
    }

    // return 0 extra bytes used
    return 0;
}

/*
* Segment 0: mod 1
* Load immediate two bytes into register pair (high: B, D, H, low: C, E, L)
* first operand goes to low, second operand goes to high
* When displayed as one number, they should be reversed (high, low)
* NOTE: assembly syntax is slightly incorrect
*/
int segment0_1(struct instructionData *currentIns) {

    // get register pair or stack pointer
    // in this order: [BC, DE, HL, SP]
    int regPairIndex = getSeqIndex_16(currentIns); 
    char* registerPair = CPURegisterPairs[regPairIndex];

    // adjust for Intel assembly syntax (ie HL -> H)
    char* printableRegisterPair = malloc(3);
    modifyRegisterPair(registerPair, &printableRegisterPair);

    // insert and print assembly instructions
    sprintf(currentIns->assembly, "LXI %s, 0x%02X%02X", printableRegisterPair, currentIns->operand2, currentIns->operand1);

    // insert help instructions
    sprintf(currentIns->help, 
        "Load immediate data into register pair (%s): N+1 into low byte, N+2 into high", 
        registerPair);

    // set clock cycles = 10
    currentIns->cycles = 10;

    // execute opcode
    uint16_t value = convert8To16((uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1);
    setReg16(currentIns->s, regPairIndex, value);

    // handle memory
    free(printableRegisterPair);

    // return number of bytes used: 2
    return 2;
}

/*
* Segment 0: mod 2
* store accumulator at address in register pair
*/
int segment0_2(struct instructionData *currentIns) {

    int immediateCount = 0; // operands used varies between instructions

    // get register pair or stack pointer
    // in this order: [BC, DE, HL, SP]
    int regPairIndex = getSeqIndex_16(currentIns); 
    char* registerPair = CPURegisterPairs[regPairIndex];

    // adjust for Intel assembly syntax (ie HL -> H)
    char* printableRegisterPair = malloc(3);
    modifyRegisterPair(registerPair, &printableRegisterPair);

    switch(regPairIndex) {

        case 0:
            // store accumulator at address in registers BC
            sprintf(currentIns->assembly, "STAX %s", printableRegisterPair);
            // store help instructions
            sprintf(currentIns->help, "Store accumulator at address in 16 bit register or register pair %s", registerPair);
            // set clock cycles
            currentIns->cycles = 7;

            // execute opcode
            moveRegToIndirect(currentIns->s, A, regPairIndex);

            break;

        case 1:
            // store accumulator at address in registers DE
            sprintf(currentIns->assembly, "STAX %s", printableRegisterPair);
            // store help instructions
            sprintf(currentIns->help, "Store accumulator at address in 16 bit register or register pair %s", registerPair);
            // set clock cycles
            currentIns->cycles = 7;

            // execute opcode
            moveRegToIndirect(currentIns->s, A, regPairIndex);
            break;

        case 2:
            // store content of registers HL in memory (imm1 is low part of address, imm2 is high part)
            // addr <- low, addr + 1 <- high
            sprintf(currentIns->assembly, "SHLD 0x%02X%02X", currentIns->operand2, currentIns->operand1);
            // store help instructions
            sprintf(currentIns->help, 
                "Store H and L directly into 2 bytes of memory addressed by immediate operands.");
            // set clock cycles
            currentIns->cycles = 16;
            immediateCount = 2;

            // execute instruction
            moveRegPairToAddress(currentIns->s, HL, (uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1);

            break;

        case 3:
            // store accumulator in memory (N+1 imm: low address, N+2 imm: high address)
            sprintf(currentIns->assembly, "STA 0x%02X%02X", currentIns->operand2, currentIns->operand1);
            // store help instructions
            sprintf(currentIns->help, "Store accumulator in memory (N+1 imm is low address, N+2 is high).");
            // set clock cycles
            currentIns->cycles = 13;
            immediateCount = 2;

            // execute instruction
            memStore(currentIns->s, currentIns->operand2, currentIns->operand1, getReg8(currentIns->s, A));
            break;
    }

    // free memory
    free(printableRegisterPair);

    // return number of extra bytes used: 0 or 2
    return immediateCount;
}

/*
* Segment 0: mod 3
* increment value in register pair
*/
int segment0_3(struct instructionData *currentIns) {

    // get register pair or stack pointer
    // in this order: [BC, DE, HL, SP]
    int regPairIndex = getSeqIndex_16(currentIns); 
    char* registerPair = CPURegisterPairs[regPairIndex];

    // adjust for Intel assembly syntax (ie HL -> H)
    char* printableRegisterPair = malloc(3);
    modifyRegisterPair(registerPair, &printableRegisterPair);

    // store assembly
    sprintf(currentIns->assembly, "INX %s", printableRegisterPair);

    // store help instructions
    sprintf(currentIns->help, "Increment value in register pair %s", printableRegisterPair);

    // set clock cycles
    currentIns->cycles = 5;

    // execute instruction
    aluAddImm16NoFlags(currentIns->s, regPairIndex, 0x01);

    // free memory and return
    free(printableRegisterPair);
    return 0;
}

/*
* Segment 0: mod 4
* increment value in high-order register
*/
int segment0_4(struct instructionData *currentIns) {

    // get high order register: every other even register:
    // [B * D * H * M *]
    int regPairIndex = getSeqIndex_16(currentIns); 
    int regIndex = regPairIndex * 2;
    char* reg = CPURegisters[regIndex];

    // store assembly
    sprintf(currentIns->assembly, "INR %s", reg);

    // store help instructions
    sprintf(currentIns->help, "increment CPU register %s", reg);

    // set clock cycles
    if (!strcmp(reg, "M")) {
        currentIns->cycles = 10;
    } else {
        currentIns->cycles = 5;
    }

    // execute instruction
    uint8_t value = getReg8(currentIns->s, regIndex) + 1;

    // handle incrementing memory (instruction 34)
    if (regIndex == M) {
        value = memFetch(currentIns->s, getReg8(currentIns->s, H), getReg8(currentIns->s, L)) + 1;
    }

    setReg8(currentIns->s, regIndex, value);

    // handle incrementing memory (instruction 34)
    if (regIndex == M) {
        memStore(currentIns->s, getReg8(currentIns->s, H), getReg8(currentIns->s, L), value);
    }

    // set sign, parity and zero flags
    aluFlags_arithmetic(currentIns->s, regIndex, value);

    return 0;
}

/*
* Segment 0: mod 5
* decrement value in high-order register
*/
int segment0_5(struct instructionData *currentIns) {

    // get high order register: every other even register:
    // [B * D * H * M *]
    int regPairIndex = getSeqIndex_16(currentIns); 
    int regIndex = regPairIndex * 2;
    char* reg = CPURegisters[regIndex];

    // store assembly
    sprintf(currentIns->assembly, "DCR %s", reg);

    // store help instructions
    sprintf(currentIns->help, "decrement CPU register %s", reg);

    // set clock cycles
    currentIns->cycles = 5;

    // execute instruction
    uint8_t value = getReg8(currentIns->s, regIndex) - 1;

    // handle incrementing memory (instruction 34)
    if (regIndex == M) {
        value = memFetch(currentIns->s, getReg8(currentIns->s, H), getReg8(currentIns->s, L)) - 1;
    }

    setReg8(currentIns->s, regIndex, value);

    // handle incrementing memory (instruction 34)
    if (regIndex == M) {
        memStore(currentIns->s, getReg8(currentIns->s, H), getReg8(currentIns->s, L), value);
    }

    // set sign, parity and zero flags
    aluFlags_arithmetic(currentIns->s, regIndex, value);

    // printf("to implement: dispatch segment 0 mod 0x05\n");
    return 0;
}

/*
* Segment 0: mod 6
* load immediate source data into register
*/
int segment0_6(struct instructionData *currentIns) {

    // get high order register: every other even register:
    // [B * D * H * M *]
    int regPairIndex = getSeqIndex_16(currentIns); 
    int regIndex = regPairIndex * 2;
    char* reg = CPURegisters[regIndex];

    // store assembly
    sprintf(currentIns->assembly, "MVI %s, 0x%02X", reg, currentIns->operand1);

    // store help information
    sprintf(currentIns->help, "Load immediate source data into register");

    // set clock cycles
    if (!strcmp(reg, "M")) {
        currentIns->cycles = 10;
    } else {
        currentIns->cycles = 5;
    }

    // execute instruction for most registers
    setReg8(currentIns->s, regIndex, currentIns->operand1);

    // if instruction is to memory, store at location in HL
    if (regIndex == M) {
        memStore(currentIns->s, getReg8(currentIns->s, H), getReg8(currentIns->s, L), (uint8_t) currentIns->operand1);
    }

    // return number of extra bytes used:
    return 1;
}

/*
* Segment 0: mod 7
* rotation, etc
*/
int segment0_7(struct instructionData *currentIns) {

    // get even-index rotate & other accumulator/ carry flag instructions
    // in this order: ["RLC", *, "RAL", *, "DAA", *, "STC", *]
    int seqIndex = getSeqIndex_8(currentIns);
    char* rotateIns = rotateInstructions[seqIndex];

    // store as assembly instruction
    sprintf(currentIns->assembly, "%s", rotateIns);

    // store help information
    sprintf(currentIns->help, 
        "set carry flag (STC) or adjust accumulator (various): RLC (rotate left), RAL (rot. left through carry), DAA (decimal adjust)");

    // set clock cycles
    currentIns->cycles = 4;

    // execute instruction
    accum_op_array[seqIndex](currentIns->s);

    return 0;
}

/*
* Segment 0: mod 8
* Undefined instructions
*/
int segment0_8(struct instructionData *currentIns) {
    // printf("undefined instruction");
    sprintf(currentIns->assembly, "Undefined instruction");
    return -1;
}

/*
* Segment 0: mod 9
* double addition using HL as accumulator
*/
int segment0_9(struct instructionData *currentIns) {
    
    // get register pair or stack pointer
    // in this order: [BC, DE, HL, SP]
    int seqIndex = getSeqIndex_16(currentIns);
    char* registerPair = CPURegisterPairs[seqIndex];

    // adjust for Intel assembly syntax (ie HL -> H)
    char* printableRegisterPair = malloc(3);
    modifyRegisterPair(registerPair, &printableRegisterPair);

    // store assembly instructions
    sprintf(currentIns->assembly, "DAD %s", printableRegisterPair);

    // store help information
    sprintf(currentIns->help, "add value in register pair to HL (HL += %s)", registerPair);

    // set cycles
    currentIns->cycles = 10;

    // execute instruction
    doubleAdd(currentIns->s, seqIndex);

    // free memory and return
    free(printableRegisterPair);
    return 0;
}


/*
* LDAX B, LDAX D, LHLD ADDR (imm1: low, imm2: high), LDA addr 
*/
int segment0_A(struct instructionData *currentIns) {
    int immediateCount = 0;
    
    // get register pair or stack pointer
    // in this order: [BC, DE, HL, SP]
    int seqIndex = getSeqIndex_16(currentIns);
    char* registerPair = CPURegisterPairs[seqIndex];

    // adjust for Intel assembly syntax (ie HL -> H)
    char* printableRegisterPair = malloc(3);
    modifyRegisterPair(registerPair, &printableRegisterPair);

    switch (seqIndex) {
        case 0:
            // LDAX B
            sprintf(currentIns->assembly, "LDAX %s", printableRegisterPair);
            sprintf(currentIns->help, "Load accumulator from address in %s", registerPair);
            currentIns->cycles = 7;
            break;

        case 1:
            // LDAX D
            sprintf(currentIns->assembly, "LDAX %s", printableRegisterPair);
            // printf("%s\n", currentIns->assembly);
            sprintf(currentIns->help, "Load accumulator from address in %s", registerPair);
            currentIns->cycles = 7;
            break;

        case 2:
            // LHLD addr
            sprintf(currentIns->assembly, "LHLD 0x%02X%02X", currentIns->operand2, currentIns->operand1);
            // printf("%s\n", currentIns->assembly);
            sprintf(currentIns->help, "Load the contents of registers HL from memory at immediate address 0x%02x (high), 0x%02x (low)", 
                    currentIns->operand2, currentIns->operand1 );
            currentIns->cycles = 16;
            immediateCount = 2;
            break;

        case 3:
            // LDA addr
            sprintf(currentIns->assembly, "LDA 0x%02X%02X", currentIns->operand2, currentIns->operand1);
            sprintf(currentIns->help, "load accumulator directly from memory (N+1 low  address, N+2 high address");
            currentIns->cycles = 13;
            immediateCount = 2;
            break;
    }

    free(printableRegisterPair);

    // return number of extra bytes used
    return immediateCount;
}

/*
* Segment 0: mod B
* decrement register pair by 1
*/
int segment0_B(struct instructionData *currentIns) {

    // get register pair or stack pointer
    // in this order: [BC, DE, HL, SP]
    int seqIndex = getSeqIndex_16(currentIns);
    char* registerPair = CPURegisterPairs[seqIndex];

    // adjust for Intel assembly syntax (ie HL -> H)
    char* printableRegisterPair = malloc(3);
    modifyRegisterPair(registerPair, &printableRegisterPair);

    // store assembly instruction
    sprintf(currentIns->assembly, "DCX %s", printableRegisterPair);

    // store help information
    sprintf(currentIns->help, "Decrement 16-bit register/register pair %s", registerPair);

    // set clock cycles
    currentIns->cycles = 5;

    // free memory and return
    free(printableRegisterPair);
    return 0;
}

/*
* segment 0: mod C
* increment value in low-order register
*/
int segment0_C(struct instructionData *currentIns) {

    // get low order register: every other odd register:
    // [* C * E * L * A]
    int regIndex = (getSeqIndex_16(currentIns) * 2) + 1;
    char *reg = CPURegisters[regIndex];

    // store assembly instruction
    sprintf(currentIns->assembly, "INR %s", reg);

    // store help information
    sprintf(currentIns->help, "Increment register %s", reg);
    
    // store clock cycles
    currentIns->cycles = 5;

    // return
    return 0;
}

/*
* segment 0: mod D
*/
int segment0_D(struct instructionData *currentIns) {

    // get low order register: every other odd register:
    // [* C * E * L * A]
    int regIndex = (getSeqIndex_16(currentIns) * 2) + 1;
    char *reg = CPURegisters[regIndex];

    // store assembly instruction
    sprintf(currentIns->assembly, "DCR %s", reg);

    // store help information
    sprintf(currentIns->help, "Decrement register %s", reg);

    // store clock cycles
    currentIns->cycles = 5;

    // return
    return 0;
}

/*
* segment 0: mod E
* load immediate data (1 byte) into CPU register
*/
int segment0_E(struct instructionData *currentIns) {

    // get low order register: every other odd register:
    // [* C * E * L * A]
    int regIndex = (getSeqIndex_16(currentIns) * 2) + 1;
    char *reg = CPURegisters[regIndex];

    // store assembly instruction
    sprintf(currentIns->assembly, "MVI %s, 0x%02X", reg, currentIns->operand1);

    // store help information
    sprintf(currentIns->help, "Load immediate byte into %s", reg);

    // set clock cycles for loading into memory
    if (regIndex == 6) {
        currentIns->cycles = 10;
    }
    // set clock cycles for other cases
    else {
        currentIns->cycles = 7;
    }

    // return number of extra bytes used: 1
    return 1;
}


int segment0_F(struct instructionData *currentIns) {

    // get odd-index rotate & other accumulator instructions
    // in this order: [*, "RRC", *, "RAR", *, "CMA", *, "CMC"]
    int seqIndex = getSeqIndex_8(currentIns);
    char* rotateIns = rotateInstructions[seqIndex];

    // store as assembly instruction
    sprintf(currentIns->assembly, "%s", rotateIns);

    // store help information
    sprintf(currentIns->help, 
        "complement carry flag (CMC) or adjust accumulator (various):\nRRC (rotate right), RAR (rot. right through carry), CMA (complement)");

    // set clock cycles
    currentIns->cycles = 4;

    // return
    return 0;
}

/*
* handler for segment 1: loading data (various location)
*/
int segment1(struct instructionData *currentIns) {

    // special case 0x76: HLT
    if (currentIns->instruction == 0x76) {
        // handle HLT
        sprintf(currentIns->assembly, "HLT");
    } 
    else {

        // get source register
        int sourceIndex = getModIndex_8(currentIns);
        char *sourceReg = CPURegisters[sourceIndex];

        // get destination register
        int destIndex = getSeqIndex_8(currentIns);
        char *destReg = CPURegisters[destIndex];

        // store assembly
        sprintf(currentIns->assembly, "MOV %s, %s", destReg, sourceReg);
        // store help information
        sprintf(currentIns->help, "load data from %s into %s", sourceReg, destReg);

        // set clock cycles if load instruction involves memory
        if (sourceIndex == 6 || destIndex == 6) {
            currentIns->cycles = 7;
        }
        // set clock cycles if memory is not touched
        else {
            currentIns->cycles = 5;
        }

    }

    return 0;
}

/*
* handler for segment 2: ALU instructions
*/
int segment2(struct instructionData *currentIns) {

    // get operation index
    int opIndex = getSeqIndex_8(currentIns);
    char* aluOp = ALUInstructions[opIndex];

    // get source register index (destination is accumulator)
    int sourceIndex = getModIndex_8(currentIns);
    char* sourceReg = CPURegisters[sourceIndex];

    // store assembly instructions
    sprintf(currentIns->assembly, "%s %s", aluOp, sourceReg);

    // store help information
    handleALUHelp(currentIns, &opIndex, &sourceIndex);

    // store clock cycles for when memory is touched
    if (sourceIndex == 6) {
        currentIns->cycles = 7;
    }
    // store clock cycles for when memory is not touched
    else {
        currentIns->cycles = 4;
    }

    return 0;
}

/*
* individual handlers for segment 3
*/

/*
* handler for segment 3 mod 0
* conditional return from subroutine if flag is clear
*/
int segment3_0(struct instructionData *currentIns) {

    // get "if clear" (even) conditional flag suffix in order:
    // "NZ", *, "NC", *, "PO", *, "P", *
    int conditionalIndex = getSeqIndex_8(currentIns);
    char* flag = flagConditionals[conditionalIndex];

    sprintf(currentIns->assembly, "R%s", flag);

    sprintf(currentIns->help, 
            "Return from subroutine if flag is clear\n(NZ = not zero, NC = not carry, PO = parity is odd (even parity clear), P = positive (sign clear))");

    currentIns->cycles = 11;
    currentIns->cyclesFalse = 5;
    return 0;
}

/*
* handler for segment 3 mod 1
* Pop 16 bits from the stack and place in register pair destination
*/
int segment3_1(struct instructionData *currentIns) {

    // get register pair
    int pairIndex = getSeqIndex_16(currentIns);
    char* registerPair = CPURegisterPairs[pairIndex];
    char* printableRegisterPair = malloc(4);
    
    if (pairIndex == 3) {
        strcpy(printableRegisterPair, "PSW\0");
        sprintf(currentIns->help, "Pop program status word (accumulator, flags) from stack");
    }
    else {
        memset(printableRegisterPair, '\0', 4 * sizeof(char));
        strncpy(printableRegisterPair, registerPair,1);
        sprintf(currentIns->help, "Pop stack from stack to 16-bit register pair %s", registerPair);
    }

    sprintf(currentIns->assembly, "POP %s", printableRegisterPair);
    currentIns->cycles = 10;

    // printf("%s\n", currentIns->assembly);
    free(printableRegisterPair);
    return 0;
}

/*
* handler for segment 3 mod 2
* conditional jump if flag is clear
*/
int segment3_2(struct instructionData *currentIns) {

    // get "if clear" (even) conditional flag suffix in order:
    // "NZ", *, "NC", *, "PO", *, "P", *
    int conditionalIndex = getSeqIndex_8(currentIns);
    char* flag = flagConditionals[conditionalIndex];

    sprintf(currentIns->assembly, "J%s 0x%02X%02X", flag, currentIns->operand2, currentIns->operand1);
    // printf("%s\n", currentIns->assembly);
    sprintf(currentIns->help, 
            "Jump if flag is clear\n(NZ = not zero, NC = not carry, PO = parity is odd (even parity clear), P = positive (sign clear))");

    currentIns->cycles = 11;

    // extra instructions used: 2
    return 2;

}
int segment3_3(struct instructionData *currentIns) {

    char* ops[] = {"JMP", "OUT", "XTHL", "DI"};
    int opIndex = getSeqIndex_16(currentIns);
    int instructionCount = 0;

    switch (opIndex) {

        case 0:
            // unconditional jump
            sprintf(currentIns->assembly, "%s 0x%02X%02X", ops[opIndex], currentIns->operand2, currentIns->operand1);
            sprintf(currentIns->help, "Unconditional jump");
            currentIns->cycles = 10;
            instructionCount = 2;
            break;

        case 1:
            // output
            sprintf(currentIns->assembly, "%s 0x%02X", ops[opIndex], currentIns->operand1);
            sprintf(currentIns->help, "Output (port)");
            currentIns->cycles = 10;
            instructionCount = 1;
            break;

        case 2:
            // swap HL with top of the stack
            sprintf(currentIns->assembly, "%s", ops[opIndex]);
            sprintf(currentIns->help, "swap contents of registers H & L with the stack");
            currentIns->cycles = 18;
            break;

        case 3:
            // disable interrupts
            sprintf(currentIns->assembly, "%s", ops[opIndex]);
            sprintf(currentIns->help, "disable interrupts");
            currentIns->cycles = 4;
            break;
    }

    // printf("%s\n", currentIns->assembly);
    return instructionCount;
}

/*
* handler for segment 3 mod 4
* conditional call subroutine if flag is clear
*/
int segment3_4(struct instructionData *currentIns) {

    // get "if clear" (even) conditional flag suffix in order:
    // "NZ", *, "NC", *, "PO", *, "P", *
    int conditionalIndex = getSeqIndex_8(currentIns);
    char* flag = flagConditionals[conditionalIndex];

    // store assembly instruction
    sprintf(currentIns->assembly, "C%s 0x%02X%02X", flag, currentIns->operand2, currentIns->operand1);

    // store help information
    sprintf(currentIns->help, 
            "Call subroutine if flag is clear\n(NZ = not zero, NC = not carry, PO = parity is odd (even parity clear), P = positive (sign clear))");

    // store clock cycles
    currentIns->cycles = 17;
    currentIns->cyclesFalse = 11;

    // return number of extra bytes used: 2
    return 2;
}

/*
* handler for segment 3 mod 5
* push contents of register pair or PSW to the stack
*/
int segment3_5(struct instructionData *currentIns) {
    // get register pair
    int pairIndex = getSeqIndex_16(currentIns);
    char* registerPair = CPURegisterPairs[pairIndex];
    char* printableRegisterPair = malloc(4);
    
    // handle program status word
    if (pairIndex == 3) {
        strcpy(printableRegisterPair, "PSW\0");
        sprintf(currentIns->help, "Push program status word (accumulator, flags) to the stack");
    }
    else {
        memset(printableRegisterPair, '\0', 4 * sizeof(char));
        strncpy(printableRegisterPair, registerPair,1);
        sprintf(currentIns->help, "Push 16 bytes from stack to register pair %s", registerPair);
    }

    // store assembly instruction
    sprintf(currentIns->assembly, "PUSH %s", printableRegisterPair);

    // set clock cycles
    currentIns->cycles = 11;

    // free memory and return
    free(printableRegisterPair);
    return 0;

}

/*
* handler for segment 3 mod 6
* ALU operations with immediate data
*/
int segment3_6(struct instructionData *currentIns) {

    // get even ALU operation
    // in the following order: ["ADI", "ACI", "SUI", "SBI", "ANI", "XRI", "ORI", "CPI"]
    int opIndex = (getSeqIndex_16(currentIns) * 2);
    char* op = ALUImmInstructions[opIndex];
    int helpSource = 8;

    sprintf(currentIns->assembly, "%s 0x%02X", op, currentIns->operand1);
    handleALUHelp(currentIns, &opIndex, &helpSource);

    currentIns->cycles = 7;

    // return number of extra bytes used: 1
    return 1;
}


/*
* handler for segment 3 mod 7
* RESET operations
*/
int segment3_7(struct instructionData *currentIns) {
    int resetIndex = getSeqIndex_8(currentIns);

    sprintf(currentIns->assembly, "RST %d", resetIndex);
    sprintf(currentIns->help, "Call reset subroutine %d", resetIndex);
    currentIns->cycles = 7;

    return 0;
}

/*
* handler for segment 3 mod 8
* Return from subroutine if flag is set
*/
int segment3_8(struct instructionData *currentIns) {
    int conditionalIndex = getSeqIndex_8(currentIns);
    char* flag = flagConditionals[conditionalIndex];

    sprintf(currentIns->assembly, "R%s", flag);
    // printf("%s\n", currentIns->assembly);
    sprintf(currentIns->help, 
            "Return from subroutine if flag is set\n(Z = zero, C = carry, PE = parity is even, M = negative (sign set))");

    currentIns->cycles = 11;
    currentIns->cyclesFalse = 5;
    return 0;
}


/*
* handler for segment 3 mod 9 (various)
*/
int segment3_9(struct instructionData *currentIns) {

    char* ops[] = {"RET", "undefined", "PCHL", "SPHL"};
    int opIndex = getSeqIndex_16(currentIns);

    sprintf(currentIns->assembly, "%s", ops[opIndex]);

    switch(opIndex) {
        case 0:
            // unconditional return
            sprintf(currentIns->help, "Unconditional return from subroutine");
            currentIns->cycles = 10;
            break;

        case 1:
            // undefined
            sprintf(currentIns->assembly, "Undefined instruction");
            // printf("Invalid instruction: %x\n", currentIns->instruction);
            return -1;
            break;

        case 2:
            // load program counter from HL
            sprintf(currentIns->help, "Load program counter with register pair HL");
            currentIns->cycles = 5;
            break;

        case 3:
            // load stack pointer from HL
            sprintf(currentIns->help, "Load stack pointer with register pair HL");
            currentIns->cycles = 5;
            break;
    }

    return 0;
}

/*
* handler for segment 3 mod A
* jump if flag is set
*/
int segment3_A(struct instructionData *currentIns) {

    int conditionalIndex = getSeqIndex_8(currentIns);
    char* flag = flagConditionals[conditionalIndex];

    sprintf(currentIns->assembly, "J%s 0x%02X%02X", flag, currentIns->operand2, currentIns->operand1);
    // printf("%s\n", currentIns->assembly);
    sprintf(currentIns->help, 
            "Jump if flag is set\n(Z = zero, C = carry, PE = parity is even, M = negative (sign set))");

    currentIns->cycles = 10;

    // return extra bytes used: 2
    return 2;
}

/*
* handler for segment 3 mod B (various)
*/
int segment3_B(struct instructionData *currentIns) {

    char *ops[] = {"undefined", "IN", "XCHG", "EI"};
    int opIndex = getSeqIndex_16(currentIns);
    int immediateBytes = 0;

    switch (opIndex) {

        case 0:
            // undefined
            sprintf(currentIns->assembly, "Undefined instruction");
            return -1;
            break;

        case 1:
            // input
            sprintf(currentIns->assembly, "%s 0x%02X", ops[opIndex], currentIns->operand1);
            sprintf(currentIns->help, "Input from port 0x%02x", currentIns->operand1);
            currentIns->cycles = 10;
            immediateBytes = 1;
            break;

        case 2:
            // contents of D&H are swapped, as are E&D
            sprintf(currentIns->assembly, "%s", ops[opIndex]);
            sprintf(currentIns->help, "Contents of DE swapped with HL");
            currentIns->cycles = 4;
            break;

        case 3:
            // enable interrupts
            sprintf(currentIns->assembly, "%s", ops[opIndex]);
            sprintf(currentIns->help, "Enable interrupts");
            currentIns->cycles = 4;
            break;
    }

    return immediateBytes;
}

/*
* handler for segment 3 mod C
* conditional call subroutine if flag is set
*/
int segment3_C(struct instructionData *currentIns) {
    int conditionalIndex = getSeqIndex_8(currentIns);
    char* flag = flagConditionals[conditionalIndex];

    sprintf(currentIns->assembly, "C%s 0x%02X%02X", flag, currentIns->operand2, currentIns->operand1);
    // printf("%s\n", currentIns->assembly);
    sprintf(currentIns->help, 
            "Call subroutine if flag is set\n(Z = zero, C = carry, PE = parity is even, M = negative (sign set))");

    currentIns->cycles = 11;
    currentIns->cyclesFalse = 5;

    // number of extra bytes used
    return 2;
}

/*
* handler for segment 3 mod D (various)
*/
int segment3_D(struct instructionData *currentIns) {

    // 0xCD is the only valid instruction in this group (unconditional call)
    if (currentIns->instruction == 0xCD) {
        sprintf(currentIns->assembly, "CALL 0x%02X%02X", currentIns->operand2, currentIns->operand1);
        sprintf(currentIns->help, "Unconditional call subroutine at immediate address");
        currentIns->cycles = 17;
        // printf("%s\n", currentIns->assembly);

        // number of extra bytes: 2
        return 2;
    }

    sprintf(currentIns->assembly, "Undefined instruction");
    // printf("Invalid instruction: %x\n", currentIns->instruction);
    return -1;
}

/*
* handler for segment 3 mod E
* ALU operations with immediate data
*/
int segment3_E(struct instructionData *currentIns) {

    // get odd ALU operation
    // in the following order: [*, "ACI", *, "SBI", *, "XRI", *, "CPI"]
    int opIndex = (getSeqIndex_16(currentIns) * 2 + 1);
    char* op = ALUImmInstructions[opIndex];
    int helpSource = 8;

    // store assembly operation
    sprintf(currentIns->assembly, "%s 0x%02X", op, currentIns->operand1);

    // store help information
    handleALUHelp(currentIns, &opIndex, &helpSource);

    // set clock cycles
    currentIns->cycles = 7;

    // number of extra bytes
    return 1;
}

/*
* handler for segment 3 mod F
* RESET operations
*/
int segment3_F(struct instructionData *currentIns) {
    int resetIndex = getSeqIndex_8(currentIns);

    sprintf(currentIns->assembly, "RST %d", resetIndex);
    sprintf(currentIns->help, "Call reset subroutine %d", resetIndex);
    currentIns->cycles = 7;

    return 0;
}