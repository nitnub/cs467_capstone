#include "opcodes.h"

// used for testing
// state s;

/*
*********************** ROTATIONS, ETC *************************
*/

/*
*   function: rotate_left
*   A left bitshift where the most significant bit wraps around and becomes least signfiicant
*/
int rotate_left(state* currentState) {

    uint8_t accum = getReg8(currentState, A);
    uint8_t wrapper = (accum & 0x80) >> 7;
    accum = accum << 1;
    accum |= wrapper;
    setReg8(currentState, A, accum);
    setFlag(currentState, CARRY, wrapper);

    return 0;
}

/*
*   function: rotate_right
*   A right bitshift where the least significant bit wraps around and becomes most signfiicant
*/
int rotate_right(state* currentState) {

    uint8_t accum = getReg8(currentState, A);
    uint8_t carryBit = accum & 0x01;
    uint8_t wrapper = (accum & 0x01) << 7;
    accum = accum >> 1;
    accum |= wrapper;
    setReg8(currentState, A, accum);
    setFlag(currentState, CARRY, carryBit);

    return 0;
}

/*
*   function: rotate_left_carry
*   A left bitshift through the carry flag.
*   The carry flag is set based on the most significant bit at start of operation.
*   The least significant bit is set based on the carry flag at start of operation.
*/
int rotate_left_carry(state* currentState) {

    uint8_t accum = getReg8(currentState, A);
    uint8_t carry = getFlag(currentState, CARRY);
    uint8_t new_carry = (accum & 0x80) >> 7;
    accum = accum << 1;
    accum |= carry;
    setFlag(currentState, CARRY, new_carry);
    setReg8(currentState, A, accum);

    return 0;
}

/*
*   function: rotate_right_carry
*   A right bitshift through the carry flag.
*   The carry flag is set based on the least significant bit at start of operation.
*   The most significant bit is set based on the carry flag at start of operation.
*/
int rotate_right_carry(state* currentState) {

    uint8_t origin_accum = getReg8(currentState,A);
    uint8_t accum = getReg8(currentState, A) >> 1;
    uint8_t carry = getFlag(currentState, CARRY) << 7;
    uint8_t new_carry = origin_accum & 0x01;
    accum |= carry;
    setFlag(currentState, CARRY, new_carry);
    setReg8(currentState, A, accum);

    return 0;
}

/*
*   function: decimal adjust
*   Adjusts the accumulator for the two nibbles to represent digits in decimal addition
*       -- if low nibble is greater than 9 or AC flag is set, add 0x06 to accumulator
*           if this causes a carry out of the byte, set the AC flag. Otherwise clear it
*       -- if subsequent high nibble is greater than 9 or carry flag is set, add 0x60
*           to accumulator. If this causes a carry out of the byte, set carry flag
*       -- set sign, zero, and parity according to usual rules
*/
int decimal_adjust(state* currentState) {
    uint8_t accum = getReg8(currentState, A);
    uint8_t ac = getFlag(currentState, AUX_CARRY);
    uint8_t carry = getFlag(currentState, CARRY);

    uint8_t low = accum & 0x0F;

    //If the least significant four bits of the accumulator have a value greater than nine, or if the auxiliary
    // carry flag is ON, DAA adds six to the accumulator. 
    if (low > 0x09 || ac != 0) {
        accum += 0x06;
        // pseudocode: set aux flag if so
        setFlag(currentState, AUX_CARRY, 0x01);
    } else {
        setFlag(currentState, AUX_CARRY, 0x00);
    }

    // auxiliary carry is either cleared here or set if there is a carry out
    //handleCarry_add(currentState, 0x09, accum);
    //setFlag(currentState, AUX_CARRY, getFlag(currentState, CARRY));

    uint8_t high = (accum & 0xF0) >> 4;

    // If the most significant four bits of the accumulator have a value greater than nine, or if the carry
    // flag is ON, DAA adds six to the most significant four bits of the accumulator. 
    if (high > 0x09 || carry != 0) {
        accum += 0x60;
        setFlag(currentState, CARRY, 0x01);
    } else {
        setFlag(currentState, CARRY, 0x00);
    }

    setReg8(currentState, A, accum);
    return 0;
}

