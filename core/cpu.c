#include "cpu.h"

/*
* ********************** GET VALUE FROM CPU *************************
*/

/*
*   function: getReg8
*   returns the current value of an 8-bit general purpose register
*   or register buffer (M, I)
*
*   @param: currentState (pointer to a state)
*   @param: regIndex (enumerated integer: B, C, D, E, F, H, L, (invalid), A)
*
*   @returns: uint8_t unsigned integer
*             if error prints message and returns 0xFF (which can be valid)
*/
uint8_t getReg8(state *currentState, int regIndex) {

    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return 0xFF;
    }

    if (regIndex < 0 || regIndex > 8) {
        perror("get register: index is out of range\n");
        return 0xFF;
    }

    return currentState->regs8[regIndex];
} 

/*
*   function: getReg16
*   returns the current value of an 16-bit register
*   or register pair buffer (BC, DE, HL, PSW)
*
*   @param: currentState, a pointer to a state struct
*   @param: regIndex [order is: BC, DE, HL, SP, PC, PSW]
*
*   @returns: uint16_t unsigned integer representing register value
*             if error, returns 0xFFFF
*
*   note that 0xFFFF can also be valid.
*/
uint16_t getReg16(state *currentState, int regIndex) {

    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return 0xFFFF;
    }

    if (regIndex < 0 || regIndex > 5) {
        perror("get register: index is out of range\n");
        return 0xFFFF;
    }

    switch(regIndex) {
        case BC: return convert8To16(getReg8(currentState, B), getReg8(currentState, C)); break;
        case DE: return convert8To16(getReg8(currentState, D), getReg8(currentState, E)); break;
        case HL: return convert8To16(getReg8(currentState, H), getReg8(currentState, L)); break;
        case SP: return currentState->regs16[regIndex]; break;
        case PC: return currentState->regs16[regIndex]; break;
        case PSW: return flagsToPSW(currentState); break;
    }
    
    return 0xFFFF;
}

/*
*   function: getFlag
*   Obtains the value of a flag at index flagIndex
*       note that index values are enumerated as follows: 
*       ZERO, CARRY, PARITY, SIGN, AUX_CARRY
*
*  @param: currentState, a pointer to a state struct
*  @param: flagIndex, an integer representing the flag of interest
*
*  @returns: 0 if flag was clear, 1 if flag was set, 0xFF if error
*/
uint8_t getFlag(state *currentState, int flagIndex) {

    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return 0xFF;
    }

    if (flagIndex < 0 || flagIndex > 4) {
        perror("Error: flag index out of bounds\n");
        return 0xFF;
    }

    return currentState->flags[flagIndex];
}

/*
*   function: getInterruptStatus
*   checks if the CPU is currently accepting interrupts
*   0 indicates disabled, nonzero indicates enabled
*   returns 0xFF if state object paramter is a NULL pointer
*/
uint8_t getInterruptStatus(state *currentState) {
    if (currentState == NULL) {
        perror("Error: index to cpu state was NULL\n");
        return 0xFF;
    }

    return currentState->currentOp.interruptReady;
}

/*
*   function: getPort
*   Retrieves the value for port no. portIndex in direction specified
*   by the portDirection
*
*   @param: currentState, a pointer to the cpu state
*   @param: portIndex, an integer between 0x00 and 0xFF representing
*           the port number in either direction
*   @param: portDirection, an unsigned 1-byte integer representing
*           a boolean indicating direction (0 is IN, nonzero is OUT) 
*/
uint8_t getPort(state *currentState, int portIndex, uint8_t portDirection) {
    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return -1;
    }

    if (portIndex < 0x00 || portIndex > 0xFF) {
        perror("getPort: index out of range\n");
        return -1;
    }

    // return an input port
    if (portDirection == 0) {
        return currentState->inp[portIndex];
    }
    // return an output port
    else {
        return currentState->outp[portIndex];
    }
}

/*
* ********************** SET VALUE IN CPU *************************
*/

