/*
 * PoC buildout for simple / naive emulator approach.
 * Opcode description text pulled from 8080 manual; some copy/paster artifacts remain.
 * Currently, all return a dummy value; final to return calculated cycles?
 *    * Could handle cycle values through other mechanism / data structure to clean things
 *      up a bit...
 * This untested code WILL contain bugs; not to be used for final build!
*/

#include <stdbool.h>
#include "cpu.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Citation: file read and buffer creation code in getFileBuffer func sourced / adapted from
//  https://web.archive.org/web/20240714234158/http://www.emulator101.com/8080-by-opcode.html
unsigned char *getFileBuffer(char fileName[], size_t *fSize) {
    FILE *f = fopen(fileName, "rb");
    if (f == NULL) {
        printf("Error: Couldn't open %s\n", fileName);
        return NULL;
    }

    //Get the file size and read it into a memory buffer
    fseek(f, 0L, SEEK_END);
    *fSize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    unsigned char *buffer = malloc(*fSize);
    fread(buffer, *fSize, 1, f);
    fclose(f);

    return buffer;
}

int loadRomToMemory(state *s, char fileName[]) {
    // copy file buffer from ROM to computer's memory...
    size_t fSize;
    unsigned char * buffer = getFileBuffer(fileName, &fSize );

    if (buffer == NULL) {
        printf("Error: Couldn't open %s\n", fileName);
        return 1;
    }

    memcpy(s->memory, buffer, fSize);
    free(buffer);
    return 0;
}

int printMemoryAddresses(const state *s, const int min, const int max) {
    uint16_t rowId = 0x00;

    // print header
    printf("Address");
    for (int i = 0; i < 16; i++) {
        if (i % 8 == 0) {
            printf(" ");
        }
        printf("%02x ", i);
    }
    printf("\n");

    // print rows
    char asciiRow[17] = {'\0'};
    for (int i = min; i < max; i++) {
        const uint8_t value = s->memory[i];

        // print row labels
        if (i % 8 == 0) {
            printf(" ");
        }

        // if hex row has been looped through, append ascii row
        if (i % 16 == 0) {
            // append ascii row to end (cover edge case of row 0)
            printf(" %s", asciiRow);
        }

        // update ascii char array for ascii range: 21(!) - 7e(~)
        if (value > 0x1f && value < 0x7f) {
            asciiRow[i % 16] = (char) value;
        } else {
            asciiRow[i % 16] = '.';
        }

        // if hex and ascii row have been added, go to newline
        if (i % 16 == 0) {
            // jump to next line
            printf("\n00%04x:", rowId);
            rowId += 0x10;
        }

        // add next value to hex row
        printf(" %02x", value);
    }

    // print last row
    printf("  %s", asciiRow);
    return 0;
}

int printAllMemoryAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_START, MEM_END);
}

int printRomAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_START, MEM_RAM_START);
}

int printRamAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_RAM_START, MEM_VIDEO_START);
}

int prinVideoMemoryAddresses(const state *s) {
    return printMemoryAddresses(s, MEM_VIDEO_START, MEM_RAM_MIRROR_START);
}

void printState(const state *s) {
    printf("\nFLAGS: Sign: %d, Zero: %d, Aux Carry: %d, Parity: %d, Carry: %d\n"
           "REGISTERS: "
           "\n\tA: 0x%02x "
           "\n\tB: 0x%02x "
           "\n\tC: 0x%02x "
           "\n\tD: 0x%02x "
           "\n\tE: 0x%02x "
           "\n\tH: 0x%02x "
           "\n\tL: 0x%02x "
           "\nSP: 0x%04x, PC: 0x%04x\n\n",
           s->flags.s, s->flags.z, s->flags.ac, s->flags.p, s->flags.c,
           s->reg.a, s->reg.b, s->reg.c, s->reg.d, s->reg.e, s->reg.h, s->reg.l,
           s->sp, s->pc);
}

// TODO: filler for now.. macro or func?
int getCycles() {
    return 321321;
}

// helpers...
uint16_t get16BitAddress(const uint8_t loBits, const uint8_t hiBits) {
    return hiBits << 8 | loBits;
}

uint16_t opGetBC(const state *s) {
    return get16BitAddress(s->reg.c, s->reg.b);
}

uint16_t opGetDE(const state *s) {
    return get16BitAddress(s->reg.e, s->reg.d);
}

uint16_t getHL(const state *s) {
    return get16BitAddress(s->reg.l, s->reg.h);
}

int opNoOp(state *s) {
    s->pc++;
    return getCycles();
}

// LXI      B
// B is high, C is low...
// B <- byte 3
// C <- byte 2
int opLxiB(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->reg.b = hiBits;
    s->reg.c = loBits;
    s->pc += 3;
    return getCycles();
}

// LXI      D
// D is high, E is low...
// D <- byte 3
// E <- byte 2
// const uint8_t loBits, const uint8_t hiBits
int opLxiD(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->reg.d = hiBits;
    s->reg.e = loBits;
    s->pc += 3;
    return getCycles();
}

// LXI      H
// H is high, L is low...
// H <- byte 3
// L <- byte 2
int opLxiH(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->reg.h = hiBits;
    s->reg.l = loBits;
    s->pc += 3;
    return getCycles();
}

// LXI      SP
// (rh) <- (byte 3),
// (rl) <- (byte 2)
int opLxiSP(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->sp = get16BitAddress(loBits, hiBits);
    s->pc += 3;
    return getCycles();
}

// STAX rp (Store accumulator indirect)
// ((rp)) <- (A)
// The content of register A is moved to the memory lo-
// cation whose address is in the register pair rp. Note:
// only register pairs rp=B (registers B and C) or rp=D
// (registers D and E) may be specified.
int stax(state *s, const uint16_t addr) {
    s->memory[addr] = s->reg.a;
    s->pc++;
    return getCycles();
}

// INX rp (Increment register pair)
// (rh) (rl) <- (rh) (rl) + 1
// The content of the register pair rp is incremented by
// one. Note: No condition flags are affected.
int opSetBC(state *s, const uint16_t value) {
    s->reg.b = value >> 8 & 0xff; // masking redundant?
    s->reg.c = value & 0xff;
    s->pc++;
    return getCycles();
}

