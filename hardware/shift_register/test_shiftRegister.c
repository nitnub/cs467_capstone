#include <assert.h>
#include <stdio.h>

#include "shiftRegister.h"


/*
 *  test initShift()
 *      verify offset properly initialized
 */
int test_initShift_01() {
    // initialize
    uint16_t expected_value = 0x00;

    // execute
    ShiftRegister_t *sr = initShiftRegister();

    // assert
    assert(expected_value == sr->offset);
    return 0;
}

/*
 *  test initShift()
 *      verify value properly initialized
 */
int test_initShift_02() {
    // initialize
    uint16_t expected_value = 0x00;

    // execute
    ShiftRegister_t *sr = initShiftRegister();

    // assert
    assert(expected_value == sr->value16Bit);
    return 0;
}

/*
 *  test addShiftRegisterValue()
 *      add initial shift register value
 */
int test_addShiftRegisterValue_01() {
    // initialize
    const uint8_t argument = 0xFF;
    uint16_t expected_value = 0xFF00;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument);
    uint16_t actual_value = sr->value16Bit;

    // assert
    assert(expected_value == actual_value);
    return 0;
}


/*
 *  test addShiftRegisterValue()
 *      add second shift register value
 */
int test_addShiftRegisterValue_02() {
    // initialize
    const uint8_t argument_1 = 0x1C;
    const uint8_t argument_2 = 0x30;
    uint16_t expected_value = 0x301C;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_1);
    addShiftRegisterValue(sr, argument_2);
    uint16_t actual_value = sr->value16Bit;

    // assert
    assert(expected_value == actual_value);
    return 0;
}


/*
 *  test addShiftRegisterValue()
 *      add third shift register value
 */
int test_addShiftRegisterValue_03() {
    // initialize
    const uint8_t argument_1 = 0x1C;
    const uint8_t argument_2 = 0x30;
    const uint8_t argument_3 = 0x02;
    uint16_t expected_value = 0x0230;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_1);
    addShiftRegisterValue(sr, argument_2);
    addShiftRegisterValue(sr, argument_3);
    uint16_t actual_value = sr->value16Bit;

    // assert
    assert(expected_value == actual_value);
    return 0;
}

/*
 *  test addShiftRegisterValue()
 *      add consecutive 0x00's to shift register
 */
int test_addShiftRegisterValue_04() {
    // initialize
    const uint8_t argument_1 = 0x1C;
    const uint8_t argument_2 = 0x00;
    const uint8_t argument_3 = 0x00;
    uint16_t expected_value = 0x0000;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_1);
    addShiftRegisterValue(sr, argument_2);
    addShiftRegisterValue(sr, argument_3);
    uint16_t actual_value = sr->value16Bit;

    // assert
    assert(expected_value == actual_value);
    return 0;
}


/*
 *  test setShiftRegisterOffset()
 *      verify error code for offset = 0xFF
 */
int test_setShiftRegisterOffset_01() {
    // initialize
    const uint8_t argument_1 = 0xFF;
    int expected_err_code = -1;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    int actual_err_code = setShiftRegisterOffset(sr, argument_1);

    // assert
    assert(actual_err_code == expected_err_code);
    return 0;
}

/*
 *  test setShiftRegisterOffset()
 *      verify no error code for offset = 0x00
 */
int test_setShiftRegisterOffset_02() {
    // initialize
    const uint8_t argument_1 = 0x00;
    int expected_err_code = 0;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    int actual_err_code = setShiftRegisterOffset(sr, argument_1);

    // assert
    assert(actual_err_code == expected_err_code);
    return 0;
}

/*
 *  test setShiftRegisterOffset()
 *      verify no error code for offset = 0x08
 */
int test_setShiftRegisterOffset_03() {
    // initialize
    const uint8_t argument_1 = 0x08;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    int actual_err_code = setShiftRegisterOffset(sr, argument_1);

    // assert
    int expected_err_code = 0;
    assert(actual_err_code == expected_err_code);
    return 0;
}

/*
 *  test setShiftRegisterOffset()
 *      verify error code for offset = 0x11
 */
int test_setShiftRegisterOffset_04() {
    // initialize
    const uint8_t argument_1 = 0x11;
    int expected_err_code = -1;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    int actual_err_code = setShiftRegisterOffset(sr, argument_1);

    // assert
    assert(actual_err_code == expected_err_code);
    return 0;
}


/*
 *  test setShiftRegisterOffset()
 *      verify value not set for offset = 0xFF
 */