/*
*   function: setReg8
*   Sets the general purpose 8-bit register at regIndex to value
*
*   @param: currentState, a pointer to the current state struct
*   @param: regIndex, an integer representing the index of a register
*   @param: value: an 8-bit unsigned integer that can be loaded in a register
*
*   @resturns: 0 if successful, -1 if error
*/
int setReg8(state *currentState, int regIndex, uint8_t value) {

    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return -1;
    }

    currentState->regs8[regIndex] = value;
    return 0;
}

/*
*   function name: setReg16
*       sets 16-bit value into appropriate registers
*       note that while register pairs can always be accessed via the 16-bit index,
*       the actual position in that index is never set.
*
*   @param: currentState, a pointer to a state struct
*   @param: regPairIndex: an integer representing the 16-bit register or register pair
*           note: these are enumerated in the following order: BC, DE, HL, SP, PC, PSW
*           Only two of these are stored in the 16-bit register array: SP and PC
*   @param: value, a uint16_t unsigned 16-bit integer to place in the register
*
*   @returns: 0 if successful, -1 if error
*/
int setReg16(state *currentState, int regPairIndex, uint16_t value) {

    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return -1;
    }

    if (regPairIndex < 0 || regPairIndex > 6) {
        perror("Set register pair: index out of bounds\n");
        return -1;
    }

    switch (regPairIndex) {

        case BC:
            currentState->regs8[B] = highFrom16Bit(value);
            currentState->regs8[C] = lowFrom16Bit(value);
            return 0;
            break;

        case DE:
            currentState->regs8[D] = highFrom16Bit(value);
            currentState->regs8[E] = lowFrom16Bit(value);
            return 0;
            break;

        case HL:
            currentState->regs8[H] = highFrom16Bit(value);
            currentState->regs8[L] = lowFrom16Bit(value);
            return 0;
            break;

        case SP:
            currentState->regs16[SP] = value;
            return 0;
            break;

        case PC:
            currentState->regs16[PC] = value;
            return 0;
            break;

        case PSW: 
            // set register buffer
            currentState->regs16[PSW] = value;

            // set register A
            currentState->regs8[A] = lowFrom16Bit(value);

            // set flags
            currentState->flags[ZERO] = PSWToFlag(ZERO, value);
            currentState->flags[CARRY] = PSWToFlag(CARRY, value);
            currentState->flags[PARITY] = PSWToFlag(PARITY, value);
            currentState->flags[SIGN] = PSWToFlag(SIGN, value);
            currentState->flags[AUX_CARRY] = PSWToFlag(AUX_CARRY, value);
            return 0;
            break;
        default:
            return -1;
            break;
    }
}

/*
*   function: setFlag
*   sets the flag at flagIndex to 1 if value is nonzero.
*   Otherwise sets to 0.
*
*   @param: currentState, a pointer to a state object
*   @param: flagIndex, an integer representing the flag
*           note these are enumerated in the following order:
*           ZERO, CARRY, PARITY, SIGN, AUX_CARRY
*   @value: an unsigned integer representing a boolean 0 or nonzero
*
*   @returns 0 if successful or -1 if error
*/
int setFlag(state *currentState, int flagIndex, uint8_t value) {

    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return -1;
    }

    if (value != 0){
        currentState->flags[flagIndex] = 0x01;
    }
    else {
        currentState->flags[flagIndex] = 0x00;
    }
    return 0;
}

/*
*   function: setPort
*   Sets the input or output port designated by portIndex and portDirection with
*   the number in value.
*
*   @param: currentState, a pointer to the current state of the cpu
*   @param: portIndex, an integer representing the port number
*   @param: portDirection, an unsigned integer representing a boolean value that
*           indicates direction (0 is input, nonzero is output)
*   @param: value, an unsigned 8-bit integer representing the value to be inserted
*           into a given port.
*/
int setPort(state *currentState, int portIndex, uint8_t portDirection, uint8_t value) {
    if (currentState == NULL) {
        perror("Error: null pointer to current state\n");
        return -1;
    }

    if (portIndex < 0x00 || portIndex > 0xFF) {
        perror("getPort: index out of range\n");
        return -1;
    }

    if (portDirection == 0) {
        currentState->inp[portIndex] = value;
    }
    else {
        currentState->outp[portIndex] = value;
    }
    return 0;
}

