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
    int r = dispatchLevel2(currentIns);
    assert(getReg16(currentIns->s, BC) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_02: 0x02 (store accumulator at address in registers BC)
*/
int test_02(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(memFetch(currentIns->s, 0x10, 0x11) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_03: 0x03 (increment value in registers BC)
*/
int test_03(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, BC) == 0x1012);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}


/*
*   test_04: 0x04 (increment value in register B)
*/
int test_04(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, B) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_05: 0x05 (decrement value in register B)
*/
int test_05(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, B) == 0x0F);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_06: 0x06 (store immediate value in register B)
*/
int test_06(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, B) == 0x18);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_07: 0x07 (rotate left)
*/
int test_07(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2E);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_09: 0x09 (double add BC to HL)
*/
int test_09(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x2426);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_0A: 0x0A (load accumulator from address in BC)
*/
int test_0A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, getReg8(currentIns->s, B), getReg8(currentIns->s, C), 0xBC);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0xBC);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_0B: decrement register pair BC
*/
int test_0B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg16(currentIns->s, BC) == 0x1010);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_0C: increment register C
*/
int test_0C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, C) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_0D: decrement register C
*/
int test_0D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, C) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_0E: put immediate value into register C
*/
int test_0E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, C) == 0x18);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_0F: rotate accumulator right
*/
int test_0F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value (0x17 -> 0x83)
    assert(getReg8(currentIns->s, A) == 0x8B);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_11: 0x11 (loads immediate data x2 into DE)
*/
int test_11(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    assert(getReg16(currentIns->s, DE) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_12: 0x12 (store accumulator at address in registers DE)
*/
int test_12(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(memFetch(currentIns->s, 0x12, 0x13) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_13: 0x13 (increment value in registers DE)
*/
int test_13(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, DE) == 0x1214);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_14: 0x14 (increment value in register D)
*/
int test_14(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, D) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_15: 0x15 (decrement value in register D)
*/
int test_15(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    
    assert(getReg8(currentIns->s, D) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_16: 0x16 (store immediate value in register D)
*/
int test_16(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, D) == 0x18);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_17: 0x17 (rotate left through carry)
*/
int test_17(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2F);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_19: 0x19 (double add DE to HL)
*/
int test_19(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x2628);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_1A: 0x1A (load accumulator from address in DE)
*/
int test_1A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, getReg8(currentIns->s, D), getReg8(currentIns->s, E), 0xDE);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0xDE);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_1B: decrement register pair DE
*/
int test_1B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg16(currentIns->s, DE) == 0x1212);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_1C: increment register E
*/
int test_1C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, E) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_1D: decrement register E
*/
int test_1D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, E) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_1E: put immediate value into register E
*/
int test_1E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, E) == 0x18);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_1F: rotate accumulator right through carry
*/
int test_1F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0x00);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value (0x17 -> 0x83)
    assert(getReg8(currentIns->s, A) == 0x0B);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_21: 0x21 (loads immediate data x2 into HL)
