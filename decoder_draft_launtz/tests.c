#include "tests.h"

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

int test_40(struct instructionData *currentIns) {

    setupTests(0x40, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, B"));

    return 0;
}

int test_41(struct instructionData *currentIns) {

    setupTests(0x41, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, C"));

    return 0;
}

int test_42(struct instructionData *currentIns) {

    setupTests(0x42, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, D"));

    return 0;
}

int test_43(struct instructionData *currentIns) {

    setupTests(0x43, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, E"));

    return 0;
}

int test_44(struct instructionData *currentIns) {

    setupTests(0x44, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, H"));

    return 0;
}

int test_45(struct instructionData *currentIns) {

    setupTests(0x45, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, L"));

    return 0;
}

int test_46(struct instructionData *currentIns) {

    setupTests(0x46, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, M"));

    return 0;
}

int test_47(struct instructionData *currentIns) {

    setupTests(0x47, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV B, A"));

    return 0;
}

int test_48(struct instructionData *currentIns) {

    setupTests(0x48, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, B"));

    return 0;
}

int test_49(struct instructionData *currentIns) {

    setupTests(0x49, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, C"));

    return 0;
}

int test_4A(struct instructionData *currentIns) {

    setupTests(0x4A, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, D"));

    return 0;
}

int test_4B(struct instructionData *currentIns) {

    setupTests(0x4B, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, E"));

    return 0;
}

int test_4C(struct instructionData *currentIns) {

    setupTests(0x4C, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, H"));

    return 0;
}

int test_4D(struct instructionData *currentIns) {

    setupTests(0x4D, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, L"));

    return 0;
}

int test_4E(struct instructionData *currentIns) {

    setupTests(0x4E, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, M"));

    return 0;
}

int test_4F(struct instructionData *currentIns) {

    setupTests(0x4F, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV C, A"));

    return 0;
}

int test_50(struct instructionData *currentIns) {

    setupTests(0x50, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, B"));

    return 0;
}

int test_51(struct instructionData *currentIns) {

    setupTests(0x51, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, C"));

    return 0;
}

int test_52(struct instructionData *currentIns) {

    setupTests(0x52, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, D"));

    return 0;
}

int test_53(struct instructionData *currentIns) {

    setupTests(0x53, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, E"));

    return 0;
}

int test_54(struct instructionData *currentIns) {

    setupTests(0x54, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, H"));

    return 0;
}

int test_55(struct instructionData *currentIns) {

    setupTests(0x55, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, L"));

    return 0;
}

int test_56(struct instructionData *currentIns) {

    setupTests(0x56, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, M"));

    return 0;
}

int test_57(struct instructionData *currentIns) {

    setupTests(0x57, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV D, A"));

    return 0;
}

int test_58(struct instructionData *currentIns) {

    setupTests(0x58, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, B"));

    return 0;
}

int test_59(struct instructionData *currentIns) {

    setupTests(0x59, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, C"));

    return 0;
}

int test_5A(struct instructionData *currentIns) {

    setupTests(0x5A, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, D"));

    return 0;
}

int test_5B(struct instructionData *currentIns) {

    setupTests(0x5B, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, E"));

    return 0;
}

int test_5C(struct instructionData *currentIns) {

    setupTests(0x5C, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, H"));

    return 0;
}

int test_5D(struct instructionData *currentIns) {

    setupTests(0x5D, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, L"));

    return 0;
}

int test_5E(struct instructionData *currentIns) {

    setupTests(0x5E, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, M"));

    return 0;
}

int test_5F(struct instructionData *currentIns) {

    setupTests(0x5F, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV E, A"));

    return 0;
}

int test_60(struct instructionData *currentIns) {

    setupTests(0x60, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, B"));

    return 0;
}

int test_61(struct instructionData *currentIns) {

    setupTests(0x61, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, C"));

    return 0;
}

int test_62(struct instructionData *currentIns) {

    setupTests(0x62, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, D"));

    return 0;
}

int test_63(struct instructionData *currentIns) {

    setupTests(0x63, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, E"));

    return 0;
}

int test_64(struct instructionData *currentIns) {

    setupTests(0x64, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, H"));

    return 0;
}

int test_65(struct instructionData *currentIns) {

    setupTests(0x65, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, L"));

    return 0;
}

int test_66(struct instructionData *currentIns) {

    setupTests(0x66, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, M"));

    return 0;
}

int test_67(struct instructionData *currentIns) {

    setupTests(0x67, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV H, A"));

    return 0;
}

int test_68(struct instructionData *currentIns) {

    setupTests(0x68, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, B"));

    return 0;
}

int test_69(struct instructionData *currentIns) {

    setupTests(0x69, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, C"));

    return 0;
}

int test_6A(struct instructionData *currentIns) {

    setupTests(0x6A, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, D"));

    return 0;
}

int test_6B(struct instructionData *currentIns) {

    setupTests(0x6B, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, E"));

    return 0;
}

int test_6C(struct instructionData *currentIns) {

    setupTests(0x6C, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, H"));

    return 0;
}

int test_6D(struct instructionData *currentIns) {

    setupTests(0x6D, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, L"));

    return 0;
}

int test_6E(struct instructionData *currentIns) {

    setupTests(0x6E, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, M"));

    return 0;
}

int test_6F(struct instructionData *currentIns) {

    setupTests(0x6F, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV L, A"));

    return 0;
}

int test_70(struct instructionData *currentIns) {

    setupTests(0x70, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV M, B"));

    return 0;
}

int test_71(struct instructionData *currentIns) {

    setupTests(0x71, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV M, C"));

    return 0;
}

int test_72(struct instructionData *currentIns) {

    setupTests(0x72, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV M, D"));

    return 0;
}

int test_73(struct instructionData *currentIns) {

    setupTests(0x73, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV M, E"));

    return 0;
}

int test_74(struct instructionData *currentIns) {

    setupTests(0x74, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV M, H"));

    return 0;
}

int test_75(struct instructionData *currentIns) {

    setupTests(0x75, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV M, L"));

    return 0;
}

int test_76(struct instructionData *currentIns) {

    setupTests(0x76, currentIns);
    assert(!strcmp(currentIns->assembly, "HLT"));

    return 0;
}

int test_77(struct instructionData *currentIns) {

    setupTests(0x77, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV M, A"));

    return 0;
}

int test_78(struct instructionData *currentIns) {

    setupTests(0x78, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, B"));

    return 0;
}

int test_79(struct instructionData *currentIns) {

    setupTests(0x79, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, C"));

    return 0;
}

int test_7A(struct instructionData *currentIns) {

    setupTests(0x7A, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, D"));

    return 0;
}

int test_7B(struct instructionData *currentIns) {

    setupTests(0x7B, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, E"));

    return 0;
}

int test_7C(struct instructionData *currentIns) {

    setupTests(0x7C, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, H"));

    return 0;
}

int test_7D(struct instructionData *currentIns) {

    setupTests(0x7D, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, L"));

    return 0;
}

int test_7E(struct instructionData *currentIns) {

    setupTests(0x7E, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, M"));

    return 0;
}

int test_7F(struct instructionData *currentIns) {

    setupTests(0x7F, currentIns);
    assert(!strcmp(currentIns->assembly, "MOV A, A"));

    return 0;
}

int test_80(struct instructionData *currentIns) {

    setupTests(0x80, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD B"));

    return 0;
}

int test_81(struct instructionData *currentIns) {

    setupTests(0x81, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD C"));

    return 0;
}

int test_82(struct instructionData *currentIns) {

    setupTests(0x82, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD D"));

    return 0;
}

int test_83(struct instructionData *currentIns) {

    setupTests(0x83, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD E"));

    return 0;
}

int test_84(struct instructionData *currentIns) {

    setupTests(0x84, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD H"));

    return 0;
}

int test_85(struct instructionData *currentIns) {

    setupTests(0x85, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD L"));

    return 0;
}

int test_86(struct instructionData *currentIns) {

    setupTests(0x86, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD M"));

    return 0;
}

int test_87(struct instructionData *currentIns) {

    setupTests(0x87, currentIns);
    assert(!strcmp(currentIns->assembly, "ADD A"));

    return 0;
}

int test_88(struct instructionData *currentIns) {

    setupTests(0x88, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC B"));

    return 0;
}

int test_89(struct instructionData *currentIns) {

    setupTests(0x89, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC C"));

    return 0;
}

int test_8A(struct instructionData *currentIns) {

    setupTests(0x8A, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC D"));

    return 0;
}

int test_8B(struct instructionData *currentIns) {

    setupTests(0x8B, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC E"));

    return 0;
}

int test_8C(struct instructionData *currentIns) {

    setupTests(0x8C, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC H"));

    return 0;
}

int test_8D(struct instructionData *currentIns) {

    setupTests(0x8D, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC L"));

    return 0;
}

int test_8E(struct instructionData *currentIns) {

    setupTests(0x8E, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC M"));

    return 0;
}

int test_8F(struct instructionData *currentIns) {

    setupTests(0x8F, currentIns);
    assert(!strcmp(currentIns->assembly, "ADC A"));

    return 0;
}

int test_90(struct instructionData *currentIns) {

    setupTests(0x90, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB B"));

    return 0;
}

int test_91(struct instructionData *currentIns) {

    setupTests(0x91, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB C"));

    return 0;
}

int test_92(struct instructionData *currentIns) {

    setupTests(0x92, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB D"));

    return 0;
}

int test_93(struct instructionData *currentIns) {

    setupTests(0x93, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB E"));

    return 0;
}

int test_94(struct instructionData *currentIns) {

    setupTests(0x94, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB H"));

    return 0;
}

int test_95(struct instructionData *currentIns) {

    setupTests(0x95, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB L"));

    return 0;
}

int test_96(struct instructionData *currentIns) {

    setupTests(0x96, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB M"));

    return 0;
}

int test_97(struct instructionData *currentIns) {

    setupTests(0x97, currentIns);
    assert(!strcmp(currentIns->assembly, "SUB A"));

    return 0;
}

int test_98(struct instructionData *currentIns) {

    setupTests(0x98, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB B"));

    return 0;
}

int test_99(struct instructionData *currentIns) {

    setupTests(0x99, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB C"));

    return 0;
}

int test_9A(struct instructionData *currentIns) {

    setupTests(0x9A, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB D"));

    return 0;
}

int test_9B(struct instructionData *currentIns) {

    setupTests(0x9B, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB E"));

    return 0;
}

int test_9C(struct instructionData *currentIns) {

    setupTests(0x9C, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB H"));

    return 0;
}

int test_9D(struct instructionData *currentIns) {

    setupTests(0x9D, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB L"));

    return 0;
}

int test_9E(struct instructionData *currentIns) {

    setupTests(0x9E, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB M"));

    return 0;
}

int test_9F(struct instructionData *currentIns) {

    setupTests(0x9F, currentIns);
    assert(!strcmp(currentIns->assembly, "SBB A"));

    return 0;
}

int test_A0(struct instructionData *currentIns) {

    setupTests(0xA0, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA B"));

    return 0;
}

int test_A1(struct instructionData *currentIns) {

    setupTests(0xA1, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA C"));

    return 0;
}

int test_A2(struct instructionData *currentIns) {

    setupTests(0xA2, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA D"));

    return 0;
}

int test_A3(struct instructionData *currentIns) {

    setupTests(0xA3, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA E"));

    return 0;
}

int test_A4(struct instructionData *currentIns) {

    setupTests(0xA4, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA H"));

    return 0;
}

int test_A5(struct instructionData *currentIns) {

    setupTests(0xA5, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA L"));

    return 0;
}

int test_A6(struct instructionData *currentIns) {

    setupTests(0xA6, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA M"));

    return 0;
}

int test_A7(struct instructionData *currentIns) {

    setupTests(0xA7, currentIns);
    assert(!strcmp(currentIns->assembly, "ANA A"));

    return 0;
}

int test_A8(struct instructionData *currentIns) {

    setupTests(0xA8, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA B"));

    return 0;
}

int test_A9(struct instructionData *currentIns) {

    setupTests(0xA9, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA C"));

    return 0;
}

int test_AA(struct instructionData *currentIns) {

    setupTests(0xAA, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA D"));

    return 0;
}

int test_AB(struct instructionData *currentIns) {

    setupTests(0xAB, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA E"));

    return 0;
}

int test_AC(struct instructionData *currentIns) {

    setupTests(0xAC, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA H"));

    return 0;
}

int test_AD(struct instructionData *currentIns) {

    setupTests(0xAD, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA L"));

    return 0;
}

int test_AE(struct instructionData *currentIns) {

    setupTests(0xAE, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA M"));

    return 0;
}

int test_AF(struct instructionData *currentIns) {

    setupTests(0xAF, currentIns);
    assert(!strcmp(currentIns->assembly, "XRA A"));

    return 0;
}

int test_B0(struct instructionData *currentIns) {

    setupTests(0xB0, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA B"));

    return 0;
}

int test_B1(struct instructionData *currentIns) {

    setupTests(0xB1, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA C"));

    return 0;
}

int test_B2(struct instructionData *currentIns) {

    setupTests(0xB2, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA D"));

    return 0;
}

int test_B3(struct instructionData *currentIns) {

    setupTests(0xB3, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA E"));

    return 0;
}

int test_B4(struct instructionData *currentIns) {

    setupTests(0xB4, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA H"));

    return 0;
}

int test_B5(struct instructionData *currentIns) {

    setupTests(0xB5, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA L"));

    return 0;
}

int test_B6(struct instructionData *currentIns) {

    setupTests(0xB6, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA M"));

    return 0;
}

int test_B7(struct instructionData *currentIns) {

    setupTests(0xB7, currentIns);
    assert(!strcmp(currentIns->assembly, "ORA A"));

    return 0;
}

int test_B8(struct instructionData *currentIns) {

    setupTests(0xB8, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP B"));

    return 0;
}

int test_B9(struct instructionData *currentIns) {

    setupTests(0xB9, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP C"));

    return 0;
}

int test_BA(struct instructionData *currentIns) {

    setupTests(0xBA, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP D"));

    return 0;
}

int test_BB(struct instructionData *currentIns) {

    setupTests(0xBB, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP E"));

    return 0;
}

int test_BC(struct instructionData *currentIns) {

    setupTests(0xBC, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP H"));

    return 0;
}

int test_BD(struct instructionData *currentIns) {

    setupTests(0xBD, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP L"));

    return 0;
}

int test_BE(struct instructionData *currentIns) {

    setupTests(0xBE, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP M"));

    return 0;
}

int test_BF(struct instructionData *currentIns) {

    setupTests(0xBF, currentIns);
    assert(!strcmp(currentIns->assembly, "CMP A"));

    return 0;
}

int test_C0(struct instructionData *currentIns) {

    setupTests(0xC0, currentIns);
    assert(!strcmp(currentIns->assembly, "RNZ"));

    return 0;
}

int test_C1(struct instructionData *currentIns) {

    setupTests(0xC1, currentIns);
    assert(!strcmp(currentIns->assembly, "POP B"));

    return 0;
}

int test_C2(struct instructionData *currentIns) {

    setupTests(0xC2, currentIns);
    assert(!strcmp(currentIns->assembly, "JNZ 0xA118"));

    return 0;
}

int test_C3(struct instructionData *currentIns) {

    setupTests(0xC3, currentIns);
    assert(!strcmp(currentIns->assembly, "JMP 0xA118"));

    return 0;
}

int test_C4(struct instructionData *currentIns) {

    setupTests(0xC4, currentIns);
    assert(!strcmp(currentIns->assembly, "CNZ 0xA118"));

    return 0;
}

int test_C5(struct instructionData *currentIns) {

    setupTests(0xC5, currentIns);
    assert(!strcmp(currentIns->assembly, "PUSH B"));

    return 0;
}

int test_C6(struct instructionData *currentIns) {

    setupTests(0xC6, currentIns);
    assert(!strcmp(currentIns->assembly, "ADI 0x18"));

    return 0;
}

int test_C7(struct instructionData *currentIns) {

    setupTests(0xC7, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 0"));

    return 0;
}

int test_C8(struct instructionData *currentIns) {

    setupTests(0xC8, currentIns);
    assert(!strcmp(currentIns->assembly, "RZ"));

    return 0;
}

int test_C9(struct instructionData *currentIns) {

    setupTests(0xC9, currentIns);
    assert(!strcmp(currentIns->assembly, "RET"));

    return 0;
}

int test_CA(struct instructionData *currentIns) {

    setupTests(0xCA, currentIns);
    assert(!strcmp(currentIns->assembly, "JZ 0xA118"));

    return 0;
}

int test_CB(struct instructionData *currentIns) {

    setupTests(0xCB, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_CC(struct instructionData *currentIns) {

    setupTests(0xCC, currentIns);
    assert(!strcmp(currentIns->assembly, "CZ 0xA118"));

    return 0;
}

int test_CD(struct instructionData *currentIns) {

    setupTests(0xCD, currentIns);
    assert(!strcmp(currentIns->assembly, "CALL 0xA118"));

    return 0;
}

int test_CE(struct instructionData *currentIns) {

    setupTests(0xCE, currentIns);
    assert(!strcmp(currentIns->assembly, "ACI 0x18"));

    return 0;
}

int test_CF(struct instructionData *currentIns) {

    setupTests(0xCF, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 1"));

    return 0;
}

int test_D0(struct instructionData *currentIns) {

    setupTests(0xD0, currentIns);
    assert(!strcmp(currentIns->assembly, "RNC"));

    return 0;
}

int test_D1(struct instructionData *currentIns) {

    setupTests(0xD1, currentIns);
    assert(!strcmp(currentIns->assembly, "POP D"));

    return 0;
}

int test_D2(struct instructionData *currentIns) {

    setupTests(0xD2, currentIns);
    assert(!strcmp(currentIns->assembly, "JNC 0xA118"));

    return 0;
}

int test_D3(struct instructionData *currentIns) {

    setupTests(0xD3, currentIns);
    assert(!strcmp(currentIns->assembly, "OUT 0x18"));

    return 0;
}

int test_D4(struct instructionData *currentIns) {

    setupTests(0xD4, currentIns);
    assert(!strcmp(currentIns->assembly, "CNC 0xA118"));

    return 0;
}

int test_D5(struct instructionData *currentIns) {

    setupTests(0xD5, currentIns);
    assert(!strcmp(currentIns->assembly, "PUSH D"));

    return 0;
}

int test_D6(struct instructionData *currentIns) {

    setupTests(0xD6, currentIns);
    assert(!strcmp(currentIns->assembly, "SUI 0x18"));

    return 0;
}

int test_D7(struct instructionData *currentIns) {

    setupTests(0xD7, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 2"));

    return 0;
}

int test_D8(struct instructionData *currentIns) {

    setupTests(0xD8, currentIns);
    assert(!strcmp(currentIns->assembly, "RC"));

    return 0;
}

int test_D9(struct instructionData *currentIns) {

    setupTests(0xD9, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_DA(struct instructionData *currentIns) {

    setupTests(0xDA, currentIns);
    assert(!strcmp(currentIns->assembly, "JC 0xA118"));

    return 0;
}

int test_DB(struct instructionData *currentIns) {

    setupTests(0xDB, currentIns);
    assert(!strcmp(currentIns->assembly, "IN 0x18"));

    return 0;
}

int test_DC(struct instructionData *currentIns) {

    setupTests(0xDC, currentIns);
    assert(!strcmp(currentIns->assembly, "CC 0xA118"));

    return 0;
}

int test_DD(struct instructionData *currentIns) {

    setupTests(0xDD, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_DE(struct instructionData *currentIns) {

    setupTests(0xDE, currentIns);
    assert(!strcmp(currentIns->assembly, "SBI 0x18"));

    return 0;
}

int test_DF(struct instructionData *currentIns) {

    setupTests(0xDF, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 3"));

    return 0;
}

int test_E0(struct instructionData *currentIns) {

    setupTests(0xE0, currentIns);
    assert(!strcmp(currentIns->assembly, "RPO"));

    return 0;
}

int test_E1(struct instructionData *currentIns) {

    setupTests(0xE1, currentIns);
    assert(!strcmp(currentIns->assembly, "POP H"));

    return 0;
}

int test_E2(struct instructionData *currentIns) {

    setupTests(0xE2, currentIns);
    assert(!strcmp(currentIns->assembly, "JPO 0xA118"));

    return 0;
}

int test_E3(struct instructionData *currentIns) {

    setupTests(0xE3, currentIns);
    assert(!strcmp(currentIns->assembly, "XTHL"));

    return 0;
}

int test_E4(struct instructionData *currentIns) {

    setupTests(0xE4, currentIns);
    assert(!strcmp(currentIns->assembly, "CPO 0xA118"));

    return 0;
}

int test_E5(struct instructionData *currentIns) {

    setupTests(0xE5, currentIns);
    assert(!strcmp(currentIns->assembly, "PUSH H"));

    return 0;
}

int test_E6(struct instructionData *currentIns) {

    setupTests(0xE6, currentIns);
    assert(!strcmp(currentIns->assembly, "ANI 0x18"));

    return 0;
}

int test_E7(struct instructionData *currentIns) {

    setupTests(0xE7, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 4"));

    return 0;
}

int test_E8(struct instructionData *currentIns) {

    setupTests(0xE8, currentIns);
    assert(!strcmp(currentIns->assembly, "RPE"));

    return 0;
}

int test_E9(struct instructionData *currentIns) {

    setupTests(0xE9, currentIns);
    assert(!strcmp(currentIns->assembly, "PCHL"));

    return 0;
}

int test_EA(struct instructionData *currentIns) {

    setupTests(0xEA, currentIns);
    assert(!strcmp(currentIns->assembly, "JPE 0xA118"));

    return 0;
}

int test_EB(struct instructionData *currentIns) {

    setupTests(0xEB, currentIns);
    assert(!strcmp(currentIns->assembly, "XCHG"));

    return 0;
}

int test_EC(struct instructionData *currentIns) {

    setupTests(0xEC, currentIns);
    assert(!strcmp(currentIns->assembly, "CPE 0xA118"));

    return 0;
}

int test_ED(struct instructionData *currentIns) {

    setupTests(0xED, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_EE(struct instructionData *currentIns) {

    setupTests(0xEE, currentIns);
    assert(!strcmp(currentIns->assembly, "XRI 0x18"));

    return 0;
}

int test_EF(struct instructionData *currentIns) {

    setupTests(0xEF, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 5"));

    return 0;
}

int test_F0(struct instructionData *currentIns) {

    setupTests(0xF0, currentIns);
    assert(!strcmp(currentIns->assembly, "RP"));

    return 0;
}

int test_F1(struct instructionData *currentIns) {

    setupTests(0xF1, currentIns);
    assert(!strcmp(currentIns->assembly, "POP PSW"));

    return 0;
}

int test_F2(struct instructionData *currentIns) {

    setupTests(0xF2, currentIns);
    assert(!strcmp(currentIns->assembly, "JP 0xA118"));

    return 0;
}

int test_F3(struct instructionData *currentIns) {

    setupTests(0xF3, currentIns);
    assert(!strcmp(currentIns->assembly, "DI"));

    return 0;
}

int test_F4(struct instructionData *currentIns) {

    setupTests(0xF4, currentIns);
    assert(!strcmp(currentIns->assembly, "CP 0xA118"));

    return 0;
}

int test_F5(struct instructionData *currentIns) {

    setupTests(0xF5, currentIns);
    assert(!strcmp(currentIns->assembly, "PUSH PSW"));

    return 0;
}

int test_F6(struct instructionData *currentIns) {

    setupTests(0xF6, currentIns);
    assert(!strcmp(currentIns->assembly, "ORI 0x18"));

    return 0;
}

int test_F7(struct instructionData *currentIns) {

    setupTests(0xF7, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 6"));

    return 0;
}

int test_F8(struct instructionData *currentIns) {

    setupTests(0xF8, currentIns);
    assert(!strcmp(currentIns->assembly, "RM"));

    return 0;
}

int test_F9(struct instructionData *currentIns) {

    setupTests(0xF9, currentIns);
    assert(!strcmp(currentIns->assembly, "SPHL"));

    return 0;
}

int test_FA(struct instructionData *currentIns) {

    setupTests(0xFA, currentIns);
    assert(!strcmp(currentIns->assembly, "JM 0xA118"));

    return 0;
}

int test_FB(struct instructionData *currentIns) {

    setupTests(0xFB, currentIns);
    assert(!strcmp(currentIns->assembly, "EI"));

    return 0;
}

int test_FC(struct instructionData *currentIns) {

    setupTests(0xFC, currentIns);
    assert(!strcmp(currentIns->assembly, "CM 0xA118"));

    return 0;
}

int test_FD(struct instructionData *currentIns) {

    setupTests(0xFD, currentIns);
    assert(!strcmp(currentIns->assembly, "Undefined instruction"));

    return 0;
}

int test_FE(struct instructionData *currentIns) {

    setupTests(0xFE, currentIns);
    assert(!strcmp(currentIns->assembly, "CPI 0x18"));

    return 0;
}

int test_FF(struct instructionData *currentIns) {

    setupTests(0xFF, currentIns);
    assert(!strcmp(currentIns->assembly, "RST 7"));

    return 0;
}