/*
*   function: complement_a
*   Complement the accumulator (a NOT operation). This is the 1s complement.
*/
int complement_a(state* currentState) {
    setReg8(currentState, A, complementRegister(getReg8(currentState, A)));
    return 0;
}

/*
*   function: set carry
*   Set the carry flag
*/
int set_carry(state* currentState) {
    setFlag(currentState, CARRY, 1);
    return 0;
}

/*
*   function: complement_carry
*   complement the carry flag
*/
int complement_carry(state* currentState) {
    setFlag(currentState, CARRY, complementFlag(getFlag(currentState, CARRY)));
    return 0;
}

/*
*********************** LOAD INSTRUCTIONS *************************
*/


/*
*   function: moveRegToReg8
*   This function enables all MOV [dest], [source] instructions for 8-bit registers
*   and memory at address stored in HL.
*/
int moveRegToReg8(state *currentState, int sourceIndex, int destIndex) {

    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return -1;
    }

    // if register is M, fetch from memory and store in "M" register buffer
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    // get value in source register and move to destination
    uint8_t sourceVal = getReg8(currentState, sourceIndex);
    int result = setReg8(currentState, destIndex, sourceVal);

    // if destination is memory, store memory buffer to memory structure
    if (destIndex == M) {
        memStore(currentState, getReg8(currentState, H), getReg8(currentState, L), getReg8(currentState, M));
    }

    if (result < 0) {
        perror("Error moving value from register to register\n");
        return -1;
    }

    return 0;
}

/* 
*   function: moveRegToIndirect
*   move register value to an address held in register pair 
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the register holding the value to store
*   @param: regPairIndex, an integer representing the register pair holding memory address
*/
int moveRegToIndirect(state *currentState, int sourceIndex, int regPairIndex) {

    uint8_t value = getReg8(currentState, sourceIndex);
    uint16_t address = getReg16(currentState, regPairIndex);
    uint8_t high = highFrom16Bit(address);
    uint8_t low = lowFrom16Bit(address);

    memStore(currentState, high, low, value);
    return 0;
}

/*
*   function: movIndirectToRegister
*   Move byte at address in register pair into register represented by destIndex
*
*   @param: currentState, a pointer to the current state
*   @param: regPairIndex: an integer representing register(s) holding the 16-bit address
*   @param: destIndex: an integer representing the register where we will store the value
*/
int movIndirectToRegister(state *currentState, int regPairIndex, int destIndex) {

    uint16_t address = getReg16(currentState, regPairIndex);
    uint8_t high = highFrom16Bit(address);
    uint8_t low = lowFrom16Bit(address);
    uint8_t value = memFetch(currentState, high, low);

    setReg8(currentState, destIndex, value);

    return 0;
}

/* move regster to address high-low */
int moveRegToAddress(state *currentState, int sourceIndex, uint8_t high, uint8_t low) {
    uint8_t value = getReg8(currentState, sourceIndex);
    memStore(currentState, high, low, value);
    return 0;
}

/* store contents of register pair at address high-low */
int moveRegPairToAddress(state *currentState, int regPairIndex, uint8_t high, uint8_t low) {

    // get register pair value and split into bytes
    uint16_t contents = getReg16(currentState, regPairIndex);   
    uint8_t valueHigh = highFrom16Bit(contents);
    uint8_t valueLow = lowFrom16Bit(contents);

    // store the low byte at the memory location given
    memStore(currentState, high, low, valueLow);

    // increment address as 16-bit number, then split into bytes
    uint16_t secondAddress = convert8To16(high, low) + 1;
    uint8_t secondHigh = highFrom16Bit(secondAddress);
    uint8_t secondLow = lowFrom16Bit(secondAddress);

    // store the higher byte at that memory location
    memStore(currentState, secondHigh, secondLow, valueHigh);
    return 0;
}

