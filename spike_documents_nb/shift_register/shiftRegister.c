#include "shiftRegister.h"


ShiftRegister_t *initShiftRegister() {
    ShiftRegister_t *sr = calloc(1, sizeof(ShiftRegister_t));
    return sr;
}

void addShiftRegisterValue(ShiftRegister_t *srState, const uint8_t value) {
    // shift the existing 16 bit register one char to the right while prepending the new value
    srState->value16Bit = ((value << 8) & 0xFF00) | ((srState->value16Bit >> 8) & 0x00FF);
}

int setShiftRegisterOffset(ShiftRegister_t *srState, const uint8_t offset) {
    // check that offset is within 16 bit range... shouldn't be negative with uint8_t
    if (offset > 0x08) {
        return -1;
    }
    srState->offset = offset;
    return 0;
}

uint8_t getShiftRegisterValue(ShiftRegister_t *srState) {

    // In practice, port 4 provides a 16 bit value that is shifted left 
    // by the number of bits specified by port 2 and port 3 returns the 
    // high order byte of the result.

    uint16_t shift_16 = srState->value16Bit << srState->offset;
    uint8_t shift_8 = (shift_16 & 0xFF00) >> 8;
    return shift_8;

    //return (srState->value16Bit >> (8 - srState->offset)) & 0xFF;
}

uint16_t printShiftRegister(ShiftRegister_t *srState) {
    return (uint16_t) srState->value16Bit;
}

uint8_t printShiftOffset(ShiftRegister_t *srState) {
    return (uint8_t) srState->offset;
}