*/
int test_21(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    assert(getReg16(currentIns->s, HL) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_22: 0x22 (store content of registers HL in memory (imm1 is low part of address, imm2 is high part))
*/
int test_22(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res1 = memFetch(currentIns->s, (uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1);
    uint8_t res2 = memFetch(currentIns->s, (uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1 + 1);
    assert(res1 == 0x15); // low byte, contents of register L
    assert(res2 == 0x14); // high byte, contents of register H

    // check cycles for correct processor state count
    assert(currentIns->cycles == 16);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_23: 0x23 (increment value in registers HL)
*/
int test_23(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x1416);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_24: 0x24 (increment value in register h)
*/
int test_24(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, H) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_25: 0x05 (decrement value in register D)
*/
int test_25(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    
    assert(getReg8(currentIns->s, H) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_26: 0x26 (store immediate value in register H)
*/
int test_26(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, H) == 0x18);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_27: 0x27 (decimal adjust for BCD addition)
*/
int test_27(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setReg8(currentIns->s, A, 0x3A);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x40);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_29: 0x29 (double add HL to HL)
*/
int test_29(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x282A);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_2A: 0x2A load registers H and L from memory (imm1: low memory address, imm2: high address)
*/
int test_2A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x21, 0x18, 0x05); // load low byte into memory at 0x2118
    memStore(currentIns->s, 0x21, 0x19, 0x06); // load high byte into memory at 0x2119
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x0605);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 16);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_2B: decrement register pair HL
*/
int test_2B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg16(currentIns->s, HL) == 0x1414);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_2C: increment register L
*/
int test_2C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, L) == 0x16);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_2D: decrement register L
*/
int test_2D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, L) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_2E: put immediate value into register L
*/
int test_2E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, L) == 0x18);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_2F: complement the accumulator
*/
int test_2F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0xE8);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_31: 0x31 (loads immediate data x2 into SP)
*/
int test_31(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, SP) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_32: 0x32 (store accumulator in memory (N+1 imm: low address, N+2 imm: high address)
*/
int test_32(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res1 = memFetch(currentIns->s, (uint8_t) currentIns->operand2, (uint8_t) currentIns->operand1);
    assert(res1 == 0x17); // accumulator

    // check cycles for correct processor state count
    assert(currentIns->cycles == 13);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_33: 0x33 (increment value in stack pointer)
*/
int test_33(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, SP) == 0x2401);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_34: 0x34 (increment value in M at address stored in HL)
*/
int test_34(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);

    // put 6 in memory at HL
    memStore(currentIns->s, 0x14, 0x15, 0x06); 
    int r = dispatchLevel2(currentIns);
    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    assert(res == 0x07);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_35: 0x05 (decrement value in memory addressed by HL)
*/
int test_35(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x06); 
    int r = dispatchLevel2(currentIns);
    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    assert(res == 0x05);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_36: 0x36 (store immediate value in memory at HL)
*/
int test_36(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    assert(res == 0x18);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_37: 0x37 (set the carry flag)
*/
int test_37(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    uint8_t carry = getFlag(currentIns->s, CARRY);

    assert(carry == 1);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_39: 0x39 (double add SP to HL)
*/
int test_39(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x3815);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_3A: 0x3A load accumulator from immediate address
*/
int test_3A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x21, 0x18, 0x0A); // load low byte into memory at 0x2118
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x0A);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 13);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_3B: decrement stack pointer
*/
int test_3B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, SP) == 0x23FF);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_3C: increment register A
*/
int test_3C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x18);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_3D: decrement register A
*/
int test_3D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x16);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test_3E: put immediate value into register A
*/
int test_3E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x18);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/*
*   test_3F: complement the carry flag
*/
int test_3F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getFlag(currentIns->s, CARRY) == 0x01);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x40: mov B, B
*/
int test_40(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);

    // assert no operands to skip
    assert(r == 0);
    return 0;
}

/* 
*   test 0x40: mov B, C
*/
int test_41(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);

    // assert no operands to skip
    assert(r == 0);
    return 0;
}

/* 
*   test 0x42: mov B, D
*/
int test_42(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);

    assert(r == 0);
    return 0;
}

/* 
*   test 0x43: mov B, E
*/
int test_43(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x44: mov B, H
*/
int test_44(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x45: mov B, L
*/
int test_45(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x46: mov B, M (tests move from memory)
*/
int test_46(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x27);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x27);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x47: mov B, A
*/
int test_47(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, B) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x48: mov C, B
*/
int test_48(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x49: mov C, C
*/
int test_49(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x4A: mov C, D
*/
int test_4A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x4B: mov C, E 
*/
int test_4B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x4C: mov C, H 
*/
int test_4C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x4D: mov C, L 
*/
int test_4D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x4E: mov C, M (tests move from memory)
*/
int test_4E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x37);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x37);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x4F: mov C, A
*/
int test_4F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, C) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert (r == 0);
    return 0;
}

/* 
*   test 0x50: mov D, B
*/
int test_50(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x51: mov D, C
*/
int test_51(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x52: mov D, D
*/
int test_52(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x53: mov D, E
*/
int test_53(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x54: mov D, H
*/
int test_54(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x14);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x55: mov D, L
*/
int test_55(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x56: mov D, M (sets store in memory)
*/
int test_56(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x47);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x47);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x57: mov D, A (sets store in memory)
*/
int test_57(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, D) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x58: mov E, B (sets store in memory)
*/
int test_58(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x59: mov E, C (sets store in memory)
*/
int test_59(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x11);
    
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    assert(r == 0);
    return 0;
}

/* 
*   test 0x5A: mov E, D (sets store in memory)
*/
int test_5A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x5B: mov E, E (sets store in memory)
*/
int test_5B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x5C: mov E, H (sets store in memory)
*/
int test_5C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x5D: mov E, L (sets store in memory)
*/
int test_5D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x5E: mov E, M (tests move to memory)
*/
int test_5E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x57);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x57);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x5F: mov E, A 
*/
int test_5F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, E) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}