int opSetDE(state *s, const uint16_t value) {
    s->reg.d = value >> 8 & 0xff; // masking redundant?
    s->reg.e = value & 0xff;
    s->pc++;
    return getCycles();
}

int opSetHL(state *s, const uint16_t value) {
    s->reg.h = value >> 8 & 0xff; // masking redundant?
    s->reg.l = value & 0xff;
    s->pc++;
    return getCycles();
}

// increment the stack pointer...
int opInxSp(state *s) {
    // decrement stack pointer
    s->sp++;

    // update program counter
    s->pc++;
    return getCycles();
}


// Couple of approaches for getting even parity...
int isEvenParity(uint8_t value) {
    int count = 0;
    while (value > 0) {
        count += value % 2;
        value /= 2;
    }
    return count % 2 == 0;
}

int isEvenParity_binary(uint8_t value) {
    // start by checking against even parity
    int parity = 0x01;
    for (int i = 0; i < 8; i++) {
        // update to difference between current even parity and next bit
        parity = parity ^ (value & 0x01);
        // move to next bit
        value >>= 1;
    }
    return parity;
}

// Update flags
// Handle flag changes via comparison of values (independent of actual data change operation)
void setFlagsNoCarry(state *s, unsigned char oldValue, unsigned char newValue) {
    s->flags.z = (newValue & 0xff) == 0;
    s->flags.s = (newValue & 0x80) != 0; // check most significant bit
    s->flags.p = isEvenParity_binary(newValue);
    s->flags.ac = ((oldValue >> 4) ^ ((newValue) >> 4)) != 0x00;
}

void setFlags(state *s, uint16_t oldValue, uint16_t newValue) {
    setFlagsNoCarry(s, oldValue, newValue);
    s->flags.c = (newValue & 0x100) != 0; // check carry bit
}


// INR r (Increment Register)
// (r) ~ (r) + 1
// The content of register r is incremented by one.
// Note: All condition flags except CY are affected.
int opInr(state *s, uint8_t *rgstr) {
    const uint16_t newValue = (uint16_t) (*rgstr + 1) & 0xff;
    setFlagsNoCarry(s, *rgstr, newValue);
    *rgstr = newValue;
    s->pc++;
    return getCycles();
}

// INR M (Increment memory)
// ((H) (L)) ~ ((H) (L)) + 1
// The content of the memory location whose address
// is contained in the H and L registers is incremented
// by one. Note: All condition flags except CY are
// affected.
int opInrMem(state *s) {
    const uint16_t address = getHL(s);
    const unsigned char newValue = s->memory[address] + 1;
    setFlags(s, s->memory[address], newValue);
    s->memory[address] = newValue;
    s->pc++;
    return getCycles();
}

// DCR r (Decrement Register)
// (r) ~ (r)-1
// The content of register r is decremented by one.
// Note: All condition flag~ except CY are affected
int opDcr(state *s, uint8_t *rgstr) {
    const uint16_t newValue = (uint16_t) ((*rgstr - 1) & 0xff);
    setFlagsNoCarry(s, *rgstr, newValue);
    *rgstr = newValue;
    s->pc++;
    return getCycles();
}

// DCR M (Decrement memory)
// ((H) (L)) ..- ((H) (L)) - 1
// The content of the memory location whose address is
// contained in the H and L registers is decremented by
// one. Note: All condition flags except CY are affected.
int opDcrMem(state *s) {
    const uint16_t address = getHL(s);
    const unsigned char newValue = s->memory[address] - 1;
    setFlags(s, s->memory[address], newValue);
    s->memory[address] = newValue;
    s->pc++;
    return getCycles();
}

// MOV r, M (Move from memory)
// (r) ~ ((H) (L))
// The content of the memory location, whose address
// is in registers Hand L, is moved to register r
int opMovToRegFromMem(state *s, uint8_t *rgstr) {
    *rgstr = s->memory[getHL(s)];
    s->pc++;
    return getCycles();
}

// MOV M, r (Move to memory)
// ((H)(L)) <- (r)
// The content of register r is moved to the memory lo-
// cation whose address is in registers H and L.
int opMovToMemFromReg(state *s, uint8_t value) {
    s->memory[getHL(s)] = value;
    s->pc++;
    return getCycles();
}

// MOV r1, r2 (Move Register)
// (r1) <- (r2)
// The content of register r2 is moved to register r1.
int opMovToRegFromReg(state *s, uint8_t *targetReg, const uint8_t *sourceReg) {
    *targetReg = *sourceReg;
    s->pc++;
    return getCycles();
}

// MVI r, data (Move Immediate)
// (r) ~ (byte 2)
// The content of byte 2 of the instruction is moved to
// register r.
int opMviReg(state *s, uint8_t *rgstr, uint8_t value) {
    *rgstr = value & 0xff;
    s->pc += 2;
    return getCycles();
}

// MVI M, data (Move to memory immediate)
// ((H) (L)) ~ (byte 2)
// The content of byte 2 of the instruction is moved to
// the memory location whose address is in registers H
// and L.
int opMviMem(state *s, uint8_t value) {
    s->memory[getHL(s)] = value;
    s->pc += 2;
    return getCycles();
}

int opRlc(state *s) {
    // convert to 16bit
    uint16_t temp = s->reg.a & 0xff;

    // shift left
    temp = temp << 1;

    // if a carry, then...
    if ((temp & 0x100) != 0) {
        s->flags.c = 1;
        temp = temp | 0x01;
    }

    // update value
    s->reg.a = temp & 0xff;

    s->pc++;
    return getCycles();
}

// RRC (Rotate right)
// (An) ~ (An-,); (A7) ~ (AO)
// (CY) ~ (AO)
// The content of the accumulator is rotated right one
// position. The high order bit and the CY flag are both
// set to the value shifted out of the low order bit posi-
// tion. Only the CY flag is affected.
int opRrc(state *s) {
    // get shifted value
    uint8_t tmp = s->reg.a >> 1;

    // if lowest bit is set, set flag and high-bit
    if ((s->reg.a & 0x01) == 1) {
        s->flags.c = 1;
        tmp = tmp | 0x80;
    } else {
        s->flags.c = 0;
    }

    s->reg.a = tmp & 0xff;

    s->pc++;
    return getCycles();
}

