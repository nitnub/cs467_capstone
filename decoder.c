#include <stdio.h>
#define REGISTERS 8
#define CATEGORIES 16

int decodeInstruction(int instruction);
int handleALUInstruction (int instruction, int* cycle_p);
int handleHaltInstruction (int instruction, int* cycle_p);
int handleHighInstructions (int instruction, int* cycle_p);
int handleLowInstructions (int instruction, int* cycle_p);
int handleMoveInstruction (int instruction, int* cycle_p);

typedef enum  {
    B,
    C,
    D,
    E,
    H,
    L,
    M, // stand-in for a location in memory
    A
} CPURegister;

char CPURegisters[] = {'B','C','D','E','H','L','M','A'};
char *ALUOps[] = {"ADD", "ADC", "SUB", "SBB", "ANA", "XRA", "ORA", "CMP"};
char *CPURegisterPairs[] = {"BC", "DE", "HL", "SP"};
char statusFlags[] = {'Z', 'C', 'P', 'S'}; 

int handleHighInstructions (int instruction, int* cycle_p) {

    if (!cycle_p) {
        return -1;
    }

    int focus = instruction % CATEGORIES;
    int destNum = (instruction - 0xC0) / CATEGORIES;
    char flag = statusFlags[destNum];
    char *flagIfClear[] = {"NZ", "NC", "PO","P"};
    char *flagIfSet[] = {"Z", "C", "PE", "M"};

    switch (focus) {

        case 0x0:
            // return if relevant flag is clear
            // cycles: 11/5
            *cycle_p = 11;
            
    
            switch (destNum) {
                case 0:
                    printf("RN%c (zero flag is clear) [clock cycles: %d]\n", flag, *cycle_p);
                    break;

                case 1:
                    printf("RN%c (carry flag is clear) [clock cycles: %d]\n", flag, *cycle_p);
                    break;

                case 2:
                    printf("RPO (parity is odd) [clock cycles: %d]\n", *cycle_p);
                    break;

                case 3:
                    printf("RP (sign flag is clear) [clock cycles: %d]\n", *cycle_p);
                    break;
            }

            break;

        case 0x01:
            // pop from stack into register pair
            char *registerPair = CPURegisterPairs[destNum];
            *cycle_p = 10;
            printf("POP %s\n", registerPair);
            break;

        case 0x02:
            // jump if relevant flag is clear
            *cycle_p = 10;
            printf("J%s ADDR\n", flagIfClear[destNum]);
            break;

        case 0x03:
            break;

        case 0x04:
            // call subroutine if relevant flag is clear
            // cycles 17/11
            *cycle_p = 17;
            printf("C%s ADDR\n", flagIfClear[destNum]);
            break;

        case 0x05:
            break;

        case 0x06:
            break;

        case 0x07:
            // built in restart calls
            *cycle_p = 11;
            printf("RST %d\n", destNum * 2);
            break;

        case 0x08:
            // return if relevant flag is set
            // cycles: 11/5
            *cycle_p = 11;
            printf("R%s\n", flagIfSet[destNum]);
            break;
        
        case 0x0A:
            break;

        case 0x0B:
            break;

        case 0x0C:
            break;

        case 0x0D:
            break;

        case 0x0E:
            break;

        case 0x0F:
            // built in restart calls
            *cycle_p = 11;
            printf("RST %d\n", destNum * 2 + 1);
            break;


    }


    return 0;
}