/*
*   function: setInterruptStatus
*   sets the interrupt status to appropriate value (0 indicates disabled,
*   nonzero indicates enabled)
*
*   @param: currentState, a pointer to the current state
*   @param: uint8_t, an unsigned integer representing the desired value
*   to set (0 = disable interrupts, nonzero = enable)
*
*   @returns 0 if successful, -1 if there is an error
*/
int setInterruptStatus(state *currentState, uint8_t value) {
    if (currentState == NULL) {
        perror("Error: index to cpu state was NULL\n");
        return -1;
    }
    if (value == 0) {
        currentState->currentOp.interruptReady = 0;
    }
    else {
        currentState->currentOp.interruptReady = 1;
    }

    return 0;
}

/*
*   function: convert8To16
*   Takes two 8-bit integers designated "high" and "low" and converts into a single 16-bit number
*
*   @param: high, a uint8_t 8-bit unsigned integer
*   @param: low, a uint8_t 8-bit unsigned integer
*
*   @returns: a uint16_t 16-bit unsigned integer
*/
uint16_t convert8To16(uint8_t high, uint8_t low) {
    return (uint16_t) (high << 8) + low;
}

/*
*   function: highFrom16Bit
*   returns the most significant 8 bits of a 16-bit number as a single 8-bit number 
*   @param: value, a 16-bit unsigned integer
*   @returns: an 8-bit unsigned integer
*/
uint8_t highFrom16Bit(uint16_t value) {
    return (uint8_t) ((value & 0xFF00) >> 8);
}

/*
*   function:lowFrom16Bit
*   returns the least significant 8 bits of a 16-bit number as a single 8-bit number 
*   @param: value, a 16-bit unsigned integer
*   @returns: an 8-bit unsigned integer
*/
uint8_t lowFrom16Bit(uint16_t value) {
    return (uint8_t) (value & 0x00FF);
}

/*
*   funcion: flagsToPSW
*   convert flags to value needed for Program Status Word.
*       most significant 8 bits: flags represented as below
*       least significant 8 bits: register A, the accumulator
*
*   | | | |A| | | | |
*   |S|Z|0|C|0|P|1|C|
*
*   @param: currentState, a pointer to a state struct
*   @returns: a uint16_t unsigned 16-bit integer representing the PSW
*/
uint16_t flagsToPSW(state *currentState) {
    uint16_t zero = currentState->flags[0] << ZERO_SHIFT;
    uint16_t carry = currentState->flags[1] << CARRY_SHIFT;
    uint16_t parity = currentState->flags[2] << PARITY_SHIFT;
    uint16_t sign = currentState->flags[3] << SIGN_SHIFT;
    uint16_t auxCarry = currentState->flags[4] << AUX_CARRY_SHIFT;

    return getReg8(currentState, A) + zero + carry + parity + sign + auxCarry +0x0200;
}

/*
*   function: PSWToFlags
*   Converts a 16-bit unsigned value representing the program status word
*   to the flag represented by flagIndex
*
*   @param: flagIndex, an integer representing the flag's position in flags array
*           These are enumerated as follows: ZERO, CARRY, PARITY, SIGN, AUX_CARRY
*
*   @returns: an unsigned 8-bit integer representing the boolean 0 or nonzero
*            Returns 0xFF if there is an error
*/
uint8_t PSWToFlag(int flagIndex, uint16_t value) {

    switch (flagIndex) {
        case ZERO: return (value & 0x4000) >> ZERO_SHIFT; break;
        case CARRY: return (value & 0x0100) >> CARRY_SHIFT; break;
        case PARITY: return (value & 0x0400) >> PARITY_SHIFT; break;
        case SIGN: return (value & 0x8000) >> SIGN_SHIFT; break;
        case AUX_CARRY: return (value & 0x1000) >> AUX_CARRY_SHIFT; break;
    }

    perror("PSW to flag: flag index out of range\n");
    return 0xFF;
}

