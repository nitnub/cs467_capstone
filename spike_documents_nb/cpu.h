#ifndef CPU_H
#define CPU_H

#include <stddef.h>
#include <stdint.h>

#define MEM_SIZE 65536

#define MEM_START 0x00
#define MEM_RAM_START 0x2000
#define MEM_VIDEO_START 0x2400
#define MEM_RAM_MIRROR_START 0x4000
#define MEM_END 0x10000

// current memory struct layout follows pattern from the emulator101 resource for now
typedef struct {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
} main_r;

typedef struct {
    uint8_t s;                          // sign flag
    uint8_t z;                          // zero flag
    uint8_t ac;                         // auxiliary carry flag
    uint8_t p;                          // parity flag
    uint8_t c;                          // carry flag
} status_r;

typedef struct {
    main_r reg;                         // registers
    status_r flags;                     // cpu flags
    uint16_t pc;                        // program counter
    uint16_t sp;                        // stack pointer
    unsigned char memory[MEM_SIZE];     // memory
} state;




int loadRomToMemory(state *s, char fileName[]);

/**
 * Move the given file's contents to a usable buffer. Must be freed.
 * @param fileName name of the file to be parsed
 * @param fSize memory address of size_t variable to store buffer length
 * @return reference to newly populated buffer (must be freed)
 */
unsigned char *getFileBuffer(char fileName[], size_t *fSize);

/**
 * Copy the contents of the given buffer to the given state object. Will overwrite the memory
 * contents of the state object through the length specified in bufferLen.
 * @param bufferLen size of the buffer to be copied
 * @param buffer reference to the buffer to be copied
 * @param s reference to the state whose memory the buffer will be copied to
 * @return
 */
int copyBufferToMemory(const size_t bufferLen, const unsigned char *buffer, state *s);

/**
 * Simulate the operation of the Intel 8080 using a state value with populated memory.
 * @param s reference to aa cpu state object
 * @return clock cycles (PLACEHOLDER VALUE FOR NOW)
 */
int emulate( state *s);

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
int prinVideoMemoryAddresses(const state *s);

/**
 * Print a custom memory address range from the given state struct.
 * @param s reference to an Intel 8080 state struct
 * @param min the min memory address to print
 * @param max one greater than the final memory address to print
 * @return 0 on succewss
 */
int printMemoryAddresses(const state *s, const int min, const int max);

/**
 * Print the current cpu state in a human-readable format.
 * @param s reference to an Intel 8080 state struct
 * @return 0 on success
 */
void printState(const state *s);
#endif //CPU_H