/*
****************** ALU INSTRUCTIONS ********************
*
*   ALU operations affect the flags.
*   Please see utility operations for details on how the flags are manipulated
*   These functions are indexed in an array, alu_op_array
*   These include (in order): alu_add, alu_add_carry, alu_sub, alu_sub_carry,
*                             alu_and, alu_xor, alu_or, alu_compare
*
*/
int aluOp (state *currentState, int sourceIndex, int aluOpIndex) {

    if (aluOpIndex > 8) {
        perror("ALU operation: index out of range\n");
        return -1;
    }

    // if register is M, fetch from memory and store in "M" register buffer
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    alu_op_array[aluOpIndex](currentState, sourceIndex);
    return 0;
}

/*
*   function: aluOpImmediate
*   A wraparound allowing immediate value to be used as source in existing alu operations
*   flags will be set as normal
*
*   @param: currentState, a pointer to the current state
*   @param: aluOpIndex, an index representing which ALU operation was called
*   @param: immediate, an unsigned 8-bit integer representing source value
*/
int aluOpImm (state *currentState, int aluOpIndex, uint8_t immediate) {

    // place immediate data into the I buffer
    setReg8(currentState, I, immediate);

    // call aluOp
    return aluOp(currentState, I, aluOpIndex);
}

/*
*   function: aluAddImm16NoFlags
*   a function allowing us to add immediate value to a 16-bit register pair
*   (flags are not updated)
*
*   @param: currentState, a pointer to the current state
*   @param: regPairIndex, an integer representing the 16-bit register(s) that will serve as accumulator
*   @param: immediate, an unsigned 8-bit integer used as an immediate source in addition operation
*/
int aluAddImm16NoFlags (state *currentState, int regPairIndex, uint8_t immediate) {

    // add immediate value to register pair
    uint16_t current = getReg16(currentState, regPairIndex);
    current += immediate;
    setReg16(currentState, regPairIndex, current);
    return 0;
}

/*
*   function: aluAddImm16NoFlags
*   a function allowing us to subtract immediate value from a 16-bit register pair
*   (flags are not updated)
*
*   @param: currentState, a pointer to the current state
*   @param: regPairIndex, an integer representing the 16-bit register(s) that will serve as accumulator
*   @param: immediate, an unsigned 8-bit integer used as an immediate source in subtraction operation
*/
int aluSubImm16NoFlags (state *currentState, int regPairIndex, uint8_t immediate) {

    // sub immediate value from register pair
    uint16_t current = getReg16(currentState, regPairIndex);
    current -= immediate;
    setReg16(currentState, regPairIndex, current);
    return 0;
}

/*
*   function: doubleAdd
*   a function allowing us to add the value in a register pair to the value in HL, 
*   storing the result in HL. The carry flag is updated if result is greater than 0xFFFF
*
*   @param: currentState, a pointer to the current state
*   @param: regPairIndex, an integer representing the 16-bit source register(s)
*/
int doubleAdd (state *currentState, int regPairIndex) {

    // get accumulator (destination) and source values
    uint16_t operand = getReg16(currentState, regPairIndex);
    uint16_t accum = getReg16(currentState, HL);

    // double add the operand value to the accumulator value
    accum += operand;
    setReg16(currentState, HL, accum);

    // double add sets carry flag if sum exceeds 0xFFFF
    uint8_t carry = ((int) operand + (int) accum) > 0xFFFF; 
    setFlag(currentState, CARRY, carry);

    return 0;
}


