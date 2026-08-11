

#ifndef HELPERS_H
#define HELPERS_H

#include "../cpu.h"
#include "../handler.h"
/**
 * Print the current memory state in a human-readable format.
 * @param s reference to an Intel 8080 state struct
 * @return 0 on success
 */
int printAllMemoryAddresses(const state *s);

/**
 * Print the ROM section of the given state struct's memory array.
 * @param s reference to an Intel 8080 state struct
 * @return 0 on success
 */
int printRomAddresses(const state *s);

/**
 * Print the RAM section of the given state struct's memory array.
 * @param s reference to an Intel 8080 state struct
 * @return 0 on success
 */
int printRamAddresses(const state *s);

/**
 * Print the Video section of the given state struct's memory array.
 * @param s reference to an Intel 8080 state struct
 * @return 0 on success
 */
int printVideoMemoryAddresses(const state *s);

/**
 * Print a custom memory address range from the given state struct.
 * @param s reference to an Intel 8080 state struct
 * @param min the min memory address to print
 * @param max one greater than the final memory address to print
 * @return 0 on succewss
 */
int printMemoryAddresses(const state *s, const int min, const int max);


/**
 * Load the given valid ROM file into the CPU state's memory.
 * @param cpuState pointer to the current program cpu state
 * @param romName name of the source program's ROM file
 * @return 0 on success, otherwise returns 1
 */
int loadRomToMemory(state *cpuState, char romName[]);

/**
 * Increment the current program counter value by the given instruction size.
 * @param cpuState pointer to the current program's CPU state
 * @param instructionSize the size, in bytes, of the current instruction
 * @return the next program counter value after incrementing
 */
uint16_t stepPC(state *cpuState, int instructionSize);

/**
 * Get the given state struct's current program counter value.
 * @param cpuState pointer to the current program's CPU state
 * @return The current program counter value
 */
uint16_t getPC(state *cpuState);

/**
 * Advance the CPU state by one program instruction.
 * @param cpuState pointer to the current program's CPU state
 * @return the updated program counter location
 */
uint16_t stepCPU(state *cpuState);
// uint16_t stepCPU(state *cpuState,  struct instructionData *insData); // needed?


#endif //HELPERS_H