/*
*   function: complementFlag
*   returns the complement of a single bit boolean value
*   @param: value, an unsigned 8-bit integer represents a boolean zero or nonzero
*   @returns: an unsigned 8-bit integer representing the complement of value
*/
uint8_t complementFlag(uint8_t value) {

    return (uint8_t) value == 0;
}

/*
*   function: complementRegister
*   returns the complement of an 8-bit unsigned integer
*
*   @param: value, an unsigned 8-bit integer representing contents of a register
*   @returns: the 1s complement, equivalent to performing a NOT operation on the value
*/
uint8_t complementRegister(uint8_t value) {

    return (uint8_t) ~value;
}

/* ******************** INTERACT WITH MEMORY ************************** */

/*
*   function: memFetch
*   fetch the byte currently in memory at the 16-bit address High-Low
*
*   @param currentState, a pointer to the current state
*   @param high, an unsigned 8-bit integer representing the high byte of address
*   @param low, an unsigned 8-bit integer representing the low byte of address
*
*   @returns a uint8_t byte that was in memory at address High-Low
*/
uint8_t memFetch(state *currentState, uint8_t high, uint8_t low) {

    uint16_t memIndex = convert8To16(high, low);

    // catch addresses out of range
    if (memIndex > MEM_END) {
        perror("memory fetch: index out of range\n");
        return 0xFF;
    }

    return currentState->memory[memIndex];

}

/*
*   returns index of location that should mirror byte in memory
*/
uint16_t memMirror(uint16_t index) {

    if (index < MEM_RAM_MIRROR_START) {
        return index + MEM_RAM_MIRROR_START;
    }

    return index - MEM_RAM_MIRROR_START;
}


/*
*   function: memStore
*   Store the byte value in memory at the 16-bit address High-Low, as well as the
*   mirrored memory address (0x0000 - 0x3FFF are mirrored at 0x4000)
*   @param currentState, a pointer to the current state
*   @param high, an unsigned 8-bit integer representing the high byte of address
*   @param low, an unsigned 8-bit integer representing the low byte of address
*
*   @returns 0 if successful, -1 if error
*
*   NOTE: this method must prevent the program from storing data in ROM
*/
int memStore(state *currentState, uint8_t high, uint8_t low, uint8_t value) {

    uint16_t memIndex = convert8To16(high, low);

    // crash out for storage in ROM
    if (memIndex < 0x2000) {
        printf("ERROR: memory storage in restricted range (ROM) at %04X (PC-1: %04X)\n", 
                    memIndex, getReg16(currentState, PC)-1);
        // do nothing
        return 0;
    }

    // check for range
    // if (memIndex > MEM_END) {
    if (memIndex > 0xFFFF) {
        perror("Error: memory out of range\n");
        return -1;
    } 

    // store and mirror value
    currentState->memory[memIndex] = value;

    uint16_t mirrorIndex = memMirror(memIndex);
    
    if (mirrorIndex < 0x2000) {
        printf("ERROR: memory storage in restricted range (ROM) at %04X (PC-1: %04X)\n", 
            memIndex, getReg16(currentState, PC)-1);
        // do nothing
        return 0;
    }

    currentState->memory[memMirror(memIndex)] = value;
    return 0;
}

/* ****************** INTERACT WITH THE STACK (below 0x2400) ****************** */

/* wrapper for pushing to stack from given register pair*/
int stackPushFromRegister (state *currentState, int regPairIndex) {

    uint16_t combined = getReg16(currentState, regPairIndex);
    uint8_t valueHigh = highFrom16Bit(combined);
    uint8_t valueLow = lowFrom16Bit(combined);

    int result = stackPushValues(currentState, valueHigh, valueLow);
    return result;
}