int test_setShiftRegisterOffset_05() {
    // initialize
    const uint8_t argument = 0xFF;
    uint8_t expected_value = 0x00;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    setShiftRegisterOffset(sr, argument);
    uint8_t actual_value = sr->offset;

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test setShiftRegisterOffset()
 *      verify offset value is unchanged when set to 0x00
 */
int test_setShiftRegisterOffset_06() {
    // initialize
    const uint8_t argument = 0x00;
    uint8_t expected_value = 0x00;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    setShiftRegisterOffset(sr, argument);
    uint8_t actual_value = sr->offset;

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test setShiftRegisterOffset()
 *      verify value is set for offset = 0x08
 */
int test_setShiftRegisterOffset_07() {
    // initialize
    const uint8_t argument = 0x08;
    uint8_t expected_value = 0x08;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    setShiftRegisterOffset(sr, argument);
    uint8_t actual_value = sr->offset;

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test setShiftRegisterOffset()
 *      verify value is set for offset changed from 0xA1 to 0x00
 */
int test_setShiftRegisterOffset_08() {
    // initialize
    const uint8_t argument_1 = 0xA1;
    const uint8_t argument_2 = 0x00;
    uint8_t expected_value = 0x00;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    setShiftRegisterOffset(sr, argument_1);
    setShiftRegisterOffset(sr, argument_2);
    uint8_t actual_value = sr->offset;

    // assert
    assert(actual_value == expected_value);
    return 0;
}


/*
 *  test setShiftRegisterOffset()
 *      verify value not set for offset = 0x11
 */
int test_setShiftRegisterOffset_09() {
    // initialize
    const uint8_t argument = 0x11;
    uint8_t expected_value = 0x00;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    setShiftRegisterOffset(sr, argument);
    uint8_t actual_value = sr->offset;

    // assert
    assert(actual_value == expected_value);
    return 0;
}


/*
 *  test getShiftRegisterValue()
 *      get initial value
 */
int test_getShiftRegisterValue_01() {
    // initialize
    ShiftRegister_t *sr =  initShiftRegister();
    uint8_t expected_value = 0x00;

    // execute
    uint8_t actual_value = getShiftRegisterValue(sr);

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test getShiftRegisterValue()
 *      get first set value with no shift
 */
int test_getShiftRegisterValue_02() {
    // initialize
    const uint8_t argument_val = 0x11;
    uint8_t expected_value = 0x11;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_val);
    uint8_t actual_value = getShiftRegisterValue(sr);

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test getShiftRegisterValue()
 *      get first set value with shift == 0x02
 */
int test_getShiftRegisterValue_03() {
    // initialize
    const uint8_t argument_val = 0xFF;
    const uint8_t argument_shift = 0x02;
    uint8_t expected_value = 0xFC;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_val);
    setShiftRegisterOffset(sr, argument_shift);
    uint8_t actual_value = getShiftRegisterValue(sr);

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test getShiftRegisterValue()
 *      get first set value with shift == 0x07
 */
int test_getShiftRegisterValue_04() {
    // initialize
    const uint8_t argument_val = 0xFF;
    const uint8_t argument_shift = 0x07;
    uint8_t expected_value = 0x80;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_val);
    setShiftRegisterOffset(sr, argument_shift);
    uint8_t actual_value = getShiftRegisterValue(sr);

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test getShiftRegisterValue()
 *      get second set value with no shift
 */
int test_getShiftRegisterValue_05() {
    // initialize
    const uint8_t argument_val_1 = 0x51; // 01010001
    const uint8_t argument_val_2 = 0x11; // 00010001
    uint8_t expected_value = 0x11;
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_val_1);
    addShiftRegisterValue(sr, argument_val_2);
    uint8_t actual_value = getShiftRegisterValue(sr);

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test getShiftRegisterValue()
 *      get second set value with shift == 0x02
 */
int test_getShiftRegisterValue_06() {
    // initialize
    const uint8_t argument_val_1 = 0x51;            // 01010001
    const uint8_t argument_val_2 = 0x11;            // 00010001
    const uint8_t argument_offset = 0x02;           // 00 01000101 010001
    uint8_t expected_value = 0x45;                  // 01000101
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_val_1);
    addShiftRegisterValue(sr, argument_val_2);
    setShiftRegisterOffset(sr, argument_offset);
    uint8_t actual_value = getShiftRegisterValue(sr);

    // assert
    assert(actual_value == expected_value);
    return 0;
}

/*
 *  test getShiftRegisterValue()
 *      get second set value with shift == 0x07
 */
int test_getShiftRegisterValue_07() {
    // initialize
    const uint8_t argument_val_1 = 0x87;            // 10000111
    const uint8_t argument_val_2 = 0x1A;            // 00011010
    const uint8_t argument_offset = 0x07;           // 0001101 01000011 1
    uint8_t expected_value = 0x43;                  // 01000011
    ShiftRegister_t *sr =  initShiftRegister();

    // execute
    addShiftRegisterValue(sr, argument_val_1);
    addShiftRegisterValue(sr, argument_val_2);
    setShiftRegisterOffset(sr, argument_offset);
    uint8_t actual_value = getShiftRegisterValue(sr);

    // assert
    assert(actual_value == expected_value);
    return 0;
}


int main(void) {
    printf("[test_shiftRegister.c] Beginning tests...\n");

    test_initShift_01();
    test_initShift_02();

    test_addShiftRegisterValue_01();
    test_addShiftRegisterValue_02();
    test_addShiftRegisterValue_03();
    test_addShiftRegisterValue_04();

    test_setShiftRegisterOffset_01();
    test_setShiftRegisterOffset_02();
    test_setShiftRegisterOffset_03();
    test_setShiftRegisterOffset_04();
    test_setShiftRegisterOffset_05();
    test_setShiftRegisterOffset_06();
    test_setShiftRegisterOffset_07();
    test_setShiftRegisterOffset_08();
    test_setShiftRegisterOffset_09();

    test_getShiftRegisterValue_01();
    test_getShiftRegisterValue_02();
    test_getShiftRegisterValue_03();
    test_getShiftRegisterValue_04();
    test_getShiftRegisterValue_05();
    test_getShiftRegisterValue_06();
    test_getShiftRegisterValue_07();

    printf("[test_shiftRegister.c] All tests passed.\n");
    return 0;
}