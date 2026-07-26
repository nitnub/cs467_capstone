#include "helpers.h"

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

uint16_t stepCPU(state *cpuState) {
    // get pc
    const int oldPc = getPC(cpuState);

    // TODO: Can instruction creation be contained in the function? Is there need to pass it in from the outside?
    struct instructionData insData;
    insData.instruction = getInstructionId(cpuState);
    insData.operand1 = cpuState->memory[oldPc + 1];
    insData.operand2 = cpuState->memory[oldPc + 2];
    insData.s = cpuState;

    // Note: don't increment PC if PC was already updated by the instruction itself
    // run instruction at pc   TODO: Does dispatchLevel2 return size on CALL / JMP?
    const int instructionSize = dispatchLevel2(&insData) + 1;   // operand count plus opcode

    // instructionSize will return zero if a jump occurred. in that case, we should not increment the PC again.
    const int newPc = getPC(cpuState);
    const int backgroundPcChange = newPc - oldPc;

    // if we jump or call, use the internally-adjusted PC value, otherwise increment program counter by operation size
    const int incrementValue = backgroundPcChange == 0 ? instructionSize : 0;
    stepPC(cpuState, incrementValue);

    // return new program counter value
    return newPc;
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