// LHLD addr (Load Hand L direct)
// (L) ~ ((byte 3)(byte 2))
// (H) ~ ((byte 3) (byte 2) + 1)
// The content of the memory location, whose address
// is specified in byte 2 and byte 3 of the inion, is
// moved to register L. The content of the memory loca-
// tion at the succeeding address is moved to register H.
int opLhld(state *s, const uint8_t loBits, const uint8_t hiBits) {
    const uint16_t address = get16BitAddress(loBits, hiBits);
    s->reg.l = s->memory[address];
    s->reg.h = s->memory[address+1];
    s->pc += 3;
    return getCycles();
}

// LDA addr (Load Accumulator direct)
// (A) <- ((byte 3) (byte 2))
// The content of the memory location, whose address
// is specified in byte 2 and byte 3 of the inion, is
// moved to register A.
int opLda(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->reg.a = s->memory[get16BitAddress(loBits, hiBits)];
    s->pc += 3;
    return getCycles();
}

// LDAX rp (Load accumulator indirect)
// (A) <- ((rp))
// The content of the memory location, whose address
// is in the register pair rp, is moved to register A. Note:
// only register pairs rp=B (registers B and C·) or rp=D
// (registers D and E) may be specified.
int opLdax(state *s, uint16_t rpValue) {
    s->reg.a = s->memory[rpValue];
    s->pc++;
    return getCycles();
}


// STA addr (Store Accumulator direct)
// ((byte 3)(byte 2)) ~ (A)
// The content of the accumulator is moved to the
// memory location whose address is specified in byte
// 2 and byte 3 of the instruction.
int opSta(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->memory[get16BitAddress(loBits, hiBits)] = s->reg.a;
    s->pc += 3;
    return getCycles();
}


// SHLD addr (Store H and L direct)
// ((byte 3) (byte 2)) <- (L)
// ((byte 3)(byte 2) + 1) <- (H)
// The content of register L is moved to the memory Jo-
// cation whose address is specified in byte 2 and byte
// 3. The content of register H is moved to the succeed-
// ing memory location.
int opShld(state *s, const uint8_t loBits, const uint8_t hiBits) {
    const uint16_t address = get16BitAddress(loBits, hiBits);
    s->memory[address] = s->reg.l & 0xff;
    s->memory[address + 1] = s->reg.h & 0xff;
    s->pc += 3;
    return getCycles();
}

// STC (Set carry)
// (CY) ~ 1
// The CY flag is set to 1. No other flags are affected.
int opStc(state *s) {
    s->flags.c = 1;
    s->pc++;
    return getCycles();
}

// DAD rp (Add register pair to H and L)
// (H) (L) ..- (H) (L) + (rh) (rl)
// The content of the register pair rp is added to the
// content of the register pair H and L. The result is
// placed in the register pair H and L. Note: Only the
// CY flag is affected. It is set if there is a carry out of
// the double precision add; otherwise it is reset.

int opDad(state *s, uint16_t rpValue) {
    uint32_t tmp = getHL(s) + rpValue;

    // if 17th (binary) position is set, carry and update flags
    if ((tmp & 0x10000) != 0) {
        s->flags.c = 1;
    } else {
        s->flags.c = 0;
    }

    opSetHL(s, tmp);

    // s->pc++; // TODO: Don't double increment pc after running opSetHL:
    return getCycles();
}


// DAA (Decimal Adjust Accumulator)
// The eight-bit number in the accumulator is adjusted
// to form two four-bit Binary-Coded-Decimal digits by
// the following process:
// 1. If the value of the least significant 4 bits of the
// accumulator is greater than 9 or if the AC flag
// is set, 6 is added to the accumulator.
// 2. If the value of the most significant 4 bits of the
// accumulator is now greater than 9, or if the CY
// flag is set, 6 is added to the most significant 4
// bits of the accumulator.
// NOTE: All flags are affected.
int opDaa(state *s) {
    uint16_t tmp = s->reg.a & 0xff;

    // check low-bits for carry
    uint8_t loBits = tmp & 0x0f;
    if (loBits > 0x09 || s->flags.ac) {
        tmp += 0x06;
    }

    // TODO: Run some tests for when to set flag...
    // set flags after first step to update carry
    setFlags(s, s->reg.a, tmp);

    // check high-bits for carry
    uint8_t hiBits = (tmp >> 4) & 0x0f;
    if (hiBits > 0x09 || s->flags.c) {
        tmp += 0x60;
    }

    // set flag settings after second step?
    setFlags(s, s->reg.a, tmp);

    s->reg.a = tmp & 0xff;

    s->pc++;
    return getCycles();
}

// DCX rp (Decrement register pair)
// (rh) (rl) ..- (rh) (rl) - 1
// The content of the register pair rp is decremented by
// one. Note: No condition flags are affected.
int opDcx(state *s, uint8_t *hiBits, uint8_t *loBits) {
    // decrement register pair in place
    uint16_t tmp = get16BitAddress(*loBits, *hiBits);
    tmp--;

    // update rp bytes
    *hiBits = (tmp >> 8) & 0xff;
    *loBits = tmp & 0xff;

    s->pc++;
    return getCycles();
}

int opDcxSp(state *s) {
    // decrement stack pointer
    s->sp--;

    // update program counter
    s->pc++;
    return getCycles();
}

// ADD r (Add Register)
// (A) <- (A) + (r)
// The content of register r is added to the content of the
// accumulator. The result is placed in the accumulator.
int opAddReg(state *s, const uint8_t regValue) {
    const uint16_t newValue = s->reg.a + regValue;

    // set flags
    setFlags(s, s->reg.a, newValue);

    // update accumulator
    s->reg.a = newValue;
    s->pc++;
    return getCycles();
}

// ADD M (Add memory)
// (A) <- (A) + ((H) (L))
// The content of the memory location whose address
// is contained in the H and L registers is added to the
// content of the accumulator. The result is placed in
// the accumulator.
int opAddMem(state *s) {
    const uint16_t newValue = s->reg.a + s->memory[getHL(s)];
    setFlags(s, s->reg.a, newValue);
    s->reg.a = newValue & 0xff;
    s->pc++;
    return getCycles();
}

