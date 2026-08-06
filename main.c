#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "core/cpu.h"
#include "helpers/helpers.h"
#include "video/video.h"
#include "video/windowManager_temp.h"
#include "interrupts/interrupt.h"
#include "controller/controller.h"
#include "menu/menu.h"

struct instructionData ins;
struct instructionData dis;
state myCpu;
state disCpu;

/*
* setup CPU for testing
*/
int setupCPU(process_r *cpu) {
    cpu->interruptBuffer = (uint8_t) 0x00;
    cpu->interruptEnabled = (uint8_t) 0x01; // start with interrupts enabled
    cpu->interruptReady = (uint8_t) 0x00;

    return 0;
}

/*
*   setup game for testing
*/
int setupMemory(state *processor, int start) {
    // clear memory
    memset(processor->memory, 0, MEM_SIZE);

    // load game ROM into memory
    char romName[] = "./invaders.combined";
    loadRomToMemory(processor, romName);

    // point to first instruction
    processor->currentOp.currentOpcode = start;

    return 0;
}


/*
*   Test processor loop with interrupts enabled
*/
int setupEmulator(struct instructionData *currentIns, Media_t *mediaBucket) {
    if (sdlVideoInit(mediaBucket)) {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }
    setupMemory(currentIns->s, 0x00);
    setupCPU(&currentIns->s->currentOp);

    currentIns->s->currentOp.interruptEnabled = 0x01;
    initializeControl(currentIns->s->inp);

    return 0;
}


int main(void) {
    ////////////////////////
    // Set Up Application //
    ////////////////////////

    // initialize a media bucket item to hold all of our SDL2 structs; can be passed to
    // shared constructor/destructor funcs to centralize our SDL2 init and tear down.
    Media_t *mediaBucket = initMedia();
    ins.s = &myCpu;
    setupEmulator(&ins, mediaBucket);


    ////////////////////////
    // Main Emulator Loop //
    ////////////////////////

    if (mainMenu(mediaBucket) == MENU_SELECTION_QUIT) {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
        printf("Thank you for playing!");
        return 0;
    }

    SDL_SetWindowTitle(mediaBucket->window, "Space Invaders");


    // run game loop...
    runIntel8080(&ins, mediaBucket);


    ///////////////////////////
    // Tear Down Application //
    ///////////////////////////

    // more to add to a shared cleanup function? Can combine audio in mediaBucket..
    sdlVideoCleanup(mediaBucket, EXIT_SUCCESS);
    printf("\nShutting down...\n");
    return 0;
}
