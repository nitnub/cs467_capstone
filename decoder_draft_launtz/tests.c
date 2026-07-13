#include <assert.h>

#include "handler.h"

struct instructionData code;

/*
* set up object for unit testiong
*/
int setupTests(int opcode, struct instructionData *currentIns) {

    // set up instruction structure
    currentIns->instruction = opcode;
    currentIns->cycles = 4;
    currentIns->operand1 = 0x18;
    currentIns->operand2 = 0xA1;

    dispatchLevel2(currentIns);

    return 0;
}

/* ****** UNIT TESTS ******** */

int test_00(struct instructionData *currentIns) {

    setupTests(0x00, currentIns);
    assert(!strcmp(currentIns->assembly, "NOP"));

    return 0;
}

int test_01(struct instructionData *currentIns) {

    setupTests(0x01, currentIns);
    assert(!strcmp(currentIns->assembly, "LXI B, 0xA118"));

    return 0;
}

int test_02(struct instructionData *currentIns) {

    setupTests(0x02, currentIns);
    assert(!strcmp(currentIns->assembly, "STAX B"));

    return 0;
}

int test_03(struct instructionData *currentIns) {

    setupTests(0x03, currentIns);
    assert(!strcmp(currentIns->assembly, "INX B"));

    return 0;
}

int test_04(struct instructionData *currentIns) {

    setupTests(0x04, currentIns);
    assert(!strcmp(currentIns->assembly, "INR B"));

    return 0;
}

int test_05(struct instructionData *currentIns) {

    setupTests(0x05, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR B"));

    return 0;
}

int test_06(struct instructionData *currentIns) {

    setupTests(0x06, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI B, 0x18"));

    return 0;
}

int test_07(struct instructionData *currentIns) {

    setupTests(0x07, currentIns);
    assert(!strcmp(currentIns->assembly, "RLC"));

    return 0;
}

int test_08(struct instructionData *currentIns) {

    setupTests(0x08, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_09(struct instructionData *currentIns) {

    setupTests(0x09, currentIns);
    assert(!strcmp(currentIns->assembly, "DAD B"));

    return 0;
}

int test_0A(struct instructionData *currentIns) {

    setupTests(0x0A, currentIns);
    assert(!strcmp(currentIns->assembly, "LDAX B"));

    return 0;
}

int test_0B(struct instructionData *currentIns) {

    setupTests(0x0B, currentIns);
    assert(!strcmp(currentIns->assembly, "DCX B"));

    return 0;
}

int test_0C(struct instructionData *currentIns) {

    setupTests(0x0C, currentIns);
    assert(!strcmp(currentIns->assembly, "INR C"));

    return 0;
}

int test_0D(struct instructionData *currentIns) {

    setupTests(0x0D, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR C"));

    return 0;
}

int test_0E(struct instructionData *currentIns) {

    setupTests(0x0E, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI C, 0x18"));

    return 0;
}

int test_0F(struct instructionData *currentIns) {

    setupTests(0x0F, currentIns);
    assert(!strcmp(currentIns->assembly, "RRC"));

    return 0;
}

int main(void) {

    test_00(&code);
    test_01(&code);
    test_02(&code);
    test_03(&code);
    test_04(&code);
    test_05(&code);
    test_06(&code);
    test_07(&code);
    test_08(&code);
    test_09(&code);
    test_0A(&code);
    test_0B(&code);
    test_0C(&code);
    test_0D(&code);
    test_0E(&code);
    test_0F(&code);

    return 0;
}