/* 
*   test 0x60: mov H, B
*/
int test_60(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x61: mov H, C
*/
int test_61(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}


/* 
*   test 0x62: mov H, D
*/
int test_62(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x63: mov H, E
*/
int test_63(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x64: mov H, H
*/
int test_64(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x65: mov H, L
*/
int test_65(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x66: mov H, M
*/
int test_66(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x67);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x67);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}


/* 
*   test 0x67: mov H, A
*/
int test_67(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r =dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, H) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x68: mov L, B
*/
int test_68(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r ==0);
    return 0;
}

/* 
*   test 0x69: mov L, C
*/
int test_69(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x6A: mov L, D
*/
int test_6A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x6B: mov L, E
*/
int test_6B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x6C: mov L, H
*/
int test_6C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x6D: mov L, L
*/
int test_6D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x6E: mov L, M
*/
int test_6E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x21);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, L) == 0x21);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x6F: mov L, A
*/
int test_6F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check register for value
    assert(getReg8(currentIns->s, A) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x70: mov M, B
*/
int test_70(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check memory for value
    assert(res == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x71: mov M, C
*/
int test_71(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check memory for value
    assert(res == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x72: mov M, D
*/
int test_72(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check memory for value
    assert(res == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x73: mov M, E
*/
int test_73(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check memory for value
    assert(res == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x74: mov M, H
*/
int test_74(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check memory for value
    assert(res == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x75: mov M, L
*/
int test_75(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check memory for value
    assert(res == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/*
*   test 0x76: HLT [todo: make sure this stops processing]
*/
int test_76(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x77: mov M, A
*/
int test_77(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t res = memFetch(currentIns->s, 0x14, 0x15);
    
    // check accumulator for value
    assert(res == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x78: mov A, B
*/
int test_78(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x10);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x79: mov A, C
*/
int test_79(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x11);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert (r == 0);
    return 0;
}

/* 
*   test 0x7A: mov A, D
*/
int test_7A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x12);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x79: mov A, E
*/
int test_7B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x13);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x7C: mov A, H
*/
int test_7C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x14);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x7D: mov A, L
*/
int test_7D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x15);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x7E: mov A, M
*/
int test_7E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x52);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x52);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x7F: mov A, A
*/
int test_7F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x17);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x80: ADD B
*/
int test_80(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x27);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x81: ADD C
*/
int test_81(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x28);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00); // carry is not set
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x82: ADD D
*/
int test_82(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x29);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00); // carry is not set
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x83: ADD E
*/
int test_83(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2A);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00); // carry is not set
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x84: ADD H
*/
int test_84(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2B);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x85: ADD L
*/
int test_85(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2C);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x86: ADD M 
*/
int test_86(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0xFF);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x16);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x87: ADD A
*/
int test_87(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2E);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x88: ADC B
*/
int test_88(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x28);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x89: ADC C
*/
int test_89(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x29);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x8A: ADC D
*/
int test_8A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2A);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x8B: ADC E
*/
int test_8B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2B);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x8C: ADC H
*/
int test_8C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2C);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x8D: ADC L
*/
int test_8D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2D);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x8E: ADC M 
*/
int test_8E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    memStore(currentIns->s, 0x14, 0x15, 0xFD);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x15);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x8F: ADC A
*/
int test_8F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2F);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x90: SUB B
*/
int test_90(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x07);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x91: SUB C
*/
int test_91(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x06);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x92: SUB D
*/
int test_92(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x05);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x93: SUB E
*/
int test_93(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x04);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x94: SUB H
*/
int test_94(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x03);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x95: SUB L
*/
int test_95(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x02);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x96: SUB M
*/
int test_96(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    memStore(currentIns->s, 0x14, 0x15, 0xFF);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x18);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x97: SUB A
*/
int test_97(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x00);
    assert(getFlag(currentIns->s, ZERO) == 0x01);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);
    
    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x98: SBB B
*/
int test_98(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x06);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x99: SBB C
*/
int test_99(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x05);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x9A: SBB D
*/
int test_9A(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x04);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x9B: SBB E
*/
int test_9B(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x03);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x9C: SBB H
*/
int test_9C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x02);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x9D: SBB L
*/
int test_9D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x01);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x9E: SBB M
*/
int test_9E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x16);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x00);
    assert(getFlag(currentIns->s, ZERO) == 0x01);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0x9F: SBB A
*/
int test_9F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0xFF);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x01); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);  // ( (registerA & 0x0F) + ~(value_subtracted) & 0x0F ) > 0x0F

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA0: ANA B
*/
int test_A0(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x10);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA1: ANA C
*/
int test_A1(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x11);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA2: ANA D
*/
int test_A2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x12);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA3: ANA E
*/
int test_A3(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x13);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA4: ANA H
*/
int test_A4(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x14);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA5: ANA L
*/
int test_A5(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x15);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA6: ANA M
*/
int test_A6(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x00);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x00);
    assert(getFlag(currentIns->s, ZERO) == 0x01);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA7: ANA A
