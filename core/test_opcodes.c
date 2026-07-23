#include <assert.h>
#include "opcodes.h"
#include "handler.h"

struct instructionData ins;
state cpu_test;


int setupInstruction(struct instructionData* currentIns, int opcode){

    // set up instruction values for testing
    currentIns->instruction = opcode;
    currentIns->operand1 = 0x18;
    currentIns->operand2 = 0x21;

    // set up registers for testing
    currentIns->s = &cpu_test;
    currentIns->s->regs8[B] = 0x10;
    currentIns->s->regs8[C] = 0x11;
    currentIns->s->regs8[D] = 0x12;
    currentIns->s->regs8[E] = 0x13;
    currentIns->s->regs8[H] = 0x14;
    currentIns->s->regs8[L] = 0x15;
    currentIns->s->regs8[A] = 0x17;

    currentIns->s->regs16[SP] = 0x2400;
    currentIns->s->regs16[PC] = 0x0080;

    currentIns->s->flags[CARRY] = 0x00;
  
    return 0;
}




/*
*   test_01: 0x01 (loads immediate data x2 into BC)
*/
int test_01(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    assert(getReg16(currentIns->s, BC) == 0x2118);
    return 0;
}

/*
*   test_02: 0x02 (store accumulator at address in registers BC)
*/
int test_02(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(memFetch(currentIns->s, 0x10, 0x11) == 0x17);
}

/*
*   test_03: 0x03 (increment value in registers BC)
*/
int test_03(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, BC) == 0x1012);
}


/*
*   test_04: 0x04 (increment value in register B)
*/
int test_04(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, B) == 0x11);
}

/*
*   test_05: 0x05 (decrement value in register B)
*/
int test_05(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, B) == 0x0F);
}

/*
*   test_06: 0x06 (store immediate value in register B)
*/
int test_06(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, B) == 0x18);
}

/*
*   test_07: 0x07 (rotate left)
*/
int test_07(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2E);
}

/*
*   test_09: 0x09 (double add BC to HL)
*/
int test_09(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x2426);
}

/*
*   test_0A: 0x0A (load accumulator from address in BC)
*/
int test_0A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, getReg8(currentIns->s, B), getReg8(currentIns->s, C), 0xBC);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0xBC);
}

/*
*   test_0B: decrement register pair BC
*/
int test_0B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg16(currentIns->s, BC) == 0x1010);
}

/*
*   test_0C: increment register C
*/
int test_0C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, C) == 0x12);
}

/*
*   test_0D: decrement register C
*/
int test_0D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, C) == 0x10);
}

/*
*   test_0E: put immediate value into register C
*/
int test_0E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, C) == 0x18);
}

/*
*   test_0F: rotate accumulator right
*/
int test_0F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value (0x17 -> 0x83)
    assert(getReg8(currentIns->s, A) == 0x8B);
}

/*
*   test_11: 0x11 (loads immediate data x2 into DE)
*/
int test_11(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    assert(getReg16(currentIns->s, DE) == 0x2118);
}

/*
*   test_12: 0x12 (store accumulator at address in registers DE)
*/
int test_12(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(memFetch(currentIns->s, 0x12, 0x13) == 0x17);
}

/*
*   test_13: 0x13 (increment value in registers DE)
*/
int test_13(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, DE) == 0x1214);
}

/*
*   test_14: 0x14 (increment value in register D)
*/
int test_14(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, D) == 0x13);
}

/*
*   test_15: 0x05 (decrement value in register D)
*/
int test_15(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    
    assert(getReg8(currentIns->s, D) == 0x11);
}

/*
*   test_16: 0x16 (store immediate value in register D)
*/
int test_16(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, D) == 0x18);
}

/*
*   test_17: 0x17 (rotate left through carry)
*/
int test_17(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2F);
}

/*
*   test_19: 0x19 (double add DE to HL)
*/
int test_19(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x2628);
}

/*
*   test_1A: 0x1A (load accumulator from address in DE)
*/
int test_1A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, getReg8(currentIns->s, D), getReg8(currentIns->s, E), 0xDE);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0xDE);
}

