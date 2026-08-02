#include "helpers.h"
#include "../interrupts/interrupt.h"
int printMemoryAddresses(const state *s, const int min, const int max) {
    // uint16_t rowId = 0x00;
    uint16_t rowId = min;

    // print header
    printf("Address");
    for (int i = 0; i < 16; i++) {
        if (i % 8 == 0) {
            printf(" ");
        }
        printf("%02x ", i);
    }
    printf("\n");

    // print rows
    char asciiRow[17] = {'\0'};
    for (int i = min; i < max; i++) {
        const uint8_t value = s->memory[i];

        // print row labels
        if (i % 8 == 0) {
            printf(" ");
        }

        // if hex row has been looped through, append ascii row
        if (i % 16 == 0) {
            // append ascii row to end (cover edge case of row 0)
            printf(" %s", asciiRow);
        }

        // update ascii char array for ascii range: 21(!) - 7e(~)
        if (value > 0x1f && value < 0x7f) {
            asciiRow[i % 16] = (char) value;
        } else {
            asciiRow[i % 16] = '.';
        }

        // if hex and ascii row have been added, go to newline
        if (i % 16 == 0) {
            // jump to next line
            printf("\n00%04x:", rowId);
            rowId += 0x10;
        }

        // add next value to hex row
        printf(" %02x", value);
    }

    // print last row
    printf("  %s", asciiRow);
    return 0;
}

int printAllMemoryAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_START, MEM_END);
}

int printRomAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_START, MEM_RAM_START);
}

int printRamAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_RAM_START, MEM_VIDEO_START);
}

int printVideoMemoryAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_VIDEO_START, MEM_RAM_MIRROR_START);
}

void numToCharArray(char *result, uint16_t number, int length) {
    const char clearBit = '0';
    const char setBit = '1';
    int pos = length - 2;

    // reset all values to terminators
    // memset(result, clearBit, length);
    for (int i = 0; i < length; i++) {
        if ((i + 1) % 5 == 0) {
            result[i] = ' ';
        } else {
            result[i] = '0';
        }
    }

    result[length-1] = '\0';

    // update
    while (number > 0) {
        // if (pos != 4) {
        if ((pos + 1) % 5 != 0) {
            result[pos] = number % 2 == 0 ? clearBit : setBit;
            number /= 2;
        }
        pos--;
    }
}

void addressToCharArray(char *result,  uint16_t number) {
    numToCharArray(result, number, TWO_BYTE_SIZE_PADDED); // TODO: for testing... this is not padded
}

void byteToCharArray(char *result,  uint16_t number) {
    numToCharArray(result, number, BYTE_SIZE_PADDED);
}