*/
int test_A7(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA8: XRA B
*/
int test_A8(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x07);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xA9: XRA C
*/
int test_A9(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x06);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xAA: XRA D
*/
int test_AA(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x05);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xAB: XRA E
*/
int test_AB(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x04);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xAC: XRA H
*/
int test_AC(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x03);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xAD: XRA L
*/
int test_AD(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x02);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xAE: XRA M
*/
int test_AE(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0xFF);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0xE8);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x01); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xAF: XRA A
*/
int test_AF(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x00);
    assert(getFlag(currentIns->s, ZERO) == 0x01);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB0: ORA B
*/
int test_B0(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB1: ORA C
*/
int test_B1(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB2: ORA D
*/
int test_B2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB3: ORA E
*/
int test_B3(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB4: ORA H
*/
int test_B4(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB5: ORA L
*/
int test_B5(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB6: ORA M 
*/
int test_B6(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    memStore(currentIns->s, 0x14, 0x15, 0x80);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x97);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x01); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB7: ORA A
*/
int test_B7(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB8: CMP B
*/
int test_B8(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xB9: CMP C
*/
int test_B9(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xBA: CMP D
*/
int test_BA(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xBB: CMP E
*/
int test_BB(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xBC: CMP H
*/
int test_BC(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xBD: CMP L
*/
int test_BD(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00); 

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xBE: CMP M
*/
int test_BE(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    memStore(currentIns->s, 0x14, 0x15, 0xFF);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xBF: CMP A
*/
int test_BF(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x01);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC0: RNZ (test 1 - returns)
*/
int test_C0(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 0);    // clear zero flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0); // program counter should be updated
    return 0;
}

/* 
*   test 0xC0: RNZ (test 2 - does not return)
*/
int test_C02(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 1);    // set zero flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    setReg16(currentIns->s, PC, 0x8020);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x8020);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x23FE);
    // assert that cycles updated in instruction object
    assert(currentIns->cycles == currentIns->cyclesFalse);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC1: POP BC
*/
int test_C1(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in register par
    assert(getReg16(currentIns->s, BC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC2: JNZ [success]
*/
int test_C2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 0);    // clear zero flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0); // program counter should be updated
    return 0;
}

/* 
*   test 0xC2_2: JNZ [failure]
*/
int test_C2_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 1);    // set zero flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2); // should jump over address
    return 0;
}

/*
*   test_C3: JMP (output instruction)
*/
int test_C3(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, PC) == 0x2118);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC4: CNZ [success]
*/
int test_C4(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 0);    // clear zero flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address [+3]


    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC4: CNZ [failure]
*/
int test_C4_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 1);    // set zero flag
    int r = dispatchLevel2(currentIns);

    // check that program counter does not change
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xC5: PUSH BC
*/
int test_C5(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE); // low byte
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF); // high byte

    assert(stackTop == getReg8(currentIns->s, C)); // low byte
    assert(stackSecond == getReg8(currentIns->s, B)); // high byte

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC6: ADI imm
*/
int test_C6(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x2F);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xC7: RST 0
*/
int test_C7(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0000);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // no change to program counter during dispatch

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC8: RZ (return if zero is set) [ success ]
*/
int test_C8(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 1);    // set zero flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xC9: RET (unconditional return)
*/
int test_C9(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xCA: JZ (jump if zero flag is set) [ success ]
*/
int test_CA(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 1);    // set zero flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0); // if success, no need to skip bytes
    return 0;
}

/* 
*   test 0xCA: JZ (jump if zero flag is set) [ failure ]
*/
int test_CA_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 0);    // clear zero flag
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2); // if failure, skip two bytes
    return 0;
}

/* 
*   test 0xCC: CZ (conditional call if zero is set) [ success ]
*/
int test_CC(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 1);    // set zero flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xCC_2: CZ (conditional call if zero is set) [ failure ]
*/
int test_CC_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, ZERO, 0);    // clear zero flag
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xCD: CALL (unconditional call)
*/
int test_CD(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xCE: ACI imm (add w/ carry immediate)
*/
int test_CE(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x30);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xCF: RST 1
*/
int test_CF(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0008);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // low byte of return address

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD0: RNC (test 1 - returns)
*/
int test_D0(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0);    // clear carry flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD0: RNC (test 2 - does not return)
*/
int test_D02(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 1);    // set carry flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    setReg16(currentIns->s, PC, 0x8020);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x8020);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x23FE);
    // check that cycles is correct for no jump
    assert(currentIns->cycles == currentIns->cyclesFalse);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD1: POP DE
*/
int test_D1(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in register par
    assert(getReg16(currentIns->s, DE) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD2: JNC [success]
*/
int test_D2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0);    // clear carry flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD2: JNC [failure]
*/
int test_D2_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 1);    // set carry flag
    int r = dispatchLevel2(currentIns);

    // check that program counter does not change
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    // we do not jump, so two operands should be skipped
    assert(r == 2);
    return 0;
}

/*
*   test_D3: OUT (output instruction)
*/
int test_D3(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getPort(currentIns->s, 0x18, OUT) == 0x17);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 1);

    setReg8(currentIns->s, A, 0xFF);
    currentIns->operand1 = 0x04;
    int r2 = dispatchLevel2(currentIns);
    uint16_t actual_value = currentIns->s->shiftReg.value16Bit;
    assert(actual_value == 0xFF00);
    
    return 0;
}

