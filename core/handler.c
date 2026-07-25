#include "handler.h"

// uncomment for testing
//struct instructionData code;

/*
* dispatches instructions between 0x00 and 0x3F
* segment_index: 0 (instructions 0x00 to 0x3F)
*/
int handler_a(struct instructionData* currentIns) {

    // printf("you have called handler a\n");
    int modIndex = getModIndex_16(currentIns);
    int operandCount = seg0Array[modIndex](currentIns);

    // if extra bytes were used, return count
    if (operandCount > 0) {
        return operandCount;
    }
    
    return 0;
}

/*
* dispatches instructions between 0x40 and 0x7F
* segment_index: 1 (instructions 0x40 to 0x7F)
*/
int handler_b(struct instructionData* currentIns) {
    // printf("you have called handler b\n");
    int operandCount = segment1(currentIns);

    // if extra bytes were used, return count
    if (operandCount > 0) {
        return operandCount;
    }

    return 0;
}

/*
* dispatches instructions between 0x80 and 0xBF
* segment_index: 2 (instructions 0x80 to 0xBF)
*/
int handler_c(struct instructionData* currentIns) {
    // printf("you have called handler c\n");
    int operandCount = segment2(currentIns);

    // if extra bytes were used, return count
    if (operandCount > 0) {
        return operandCount;
    }

    return 0;
}

/*
* dispatches instructions bewteen 0xC0 and 0xFF
* segment_index: 3 (instruction 0xC0 to 0xFF)
*/
int handler_d(struct instructionData* currentIns) {
    // printf("you have called handler d\n");
    int modIndex = getModIndex_16(currentIns);
    int operandCount = seg3Array[modIndex](currentIns);

    if (operandCount > 0) {
        return operandCount;
    }

    return 0;
}

/*
* function name: getL2Segment
* description: get appropriate segment for hex instruction between 00 and FF
* validates that instruction is in range and returns segment index (0-4).
* if out of range, returns -1
*/
int getL2Segment(int *instruction_pointer) {

    // validate that instruction is in range
    if (instruction_pointer != NULL && *instruction_pointer >= 0x00 && *instruction_pointer <= 0xFF) {
        return *instruction_pointer / 64;
    }

    printf("error: instruction is out of range \n");
    return -1;
}


/*
* validates that instruction is in range. 
* dispatches correct instruction segment handler
* returns 0 if successful
* otherwise, returns -1
*/
int dispatchLevel2(struct instructionData *currentIns) {

    int segment = getL2Segment(&currentIns->instruction);

    if (segment >= 0) {
        int operandCount = funcArray[segment](currentIns);

        if (operandCount > 0) {
            return operandCount;
        }
        return 0;
    }

    return -1;
}


/*
int main(void) {


    code.instruction = 006;
    code.cycles = 4;
    code.operand1 = 0x18;
    code.operand2 = 0xA1;
    dispatchLevel2(&code);
    printf("%s\n", code.assembly);
}
*/