void printState(state *s) {

    char portIn0[BYTE_SIZE_PADDED];
    char portOut0[BYTE_SIZE_PADDED];
    char portIn1[BYTE_SIZE_PADDED];
    char portOut1[BYTE_SIZE_PADDED];
    char portIn2[BYTE_SIZE_PADDED];
    char portOut2[BYTE_SIZE_PADDED];
    char portIn3[BYTE_SIZE_PADDED];
    char portOut3[BYTE_SIZE_PADDED];
    char portIn4[BYTE_SIZE_PADDED];
    char portOut4[BYTE_SIZE_PADDED];
    char portIn5[BYTE_SIZE_PADDED];
    char portOut5[BYTE_SIZE_PADDED];
    char portIn6[BYTE_SIZE_PADDED];
    char portOut6[BYTE_SIZE_PADDED];

    byteToCharArray(portIn0, s->inp[0]);
    byteToCharArray(portOut0, s->outp[0]);

    byteToCharArray(portIn1, s->inp[1]);
    byteToCharArray(portOut1, s->outp[1]);

    byteToCharArray(portIn2, s->inp[2]);
    byteToCharArray(portOut2, s->outp[2]);

    byteToCharArray(portIn3, s->inp[3]);
    byteToCharArray(portOut3, s->outp[3]);

    byteToCharArray(portIn4, s->inp[4]);
    byteToCharArray(portOut4, s->outp[4]);

    byteToCharArray(portIn5, s->inp[5]);
    byteToCharArray(portOut5, s->outp[5]);

    byteToCharArray(portIn6, s->inp[6]);
    byteToCharArray(portOut6, s->outp[6]);



    // shift register
    char shiftRegTo16Bit[TWO_BYTE_SIZE_PADDED];
    byteToCharArray(shiftRegTo16Bit, s->shiftReg.value16Bit);

    // stack pointer
    unsigned char sp = getReg16(s, SP);
    unsigned char pc = getReg16(s, PC);
    printf("PC: %04x\n", pc);

    printf("\nFLAGS: Sign: %d, Zero: %d, Aux Carry: %d, Parity: %d, Carry: %d\n"
           "REGISTERS: "
           "\n\tA: 0x%02x "
           "\n\tB: 0x%02x "
           "\n\tC: 0x%02x "
           "\n\tD: 0x%02x "
           "\n\tE: 0x%02x "
           "\n\tH: 0x%02x "
           "\n\tL: 0x%02x "
           "\nSP: 0x%04x, PC: 0x%04x"
           "\nInterrupt Enabled: %d"
           "\nShift Register:"
           "\n\tOffset: %d"
           // "\n\tFull Reg: 0x%04x"
           "\n\tFull Reg: %s"
           "\nPORTS:"
           "\n\t[0] I: %s O: %s"
           "\n\t[1] I: %s O: %s"
           "\n\t[2] I: %s O: %s"
           "\n\t[3] I: %s O: %s"
           "\n\t[4] I: %s O: %s"
           "\n\t[5] I: %s O: %s"
           "\n\t[6] I: %s O: %s"
           "\nTop of stack: %04x"
           "\nTop of stack-1: %04x"
           "\nNext Operation: [%02x] -> %02x, %02x"
           "\n\n",


            s->flags[SIGN], s->flags[ZERO], s->flags[AUX_CARRY], s->flags[PARITY], s->flags[CARRY],
            s->regs8[A], s->regs8[B],s->regs8[C],s->regs8[D],s->regs8[E],s->regs8[H],s->regs8[L],
            s->regs16[SP], s->regs16[PC],
            s->currentOp.interruptReady,
            s->shiftReg.offset,
            shiftRegTo16Bit,
            portIn0, portOut0,
            portIn1, portOut1,
            portIn2, portOut2,
            portIn3, portOut3,
            portIn4, portOut4,
            portIn5, portOut5,
            portIn6, portOut6,
            s->memory[sp],
            s->memory[sp-1],
            s->memory[s->regs16[PC]], s->memory[s->regs16[PC]+1], s->memory[s->regs16[PC]+2]);
}


// uint16_t stepPC(state *cpuState, const int instructionSize) {
uint16_t stepPC(state *cpuState, const int instructionSize) {
    // get current pc
    const int pCounter = getReg16(cpuState, PC);

    // increment by given instruction size (able to get instruction size without executing?)
    setReg16(cpuState, PC, pCounter + instructionSize);
    return getReg16(cpuState, PC);
}

uint16_t getPC(state *cpuState) {
    return getReg16(cpuState, PC);
}

uint8_t getInstructionId(state *cpuState) {
    return cpuState->memory[getPC(cpuState)];
}

// int updateInstruction(state *cpuState, struct instructionData *instructionData) {
int loadNextInstruction(struct instructionData *instructionData) {
    if (instructionData == NULL) {
        printf("Error reading instructionData struct while updating instruction.\n");
        return -1;
    }

    state *s = instructionData->s;
    if (s == NULL) {
        printf("Error reading state struct while updating instruction.\n");
        return -1;
    }

    instructionData->instruction = getInstructionId(s);
    instructionData->operand1 = s->memory[getReg16(s, PC) + 1];
    instructionData->operand2 = s->memory[getReg16(s, PC) + 2];

    return 0;
}