/* 
*   test 0xd4: CNC [ success ]
*/
int test_D4(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0);    // clear carry flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xd4: CNC [ failure ]
*/
int test_D4_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 1);    // set carry flag
    int r = dispatchLevel2(currentIns);

    // check that program counter does not change
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xD5: PUSH DE
*/
int test_D5(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE); // low byte
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF); // high byte

    assert(stackTop == getReg8(currentIns->s, E)); // low byte
    assert(stackSecond == getReg8(currentIns->s, D)); // high byte

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD6: SUI imm
*/
int test_D6(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0xFF);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x01); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xD7: RST 2
*/
int test_D7(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0010);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // low byte of return address

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD8: RC (return if carry is set) [SUCCESS]
*/
int test_D8(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 1);    // set carry flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xD8: RC (return if carry is set) [failure]
*/
int test_D8_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0);    // clear carry flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xDA: JC (jump if carry flag is set) [success]
*/
int test_DA(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 1);    // set carry flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xDA_2: JC (jump if carry flag is set) [failure]
*/
int test_DA_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0);    // clear carry flag
    int r = dispatchLevel2(currentIns);

    // check that program counter does not change
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_DB: IN (input instruction)
*/
int test_DB(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setPort(currentIns->s, 0x18, IN, 0x54);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x54);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 1);

    // output 
    currentIns->instruction = 0xD3;
    currentIns->operand1 = 0x02;
    setReg8(currentIns->s, A, 0x02);
    int r4 = dispatchLevel2(currentIns);

    currentIns->instruction = 0xD3;
    currentIns->operand1 = 0x04;
    setReg8(currentIns->s, A, 0xFF); 
    int r2 = dispatchLevel2(currentIns);

    currentIns->instruction = 0xD3;
    currentIns->operand1 = 0x04;
    setReg8(currentIns->s, A, 0x22); 
    int r3 = dispatchLevel2(currentIns);

    // input
    currentIns->instruction = opcode;
    currentIns->operand1 = 0x03;
    int r5 = dispatchLevel2(currentIns);
    uint8_t fromShift = getReg8(currentIns->s, A);

    assert(fromShift == 0x8B);
    
    return 0;
}

/* 
*   test 0xDC: CC (conditional call if carry is set) [success]
*/
int test_DC(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 1);    // set carry flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xDC: CC (conditional call if carry is set) [failure]
*/
int test_DC_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, CARRY, 0);    // clear carry flag
    int r = dispatchLevel2(currentIns);

    // check that program counter does not change
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xDE: SBI imm (subtract w/ carry immediate)
*/
int test_DE(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    set_carry(currentIns->s);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0xFE);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x01); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xDF: RST 3
*/
int test_DF(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0018);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // low byte of return address
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE0: RPO (return if parity is clear) [success]
*/
int test_E0(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 0);    // clear parity flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE0: RPO (test 2 - does not return)
*/
int test_E02(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 1);    // set parity flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    setReg16(currentIns->s, PC, 0x8020);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x8020);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x23FE);
    // check that cycles is correct for no jump
    assert(currentIns->cycles == currentIns->cyclesFalse);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE1: POP HL
*/
int test_E1(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in register par
    assert(getReg16(currentIns->s, HL) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE2: JPO (jump if parity is clear) [success]
*/
int test_E2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 0);    // clear parity flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE2_2: JPO (jump if parity is clear) [failure]
*/
int test_E2_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 1);    // set parity flag
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check that we will jump over operands
    assert(r == 2);
    return 0;
}