/*
* parent function for instructions under 0x40
*/
int handleLowInstructions (int instruction, int* cycle_p) {

    if (!cycle_p) {
        return -1;
    }

    int focus = instruction % CATEGORIES;
    int destNum = instruction / CATEGORIES;
    char *destRegister = CPURegisterPairs[destNum];
    char higherDestReg = CPURegisters[destNum * 2];
    char lowerDestReg = CPURegisters[destNum * 2 + 1];

    switch (focus) {

        case 0x0:
            // 'no operation' (0x00) and undefined
            if (instruction == 0x0) {
                *cycle_p = 4;
                printf("NOP [clock cycles: %d]\n", *cycle_p);
            }

            else {
                printf("UNDEFINED INSTRUCTION\n");
            }
            break;

        case 0x1:
            // 'load immediate' (2 bytes) into register pair ("ADDR")
            
            // find register
            destNum = (instruction / CATEGORIES);
            destRegister = CPURegisterPairs[destNum];

            // set clock cycles = 10
            *cycle_p = 10;

            printf("LXI %s, ADDR [clock cycles: %d]\n", destRegister, *cycle_p);
            break;

        case 0x2:
        // store accumulator at address in register pair
            
            switch (destNum) {

                case 0:
                    // store accumulator at address in registers BC
                    *cycle_p = 7;
                    printf("STAX %s [clock cycles: %d]\n", destRegister, *cycle_p);
                    break;

                case 1:
                    // store accumulator at address in registers DE
                    *cycle_p = 7;
                    printf("STAX %s [clock cycles: %d]\n", destRegister, *cycle_p);
                    break;

                case 2:
                    // store content of registers HL in memory (imm1 is low part of address, imm2 is high part)
                    *cycle_p = 16;
                    printf("SHLD ADDR [clock cycles: %d]\n", *cycle_p);
                    break;

                case 3:
                    // store accumulator in memory (N+1 imm: low address, N+2 imm: high address)
                    *cycle_p = 13;
                    printf("STA ADDR [clock cycles: %d]\n", *cycle_p);
                    break;
            }
            break;

        case 0x3:
            // increment value in register pair
            *cycle_p = 5;
            printf("INX %s [clock cycles: %d]\n", destRegister, *cycle_p);
            break;

        case 0x4:
            // increment value in high-order byte of register pair
            *cycle_p = 5;
            printf("INR %c [clock cycles: %d]\n", higherDestReg, *cycle_p);
            break;

        case 0x5:
            // decrement value in high-order byte of register pair
            *cycle_p = 5;
            printf("DCR %c [clock cycles: %d]\n", higherDestReg, *cycle_p);
            break;

        case 0x6:
            // load immediate (1 byte) into high order register
            if (higherDestReg == 'M') {
                *cycle_p = 10;
            } else {
                *cycle_p = 7;
            }

            printf("MVI %c, sss [clock cycles: %d]\n", higherDestReg, *cycle_p);
            break;

        case 0x7:
            // rotate accumulator (various instructions)

            *cycle_p = 4;
            switch (destNum) {
                case 0:
                    // rotate accumulator left
                    printf("RLC [clock cycles: %d]\n", *cycle_p);
                    break;
                
                case 1:
                    // rotate accumulator left through the carry bit 
                    // (LSB will take on value of carry flag)
                    printf("RAL [clock cycles: %d]\n", *cycle_p);

                    break;

                case 2:
                    // decimal adjust the accumulator
                    printf("DAA [clock cycles: %d]\n", *cycle_p);
                    break;

                case 3:
                    // set the carry flag
                    printf("STC [clock cycles: %d]\n", *cycle_p);
                    break;
            }

            break;

        case 0x8:
            // undefined
            printf("undefined instruction\n");
            break;

        case 0x9:
            // double addition (HL += value in register pair)
            *cycle_p = 10;
            printf("DAD %s [clock cycles: %d]\n", destRegister, *cycle_p);
            break;

        case 0xA:
            // load accumulator from address in register pair

            switch (destNum) {
                case 0:
                    // load accumulator from address in BC
                    *cycle_p = 7;
                    printf("LDAX BC [clock cycles: %d]\n", *cycle_p);
                    break;
                
                case 1:
                    // load accumulator from address in DE
                    *cycle_p = 7;
                    printf("LDAX DE [clock cycles: %d]\n", *cycle_p);
                    break;

                case 2:
                    // load registers H and L from memory 
                    // (imm1: low memory address, imm2: high address)
                    *cycle_p = 16;
                    printf("LHLD ADDR [clock cycles: %d]\n", *cycle_p);
                    break;

                case 3:
                    // load accumulator directly from memory 
                    // (N+1 low  address, N+2 high address)
                    *cycle_p = 13;
                    printf("LDA ADDR [clock cycles: %d]\n", *cycle_p);
                    break;
            }

            break;

        case 0xB:
            *cycle_p = 5;
            printf("DCX %s [clock cycles: %d]\n", destRegister, *cycle_p);
            break;

        case 0xC:
            // increment value in low-order byte of register pair
            *cycle_p = 5;
            printf("INR %c [clock cycles: %d]\n", lowerDestReg, *cycle_p);
            break;

        case 0xD:
            // decrement value in low-order byte of register pair
            *cycle_p = 5;
            printf("DCR %c [clock cycles: %d]\n", lowerDestReg, *cycle_p);
            break;

        case 0xE:
            // load immediate (1 byte) into low order register
            if (lowerDestReg == 'M') {
                *cycle_p = 10;
            } else {
                *cycle_p = 7;
            }

            printf("MVI %c, sss [clock cycles: %d]\n", lowerDestReg, *cycle_p);
            break;

            break;

        case 0xF:
            // rotate accumulator (various instructions)
            *cycle_p = 4;
            switch (destNum) {
                case 0:
                    // rotate accumulator right
                    printf("RLC [clock cycles: %d]\n", *cycle_p);
                    break;
                
                case 1:
                    // rotate accumulator right through the carry bit 
                    // (MSB will take on value of carry flag)
                    printf("RAR [clock cycles: %d]\n", *cycle_p);
                    break;

                case 2:
                    // complement the accumulator
                    printf("CMA [clock cycles: %d]\n", *cycle_p);
                    break;

                case 3:
                    // complement the carry flag
                    printf("CMC [clock cycles: %d]\n", *cycle_p);
                    break;
            }


            break;

    }


    return 0;
}