/* 
*   function: alu_add
*   performs ADD [REGISTER] operation on the CPU
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_add (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    // access CPU & perform calculation
    uint8_t sourceVal = getReg8(currentState, sourceIndex);
    uint8_t destVal = getReg8(currentState, A);
    uint8_t result = sourceVal + destVal;

    // handle flags
    aluFlags_arithmetic(currentState, sourceIndex, (uint8_t) result);
    handleAuxCarryAdd(currentState, sourceVal, destVal);
    handleCarry_add(currentState, sourceVal, destVal);

    // set register with result last
    setReg8(currentState, A, (uint8_t) result);
    return 0;
}

/* 
*   function: alu_add_carry
*   performs ADC [REGISTER] operation on the CPU (add with carry)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_add_carry (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    // access CPU & perform calculation
    uint8_t originalSource = getReg8(currentState, sourceIndex); // preserve low nibble
    uint16_t sourceVal = originalSource + getFlag(currentState, CARRY);
    uint8_t destVal = getReg8(currentState, A);
    uint8_t result = sourceVal + destVal;

    // update flags
    aluFlags_arithmetic(currentState, sourceIndex, (uint8_t) result);
    handleCarry_add(currentState, sourceVal, destVal);
    handleAuxCarryAdd(currentState, originalSource, destVal);

    // set accumulator with result
    setReg8(currentState, A, (uint8_t) result);

    return 0;
}

/* 
*   function: alu_sub
*   performs SUB [REGISTER] operation on the CPU (subtraction)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_sub (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    // access the CPU and perform calculations
    uint8_t sourceVal = getReg8(currentState, sourceIndex);
    uint8_t complement_source = (~sourceVal) + 1; // perform twos complement
    uint8_t destVal = getReg8(currentState, A);
    uint8_t result = complement_source + destVal;

    // handle flags    
    aluFlags_arithmetic(currentState, sourceIndex, result);
    handleCarry_sub(currentState, sourceVal, destVal);
    handleAuxCarrySub(currentState, sourceVal, destVal);

    // set accumulator with result
    setReg8(currentState, A, result);
    return 0;
}

/* 
*   function: alu_sub_carry
*   performs SBB [REGISTER] operation on the CPU (subtraction with carry)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_sub_carry (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    uint8_t originalSource = getReg8(currentState, sourceIndex); // preserve low nibble
    uint16_t sourceVal = originalSource + getFlag(currentState, CARRY);
    uint8_t destVal = getReg8(currentState, A);
    uint16_t result = (~sourceVal + 1) + getReg8(currentState, A);
    result = result % 0x100;
    
    aluFlags_arithmetic(currentState, sourceIndex, (uint8_t) result);
    handleAuxCarrySub(currentState, originalSource, destVal);
    handleCarry_sub(currentState, sourceVal, destVal);

    setReg8(currentState, A, (uint8_t) result);
    return 0;
}

/* 
*   function: alu_and
*   performs ANA [REGISTER] operation on the CPU (bitwise AND)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_and (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    uint8_t sourceVal = getReg8(currentState, sourceIndex);
    uint8_t destVal = getReg8(currentState, A);
    uint8_t result = sourceVal & destVal;

    setReg8(currentState, A, result);
    aluFlags_logic(currentState, sourceIndex, result);      // clears aux carry
    handleAuxCarryAnd(currentState, sourceVal, destVal);    // this must come after
    return 0;
}

/* 
*   function: alu_xor
*   performs XRA [REGISTER] operation on the CPU (bitwise XOR)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_xor (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    uint8_t sourceVal = getReg8(currentState, sourceIndex);
    uint8_t destVal = getReg8(currentState, A);

    uint8_t result = sourceVal ^ destVal;

    setReg8(currentState, A, result);
    aluFlags_logic(currentState, sourceIndex, result);
    return 0;
}

/* 
*   function: alu_or
*   performs ORA [REGISTER] operation on the CPU (bitwise OR)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_or (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    uint8_t sourceVal = getReg8(currentState, sourceIndex);
    uint8_t destVal = getReg8(currentState, A);

    uint8_t result = sourceVal | destVal;

    setReg8(currentState, A, result);
    aluFlags_logic(currentState, sourceIndex, result);
    return 0;
}


/* 
*   function: alu_cmp
*   performs CMP [REGISTER] operation on the CPU (compare)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer representing the index of the source (operand) register
*/
int alu_compare (state* currentState, int sourceIndex) {

    // retrieve memory if needed
    if (sourceIndex == M) {
        setReg8(currentState, M, memFetch(currentState, getReg8(currentState, H), getReg8(currentState, L)));
    }

    // access the CPU and perform calculations
    uint8_t sourceVal = getReg8(currentState, sourceIndex);
    uint8_t complement_source = (~sourceVal) + 1; // perform twos complement
    uint8_t destVal = getReg8(currentState, A);
    uint8_t result = complement_source + destVal;

    // handle flags    
    aluFlags_arithmetic(currentState, sourceIndex, result);
    handleCarry_sub(currentState, sourceVal, destVal);
    handleAuxCarrySub(currentState, sourceVal, destVal);

    return 0;
}