/*
*   test_1B: decrement register pair DE
*/
int test_1B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg16(currentIns->s, DE) == 0x1212);
}

/*
*   test_1C: increment register E
*/
int test_1C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, E) == 0x14);
}

/*
*   test_1D: decrement register E
*/
int test_1D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, E) == 0x12);
}

/*
*   test_1E: put immediate value into register E
*/
int test_1E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, E) == 0x18);
}

/*
*   test_1F: rotate accumulator right through carry
*/
int test_1F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0x00);
    dispatchLevel2(currentIns);

    // check accumulator for value (0x17 -> 0x83)
    assert(getReg8(currentIns->s, A) == 0x0B);
}

/*
*   test_21: 0x21 (loads immediate data x2 into HL)
*/
int test_21(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    assert(getReg16(currentIns->s, HL) == 0x2118);
}

/*
*   test_22: 0x22 (store content of registers HL in memory (imm1 is low part of address, imm2 is high part))
*/
int test_22(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res1 = memFetch(currentIns->s, (uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1);
    uint8_t res2 = memFetch(currentIns->s, (uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1 + 1);
    assert(res1 == 0x15); // low byte, contents of register L
    assert(res2 == 0x14); // high byte, contents of register H
}

/*
*   test_23: 0x23 (increment value in registers HL)
*/
int test_23(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x1416);
}

/*
*   test_24: 0x24 (increment value in register h)
*/
int test_24(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, H) == 0x15);
}

/*
*   test_25: 0x05 (decrement value in register D)
*/
int test_25(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    
    assert(getReg8(currentIns->s, H) == 0x13);
}

/*
*   test_26: 0x26 (store immediate value in register H)
*/
int test_26(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, H) == 0x18);
}

/*
*   test_27: 0x27 (decimal adjust for BCD addition)
*/
int test_27(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setReg8(currentIns->s, A, 0x3A);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x40);
}

/*
*   test_29: 0x29 (double add HL to HL)
*/
int test_29(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x282A);
}

/*
*   test_2A: 0x2A load registers H and L from memory (imm1: low memory address, imm2: high address)
*/
int test_2A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x21, 0x18, 0x05); // load low byte into memory at 0x2118
    memStore(currentIns->s, 0x21, 0x19, 0x06); // load high byte into memory at 0x2119
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x0605);
}

/*
*   test_2B: decrement register pair HL
*/
int test_2B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg16(currentIns->s, HL) == 0x1414);
}

/*
*   test_2C: increment register L
*/
int test_2C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, L) == 0x16);
}

/*
*   test_2D: decrement register L
*/
int test_2D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, L) == 0x14);
}

/*
*   test_2E: put immediate value into register L
*/
int test_2E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, L) == 0x18);
}

/*
*   test_2F: complement the accumulator
*/
int test_2F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0xE8);
}

/*
*   test_31: 0x31 (loads immediate data x2 into SP)
*/
int test_31(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    assert(getReg16(currentIns->s, SP) == 0x2118);
}

/*
*   test_32: 0x32 (store accumulator in memory (N+1 imm: low address, N+2 imm: high address)
*/
int test_32(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res1 = memFetch(currentIns->s, (uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1);
    assert(res1 == 0x17); // accumulator
}

/*
*   test_33: 0x33 (increment value in stack pointer)
*/
int test_33(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, SP) == 0x2401);
}

/*
*   test_34: 0x34 (increment value in M at address stored in HL)
*/
int test_34(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);

    // put 6 in memory at HL
    memStore(currentIns->s, 0x14, 0x15, 0x06); 
    dispatchLevel2(currentIns);
    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    assert(res == 0x07);
}

/*
*   test_35: 0x05 (decrement value in memory addressed by HL)
*/
int test_35(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x06); 
    dispatchLevel2(currentIns);
    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    assert(res == 0x05);
}

/*
*   test_36: 0x36 (store immediate value in memory at HL)
*/
int test_36(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    assert(res == 0x18);
}