/*
*   test_E3: XTHL
*/
int test_E3(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    stackPushValues(currentIns->s, 0x03, 0x03);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x0303);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 18);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE4: CPO (call if parity is clear) [success]
*/
int test_E4(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 0);    // clear parity flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE4: CPO (call if parity is clear) [failure]
*/
int test_E4_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 1);    // set parity flag
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xE5: PUSH HL
*/
int test_E5(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE); // low byte
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF); // high byte

    assert(stackTop == getReg8(currentIns->s, L)); // low byte
    assert(stackSecond == getReg8(currentIns->s, H)); // high byte
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE6: ANI imm
*/
int test_E6(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x10);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xE7: RST 4
*/
int test_E7(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0020);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // low byte of return address

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE8: RP (return if parity is set) [ success ]
*/
int test_E8(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 1);    // set parity flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE8: RP (return if parity is set) [ failure ]
*/
int test_E8_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 0);    // clear parity flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xE9: PCHL put HL in program counter
*/
int test_E9(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, PC) == getReg16(currentIns->s, HL));
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xEA: JP (jump if parity flag is set) [ success ]
*/
int test_EA(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 1);    // set parity flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xEA: JP (jump if parity flag is set) [ failure ]
*/
int test_EA_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 0);    // clear parity flag
    int r = dispatchLevel2(currentIns);

    // check that the program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xEB: XCHG (DE and HL are swapped)
*/
int test_EB(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, HL) == 0x1213);
    assert(getReg16(currentIns->s, DE) == 0x1415);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xEC: CM (conditional call if parity is set) [success]
*/
int test_EC(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 1);    // set parity flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xEC: CM (conditional call if parity is set) [failure]
*/
int test_EC_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, PARITY, 0);    // clear parity flag
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xEE: XRI imm (compare imediate)
*/
int test_EE(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x0F);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xEF: RST 5
*/
int test_EF(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0028);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // low byte of return address

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF0: RP (test 1 - returns if sign is clear) [ success ]
*/
int test_F0(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 0);    // clear sign flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF0: RP (test 2 - does not return)
*/
int test_F02(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 1);    // set sign flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    setReg16(currentIns->s, PC, 0x8020);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x8020);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x23FE);
    // check that cycles is correct for no jump
    assert(currentIns->cycles == currentIns->cyclesFalse);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return values
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF1: POP PSW, stackPushFromRegister [for PSW]
*/
int test_F1(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    // store program status word
    uint16_t pswval = getReg16(currentIns->s, PSW);

    // check push has decremented stack & put PSW on stack
    stackPushFromRegister(currentIns->s, PSW);  // push psw
    assert(memFetch(currentIns->s, 0x23, 0xFF) == (flagsToPSW(currentIns->s) & 0xFF00) >> 8);
    assert(memFetch(currentIns->s, 0x23, 0xFE) == getReg8(currentIns->s, A));

    int r = dispatchLevel2(currentIns);

    // check that address is now in register pair
    assert(getReg16(currentIns->s, PSW) == pswval);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF2: JP [ jump if sign is clear ] [success]
*/
int test_F2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 0);    // clear sign flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF2: JP [ jump if sign is clear ] [failure]
*/
int test_F2_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 1);    // set sign flag
    int r = dispatchLevel2(currentIns);

    // check that program counter does not change
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_F3: DI (disable interrupt)
*/
int test_F3(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    stackPushValues(currentIns->s, 0x03, 0x03);
    int r = dispatchLevel2(currentIns);

    assert(currentIns->s->currentOp.interruptReady == 0x00);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF4: CP (call if sign is clear) [success]
*/
int test_F4(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 0);    // clear sign flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF4: CP (call if sign is clear) [failure]
*/
int test_F4_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 1);    // set sign flag
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check that we are prepared to jump operands
    assert(r == 2);
    return 0;
}

/* 
*   test 0xF5: PUSH PSW
*/
int test_F5(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE); // low byte
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF); // high byte

    assert(stackTop == lowFrom16Bit(getReg16(currentIns->s, PSW))); // low byte
    assert(stackSecond == highFrom16Bit(getReg16(currentIns->s, PSW))); // high byte
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}


/* 
*   test 0xF6: ORI imm
*/
int test_F6(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x1F);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x00);
    assert(getFlag(currentIns->s, PARITY) == 0x00); 
    assert(getFlag(currentIns->s, SIGN) == 0x00); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x00);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xF7: RST 6
*/
int test_F7(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0030);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // low byte of return address
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF8: RM (return if sign flag is set) [ success]
*/
int test_F8(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 1);    // set sign flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0102);
    // check that stack pointer has incremented
    assert(getReg16(currentIns->s, SP) == 0x2400);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF8: RM (return if sign flag is set) [ failure]
*/
int test_F8_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 0);    // clear sign flag
    stackPushValues(currentIns->s, 0x01, 0x02); // push value to stack
    int r = dispatchLevel2(currentIns);

    // check that program counter has not changed
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF9: SPHL (push HL to the stack)
*/
int test_F9(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg16(currentIns->s, SP) == getReg16(currentIns->s, HL));
    // check cycles for correct processor state count
    assert(currentIns->cycles == 5);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xFA: JM (jump if sign flag is set)
