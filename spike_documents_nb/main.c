#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "cpu.h"
#include "disassembler.h"



// temporarily rename to "main1" to avoid conflicts; change back if testing these spike files...
int main1() {
    state cpu_state = {};

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

    // copy file buffer from ROM to computer's memory...
    size_t fSize;
    unsigned char * buffer = getFileBuffer(fileName, &fSize );

    if (buffer == NULL) {
        return EXIT_FAILURE;
    }

    copyBufferToMemory(fSize, buffer, &cpu_state);


    // Uncomment to print initial emulator memory state (can call func elsewhere as well)
    // return printMemoryAddresses(&cpu_state);

    // Uncomment to print initial emulator cpu state (can call func elsewhere as well)
    // printState(&cpu_state);


    // endless "done" loop as simple placeholder for now
    // can set a range conditional for "done" to force loop to end and then print state / memory
    int done = 0;
    while (!done) {
        if (emulate(&cpu_state) == -1) {
            free(buffer);
            return EXIT_FAILURE;
        }
    }

    // free buffer
    free(buffer);
    return EXIT_SUCCESS;
}
