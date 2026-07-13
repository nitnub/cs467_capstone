#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "cpu.h"
#include "disassembler.h"



// temporarily rename to "main1" to avoid conflicts; change back if testing these spike files...
int main() {
    state cpuState = {};

    // update file name to point to valid ROM
    char fileName[] = "invaders.combined";

    /* **************
     * Print Assembly
     * **************/

    // uncomment to print assembly
    // return printAssembly(fileName);


    /* ******************
     * Run Emulator (PoC)
     * ******************/

    // copy file buffer from ROM to cpu struct's memory...            
    loadRomToMemory(&cpuState,fileName);

    // Uncomment to print initial emulator memory state (can call func elsewhere as well)
    // return printAllMemoryAddresses(&cpu_state);


    // Uncomment to print initial emulator ROM state (can call func elsewhere as well)
    // return printRomAddresses(&cpuState);
    
    // current cpu implementation gets to loop at address 1a32
    // can set a range to force loop to end and then print state / memory.
    int done = 0;
    while (done < 1000) {
        if (emulate(&cpuState) == -1) {
            return EXIT_FAILURE;
        }
        printState(&cpuState);
        done++;
    }

    // uncomment to print all memory or ROM memory range only at end of emulation loop 
    // return printAllMemoryAddresses(&cpuState);
    printRomAddresses(&cpuState);

    return EXIT_SUCCESS;
}