/*
*   test_37: 0x37 (set the carry flag)
*/
int test_37(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);
    uint8_t carry = getFlag(currentIns->s, CARRY);

    assert(carry == 1);
}

/*
*   test_39: 0x39 (double add SP to HL)
*/
int test_39(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x3815);
}

/*
*   test_3A: 0x3A load accumulator from immediate address
*/
int test_3A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x21, 0x18, 0x0A); // load low byte into memory at 0x2118
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x0A);
}

/*
*   test_3B: decrement stack pointer
*/
int test_3B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, SP) == 0x23FF);
}

/*
*   test_3C: increment register A
*/
int test_3C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x18);
}

/*
*   test_3D: decrement register A
*/
int test_3D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x16);
}

/*
*   test_3E: put immediate value into register A
*/
int test_3E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x18);
}

/*
*   test_3F: complement the carry flag
*/
int test_3F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getFlag(currentIns->s, CARRY) == 0x01);
}

/* 
*   test 0x40: mov B, B
*/
int test_40(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x10);
}

/* 
*   test 0x40: mov B, C
*/
int test_41(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x11);
}

/* 
*   test 0x42: mov B, D
*/
int test_42(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x12);
}

/* 
*   test 0x43: mov B, E
*/
int test_43(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x13);
}

/* 
*   test 0x44: mov B, H
*/
int test_44(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x14);
}

/* 
*   test 0x45: mov B, L
*/
int test_45(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x15);
}

/* 
*   test 0x46: mov B, M (tests move from memory)
*/
int test_46(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x27);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x27);
}

/* 
*   test 0x47: mov B, A
*/
int test_47(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x17);
}

/* 
*   test 0x48: mov C, B
*/
int test_48(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x10);
}

/* 
*   test 0x49: mov C, C
*/
int test_49(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x11);
}

/* 
*   test 0x4A: mov C, D
*/
int test_4A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x12);
}

/* 
*   test 0x4B: mov C, E 
*/
int test_4B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x13);
}

/* 
*   test 0x4C: mov C, H 
*/
int test_4C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x14);
}

/* 
*   test 0x4D: mov C, L 
*/
int test_4D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x15);
}

/* 
*   test 0x4E: mov C, M (tests move from memory)
*/
int test_4E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x37);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x37);
}

/* 
*   test 0x4F: mov C, A
*/
int test_4F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x17);
}

/* 
*   test 0x50: mov D, B
*/
int test_50(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x10);
}

/* 
*   test 0x51: mov D, C
*/
int test_51(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x11);
}

/* 
*   test 0x52: mov D, D
*/
int test_52(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x12);
}

/* 
*   test 0x53: mov D, E
*/
int test_53(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x13);
}

/* 
*   test 0x54: mov D, H
*/
int test_54(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x14);
}

/* 
*   test 0x55: mov D, L
*/
int test_55(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x15);
}

/* 
*   test 0x56: mov D, M (sets store in memory)
*/
int test_56(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x47);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x47);
}

/* 
*   test 0x57: mov D, A (sets store in memory)
*/
int test_57(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x17);
}

/* 
*   test 0x58: mov E, B (sets store in memory)
*/
int test_58(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x10);
}

/* 
*   test 0x59: mov E, C (sets store in memory)
*/
int test_59(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x11);
}

/* 
*   test 0x5A: mov E, D (sets store in memory)
*/
int test_5A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x12);
}

/* 
*   test 0x5B: mov E, E (sets store in memory)
*/
int test_5B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x13);
}

/* 
*   test 0x5C: mov E, H (sets store in memory)
*/
int test_5C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x14);
}

/* 
*   test 0x5D: mov E, L (sets store in memory)
*/
int test_5D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x15);
}

/* 
*   test 0x5E: mov E, M (tests move to memory)
*/
int test_5E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x57);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x57);
}

/* 
*   test 0x5F: mov E, A 
*/
int test_5F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x17);
}


/* 
*   test 0x60: mov H, B
*/
int test_60(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x10);
}

/* 
*   test 0x61: mov H, C
*/
int test_61(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x11);
}


