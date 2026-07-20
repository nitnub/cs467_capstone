#ifndef CPU_H
#define CPU_H

#include <stddef.h>
#include <stdint.h>
#include <pthread.h>
#include <stdio.h>

#define MEM_SIZE 65536

#define MEM_START 0x00
#define MEM_RAM_START 0x2000
#define MEM_VIDEO_START 0x2400
#define MEM_RAM_MIRROR_START 0x4000
#define MEM_END 0x8000
#define PORT_COUNT 0xFF

// shift constants used to convert between flags and PSW
#define ZERO_SHIFT 0x0E
#define CARRY_SHIFT 0x08
#define PARITY_SHIFT 0x0A
#define SIGN_SHIFT 0x0F
#define AUX_CARRY_SHIFT 0x0C

// enumeration utility for accessing 8-bit registers
enum registers8 {
    B,
    C,
    D,
    E,
    H,
    L,
    M,
    A,
    I
};

// enumeration utility for accessing 16-bit registers
// and register pair buffers for BC, DE, HL, and the PSW
enum registers16 {
    BC,
    DE,
    HL,
    SP,
    PC,
    PSW
};

enum flags {
    ZERO,
    CARRY,
    PARITY,
    SIGN,
    AUX_CARRY,
    NO_FLAG
};

typedef struct {
    uint8_t currentOpcode;              // current opocde 
    uint8_t interruptBuffer;            // buffer for interrupt input
    uint8_t interruptReady;             // boolean. Is an interrupt ready
} process_r;  

typedef struct {
    pthread_mutex_t enableInt;
    pthread_mutex_t cyclesAccess;
    int interruptInit;
    int shutdownCondition;
    uint64_t refresh_cycles;
} interrupt_r;

typedef struct {
    uint8_t regs8[9];                   // 8 bit registers: B, C, D, E, H, L, (memory buffer), A, (operand buffer) 
    uint16_t regs16[6];                 // 16 bit registers: BC buffer, DE buffer, HL buffer, SP, PC, PSW buffer
    uint8_t flags[5];                   // status flags: Z, C, P, S, AC
    interrupt_r interrupts;             // handle interrupts
    process_r currentOp;                // currentOp and pending interrupt vectors
    uint8_t outp[PORT_COUNT];           // output ports
    uint8_t inp[PORT_COUNT];            // input ports
    unsigned char memory[MEM_SIZE];     // memory
    pthread_mutex_t ioOutpLock;         // lock on output ports -- to avoid race conditions
    pthread_mutex_t ioInputLock;        // lock on input ports -- to avoid race conditions
} state;


/* register & flag getters */
uint8_t getReg8(state *currentState, int regIndex);
uint16_t getReg16(state *currentState, int regIndex);
uint8_t getFlag(state *currentState, int flagIndex);

/* register & flag setters */
int setReg8(state *currentState, int regIndex, uint8_t value);
int setReg16(state *currentState, int regPairIndex, uint16_t value);
int setFlag(state *currentState, int flagIndex, uint8_t value);

/* Conversion &  Utility functions */
uint16_t convert8To16(uint8_t high, uint8_t low);
uint8_t highFrom16Bit(uint16_t value);
uint8_t lowFrom16Bit(uint16_t value);
uint16_t flagsToPSW(state *currentState);
uint8_t PSWToFlag(int flagIndex, uint16_t value);
uint8_t complementFlag(uint8_t value);
uint8_t complementRegister(uint8_t value);

/* Memory fetch & store */
uint8_t memFetch(state *currentState, uint8_t high, uint8_t low);
uint16_t memMirror(uint16_t index);
int memStore(state *currentState, uint8_t high, uint8_t low, uint8_t value);

/* Stack pop and push */
int stackPushFromRegister (state *currentState, int regPairIndex);
int stackPushValues (state *currentState, uint8_t valueHigh, uint8_t valueLow);
int stackPopValues (state *currentState, int regPairIndex);

#endif 