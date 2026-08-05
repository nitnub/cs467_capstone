#ifndef SHIFTREGISTER_H
#define SHIFTREGISTER_H

#include <stdint.h>
#include <stdlib.h>

/**
 * Note: Register value should not be accessed directly; program will
 * expect an 8-bit result.
 */
typedef struct {
    uint8_t offset;
    uint16_t value16Bit;
} ShiftRegister_t;

/**
 * Get a pointer to an initialized shift register struct. Must be freed.
 * @return pointer to an initialized shift register struct
 */
ShiftRegister_t * initShiftRegister();

/**
 * Update the shift register by inserting the given hex value and shifting
 * the existing value by one byte.
 * @param srState pointer to the program shift register
 * @param value hex value to be inserted into the shift register
 */
void addShiftRegisterValue(ShiftRegister_t *srState, uint8_t value);

/**
 * Update the offset size, in bits, to right-shift the start of the next
 * byte-length read from the 16-bot shift register.
 * @param srState pointer to the program shift register
 * @param offset the offset size to use for the next byte-length register read
 * @return -1 if error, 0 if not
 */
int setShiftRegisterOffset(ShiftRegister_t *srState, uint8_t offset);

/**
 * Get the shifted value from the register.
 * @param srState pointer to the program shift register
 * @return shifted hex value from the register
 */
uint8_t getShiftRegisterValue(ShiftRegister_t *srState);

uint16_t printShiftRegister(ShiftRegister_t *srState);
uint8_t printShiftOffset(ShiftRegister_t *srState);

#endif //SHIFTREGISTER_H