/* 
*   function: handleZero_arithmetic
*   Sets the zero flag based if the result of an ALU operation is 0
*
*   @param: currentState, a pointer to the current state
*   @result: a uint8_t 8-bit unsigned integer
*/
int handleZero_arithmetic (state *currentState, uint8_t result) {

    uint8_t zero = (result == 0);
    setFlag(currentState, ZERO, zero);

    return 0;
}

/* handle ALU flags during arithmetic: carry */
int handleCarry_add (state *currentState, uint16_t sourceVal, uint8_t destVal) {

    uint8_t carry = ((int) sourceVal + (int) destVal) > 0xFF; 
    setFlag(currentState, CARRY, carry);

    return 0;
}

/*
*   function: handleCarry_sub
*   sets the Carry flag when the value in the source (operand) register
*   is greater than the value in the destination (accumulator)
*
*   @param: currentState, a pointer to the current State
*   @param: sourceVal, an unsigned 8-bit integer representing the operand register
*   @param: destVal, an unsigned 8-bit integer representing the accumulator value
*/
int handleCarry_sub (state *currentState, uint16_t sourceVal, uint8_t destVal) {

    uint8_t carry = (sourceVal > destVal);
    setFlag(currentState, CARRY, carry);

    return 0;
}

/* 
*   function: handleSign
*   sets the sign flag if the most significant bit of result is set
*
*   @param: currentState, a pointer to the current state
*   @param: result: an 8-bit unsigned integer representing result of operation
*/
int handleSign (state *currentState, uint8_t result) {

    uint8_t sign = result >> 7;
    setFlag(currentState, SIGN, sign);

    return 0;
} 

/* 
*   function handleParity
*   sets parity bit in CPU structure after arithmetic or logical operation 
*
*   @param: a pointer to the current state
*   @param: the result of recent ALU operation, an 8-bit integer
*
*   citation: adapted from: https://stackoverflow.com/questions/21617970/how-can-i-check-if-a-value-has-even-parity-of-bits-or-odd
*/
int handleParity (state *currentState, uint8_t result) {

    uint8_t resultCopy = result;

    resultCopy ^= resultCopy >> 4;
    resultCopy ^= resultCopy >> 2;
    resultCopy ^= resultCopy >> 1;

    uint8_t parity = (~resultCopy) & 1;
    setFlag(currentState, PARITY, parity);

    return 0;

}

/* 
*   function: handleAuxCarryAdd
*   sets auxiliary carry if the sum of the two lower nibbles is greater than 0x0F
*   (used for ADD and ADC operations)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceVal, an unsigned 8-bit integer representing the operand
*   @param: destVal, an unsigned 8-bit integer reprsenting the accumulator value
*/
int handleAuxCarryAdd (state *currentState, uint8_t sourceVal, uint8_t destVal) {

    uint8_t aux = ((sourceVal & 0x0F) + (destVal & 0x0F)) > 0x0F;
    setFlag(currentState, AUX_CARRY, aux);
    
    return 0;
}