/* 
*   test 0x62: mov H, D
*/
int test_62(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x12);
}

/* 
*   test 0x63: mov H, E
*/
int test_63(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x13);
}

/* 
*   test 0x64: mov H, H
*/
int test_64(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x14);
}

/* 
*   test 0x65: mov H, L
*/
int test_65(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x15);
}

/* 
*   test 0x66: mov H, M
*/
int test_66(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x67);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x67);
}


/* 
*   test 0x67: mov H, A
*/
int test_67(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x17);
}

/* 
*   test 0x68: mov L, B
*/
int test_68(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x10);
}

/* 
*   test 0x69: mov L, C
*/
int test_69(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x11);
}

/* 
*   test 0x6A: mov L, D
*/
int test_6A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x12);
}

/* 
*   test 0x6B: mov L, E
*/
int test_6B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x13);
}

/* 
*   test 0x6C: mov L, H
*/
int test_6C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x14);
}

/* 
*   test 0x6D: mov L, L
*/
int test_6D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x15);
}

/* 
*   test 0x6E: mov L, M
*/
int test_6E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x21);
    dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x21);
}

/* 
*   test 0x6F: mov L, A
*/
int test_6F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x17);
}

/* 
*   test 0x70: mov M, B
*/
int test_70(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res = 0x10);
}

/* 
*   test 0x71: mov M, C
*/
int test_71(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res = 0x11);
}

/* 
*   test 0x72: mov M, D
*/
int test_72(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res = 0x12);
}

/* 
*   test 0x73: mov M, E
*/
int test_73(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res = 0x13);
}

/* 
*   test 0x74: mov M, H
*/
int test_74(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res = 0x14);
}

/* 
*   test 0x75: mov M, L
*/
int test_75(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res = 0x15);
}

/* 
*   test 0x77: mov M, A
*/
int test_77(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res = 0x17);
}

/* 
*   test 0x78: mov A, B
*/
int test_78(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x10);
}

/* 
*   test 0x79: mov A, C
*/
int test_79(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x11);
}

/* 
*   test 0x7A: mov A, D
*/
int test_7A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x12);
}

/* 
*   test 0x79: mov A, E
*/
int test_7B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x13);
}

/* 
*   test 0x7C: mov A, H
*/
int test_7C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x14);
}

/* 
*   test 0x7D: mov A, L
*/
int test_7D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x15);
}

/* 
*   test 0x7E: mov A, M
*/
int test_7E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x52);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x52);
}

/* 
*   test 0x7F: mov A, M
*/
int test_7F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x17);
}

/*
*   test_D3: OUT (output instruction)
*/
int test_D3(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    assert(getPort(currentIns->s, 0x18, OUT) == 0x17);
    return 0;
}

/*
*   test_DB: IN (input instruction)
*/
int test_DB(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setPort(currentIns->s, 0x18, IN, 0x54);
    dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x54);
    return 0;
}