/*
* parent function for arithmetic instructions
*/
int handleALUInstruction (int instruction, int* cycle_p) {

    // error: null pointer to cycles
    if (!cycle_p) {
        return -1;
    }

    // get register involved
    int opSrc = instruction % REGISTERS;
    char registerSrc = CPURegisters[opSrc];
    //printf("source register for ALU is: %c\n", registerSrc);

    // set clock cycles
    // if memory is involved, should be 7
    // otherwise, should be 4
    if (opSrc == 6) {
        *cycle_p = 7;
    } else {
        *cycle_p = 4;
    }

    // get operation
    int opType = (instruction - 0x80) / REGISTERS;
    char* opTypeName = ALUOps[opType];
    //printf("operation is: %s\n", opTypeName);


    printf("%s %c [clock cycles: %d]\n", opTypeName, registerSrc, *cycle_p);

    return 0;
}


/*
* handle special case instruction 0x76: HLT
*/
int handleHaltInstruction (int instruction, int* cycle_p) {
    if (cycle_p != NULL) {
        *cycle_p = 7;
    } else {
        // error: cycle_p is a null pointer
        return -1;
    }
    printf("HLT [clock cycles: %d]\n", *cycle_p);

}

/*
* handle move instructions. range: [0x40, 0x77]
*/
int handleMoveInstruction (int instruction, int* cycle_p) {

        // move instructions: source register
        int moveSrc = instruction % REGISTERS;
        char registerFrom = CPURegisters[moveSrc];

        // move instructions: destination register
        int moveDest = (instruction - 0x40) / REGISTERS;
        char registerTo = CPURegisters[moveDest];

        // get clock cycles
        // should be 7 if memory is involved
        // otherwise should be 5
        if (cycle_p != NULL) {
            if (moveSrc == 6 || moveDest == 6) {
                *cycle_p = 7;
            } else {
                *cycle_p = 5;
            }
        } else {
            // error: cycle_p is a null pointer
            return -1;
        }
        
        printf("MOV %c, %c [clock cycles: %d]\n", registerTo, registerFrom, *cycle_p);
        return 0;
}

/*
* parent method for decoding instructions
*/
int decodeInstruction(int instruction) {

    int cycles;
    
    if (instruction < 0x40) {
        handleLowInstructions(instruction, &cycles);

    }
    else if (instruction < 0x80) {

        // special case: HLT instruction
        if (instruction == 0x76) {
            handleHaltInstruction(instruction, &cycles);
            return 0;
        }

        handleMoveInstruction(instruction, &cycles);
        return 0;

    }
    else if (instruction < 0xC0) {
        handleALUInstruction(instruction, &cycles);

    }
    else {
        handleHighInstructions(instruction, &cycles);
    }

    return 0;
}


int main (void) {

    decodeInstruction(0x00);
    decodeInstruction(0x41);
    decodeInstruction(0x5A);
    decodeInstruction(0x76);
    decodeInstruction(0xBE);
    decodeInstruction(0x31);
    decodeInstruction(0x02);
    decodeInstruction(0x13);
    decodeInstruction(0x34);
    decodeInstruction(0x35);
    decodeInstruction(0x2B);

    decodeInstruction(0xf8);
}