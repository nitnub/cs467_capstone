#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "../../core/cpu.h"
#include "../../helpers/helpers.h"
#include "../../video/video.h"
#include "../../video/windowManager_temp.h"
#include "../../interrupts/interrupt.h"



int main(void) {

    ////////////////////////
    // Set Up Application //
    ////////////////////////

    // initialize a media bucket item to hold all of our SDL2 structs; can be passed to
    // constructor/destructor to centralize our SDL2 init and tear down.
    Media_t *mediaBucket = initMedia();

    // try to initialize video module
    if (sdlVideoInit(mediaBucket)) {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }

    // setup video interrupt timing
    // struct timeval *lastTime = NULL;
    // long lastUpdate = gettimeofday(lastTime, NULL); // used for timer approach to sending video interrupts
    int vidInterrupt = 1;



    // get file
    char romName[] = "../invaders.combined";

    // load rom to a new CPU state struct
    static state cpuState; // static so this ~65KB struct doesn't sit on the stack.
    loadRomToMemory(&cpuState,romName);




    // setup ports needed?
    cpuState.inp[0] = INITIAL_PORT0;
    cpuState.inp[1] = INITIAL_PORT1;
    cpuState.inp[2] = INITIAL_PORT2;

    cpuState.outp[0] = INITIAL_PORT0;
    cpuState.outp[1] = INITIAL_PORT1;
    cpuState.outp[2] = INITIAL_PORT2;




    ///////////////////////
    // Main Program Loop //
    ///////////////////////

    // simulate game loop... temp for now
    int done = 0;
    setInterruptStatus(&cpuState, 1);

    while (!done) {

        // advance the CPU state per frame allowance
        // remove the while() wrapper if using timer approach for video interrupt
        int cycles = 0;
        while (cycles <= CYCLES_PER_FRAME) {
            cycles += stepCPU(&cpuState);

            // check sound here?
            // ...
            // poll_sound(&cpuState);  
        }


        // check for user inputs (filler for now so that we can close the window)
        done = readControls(&cpuState);

        setInterruptStatus(&cpuState, 1);
        // for timer approach w/video interrupt...
        // if (sendVideoInterrupt(&cpuState, &lastUpdate)) {

            // if interrupts are enabled...
            if (getInterruptStatus(&cpuState) == 1) {

                // push program counter to the stack
                stackPushFromRegister(&cpuState, PC);



                // alternate between vidInterrupt ports 1 and 2
                unsigned char priorPort = getPort(&cpuState, vidInterrupt, IN);

                if (vidInterrupt == 1) {
                    // clear sister bit
                    // setPort(&cpuState,vidInterrupt, IN, priorPort & ~0x8);
                    setPort(&cpuState,vidInterrupt, IN, priorPort | 0x10);
                } else {
                    // clear sister bit
                    // setPort(&cpuState,vidInterrupt, IN, priorPort & ~010);
                    setPort(&cpuState,vidInterrupt, IN, priorPort | 0x08);
                }
                // set the pc for interrupt
                setReg16(&cpuState, PC, 8 * vidInterrupt);

                // flip vidInterrupt between 1 and 2
                vidInterrupt = 1 + vidInterrupt % 2;

                // disable interrupts while video update happening
                setInterruptStatus(&cpuState, 0);


                // draw video memory to the screen
                drawScreen(&cpuState, mediaBucket);
            }
        // }  // uncomment for sendVideoInterrupt() timing loop layer approach
    }



    ///////////
    // debug //
    ///////////

    // printAllMemoryAddresses(&cpuState);
    // printVideoMemoryDeclaration(&cpuState);


    ///////////////////////////
    // Tear Down Application //
    ///////////////////////////

    sdlVideoCleanup(mediaBucket, EXIT_SUCCESS);
    printf("\nShutting down...\n");
    return 0;
}