/* 
*   function: handleAuxCarrySub
*   sets auxiliary carry if the accumulator's lower nibbles is less than than
*   the operand's lower nibble
*   (used for SUB and SBB instructions)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceVal, an unsigned 8-bit integer representing the operand
*   @param: destVal, an unsigned 8-bit integer reprsenting the accumulator value
*/
/* handle auxiliary carry flag during SUB and SBB operations */
int handleAuxCarrySub (state *currentState, uint8_t sourceVal, uint8_t destVal) {

    uint8_t aux = (destVal & 0x0F) < (sourceVal & 0x000F);
    setFlag(currentState, AUX_CARRY, aux);

    return 0;

}

/*
*   function: handleAuxCarryAnd
*   The auxiliary carry flag is set based on results of OR operation between
*   byte three in the source and byte three in the destination.
*/
int handleAuxCarryAnd (state *currentState, uint8_t sourceVal, uint8_t destVal) {

    if ((sourceVal & 0x08) | (destVal & 0x08)) {
        setFlag(currentState, AUX_CARRY, 1);
    } else {
        setFlag(currentState, AUX_CARRY, 0);
    }
    return 0;
}

/* 
*   function: aluFlags_arithmetic
*   sets the zero flag if the result of an arithmetic operation is zero.
*   sets the parity flag if the result of an arithmetic operation has an even number
*   of bits that are set.
*   sets the sign flag if the most significant bit of the result is set.
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer pointing the source operand register
*   @param: result, an unsigned 8-bit integer representing the result of an arithmetic operation.
*/
int aluFlags_arithmetic (state *currentState, int sourceIndex, uint8_t result) {
    
    handleZero_arithmetic(currentState, result);
    handleParity(currentState, result);
    handleSign(currentState, result);

    return 0;
}

/* 
*   function: aluFlags_logic
*   sets the zero flag if the result of a logical operation is zero.
*   sets the parity flag if the result of a logical operation has an even number
*   of bits that are set.
*   sets the sign flag if the most significant bit of the result is set.
*   clears the carry flag
*   clears the auxiliary carry flag (note this behavior must be overridden by AND to match
*            the actual 8080 processor)
*
*   @param: currentState, a pointer to the current state
*   @param: sourceIndex, an integer pointing the source operand register
*   @param: result, an unsigned 8-bit integer representing the result of an arithmetic operation.
*/
int aluFlags_logic (state *currentState, int sourceIndex, uint8_t result) {

    // clears the carry flag
    setFlag(currentState, CARRY, 0);
    setFlag(currentState, AUX_CARRY, 0); // for OR and XOR only
    handleSign(currentState, result);
    handleZero_arithmetic(currentState, result);
    handleParity(currentState, result);

    return 0;
}

/* **************** IMPLEMENT HANDLERS FOR FINAL SEGMENT ********************/

/*
*   function: returnFrom
*   Executes various conditional and nonconditional return commands. When conditions
*   are met, we pop the return address from the stack into the program counter.
*
*   @param: currentState, a pointer to the currentState
*   @param: flagIndex, an integer representing the flag we must check before executing
*           (note that NO_FLAG is an acceptable index)
*   @param: condition, an unsigned integer that should be 0 if we want to jump when clear,
*           or 1 if we want to jump when set. Use 0 for unconditional returns
*/
int returnFrom(state *currentState, int flagIndex, uint8_t condition) {

    if (flagIndex == NO_FLAG || getFlag(currentState, flagIndex) == condition) {
        // pop program counter from the stack
        stackPopValues(currentState, PC);
        return 0;
    }

    return 1;
}

/*
*   function: jumpTo
*   Executes various conditional and nonconditional jump commands. When conditions
*   are met, we insert an imediate operand into the program counter.
*
*   @param: currentState, a pointer to the currentState
*   @param: flagIndex, an integer representing the flag we must check before executing
*           (note that NO_FLAG is an acceptable index)
*   @param: condition, an unsigned integer that should be 0 if we want to jump when clear,
*           or 1 if we want to jump when set. Use 0 for unconditional jumps
*   @param: highAddr - the more significant portion of address we're jumping to
*   @param: lowAddr - the less significant portion of address we're jumping to
*/
int jumpTo(state *currentState, int flagIndex, uint8_t condition, uint8_t highAddr, uint8_t lowAddr) {

    if (flagIndex == NO_FLAG || getFlag(currentState, flagIndex) == condition) {

        // convert address to 16-bit number
        uint16_t address = convert8To16(highAddr, lowAddr);

        // load it into the program counter
        setReg16(currentState, PC, address);
        return 0;
    }

    return 2; // returns 2 if no jump (to jump over address)
}