*/
int test_FA(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 1);    // clear sign flag
    int r = dispatchLevel2(currentIns);

    // check that immediate operands are now the address in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xFA: JM (jump if sign flag is set) [failure]
*/
int test_FA_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 0);    // clear sign flag
    int r = dispatchLevel2(currentIns);

    // check that program counter doesn't change
    assert(getReg16(currentIns->s, PC) == 0x0080);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 10);
    // check return value
    assert(r == 2);
    return 0;
}

/*
*   test_FB: EI (enable interrupt)
*/
int test_FB(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(currentIns->s->currentOp.interruptEnabled == 0x01);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 4);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xF4: CM (conditional call if sign is set)
*/
int test_FC(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 1);    // set sign flag
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x2118);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x82); // low byte of return address

    // check pop of return address back to the program counter
    stackPopValues(currentIns->s, PC);
    assert(getReg16(currentIns->s, PC) == 0x0082);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 17);
    // check return value
    assert(r == 0);
    return 0;
}

/* 
*   test 0xFC: CM (conditional call if sign is set) [FAILURE]
*/
int test_FC_2(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    setFlag(currentIns->s, SIGN, 0);    // clear sign flag
    int r = dispatchLevel2(currentIns);

    // check that program counter has not change
    assert(getReg16(currentIns->s, PC) == 0x0080);
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 2);
    return 0;
}

/* 
*   test 0xFE: CPI imm (compare imediate)
*/
int test_FE(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    assert(getReg8(currentIns->s, A) == 0x17);
    assert(getFlag(currentIns->s, ZERO) == 0x00);
    assert(getFlag(currentIns->s, CARRY) == 0x01);
    assert(getFlag(currentIns->s, PARITY) == 0x01); 
    assert(getFlag(currentIns->s, SIGN) == 0x01); 
    assert(getFlag(currentIns->s, AUX_CARRY) == 0x01);

    // check cycles for correct processor state count
    assert(currentIns->cycles == 7);
    // check return value
    assert(r == 1);
    return 0;
}

/* 
*   test 0xFF: RST 7
*/
int test_FF(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    int r = dispatchLevel2(currentIns);

    // check that address is now in program counter
    assert(getReg16(currentIns->s, PC) == 0x0038);
    uint8_t stackTop = memFetch(currentIns->s, 0x23, 0xFE);
    uint8_t stackSecond = memFetch(currentIns->s, 0x23, 0xFF);
    assert(stackSecond == 0x00); // low byte of return address
    assert(stackTop == 0x80); // low byte of return address
    // check cycles for correct processor state count
    assert(currentIns->cycles == 11);
    // check return value
    assert(r == 0);
    return 0;
}

