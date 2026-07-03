#include <stdio.h>
#define REGISTERS 8
#define CATEGORIES 16

int decodeInstruction(int instruction);
int handleALUInstruction (int instruction, int* cycle_p);
int handleHaltInstruction (int instruction, int* cycle_p);
int handleHighInstructions (int instruction, int* cycle_p);
int handleLowInstructions (int instruction, int* cycle_p);
int handleMoveInstruction (int instruction, int* cycle_p);

typedef enum  {
    B,
    C,
    D,
    E,
    H,
    L,
    M, // stand-in for a location in memory
    A
} CPURegister;

char CPURegisters[] = {'B','C','D','E','H','L','M','A'};
char *ALUOps[] = {"ADD", "ADC", "SUB", "SBB", "ANA", "XRA", "ORA", "CMP"};
char *CPURegisterPairs[] = {"BC", "DE", "HL", "SP"};
char statusFlags[] = {'Z', 'C', 'P', 'S'}; 

/*
* NOTES ON OPCODES FOR THE INTEL 8080 CPU
*
*  -------- HEXADECIMAL RANGE:      0-3F -----------
*
*   16 BIT "REGISTER PAIRS" = [
*                                   0. BC
*                                   1. DE
*                                   2. HL
*                                   3. SP // stack pointer
*                             ]
*                                   = instruction / 16
*
*
*   CPU REGISTERS = [
*                           0. B
*                           1. C
*                           2. D
*                           3. E
*                           4. H
*                           5. L
*                           6. memory location at address in HL ("M")
*                           7. A
*                    ]
*                           = (instruction - 0x40) / 8
*
*   INSTRUCTION % 16 = 
*             0           NOP at 0x00 or undefined
*             1           load immediate (2 bytes) into register pair
*             2           store accumulator at address in register pair
*             3           increment value in register pair
*             4           increment value in high-order byte of register pair
*             5           decrement value in high-order byte of register pair
*             6           load immediate (1 byte) into high order register
*             7           rotate accumulator (various instructions)
*                               0. rotate left
*                               1. rotate left through carry bit
*                               2. decimal adjust accumulator
*                               3. set carry flag
*             8           undefined
*             9           double addition (HL += value in register pair)
*             A           load accumulator from address in register pair, various
*                               0. load accumulator from address in BC
*                               1. load accumulator from address in DE
*                               2. load registers H and L from memory 
*                                  (imm1: low memory address, imm2: high address)
*                               3. load accumulator directly from memory 
*                                  (N+1 low  address, N+2 high address)
*             B           decrement value in register pair
*             C           increment value in low-order byte of register pair
*             D           decrement value in low-order byte of register pair
*             E           load immediate (1 byte) into low order register
*             F           rotate accumulator (various instructions)
*                               0. rotate right
*                               1. rotate right through carry bit
*                               2. complement accumulator
*                               3. complement carry flag
*
*
*   ------- HEXADECIMAL RANGE:      40-7F -------------
*
*   CPU REGISTERS = [
*                           0. B
*                           1. C
*                           2. D
*                           3. E
*                           4. H
*                           5. L
*                           6. memory location at address in HL ("M")
*                           7. A
*                    ]
*                           = (instruction - 0x40) / 8
*
*   INSTRUCTION % 8 = 
*             0           move byte from register B to register or memory
*             1           move byte from register C into register or memory
*             2           move byte from register D into register or memory
*             3           move byte from register E into register or memory
*             4           move byte from register H into register or memory
*             5           move byte from register L into register or memory
*             6           move byte from memory location in HL into register 
*                           except 0X76 is "HLT"
*             7           move byte from register A into register or memory
*
*
*   ------- HEXADECIMAL RANGE:      80-BF -------------
*
*   ALU OPERATIONS = [
*                           0. addition (A += register)
*                           1. addition w/ carry (A += (register + carry))
*                           2. subtraction (A -= register)
*                           3. subtraction w/ carry (A -= (register + carry))
*                           4. logical AND (A &= register)
*                           5. logical XOR (A ^= register)
*                           6. logical OR (A ||= register)
*                           7. compare (A - register)
*                    ]
*                           = (instruction - 0x80) / 8
*
*
*   INSTRUCTION % 8 =
*             0           alu operation involving register B
*             1           alu operation involving register C
*             2           alu operation involving register D
*             3           alu operation involving register E
*             4           alu operation involving register H
*             5           alu operation involving register L
*             6           alu operation involving byte in memory at address in HL (M)
*             7           alu operation involving register A
*
*
*  -------- HEXADECIMAL RANGE:      C0-FF -----------
*
*
*   RELEVANT FLAG = [
*                           0. Zero (Z)
*                           1. Carry (C)
*                           2. Parity (P)
*                           3. Sign (S)
*                    ]
*                           = (instruction - 0xC0) / 16
*
*
*   INSTRUCTION % 16 = 
*             0           return if relevant flag is clear
*             1           pop from stack into register pair
*             2           jump if relevant flag is clear
*             3           various
*             4           call subroutine if relevant flag is clear
*             5           push register pair onto the stack
*             6           ALU operations w/ immediate value & accumulator
*             7           built in restart calls
*             8           return if relevant flag is set
*             9           various
*             A           jump if relevant flag is set
*             B           various
*             C           call subroutine if relevant flag is set
*             D           various
*             E           ALU operations w/ immediate value & accumulator
*             F           built in restart calls
*/