#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

#include <stdint.h>
#include "../../core/cpu.h"


typedef struct {
    uint8_t offset;
    uint16_t value;
} ShiftRegister_t;

// void addShiftRegisterValue(state *currentState, uint8_t value);
// void setShiftRegisterOffset(state *currentState, uint8_t value);
// unsigned char getShiftRegisterValue(state *currentState, int shiftOffset);

// void initShiftRegister(ShiftRegister_t *srState);
ShiftRegister_t * initShiftRegister();

void addShiftRegisterValue(ShiftRegister_t *srState, uint8_t value);
int setShiftRegisterOffset(ShiftRegister_t *srState, uint8_t offset);
unsigned char getShiftRegisterValue(ShiftRegister_t *srState);


#endif //SHIFTREGISTER_H