/*
*   function: callProc
*   Executes various conditional and nonconditional call commands. When conditions
*   are met, we push a return address to the stack and insert immediate value into the
*   program counter.
*
*   @param: currentState, a pointer to the currentState
*   @param: flagIndex, an integer representing the flag we must check before executing
*           (note that NO_FLAG is an acceptable index)
*   @param: condition, an unsigned integer that should be 0 if we want to jump when clear,
*           or 1 if we want to jump when set. Use 0 for unconditional calls
*   @param: highAddr - the more significant portion of address we're jumping to
*   @param: lowAddr - the less significant portion of address we're jumping to
*/
int callProc(state *currentState, int flagIndex, uint8_t condition, uint8_t highAddr, uint8_t lowAddr) {

    if (flagIndex == NO_FLAG || getFlag(currentState, flagIndex) == condition) {
        
        // increment pc before pushing  
        setReg16(currentState, PC, getReg16(currentState, PC) + 2);
        // push program counter to stack
        stackPushFromRegister(currentState, PC);
        // convert address to 16-bit number
        uint16_t address = convert8To16(highAddr, lowAddr);
        // load it into the program counter
        setReg16(currentState, PC, address);
        
        return 0;
    }
    // return 2 to jump over immediate bytes if call does not happen
    return 2;
}

/*
*   function: callProcRST
*   calls a procedure without expecting an operand (so operands are not skipped)
*
*   @param: currentState, a pointer to the current state structure
*   @param: lowAddr, the 8-bit address of the restart vector
*/
int callProcRST(state *currentState, uint8_t lowAddr) {
    // push program counter to the stack
    stackPushFromRegister(currentState, PC);
    // convert address to 16-bit number
    uint16_t address = convert8To16(0x00, lowAddr);
    // load into program counter
    setReg16(currentState,PC, address);

    return 0;
}

/* 
**************************** INPUT/OUTPUT ***************************
*/

/* 
*   function: handleIN
*   inserts a byte in accumulator from the relevant port
*   (must obtain the mutex lock before proceeding)
*
*   @param: currentState, a pointer to the current state
*   @param: port: the port in question
*/
int handleIN(state *currentState, uint8_t port) {

    // loads the accumulator with input byte at appropriate port
    // this is going to have to get a lock
    setReg8(currentState, A, currentState->inp[port]);
    return 0;
}


/* 
*   function: handleOUT
*   places a byte from the relevant port into the accumulator
*   (must obtain the mutex lock before proceeding)
*
*   @param: currentState, a pointer to the current state
*   @param: port: the port in question
*/
int handleOUT(state *currentState, uint8_t port) {
    uint8_t outByte = getReg8(currentState, A);

    currentState->outp[port] = outByte;

    return 0;
}


/* 
**************************** INTERRUPTS ****************************
*/

/* handle EI */
int handleEI (state *currentState) {
    setInterruptStatus(currentState, 1);
    return 0;
}

/* handle DI */
int handleDI (state *currentState) {
    setInterruptStatus(currentState, 0);
    return 0;
}

/* 
**************************** MISCELLANEOUS *************************
*/

/* 
*   function: XTHL
*   description: swaps contents of register HL with the stack
*
*   @param: currentState, a pointer to the current state
*/
int handleXTHL (state *currentState) {
    uint16_t temp = getReg16(currentState, HL);
    stackPopValues(currentState, HL);
    stackPushValues(currentState, highFrom16Bit(temp), lowFrom16Bit(temp));
    return 0;
}