/*
*   Where SP is the original Stack Pointer:
*       Low byte goes to memory at SP - 2
*       High byte goes to memory at SP - 1
*/
int stackPushValues (state *currentState, uint8_t valueHigh, uint8_t valueLow) {

    uint16_t sp = getReg16(currentState, SP);

    // get first address (for high value)
    uint8_t highAddress = highFrom16Bit(sp - 1);
    uint8_t lowAddress = lowFrom16Bit(sp - 1);
    memStore(currentState, highAddress, lowAddress, valueHigh);

    // get second address (for low value)
    highAddress = highFrom16Bit(sp - 2);
    lowAddress = lowFrom16Bit(sp - 2);
    memStore(currentState, highAddress, lowAddress, valueLow);

    // adjust stack pointer
    setReg16(currentState, SP, sp-2);

    return 0;
}

/*
*   Where SP is the original Stack Pointer:
*       Low byte comes from memory at SP
*       High byte comess from memory at SP+1
*/
int stackPopValues (state *currentState, int regPairIndex) {

    // get starting value of stack pointer
    uint16_t sp = getReg16(currentState, SP);

    // get first address (for low value)
    uint8_t highAddress = highFrom16Bit(sp);
    uint8_t lowAddress = lowFrom16Bit(sp);
    uint8_t valueLow = memFetch(currentState, highAddress, lowAddress);

    // get second address (for high value)
    highAddress = highFrom16Bit(sp+1);
    lowAddress = lowFrom16Bit(sp+1);
    uint8_t valueHigh = memFetch(currentState, highAddress, lowAddress);

    // combine and store the 2-byte number in destination register or register pair
    uint16_t combinedVal = convert8To16(valueHigh, valueLow);
    setReg16(currentState, regPairIndex, combinedVal);

    // adjust stack pointer
    setReg16(currentState, SP, sp+2);

    return 0;
}

/* 
*   print CPU state, including registers and next cued up op
*/
void printCPUState(state *currentState) {

    // print registers
    printf("%s%sCurrent CPU state:\nREGISTERS:\n",C_HOME,C_CLEAR);
    printf("A: 0x%02X\n", getReg8(currentState, A));
    printf("B: 0x%02X ", getReg8(currentState, B));
    printf("C: 0x%02X\n", getReg8(currentState, C));
    printf("D: 0x%02X ", getReg8(currentState, D));
    printf("E: 0x%02X\n", getReg8(currentState, E));
    printf("H: 0x%02X ", getReg8(currentState, H));
    printf("L: 0x%02X\n", getReg8(currentState, L));
    printf("PC: %04X | loaded opcode: %02X\n", getReg16(currentState, PC), currentState->currentOp.currentOpcode);
    printf("SP: %04X\n", getReg16(currentState, SP));

    // print flags & interrupt enable bit
    printf("\nFLAGS\n");
    printf("Zero: %02X | ", getFlag(currentState, ZERO));
    printf("Carry: %02X | ", getFlag(currentState, CARRY));
    printf("Parity: %02X | ", getFlag(currentState, PARITY));
    printf("Sign: %02X | ", getFlag(currentState, SIGN));
    printf("Auxiliary Carry: %02X\n", getFlag(currentState, AUX_CARRY));
    printf("Interrupts enabled: %02X\n", currentState->currentOp.interruptEnabled);

    // print stack
    printf("\n");   
    printStack(currentState);
    printf("\n");
    return;
}

/*
*   print stack
*/
void printStack(state *currentState) {

    uint16_t stackPointer = getReg16(currentState, SP);
    if (stackPointer != 0x0000) {
        for (uint16_t i = STACKTOP; i >= stackPointer && stackPointer < 0x2400; i--) {


            if (i == STACKTOP) {
                printf("STACK:\n");
            }


            uint8_t stackVal = memFetch(currentState, highFrom16Bit(i), lowFrom16Bit(i));
            printf("[0x%04X] %02X\n", i, stackVal);
        }
    }
    return;
}