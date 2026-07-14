#include <assert.h>

#include "handler.h"

struct instructionData code;

/*
* set up object for unit testing of dispatch function (disassembler)
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

int test_10(struct instructionData *currentIns) {

    setupTests(0x10, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_11(struct instructionData *currentIns) {

    setupTests(0x11, currentIns);
    assert(!strcmp(currentIns->assembly, "LXI D, 0xA118"));

    return 0;
}

int test_12(struct instructionData *currentIns) {

    setupTests(0x12, currentIns);
    assert(!strcmp(currentIns->assembly, "STAX D"));

    return 0;
}

int test_13(struct instructionData *currentIns) {

    setupTests(0x13, currentIns);
    assert(!strcmp(currentIns->assembly, "INX D"));

    return 0;
}

int test_14(struct instructionData *currentIns) {

    setupTests(0x14, currentIns);
    assert(!strcmp(currentIns->assembly, "INR D"));

    return 0;
}

int test_15(struct instructionData *currentIns) {

    setupTests(0x15, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR D"));

    return 0;
}

int test_16(struct instructionData *currentIns) {

    setupTests(0x16, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI D, 0x18"));

    return 0;
}

int test_17(struct instructionData *currentIns) {

    setupTests(0x17, currentIns);
    assert(!strcmp(currentIns->assembly, "RAL"));

    return 0;
}

int test_18(struct instructionData *currentIns) {

    setupTests(0x18, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_19(struct instructionData *currentIns) {

    setupTests(0x19, currentIns);
    assert(!strcmp(currentIns->assembly, "DAD D"));

    return 0;
}

int test_1A(struct instructionData *currentIns) {

    setupTests(0x1A, currentIns);
    assert(!strcmp(currentIns->assembly, "LDAX D"));

    return 0;
}

int test_1B(struct instructionData *currentIns) {

    setupTests(0x1B, currentIns);
    assert(!strcmp(currentIns->assembly, "DCX D"));

    return 0;
}

int test_1C(struct instructionData *currentIns) {

    setupTests(0x1C, currentIns);
    assert(!strcmp(currentIns->assembly, "INR E"));

    return 0;
}

int test_1D(struct instructionData *currentIns) {

    setupTests(0x1D, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR E"));

    return 0;
}

int test_1E(struct instructionData *currentIns) {

    setupTests(0x1E, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI E, 0x18"));

    return 0;
}

int test_1F(struct instructionData *currentIns) {

    setupTests(0x1F, currentIns);
    assert(!strcmp(currentIns->assembly, "RAR"));

    return 0;
}

int test_20(struct instructionData *currentIns) {

    setupTests(0x20, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_21(struct instructionData *currentIns) {

    setupTests(0x21, currentIns);
    assert(!strcmp(currentIns->assembly, "LXI H, 0xA118"));

    return 0;
}

int test_22(struct instructionData *currentIns) {

    setupTests(0x22, currentIns);
    assert(!strcmp(currentIns->assembly, "SHLD 0xA118"));

    return 0;
}

int test_23(struct instructionData *currentIns) {

    setupTests(0x23, currentIns);
    assert(!strcmp(currentIns->assembly, "INX H"));

    return 0;
}

int test_24(struct instructionData *currentIns) {

    setupTests(0x24, currentIns);
    assert(!strcmp(currentIns->assembly, "INR H"));

    return 0;
}

int test_25(struct instructionData *currentIns) {

    setupTests(0x25, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR H"));

    return 0;
}

int test_26(struct instructionData *currentIns) {

    setupTests(0x26, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI H, 0x18"));

    return 0;
}

int test_27(struct instructionData *currentIns) {

    setupTests(0x27, currentIns);
    assert(!strcmp(currentIns->assembly, "DAA"));

    return 0;
}

int test_28(struct instructionData *currentIns) {

    setupTests(0x28, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_29(struct instructionData *currentIns) {

    setupTests(0x29, currentIns);
    assert(!strcmp(currentIns->assembly, "DAD H"));

    return 0;
}

int test_2A(struct instructionData *currentIns) {

    setupTests(0x2A, currentIns);
    assert(!strcmp(currentIns->assembly, "LHLD 0xA118"));

    return 0;
}

int test_2B(struct instructionData *currentIns) {

    setupTests(0x2B, currentIns);
    assert(!strcmp(currentIns->assembly, "DCX H"));

    return 0;
}

int test_2C(struct instructionData *currentIns) {

    setupTests(0x2C, currentIns);
    assert(!strcmp(currentIns->assembly, "INR L"));

    return 0;
}

int test_2D(struct instructionData *currentIns) {

    setupTests(0x2D, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR L"));

    return 0;
}

int test_2E(struct instructionData *currentIns) {

    setupTests(0x2E, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI L, 0x18"));

    return 0;
}

int test_2F(struct instructionData *currentIns) {

    setupTests(0x2F, currentIns);
    assert(!strcmp(currentIns->assembly, "CMA"));

    return 0;
}

int test_30(struct instructionData *currentIns) {

    setupTests(0x30, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_31(struct instructionData *currentIns) {

    setupTests(0x31, currentIns);
    assert(!strcmp(currentIns->assembly, "LXI SP, 0xA118"));

    return 0;
}

int test_32(struct instructionData *currentIns) {

    setupTests(0x32, currentIns);
    assert(!strcmp(currentIns->assembly, "STA 0xA118"));

    return 0;
}

int test_33(struct instructionData *currentIns) {

    setupTests(0x33, currentIns);
    assert(!strcmp(currentIns->assembly, "INX SP"));

    return 0;
}

int test_34(struct instructionData *currentIns) {

    setupTests(0x34, currentIns);
    assert(!strcmp(currentIns->assembly, "INR M"));

    return 0;
}

int test_35(struct instructionData *currentIns) {

    setupTests(0x35, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR M"));

    return 0;
}

int test_36(struct instructionData *currentIns) {

    setupTests(0x36, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI M, 0x18"));

    return 0;
}

int test_37(struct instructionData *currentIns) {

    setupTests(0x37, currentIns);
    assert(!strcmp(currentIns->assembly, "STC"));

    return 0;
}

int test_38(struct instructionData *currentIns) {

    setupTests(0x38, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_39(struct instructionData *currentIns) {

    setupTests(0x39, currentIns);
    assert(!strcmp(currentIns->assembly, "DAD SP"));

    return 0;
}

int test_3A(struct instructionData *currentIns) {

    setupTests(0x3A, currentIns);
    assert(!strcmp(currentIns->assembly, "LDA 0xA118"));

    return 0;
}

int test_3B(struct instructionData *currentIns) {

    setupTests(0x3B, currentIns);
    assert(!strcmp(currentIns->assembly, "DCX SP"));

    return 0;
}

int test_3C(struct instructionData *currentIns) {

    setupTests(0x3C, currentIns);
    assert(!strcmp(currentIns->assembly, "INR A"));

    return 0;
}

int test_3D(struct instructionData *currentIns) {

    setupTests(0x3D, currentIns);
    assert(!strcmp(currentIns->assembly, "DCR A"));

    return 0;
}

int test_3E(struct instructionData *currentIns) {

    setupTests(0x3E, currentIns);
    assert(!strcmp(currentIns->assembly, "MVI A, 0x18"));

    return 0;
}

int test_3F(struct instructionData *currentIns) {

    setupTests(0x3F, currentIns);
    assert(!strcmp(currentIns->assembly, "CMC"));

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

    test_10(&code);
    test_11(&code);
    test_12(&code);
    test_13(&code);
    test_14(&code);
    test_15(&code);
    test_16(&code);
    test_17(&code);
    test_18(&code);
    test_19(&code);
    test_1A(&code);
    test_1B(&code);
    test_1C(&code);
    test_1D(&code);
    test_1E(&code);
    test_1F(&code);

    test_20(&code);
    test_21(&code);
    test_22(&code);
    test_23(&code);
    test_24(&code);
    test_25(&code);
    test_26(&code);
    test_27(&code);
    test_28(&code);
    test_29(&code);
    test_2A(&code);
    test_2B(&code);
    test_2C(&code);
    test_2D(&code);
    test_2E(&code);
    test_2F(&code);

    test_30(&code);
    test_31(&code);
    test_32(&code);
    test_33(&code);
    test_34(&code);
    test_35(&code);
    test_36(&code);
    test_37(&code);
    test_38(&code);
    test_39(&code);
    test_3A(&code);
    test_3B(&code);
    test_3C(&code);
    test_3D(&code);
    test_3E(&code);
    test_3F(&code);

    return 0;
}