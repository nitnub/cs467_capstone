

#include "shiftRegister.h"

#include <stdlib.h>


// void initShiftRegister(ShiftRegister_t *srState) {
//     srState->offset = 0x00;
//     srState->value = 0x00;
// }

ShiftRegister_t *initShiftRegister() {
    ShiftRegister_t *sr = calloc(1, sizeof(ShiftRegister_t));
    return sr;
}


void addShiftRegisterValue(ShiftRegister_t *srState, const uint8_t value) {
    // shift the existing 16 bit register one char to the right while prepending the new value
    srState->value = (value << 8 & 0xFF00) | (srState->value >> 8 & 0x00FF);
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
    return srState->value >> (8 - srState->offset);
}



// // OUT value to port 4 is the next value to add to the shift register
// // Simulate 16 bit shift register hardware in Space Invaders machine
// void addTo16BitShiftRegister(state *s, const uint8_t value) {
//
//     printf("@@addTo16BitShiftRegister\n");
//     const uint16_t hiByte = value << 8 & 0xff00;
//     s->si.sr = hiByte & (s->si.sr >> 8);
// }
//
// // OUT value to port 2 is the shiftOffset
// int get16BitShiftRegisterByOffset(state *s, const int shiftOffset) {
//
//     printf("@@get16BitShiftRegisterByOffset\n");
//     const uint8_t tmp = s->si.sr >> (8 - shiftOffset);
//     s->si.sr_result = tmp & 0xff;
//     return tmp & 0xff;
// }