int main (void) {

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
    test_76(&ins, 0x76); // HLT
    test_77(&ins, 0x77);
    test_78(&ins, 0x78);
    test_79(&ins, 0x79);
    test_7A(&ins, 0x7A);
    test_7B(&ins, 0x7B);
    test_7C(&ins, 0x7C);
    test_7D(&ins, 0x7D);
    test_7E(&ins, 0x7E);
    test_7F(&ins, 0x7F);

    test_80(&ins, 0x80);
    test_81(&ins, 0x81);
    test_82(&ins, 0x82);
    test_83(&ins, 0x83);
    test_84(&ins, 0x84);
    test_85(&ins, 0x85);
    test_86(&ins, 0x86);
    test_87(&ins, 0x87);
    test_88(&ins, 0x88);
    test_89(&ins, 0x89);
    test_8A(&ins, 0x8A);
    test_8B(&ins, 0x8B);
    test_8C(&ins, 0x8C);
    test_8D(&ins, 0x8D);
    test_8E(&ins, 0x8E);
    test_8F(&ins, 0x8F);

    test_90(&ins, 0x90);
    test_91(&ins, 0x91);
    test_92(&ins, 0x92);
    test_93(&ins, 0x93);
    test_94(&ins, 0x94);
    test_95(&ins, 0x95);
    test_96(&ins, 0x96);
    test_97(&ins, 0x97);
    test_98(&ins, 0x98);
    test_99(&ins, 0x99);
    test_9A(&ins, 0x9A);
    test_9B(&ins, 0x9B);
    test_9C(&ins, 0x9C);
    test_9D(&ins, 0x9D);
    test_9E(&ins, 0x9E);
    test_9F(&ins, 0x9F);

    test_A0(&ins, 0xA0);
    test_A1(&ins, 0xA1);
    test_A2(&ins, 0xA2);
    test_A3(&ins, 0xA3);
    test_A4(&ins, 0xA4);
    test_A5(&ins, 0xA5);
    test_A6(&ins, 0xA6);
    test_A7(&ins, 0xA7);
    test_A8(&ins, 0xA8);
    test_A9(&ins, 0xA9);
    test_AA(&ins, 0xAA);
    test_AB(&ins, 0xAB);
    test_AC(&ins, 0xAC);
    test_AD(&ins, 0xAD);
    test_AE(&ins, 0xAE);
    test_AF(&ins, 0xAF);

    test_B0(&ins, 0xB0);
    test_B1(&ins, 0xB1);
    test_B2(&ins, 0xB2);
    test_B3(&ins, 0xB3);
    test_B4(&ins, 0xB4);
    test_B5(&ins, 0xB5);
    test_B6(&ins, 0xB6);
    test_B7(&ins, 0xB7);
    test_B8(&ins, 0xB8);
    test_B9(&ins, 0xB9);
    test_BA(&ins, 0xBA);
    test_BB(&ins, 0xBB);
    test_BC(&ins, 0xBC);
    test_BD(&ins, 0xBD);
    test_BE(&ins, 0xBE);
    test_BF(&ins, 0xBF);

    test_C0(&ins, 0xC0);
    test_C02(&ins, 0xC0);
    test_C1(&ins, 0xC1);
    test_C2(&ins, 0xC2);
    test_C2_2(&ins, 0xC2);
    test_C3(&ins, 0xC3);
    test_C4(&ins, 0xC4);
    test_C4_2(&ins, 0xC4);
    test_C5(&ins, 0xC5);
    test_C6(&ins, 0xC6);
    test_C7(&ins, 0xC7);
    test_C8(&ins, 0xC8);
    test_C9(&ins, 0xC9);
    test_CA(&ins, 0xCA); // success
    test_CA_2(&ins, 0xCA); // failure
    test_CC(&ins, 0xCC);
    test_CC_2(&ins, 0xCC);
    test_CD(&ins, 0xCD);
    test_CE(&ins, 0xCE);
    test_CF(&ins, 0xCF);

    test_D0(&ins, 0xD0);
    test_D02(&ins, 0xD0);
    test_D1(&ins, 0xD1);
    test_D2(&ins, 0xD2);
    test_D2_2(&ins, 0xD2);
    test_D3(&ins, 0xD3);
    test_D4(&ins, 0xD4);
    test_D4_2(&ins, 0xD4);
    test_D5(&ins, 0xD5);
    test_D6(&ins, 0xD6);
    test_D7(&ins, 0xD7);
    test_D8(&ins, 0xD8);    // d9 is undefined
    test_D8_2(&ins, 0xD8);
    test_DA(&ins, 0xDA);
    test_DA_2(&ins, 0xDA);
    test_DB(&ins, 0xDB);
    test_DC(&ins, 0xDC);
    test_DC_2(&ins, 0xDC);
    test_DE(&ins, 0xDE);    // dd is undefined
    test_DF(&ins, 0xDF); 

    test_E0(&ins, 0xE0);
    test_E02(&ins, 0xE0);
    test_E1(&ins, 0xE1);
    test_E2(&ins, 0xE2);
    test_E2_2(&ins, 0xE2);
    test_E3(&ins, 0xE3);
    test_E4(&ins, 0xE4);
    test_E4_2(&ins, 0xE4);
    test_E5(&ins, 0xE5);
    test_E6(&ins, 0xE6);
    test_E7(&ins, 0xE7);
    test_E8(&ins, 0xE8);
    test_E8_2(&ins, 0xE8);
    test_E9(&ins, 0xE9);
    test_EA(&ins, 0xEA);
    test_EA_2(&ins, 0xEA);
    test_EB(&ins, 0xEB);
    test_EC(&ins, 0xEC);
    test_EC_2(&ins, 0xEC);
    test_EE(&ins, 0xEE);    // ED is undefined
    test_EF(&ins, 0xEF);

    test_F0(&ins, 0xF0);
    test_F02(&ins, 0xF0);
    test_F1(&ins, 0xF1);
    test_F2(&ins, 0xF2);
    test_F2_2(&ins, 0xF2);
    test_F3(&ins, 0xF3);
    test_F4(&ins, 0xF4);
    test_F4_2(&ins, 0xF4);
    test_F5(&ins, 0xF5);
    test_F6(&ins, 0xF6);
    test_F7(&ins, 0xF7);
    test_F8(&ins, 0xF8);
    test_F8_2(&ins, 0xF8);
    test_F9(&ins, 0xF9);
    test_FA(&ins, 0xFA);
    test_FA_2(&ins, 0xFA);
    test_FB(&ins, 0xFB);
    test_FC(&ins, 0xFC);
    test_FC_2(&ins, 0xFC);
    test_FE(&ins, 0xFE); // FD is undefined
    test_FF(&ins, 0xFF);

    return 0; 
}