// SUB r (Subtract Register)
// (A) <- (A) - (r)
// The content of register r is subtracted from the con-
// tent of the accumulator. The result is placed in the
// accumulator.
int opSubReg(state *s, const uint8_t regValue) {
    uint16_t newValue = s->reg.a - regValue;
    setFlags(s, s->reg.a, newValue);
    s->reg.a = newValue & 0xff;
    s->pc++;
    return getCycles();
}



// ANA r (AND Register)
// (A) ~ (A) /\ (r)
// The content of register r is logically anded with the
// content of the accumulator. The result is placed in
// the accumulator. The CY flag is cleared.
int opAnaReg(state *s, uint8_t regValue) {
    uint16_t newValue = s->reg.a & regValue;

    // set flags, always clearing c
    setFlags(s, s->reg.a, newValue);
    s->flags.c = 0;

    // update register
    s->reg.a = newValue;
    s->pc++;
    return getCycles();
}

// XRA r (Exclusive OR Register)
// (A) <- (A) V (r)
// The content of register r is exclusive-or'd with the
// content of the accumulator. The result is placed in
// the accumulator. The CY and AC flags are cleared.
int opXraReg(state *s, uint8_t regValue) {
    uint16_t newValue = s->reg.a ^ regValue;

    // set flags and clear CY and AC
    setFlags(s, s->reg.a, newValue);
    s->flags.c = 0;
    s->flags.ac = 0;

    // update accumulator
    s->reg.a = newValue;
    s->pc++;
    return getCycles();
}

// ORA r (OR Register)
// (A) <- (A) V (r)
// The content of register r is inclusive-OR'd with the
// content of the accumulator. The result is placed in
// the accumulator. The CY and AC flags are cleared
int opOraReg(state *s, const uint8_t regValue) {
    const uint16_t newValue = s->reg.a | regValue;

    // set flags and clear CY and AC
    setFlags(s, s->reg.a, newValue);
    s->flags.c = 0;
    s->flags.ac = 0;

    // update accumulator
    s->reg.a = newValue;

    s->pc++;
    return getCycles();
}

// TODO: Setting all flags - impact of this?
// CMP r (Compare Register)
// (A) (r)
// The content of register r is subtracted from the ac-
// cumulator. The accumulator remains unchanged. The
// condition flags are set as a result of the subtraction.
// The Z flag is set to 1 if (A) = (r). The CY flag is set to
// 1 if (A) < (r) .
int opCmpReg(state *s, const uint8_t regValue) {
    const uint16_t newValue = s->reg.a - regValue;

    // set flags via standard call and nothing else?
    setFlags(s, s->reg.a, newValue);

    // TODO: Explicit here; verify necessary and not contained in setFlags logic
    if (s->reg.a == regValue) {
        s->flags.z = 1;
    }
    if (s->reg.a < regValue) {
        s->flags.c = 1;
    }
    // TODO: Explicit here; verify necessary and not contained in setFlags logic
    s->pc++;
    return getCycles();
}

// TODO: Test: is cy flag properly set on negative result?
// CMP M (Compare memory)
// (A) ((H) (L))
// The content of the memory location whose address
// is contained in the H and L registers is subtracted
// from the accumulator. The accumulator remains un-
// changed. The condition flags are set as a result of the
// subtraction. The Z flag is set to 1 if (A) = ((H) (L)).
// The CY flag is set to 1 if (A) < ((H) (L)).
int opCmpMem(state *s) {
    // get new value
    const uint16_t newValue = s->reg.a - s->memory[getHL(s)];

    // set flags via standard call and nothing else?
    setFlags(s, s->reg.a, newValue);

    s->pc++;
    return getCycles();
}

// TODO: is cy flag properly set on negative result?
// CPI data (Compare immediate)
// (A) (byte 2)
// The content of the second byte of the instruction is
// subtracted from the accumulator. The condition flags
// are set by the result of the subtraction. The Z flag is
// set to 1 if (A) = (byte 2). The CY flag is set to 1 if
// (A) < (byte 2).
int opCpi(state *s, const uint8_t value) {
    const uint16_t newValue = s->reg.a + value;
    setFlags(s, s->reg.a, newValue);
    s->pc += 2;
    return getCycles();
}

// TODO: See page 56 of manual for guidance on conditionals...
// RET (Return)
// (PCl) <- ((SP));
// (PCH) <- ((SP) + 1);
// (SP) <- (SP) + 2;
// The content of the memory location whose address
// is specified in register SP is moved to the low-order
// eight bits of register PC. The content of the memory
// location whose address is one more than the content
// of register SP is moved to the high-order eight bits of
// register PC. The content of register SP is incremented by 2.
int opRet(state *s) {
    const uint8_t loBits = s->memory[s->sp]; // TODO: Way to verify this is assigned to lower bits?
    const uint8_t hiBits = s->memory[s->sp + 1];

    s->pc = get16BitAddress(loBits, hiBits);
    s->sp += 2;
    return getCycles();
}

// Page 55: NZ - not zero (Z = 0)
int opReturnIfTrue(state *s, bool condition) {
    if (condition) {
        opRet(s);
    } else {
        // "...otherwise, control continues sequentially."
        s->pc++;
    }
    return getCycles();
}

// Page 55: NZ - not zero (Z = 0)
int opRnz(state *s) {
    return opReturnIfTrue(s, s->flags.z == 0);
}

// Page 55: 2 - zero (Z = 1)
int opRz(state *s) {
    return opReturnIfTrue(s, s->flags.z == 1);
}

// Page 55: NC - no carry (CY = 0)
int opRnc(state *s) {
    return opReturnIfTrue(s, s->flags.c == 0);
}

// RST n
// (Restart)
// ((SP) - 1) ~ (PCH)
// ((SP) - 2) ~ (PCl)
// (SP) ~ (SP) - 2
// (PC) ~ 8* (NNN)
// The high-order eight bits of the next instruction ad-
// dress are moved to the memory location whose
// address is one less than the content of register SP.
// The low-order eight bits of the next instruction ad-
// dress are moved to the memory location whose
// address is two less than the content of register SP.
// The content of register SP is decremented by two.
// Control is transferred to the instruction whose ad-
// dress is eight times the content of NNN.
int opRst(state *s, int n) {

    s->memory[s->sp-1] = (s->pc >> 8) & 0xff;
    s->memory[s->sp-2] = s->pc & 0xff;

    s->sp -= 2;
    // TODO: multiply binary representation of NNN (ex: 111 == 7 decimal) by 8..
    s->pc = 8 * n;
    return getCycles();
}