int main (void) {

    pthread_mutex_init(&cpu_test.ioInputLock, NULL);
    pthread_mutex_init(&cpu_test.ioOutpLock, NULL);
    memset(&cpu_test.memory, 0, MEM_SIZE);

    test_01(&ins, 0x01);    // 0 is NOP
    test_02(&ins, 0x02);
    test_03(&ins, 0x03);
    test_04(&ins, 0x04);
    test_05(&ins, 0x05);
    test_06(&ins, 0x06);
    test_07(&ins, 0x07);
    test_09(&ins, 0x09);    // 8 is undefined
    test_0A(&ins, 0x0A);
    test_0B(&ins, 0x0B);
    test_0C(&ins, 0x0C);
    test_0D(&ins, 0x0D);
    test_0E(&ins, 0x0E);
    test_0F(&ins, 0x0F);

    test_11(&ins, 0x11);
    test_12(&ins, 0x12);
    test_13(&ins, 0x13);
    test_14(&ins, 0x14);
    test_15(&ins, 0x15);
    test_16(&ins, 0x16);
    test_17(&ins, 0x17);    // 18 is undefined
    test_19(&ins, 0x19);
    test_1A(&ins, 0x1A);
    test_1B(&ins, 0x1B);
    test_1C(&ins, 0x1C);
    test_1D(&ins, 0x1D);
    test_1E(&ins, 0x1E);
    test_1F(&ins, 0x1F);

    test_21(&ins, 0x21);
    test_22(&ins, 0x22);
    test_23(&ins, 0x23);
    test_24(&ins, 0x24);
    test_25(&ins, 0x25);
    test_26(&ins, 0x26);
    test_27(&ins, 0x27);
    test_29(&ins, 0x29);    // 28 is undefined
    test_2A(&ins, 0x2A);
    test_2B(&ins, 0x2B);
    test_2C(&ins, 0x2C);
    test_2D(&ins, 0x2D);
    test_2E(&ins, 0x2E);
    test_2F(&ins, 0x2F);

    test_31(&ins, 0x31);
    test_32(&ins, 0x32);
    test_33(&ins, 0x33);
    test_34(&ins, 0x34);
    test_35(&ins, 0x35);
    test_36(&ins, 0x36);
    test_37(&ins, 0x37);    // 38 is undefined
    test_39(&ins, 0x39);
    test_3A(&ins, 0x3A);
    test_3B(&ins, 0x3B);
    test_3C(&ins, 0x3C);
    test_3D(&ins, 0x3D);
    test_3E(&ins, 0x3E);
    test_3F(&ins, 0x3F);

    test_40(&ins, 0x40);
    test_41(&ins, 0x41);
    test_42(&ins, 0x42);
    test_43(&ins, 0x43);
    test_44(&ins, 0x44);
    test_45(&ins, 0x45);
    test_46(&ins, 0x46);
    test_47(&ins, 0x47);
    test_48(&ins, 0x48);
    test_49(&ins, 0x49);
    test_4A(&ins, 0x4A);
    test_4B(&ins, 0x4B);
    test_4C(&ins, 0x4C);
    test_4D(&ins, 0x4D);
    test_4E(&ins, 0x4E);
    test_4F(&ins, 0x4F);

    test_50(&ins, 0x50);
    test_51(&ins, 0x51);
    test_52(&ins, 0x52);
    test_53(&ins, 0x53);
    test_54(&ins, 0x54);
    test_55(&ins, 0x55);
    test_56(&ins, 0x56);
    test_57(&ins, 0x57);
    test_58(&ins, 0x58);
    test_59(&ins, 0x59);
    test_5A(&ins, 0x5A);
    test_5B(&ins, 0x5B);
    test_5C(&ins, 0x5C);
    test_5D(&ins, 0x5D);
    test_5E(&ins, 0x5E);
    test_5F(&ins, 0x5F);

    test_60(&ins, 0x60);
    test_61(&ins, 0x61);
    test_62(&ins, 0x62);
    test_63(&ins, 0x63);
    test_64(&ins, 0x64);
    test_65(&ins, 0x65);
    test_66(&ins, 0x66);
    test_67(&ins, 0x67);
    test_68(&ins, 0x68);
    test_69(&ins, 0x69);
    test_6A(&ins, 0x6A);
    test_6B(&ins, 0x6B);
    test_6C(&ins, 0x6C);
    test_6D(&ins, 0x6D);
    test_6E(&ins, 0x6E);
    test_6F(&ins, 0x6F);

    test_70(&ins, 0x70);
    test_71(&ins, 0x71);
    test_72(&ins, 0x72);
    test_73(&ins, 0x73);
    test_74(&ins, 0x74);
    test_75(&ins, 0x75);
    test_77(&ins, 0x77);
    test_78(&ins, 0x78);
    test_79(&ins, 0x79);
    test_7A(&ins, 0x7A);
    test_7B(&ins, 0x7B);
    test_7C(&ins, 0x7C);
    test_7D(&ins, 0x7D);
    test_7E(&ins, 0x7E);
    test_7F(&ins, 0x7F);

    test_D3(&ins, 0xD3);
    test_DB(&ins, 0xDB);
    return 0; 
}