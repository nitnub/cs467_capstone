#ifndef OPCODES_H
#define OPCODES_H

#include <string.h> // for zeroing memory during testing
#include "cpu.h"

enum alu_ops {
    ADD,
    ADC,
    SUB,
    SBB,
    ANA,
    XRA,
    ORA,
    CMP
};

typedef int (* const alu_i)(state*, int);
int alu_add (state*, int);
int alu_add_carry (state*, int);
int alu_sub (state*, int);
int alu_sub_carry (state*, int);
int alu_and (state*, int);
int alu_xor (state*, int);
int alu_or (state*, int);
int alu_compare (state*, int);

static alu_i alu_op_array[] = {alu_add, alu_add_carry, alu_sub, alu_sub_carry, alu_and, alu_xor, alu_or, alu_compare};

int aluOp (state *currentState, int sourceIndex, int aluOpIndex);
int aluOpImm (state *currentState, int aluOpIndex, uint8_t immediate);
int aluAddImm16NoFlags (state *currentState, int regPairIndex, uint8_t immediate);
int aluSubImm16NoFlags (state *currentState, int regPairIndex, uint8_t immediate);
int doubleAdd (state *currentState, int regPairIndex);

/* utility functions for flags during ALU operations */
int handleZero_arithmetic (state *currentState, uint8_t result);
int handleCarry_add (state *currentState, uint16_t sourceVal, uint8_t destVal);
int handleCarry_sub (state *currentState, uint16_t sourceVal, uint8_t destVal);
int handleSign (state *currentState, uint8_t result);
int handleParity (state *currentState, uint8_t result);
int handleAuxCarryAdd (state *currentState, uint8_t sourceVal, uint8_t destVal);
int handleAuxCarrySub (state *currentState, uint8_t sourceVal, uint8_t destVal);
//int handleAuxCarryLogic (state *currentState, uint8_t sourceVal, uint8_t destVal);
int handleAuxCarryAnd (state *currentState, uint8_t sourceVal, uint8_t destVal);
int aluFlags_arithmetic (state *currentState, int sourceIndex, uint8_t result);
int aluFlags_logic (state *currentState, int sourceIndex, uint8_t result);

/* load move instructions */
int moveRegToReg8(state *currentState, int sourceIndex, int destIndex);
int moveRegToIndirect(state *currentState, int sourceIndex, int regPairIndex);
int moveRegToAddress(state *currentState, int sourceIndex, uint8_t high, uint8_t low);
int moveRegPairToAddress(state *currentState, int regPairIndex, uint8_t high, uint8_t low);
int movIndirectToRegister(state *currentState, int regPairIndex, int destIndex);

enum accum_ops {
    RLC,
    RRC,
    RAL,
    RAR,
    DAA,
    CMA,
    STC,
    CMC
};

typedef int (* const acc_i)(state*);
int rotate_left(state*);
int rotate_right(state*);
int rotate_left_carry(state*);
int rotate_right_carry(state*);
int decimal_adjust(state*);
int complement_a(state*);
int set_carry(state*);
int complement_carry(state*);

static acc_i accum_op_array[] = {rotate_left, 
                                rotate_right, 
                                rotate_left_carry, 
                                rotate_right_carry, 
                                decimal_adjust,
                                complement_a,
                                set_carry,
                                complement_carry};

/* miscellaneous instructions */
int handleXTHL (state *currentState);

#endif