// POP rp (Pop)
// (rl) <- ((SP))
// (rh) <- ((SP) + 1)
// (SP) <- (SP) + 2
// The content of the memory location, whose address
// is specified by the content of register SP, is moved to
// the low-order register of register pair rp. The content
// of the memory location, whose address is one more
// than the content of register SP, is moved to the high-
// order register of register pair rp. The content of reg-
// ister SP is incremented by 2. Note: Register pair
// rp = SP may not be specified.
int opPop(state *s, uint8_t *rpHigh, uint8_t *rpLow) {  // TODO: Switch H/L signature orderin to match other funcs?
    *rpLow = s->memory[s->sp];
    *rpHigh = s->memory[s->sp + 1];

    s->sp += 2;
    s->pc++;
    return getCycles();
}

// TODO: Needs testing...
// POP PSW (Pop processor status word)
// (CY) ~ ((SP))O
// (P) ..- ((SP))2
// (AC) ~ ((SP))4
// (Z) ~ ((SP))6
// (S) ~ ((SP))7
// (A) ...- ((SP) + 1)
// (SP) ...- (SP) + 2
// The content of the memory location whose address
// is specified by the content of register SP is used to
// restore the condition flags. The content of the mem-
// ory location whose address is one more than the
// content of register SP is moved to register A. The
// content of register SP is incremented by 2.
int opPopPsw(state *s) {
    const uint8_t statusWord = s->memory[s->sp];

    // set flags from status word
    s->flags.c = statusWord & 0x01;
    s->flags.p = (statusWord & 0x04) == 0x04;
    s->flags.ac = (statusWord & 0x10) == 0x10;
    s->flags.z = (statusWord & 0x40) == 0x40;
    s->flags.s = (statusWord & 0x80) == 0x80;

    // update register a
    s->reg.a = s->memory[s->sp + 1];

    // update stack pointer
    s->sp += 2;
    s->pc++;
    return getCycles();
}


// PUSH rp (Push)
// ((SP) - 1) <- (rh)
// ((SP) - 2) <- (rl)
// (SP) <- (SP) - 2
// The content of the high-order register of register pair
// rp is moved to the memory location whose address is
// one less than the content of register SP. The content
// of the low-order register of register pair rp is moved
// to the memory location whose address is two less
// than the content of register SP. The content of reg-
// ister SP is decremented by 2. Note: Register pair
// rp = SP may not be specified.
int opPush(state *s, const uint8_t rpHigh, const uint8_t rpLow) {
    s->memory[s->sp - 1] = rpHigh;
    s->memory[s->sp - 2] = rpLow;
    s->sp -= 2;
    s->pc++;
    return getCycles();
}

// PUSH PSW (Push processor status word)
// ((SP) -1) ~ (A)
// ((SP) - 2)0 ..- (CY) , ((SP) - 2) 1 ~ 1
// ((SP) - 2)2 ~ (P), ((SP) - 2)3 ~ 0
// ((SP) - 2)4 ~ (AC) , ((SP) - 2)5 ~ 0
// ((SP) - 2)6 ..- (Z), ((SP) - 2)7 ~ (S)
// (SP) ~ (SP) - 2
// The content of register A is moved to the memory
// location whose address is one less than register SP.
// The contents of the condition flags are assembled
// into a processor status word and the word is moved
// to the memory location whose address is two less
// than the content of register SP. The content of reg-
// ister SP is decremented by two
int opPushPsw(state *s) {
    s->memory[s->sp-1] = s->reg.a;

    uint8_t statusWord = 0x00;
    // TODO: found below approach in emulator101. Much more elegant than if statements...

    // Note: bit 1 is always set, bits 3 and 5 are always clear
    statusWord = statusWord
                 | s->flags.c
                 | 0x02                 // bit 1 is always set
                 | s->flags.p << 2
                 | s->flags.ac << 4
                 | s->flags.z << 6
                 | s->flags.s << 7;

    s->memory[s->sp-2] = statusWord;

    s->sp -= 2;
    s->pc++;
    return getCycles();
}


// JMP addr (Jump)
// (PC) <- (byte 3) (byte 2)
// Control is transferred to the instruction whose ad-
// dress is specified in byte 3 and byte 2 of the current
// instruction.
int opJmp(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->pc = get16BitAddress(loBits, hiBits);
    return getCycles();
}

// page 55:
// TODO: what does "otherwise, control continues sequentially" imply? return 1 instead of 3?
// Jcondition addr (Conditional jump)
// If (CCC),
// (PC) ~ (byte 3) (byte 2)
// If the specified condition is true, control is trans-
// ferred to the instruction whose address is specified in
// byte 3 and byte 2 of the current instruction; other-
// wise, control continues sequentially.

int jumpIfTrue(state *s, const uint8_t loBits, const uint8_t hiBits, bool condition) {
    if (condition) {
        opJmp(s, loBits, hiBits);
    } else {
        s->pc += 3;
    }
    // otherwise, control continues sequentially...
    return getCycles();
}

int opJz(state *s, const uint8_t loBits, const uint8_t hiBits) {
    return jumpIfTrue(s, loBits, hiBits, s->flags.z == 1);
}

int opJnz(state *s, const uint8_t loBits, const uint8_t hiBits) {
    return jumpIfTrue(s, loBits, hiBits, s->flags.z == 0);
}

int opJc(state *s, const uint8_t loBits, const uint8_t hiBits) {
    return jumpIfTrue(s, loBits, hiBits, s->flags.c == 1);
}

int opJnc(state *s, const uint8_t loBits, const uint8_t hiBits) {
    return jumpIfTrue(s, loBits, hiBits, s->flags.c == 0);
}

int opJm(state *s, const uint8_t loBits, const uint8_t hiBits) {
    return jumpIfTrue(s, loBits, hiBits, s->flags.s == 1);
}