uint16_t stepCPU(state *cpuState) {
    // get pc
    const int oldPc = getPC(cpuState);

    // TODO: Can instruction creation be contained in the function? Is there need to pass it in from the outside?
    struct instructionData insData;
    insData.instruction = getInstructionId(cpuState);
    insData.operand1 = cpuState->memory[oldPc + 1];
    insData.operand2 = cpuState->memory[oldPc + 2];
    insData.s = cpuState;

    // handle port
    uint8_t thisHex = cpuState->memory[getPC(cpuState)];
    uint8_t nextHex = cpuState->memory[getPC(cpuState) + 1];
    
    switch (thisHex) {
        case 0xd3:

            // if OUT to 4, shift a new value in
            if (nextHex == 0x04) {
                // printf("~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OUT:: via d3 -> %02x\n", nextHex);
                addShiftRegisterValue(&cpuState->shiftReg, getReg8(cpuState, A));
                // update the port...
                setPort(cpuState,0x04, OUT, nextHex);
                break;
            }

            // if OUT to 2, update offset from A
            else if (nextHex == 0x02) {
                // printf("~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OUT:: via d3 -> %02x\n", nextHex);
                setShiftRegisterOffset(&cpuState->shiftReg, nextHex);

                // update the port...
                setPort(cpuState,0x02, OUT, getReg8(cpuState, A));
                break;
            }

            // if OUT to 3.....
            else if (nextHex == 0x03) {
                printf("~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OUT:: via d3 -> %02x\n", nextHex);
                // update the port...
                setPort(cpuState,0x02, OUT, getReg8(cpuState, A));
                break;
            }
            else if (nextHex == 0x06) {
                // 6 for logging?
                printf("~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~OUT:: via d3 -> %02x\n", nextHex);
                // return 1;
                break;
            } else {
                // printf("~other~~~~~~~~~~~~~~~~~~~~~~~~~~~OUT:: via d3 -> %02x\n", nextHex);

            }
            break;
        case 0xdb:
            // if IN from 3, return the shift result
            if (nextHex == 0x03) {
                // printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IN:: via db -> %02x\n", nextHex);
                unsigned char shiftResult = getShiftRegisterValue(&cpuState->shiftReg);
                setReg8(cpuState, A, shiftResult);

                // update the port...
                setPort(cpuState,0x03, IN, shiftResult);
                // printState(cpuState);

            } else if (nextHex == 0x01) {
                // VIDEO WRITE
                // printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IN:: via db -> %02x\n", nextHex);
                // printState(cpuState);
            } else if (nextHex == 0x02) {
                // VIDEO WRITE
                // printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IN:: via db -> %02x\n", nextHex);
                // printState(cpuState);
            }
            else {
                // printf("~other~~~~~~~~~~~~~~~~~~~~~~IN:: via db -> %02x\n", nextHex);
            }

            break;
        default:
            // if not port, pass
            break;
    }


    // Note: don't increment PC if PC was already updated by the instruction itself
    // run instruction at pc   TODO: Does dispatchLevel2 return size on CALL / JMP?
    // aluAddImm16NoFlags(cpuState, PC, 0x01);
    const int instructionSize = dispatchLevel2(&insData) + 1;   // operand count plus opcode

    // instructionSize will return zero if a jump occurred. in that case, we should not increment the PC again.
    const int newPc = getPC(cpuState);
    const int backgroundPcChange = newPc - oldPc;

    // if we jump or call, use the internally-adjusted PC value, otherwise increment program counter by operation size
    const int incrementValue = backgroundPcChange == 0 ? instructionSize : 0;
    stepPC(cpuState, incrementValue);

    return insData.cycles;
}

int loadRomToMemory(state *cpuState, char romName[]) {
    FILE *f = fopen(romName, "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", romName);
        return 1;
    }

    long n = (long)fread(cpuState->memory, 1, MEM_SIZE, f);
    fclose(f);
    if (n == 0)
    {
        fprintf(stderr, "%s: read 0 bytes\n", romName);
        return 1;
    }
    printf("Loaded %s (%ld bytes)\n", romName, n);

    return n;
}