/* 
*   function: handlePCHL
*   description: loads the program counter with value in register pair HL
*   (basically an indirect jump to the location in HL)
*
*   @param: currentState, a pointer to the current state
*/
int handlePCHL (state *currentState) {
    setReg16(currentState, PC, getReg16(currentState, HL));
    return 0;
}

/* 
*   function: handleSPHL
*   description: loads the stack pointer with address stored in registers HL
*
*   @param: currentState, a pointer to the current state
*/
int handleSPHL (state *currentState) {
    setReg16(currentState, SP, getReg16(currentState, HL));
    return 0;
}

/* 
*   function: handleXCHG
*   description: swaps contents of registers DE with registers HL
*
*   @param: currentState, a pointer to the current state
*/
int handleXCHG (state *currentState) {
    uint16_t temp = getReg16(currentState, DE);
    setReg16(currentState, DE, getReg16(currentState, HL));
    setReg16(currentState, HL, temp);
    return 0;
}

/*
int main (void) {

    // initialize IO mutex locks
    pthread_mutex_init(&s.ioInputLock, NULL);
    pthread_mutex_init(&s.ioOutpLock, NULL);
    memset(&s.memory, 0, MEM_SIZE);
    s.regs8[A] = 0x03;
    s.regs8[B] = 0x13;
    s.regs8[C] = 0x12;
    s.regs8[H] = 0x22;
    s.regs8[L] = 0x18;
    

    s.memory[0x2218] = 0x02;
    setFlag(&s, CARRY, 1);
    aluOpImm(&s, ADD, 0x05);

    printf("the answer is: %02X\n", getReg8(&s, A));
    printf("The zero flag is: %02X\n", getFlag(&s, ZERO));
    printf("The carry flag is: %02X\n", getFlag(&s, CARRY));
    printf("The parity flag is: %02X\n", getFlag(&s, PARITY));
    printf("The sign flag is: %02X\n", getFlag(&s, SIGN));
    printf("The aux carry flag is: %02X\n", getFlag(&s, AUX_CARRY));

    moveRegToReg8(&s, A, M);
    printf("The value in memory is: %02X\n", memFetch(&s, getReg8(&s, H), getReg8(&s, L)));

    moveRegToReg8(&s, M, B);
    printf("The value in B is: %02X\n", getReg8(&s, B));

    setReg16(&s, SP, 0x2400);
    printf("The stack pointer s is %04X\n", getReg16(&s, SP));
    stackPushValues(&s, 0x07, 0x12);
  
    printf("The stack pointer s is %04X\n", getReg16(&s, SP));
    returnFrom(&s, CARRY, 1);
    printf("The stack pointer s is %04X\n", getReg16(&s, SP));
    printf("The program counter is %04X\n", getReg16(&s, PC));

    set_carry(&s);
    rotate_left_carry(&s);
    printf("after rotation left w/ carry, the answer is: %02X\n", getReg8(&s, A));

    rotate_left(&s);
    printf("after rotation left, the answer is: %02X\n", getReg8(&s, A));
        rotate_left(&s);
    printf("after rotation left, the answer is: %02X\n", getReg8(&s, A));
        rotate_left(&s);
    printf("after rotation left, the answer is: %02X\n", getReg8(&s, A));
        rotate_left(&s);
    printf("after rotation left, the answer is: %02X\n", getReg8(&s, A));

    aluOpImm(&s, ADD, 0x0B);
    printf("after adding 0x0B the accum is: %02X\n", getReg8(&s, A));
    decimal_adjust(&s);
    printf("after adding 0x0B and decimal adjusting the accum is: %02X\n", getReg8(&s, A));

    uint16_t previous = getReg16(&s, HL);
    uint16_t bc_previous = getReg16(&s, BC);
    doubleAdd(&s, BC);
    printf("the value of HL (%04X) after double add BC (%04X) is now %04X\n", previous, bc_previous, getReg16(&s, HL));
    printf("The carry flag is: %02X\n", getFlag(&s, CARRY));

}
*/