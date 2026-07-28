#include <stdlib.h>
#include "shiftRegister.h"


ShiftRegister_t *initShiftRegister() {
    ShiftRegister_t *sr = calloc(1, sizeof(ShiftRegister_t));
    return sr;
}

void addShiftRegisterValue(ShiftRegister_t *srState, const uint8_t value) {
    // shift the existing 16 bit register one char to the right while prepending the new value
    srState->value16Bit = (value << 8 & 0xFF00) | (srState->value16Bit >> 8 & 0x00FF);
}

int setShiftRegisterOffset(ShiftRegister_t *srState, const uint8_t offset) {
    // check that offset is within 16 bit range... shouldn't be negative with uint8_t
    if (offset > 0x08) {
        return -1;
    }
    srState->offset = offset;
    return 0;
}

unsigned char getShiftRegisterValue(ShiftRegister_t *srState) {
    return srState->value16Bit >> (8 - srState->offset) & 0xFF;
}
