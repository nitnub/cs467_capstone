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

    // check accumulator for value
    assert(getReg16(currentIns->s, SP) == 0x23FF);
}

/*
*   test_3C: increment register A
*/
int test_3C(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x18);
}

/*
*   test_3D: decrement register A
*/
int test_3D(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x16);
}

/*
*   test_3E: put immediate value into register A
*/
int test_3E(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getReg8(currentIns->s, A) == 0x18);
}

/*
*   test_3F: complement the carry flag
*/
int test_3F(struct instructionData *currentIns, int opcode) {
    setupInstruction(currentIns, opcode);
    dispatchLevel2(currentIns);

    // check accumulator for value
    assert(getFlag(currentIns->s, CARRY) == 0x01);
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

    return 0; 
}