// CALL addr (Call)
// ((SP) - 1) <- (PCH)
// ((SP) - 2) <- (PCl)
// (SP) <- (SP) - 2
// (PC) <- (byte 3) (byte 2)
// The high-order eight bits of the next instruction ad-
// dress are moved to the memory location whose
// address is one less than the content of register SP.
// The low-order eight bits of the next instruction ad-
// dress are moved to the memory location whose
// address is two less than the content of register SP.
// The content of register SP is decremented by 2. Con-
// trol is transferred to the instruction whose address is
// specified in byte 3 and byte 2 of the current
// instruction.
int opCall(state *s, const uint8_t loBits, const uint8_t hiBits) {
    s->memory[s->sp - 1] = (s->pc >> 8) & 0xff;
    s->memory[s->sp - 2] = s->pc & 0xff;
    s->sp -= 2;
    s->pc = get16BitAddress(loBits, hiBits);
    return getCycles();
}

int callIfTrue(state *s, const uint8_t loBits, const uint8_t hiBits, bool condition) {
    if (condition) {
        opCall(s, loBits, hiBits);
    } else {
        // otherwise, control continues sequentially...
        s->pc += 3;
    }
    return getCycles();
}

int opCz(state *s, const uint8_t loBits, const uint8_t hiBits) {
    return callIfTrue(s,  loBits,  hiBits, s->flags.z == 1);
}

int opCnz(state *s, const uint8_t loBits, const uint8_t hiBits) {
    return callIfTrue(s,  loBits,  hiBits, s->flags.z == 0);
}

// ADI data (Add immediate)
// (A) <- (A) + (byte 2)
// The content of the second byte of the instruction is
// added to the content of the accumulator. The result
// is placed in the accumulator.
int opAdi(state *s, const uint8_t value) {
    const uint16_t newValue = s->reg.a + value;

    // update flags
    setFlags(s, s->reg.a, newValue);

    // update register
    s->reg.a = newValue & 0xff;

    s->pc += 2;
    return getCycles();
}


// ANI data (AND immediate)
// (A) ~ (A) /\ (byte 2)
// The content of the second byte of the instruction is
// logically anded with the contents of the accumulator .
// The result is placed in the accumulator. The CY and
// AC flags are cleared.
int opAni(state *s, const uint8_t value) {
    const uint16_t newValue = s->reg.a & value;

    // set flags; clear c and ac flags
    setFlags(s, s->reg.a, newValue);
    s->flags.c = 0;
    s->flags.ac = 0;

    s->reg.a = newValue & 0xff;
    s->pc += 2;
    return getCycles();
}

// XCHG (Exchange H and L with D and E)
// (H) <-> (D)
// (L) <-> (E)
// The contents of registers Hand L are exchanged with
// the contents of registers D and E
int opXchg(state *s) {
    const uint8_t tmpH = s->reg.h;
    const uint8_t tmpL = s->reg.l;

    s->reg.h = s->reg.d;
    s->reg.l = s->reg.e;

    s->reg.d = tmpH;
    s->reg.e = tmpL;

    s->pc++;
    return getCycles();
}


// ORI data (OR Immediate)
// (A) <- (A) V (byte 2)
// The content of the second byte of the instruction is
// inclusive-OR'd with the content of the accumulator.
// The result is placed in the accumulator. The CY and
// AC flags are cleared.
int opOri(state *s, const uint8_t value) {
    const uint16_t newValue = s->reg.a | value;

    // set flags and clear CY and AC
    setFlags(s, s->reg.a, newValue);
    s->flags.c = 0;
    s->flags.ac = 0;

    // update accumulator
    s->reg.a = newValue;
    s->pc += 2;
    return getCycles();
}


// IN port (Input)
// (A) <- (data)
// The data placed on the eight bit bi-directional data
// bus by the specified port is moved to register A
int opIn(state *s, uint8_t value) {
    printf("~~~~~~~~~Need to implement opIn [next byte: 0x%02x]~~~~~~~~~\n", value);
    s->pc += 2;
    return getCycles();
}

// OUT port (Output)
// (data) <- (A)
// The content of register A is placed on the eight bit
// bi-directional data bus for transmission to the spec-
// ified port.
int opOut(state *s, uint8_t value) {
    printf("~~~~~~~~~(pc= %02x) Need to implement opOut[next byte: 0x%02x]~~~~~~~~~\n", s->pc, value);
    s->pc += 2;
    return getCycles();
}

// EI (Enable interrupts)
// The interrupt system is enabled following the execu-
// tion of the next instruction.
int opEi(state *s) {
    printf("~~~~~~~~~Need to implement opEi~~~~~~~~~\n");
    s->pc++;
    return getCycles();
}

// SUI data (Subtract immediate)
// (A) <- (A) - (byte 2)
// The content of the second byte of the instruction is
// subtracted from the content of the accumulator. The
// result is placed in the accumulator.
int opSui(state *s, const uint8_t value) {
    const uint16_t newValue = s->reg.a - value;

    // set flags
    setFlags(s, s->reg.a, newValue);

    // update register
    s->reg.a = newValue & 0xff;

    s->pc += 2;
    return getCycles();
}

// SBI data (Subtract immediate with borrow)
// (A) <- (A) - (byte 2) - (CY)
// The contents of the second byte of the instruction
// and the contents of the CY flag are both subtracted
// from the accumulator. The result is placed in the
// accumulator.
int opSbi(state *s, const uint8_t value) {
    return opSui(s, value - s->flags.c);
}

// XTHL (Exchange stack top with Hand L)
// (L) ~((SP))
// (H) ~ ((SP) + 1)
// The content of the L register is exchanged with the
// content of the memory location whose address is
// specified by the content of register SP. The content
// of the H register is exchanged with the content of the
// memory location whose address is one more than the
// content of register SP.
int opXthl(state *s) {
    const uint8_t tmpL = s->reg.l;
    const uint8_t tmpH = s->reg.h;

    s->reg.l = s->memory[s->sp];
    s->reg.h = s->memory[s->sp + 1];

    s->memory[s->sp] = tmpL;
    s->memory[s->sp + 1] = tmpH;

    s->pc += 1;
    return getCycles();
}


// PCHL (Jump H and l indirect - move Hand L to PC)
// (PCH) <- (H)
// (PCl) <- (l)
// The content of register H is moved to the high-order
// eight bits of register PC. The content of register l is
// moved to the low-order eight bits of register PC.
int opPchl(state *s) {
    s->pc = get16BitAddress(s->reg.l, s->reg.h);
    return 1;
}


int emulate(state *s) {
    unsigned char *code = &s->memory[s->pc];
    // dummy value for clock cycles
    int cc = 999999;

    // debug printing
    // printf("Program Counter: %04x -> %02x\n ", s->pc, code[0]);
    // printf("%04x \n", s->pc);

    // can get clockCycles through other structure at single point; currently returning dummy value from each function
    switch (*code) {
        case 0x00: cc = opNoOp(s); break;                                       // was in original implementation
        case 0x01: cc = opLxiB(s, code[1], code[2]); break;
        case 0x02: cc = stax(s, opGetBC(s)); break;
        case 0x03: cc = opSetBC(s, opGetBC(s) + 1); break;                  // was in original implementation
        case 0x04: cc = opInr(s, &s->reg.b); break;
        case 0x05: cc = opDcr(s, &s->reg.b); break;
        case 0x06: cc = opMviReg(s, &s->reg.b, code[1]); break;
        case 0x07: cc = opRlc(s); break;                                        // was in original implementation
        case 0x08: cc = opNoOp(s); break;                                       // was in original implementation
        case 0x09: cc = opDad(s, opGetBC(s)); break;
        case 0x0a: cc = opLdax(s, opGetBC(s)); break;                   // TODO: Remove as unneeded?
        case 0x0b: cc = opDcx(s, &s->reg.b, &s->reg.c); break;

        case 0x0d: cc = opDcr(s, &s->reg.c); break;
        case 0x0e: cc = opMviReg(s, &s->reg.c, code[1]); break;
        case 0x0f: cc = opRrc(s); break;

        case 0x11: cc = opLxiD(s, code[1], code[2]); break;
        case 0x13: cc = opSetDE(s, opGetDE(s) + 1); break;
        case 0x14: cc = opInr(s, &s->reg.d); break;
        case 0x15: cc = opDcr(s, &s->reg.d); break;
        case 0x16: cc = opMviReg(s, &s->reg.d, code[1]); break;
        case 0x18: cc = opNoOp(s); break;
        case 0x19: cc = opDad(s, opGetDE(s)); break;
        case 0x1a: cc = opLdax(s, opGetDE(s)); break;

        case 0x20: cc = opNoOp(s); break;
        case 0x21: cc = opLxiH(s, code[1], code[2]); break;
        case 0x22: cc = opShld(s, code[1], code[2]); break;
        case 0x23: cc = opSetHL(s, getHL(s) + 1); break;
        case 0x24: cc = opInr(s, &s->reg.h); break;
        case 0x26: cc = opMviReg(s, &s->reg.h, code[1]); break;
        case 0x27: cc = opDaa(s); break;
        case 0x29: cc = opDad(s, getHL(s)); break;
        case 0x2a: cc = opLhld(s, code[1], code[2]); break;
        case 0x2b: cc = opDcx(s, &s->reg.h, &s->reg.l); break;
        case 0x2c: cc = opInr(s, &s->reg.l); break;
        case 0x2e: cc = opMviReg(s, &s->reg.l, code[1]); break;

        case 0x31: cc = opLxiSP(s, code[1], code[2]); break;
        case 0x32: cc = opSta(s, code[1], code[2]); break;
        case 0x34: cc = opInrMem(s); break;
        case 0x35: cc = opDcrMem(s); break;
        case 0x36: cc = opMviMem(s, code[1]); break;
        case 0x37: cc = opStc(s); break;
        case 0x3a: cc = opLda(s, code[1], code[2]); break;
        case 0x3b: cc = opDcxSp(s); break;
        case 0x3c: cc = opInr(s, &s->reg.a); break;
        case 0x3d: cc = opDcr(s, &s->reg.a); break;
        case 0x3e: cc = opMviReg(s, &s->reg.a, code[1]); break;

        case 0x40: cc = opMovToRegFromReg(s, &s->reg.b, &s->reg.b); break;
        case 0x41: cc = opMovToRegFromReg(s, &s->reg.b, &s->reg.c); break;
        case 0x42: cc = opMovToRegFromReg(s, &s->reg.b, &s->reg.d); break;
        case 0x43: cc = opMovToRegFromReg(s, &s->reg.b, &s->reg.e); break;
        case 0x44: cc = opMovToRegFromReg(s, &s->reg.b, &s->reg.h); break;
        case 0x45: cc = opMovToRegFromReg(s, &s->reg.b, &s->reg.l); break;
        case 0x46: cc = opMovToRegFromMem(s, &s->reg.b); break;
        case 0x47: cc = opMovToRegFromReg(s, &s->reg.b, &s->reg.a); break;
        case 0x4e: cc = opMovToRegFromMem(s, &s->reg.c); break;
        case 0x4f: cc = opMovToRegFromReg(s, &s->reg.c, &s->reg.a); break;

        case 0x54: cc = opMovToRegFromReg(s, &s->reg.d, &s->reg.h); break;
        case 0x56: cc = opMovToRegFromMem(s, &s->reg.d); break;
        case 0x5e: cc = opMovToRegFromMem(s, &s->reg.e); break;
        case 0x5f: cc = opMovToRegFromReg(s, &s->reg.e, &s->reg.a); break;

        case 0x60: cc = opMovToRegFromReg(s, &s->reg.h, &s->reg.b); break;
        case 0x61: cc = opMovToRegFromReg(s, &s->reg.h, &s->reg.c); break;
        case 0x62: cc = opMovToRegFromReg(s, &s->reg.h, &s->reg.d); break;
        case 0x63: cc = opMovToRegFromReg(s, &s->reg.h, &s->reg.e); break;
        case 0x64: cc = opMovToRegFromReg(s, &s->reg.h, &s->reg.h); break;
        case 0x65: cc = opMovToRegFromReg(s, &s->reg.h, &s->reg.l); break;
        case 0x66: cc = opMovToRegFromMem(s, &s->reg.h); break;
        case 0x67: cc = opMovToRegFromReg(s, &s->reg.h, &s->reg.a); break;
        case 0x68: cc = opMovToRegFromReg(s, &s->reg.l, &s->reg.b); break;
        case 0x69: cc = opMovToRegFromReg(s, &s->reg.l, &s->reg.c); break;
        case 0x6a: cc = opMovToRegFromReg(s, &s->reg.l, &s->reg.d); break;
        case 0x6b: cc = opMovToRegFromReg(s, &s->reg.l, &s->reg.e); break;
        case 0x6c: cc = opMovToRegFromReg(s, &s->reg.l, &s->reg.h); break;
        case 0x6d: cc = opMovToRegFromReg(s, &s->reg.l, &s->reg.l); break;
        case 0x6e: cc = opMovToRegFromMem(s, &s->reg.l); break;
        case 0x6f: cc = opMovToRegFromReg(s, &s->reg.l, &s->reg.a); break;



        case 0x70: cc = opMovToMemFromReg(s, s->reg.b); break;
        case 0x71: cc = opMovToMemFromReg(s, s->reg.c); break;
        case 0x72: cc = opMovToMemFromReg(s, s->reg.d); break;
        case 0x73: cc = opMovToMemFromReg(s, s->reg.e); break;
        case 0x77: cc = opMovToMemFromReg(s, s->reg.a); break;
        case 0x78: cc = opMovToRegFromReg(s, &s->reg.a, &s->reg.b); break;
        case 0x79: cc = opMovToRegFromReg(s, &s->reg.a, &s->reg.c); break;
        case 0x7a: cc = opMovToRegFromReg(s, &s->reg.a, &s->reg.d); break;
        case 0x7b: cc = opMovToRegFromReg(s, &s->reg.a, &s->reg.e); break;
        case 0x7c: cc = opMovToRegFromReg(s, &s->reg.a, &s->reg.h); break;
        case 0x7d: cc = opMovToRegFromReg(s, &s->reg.a, &s->reg.l); break;
        case 0x7e: cc = opMovToRegFromMem(s, &s->reg.a); break;
        case 0x7f: cc = opMovToRegFromReg(s, &s->reg.a, &s->reg.a); break;

        case 0x80: cc = opAddReg(s, s->reg.b); break;
        case 0x81: cc = opAddReg(s, s->reg.c); break;
        case 0x82: cc = opAddReg(s, s->reg.d); break;
        case 0x83: cc = opAddReg(s, s->reg.e); break;
        case 0x84: cc = opAddReg(s, s->reg.h); break;
        case 0x85: cc = opAddReg(s, s->reg.l); break;
        case 0x86: cc = opAddMem(s); break;
        case 0x87: cc = opAddReg(s, s->reg.a); break;


        case 0x90: cc = opSubReg(s, s->reg.b); break;
        case 0x91: cc = opSubReg(s, s->reg.c); break;
        case 0x92: cc = opSubReg(s, s->reg.d); break;
        case 0x93: cc = opSubReg(s, s->reg.e); break;
        case 0x94: cc = opSubReg(s, s->reg.h); break;
        case 0x95: cc = opSubReg(s, s->reg.l); break;
        // case 0x96: cc = opSubReg(s, s->); break;



        case 0x97: cc = opSubReg(s, s->reg.a); break;

        case 0xa0: cc = opAnaReg(s, s->reg.b); break;
        case 0xa7: cc = opAnaReg(s, s->reg.a); break;
        case 0xaf: cc = opXraReg(s, s->reg.a); break;

        case 0xb0: cc = opOraReg(s, s->reg.b); break;
        case 0xb4: cc = opOraReg(s, s->reg.h); break;
        case 0xb8: cc = opCmpReg(s, s->reg.b); break;
        case 0xbe: cc = opCmpMem(s); break;

        case 0xc0: cc = opRnz(s); break;
        case 0xc1: cc = opPop(s, &s->reg.b, &s->reg.c); break;
        case 0xc2: cc = opJnz(s, code[1], code[2]); break;
        case 0xc3: cc = opJmp(s, code[1], code[2]); break;              // was in original implementation
        case 0xc4: cc = opCnz(s, code[1], code[2]); break;
        case 0xc5: cc = opPush(s, s->reg.b, s->reg.c); break;
        case 0xc6: cc = opAdi(s, code[1]); break;
        case 0xc8: cc = opRz(s); break;
        case 0xc9: cc = opRet(s); break;
        case 0xca: cc = opJz(s, code[1], code[2]); break;
        case 0xcc: cc = opCz(s, code[1], code[2]); break;
        case 0xcd: cc = opCall(s, code[1], code[2]); break;

        case 0xd0: cc = opRnc(s); break;
        case 0xd1: cc = opPop(s, &s->reg.d, &s->reg.e); break;
        case 0xd2: cc = opJnc(s, code[1], code[2]); break;
        case 0xd3: cc = opOut(s, code[1]);  break;                                  // TODO: not implemented
        case 0xda: cc = opJc(s, code[1], code[2]); break;
        case 0xdb: cc = opIn(s, code[1]);  break;                                   // TODO: not implemented
        case 0xd5: cc = opPush(s, s->reg.d, s->reg.e); break;
        case 0xd6: cc = opSui(s, code[1]); break;
        case 0xde: cc = opSbi(s, code[1]); break;

        case 0xe1: cc = opPop(s, &s->reg.h, &s->reg.l); break;
        case 0xe3: cc = opXthl(s); break;
        case 0xe5: cc = opPush(s, s->reg.h, s->reg.l); break;
        case 0xe9: cc = opPchl(s); break;
        case 0xe6: cc = opAni(s, code[1]); break;
        case 0xeb: cc = opXchg(s); break;

        case 0xf1: cc = opPopPsw(s); break;
        case 0xf5: cc = opPushPsw(s); break;
        case 0xf6: cc = opOri(s, code[1]); break;
        case 0xfa: cc = opJm(s, code[1], code[2]); break;
        case 0xfb: opEi(s); break;                                                  // TODO: not implemented
        case 0xfe: cc = opCpi(s, code[1]); break;
        case 0xff: cc = opRst(s, 7); break;

        default:
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  UNKNOWN: %02x\n", code[0]);
            s->pc += 2;
            return -1;
    }
    return cc;
}
