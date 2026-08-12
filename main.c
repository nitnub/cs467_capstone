#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "core/cpu.h"
#include "core/helpers/helpers.h"
#include "hardware/video/video.h"
#include "hardware/audio/audio.h"
// #include "hardware/video/windowManager_temp.h"
#include "hardware/interrupts/interrupt.h"
#include "hardware/controller/controller.h"
#include "menu/menu.h"

struct instructionData ins;
struct instructionData dis;
state myCpu;
state disCpu;

/*
* setup interrupts & processing structure within CPU
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
    char romName[] = "./game_files/invaders.combined";
    loadRomToMemory(processor, romName);

    // point to first instruction
    processor->currentOp.currentOpcode = start;
    
    // set name of game in the state structure
    processor->gameIndex = SPACE_INVADERS;

    return 0;
}


/*
*   Test processor loop with interrupts enabled
*/
int setupEmulator(struct instructionData *currentIns, Media_t *mediaBucket, Audio *audio) {
    if (sdlVideoInit(mediaBucket)) {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }
    if (sdlAudioInit(audio)) {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }
    setupMemory(currentIns->s, 0x00);
    setupCPU(&currentIns->s->currentOp);

    currentIns->s->currentOp.interruptEnabled = 0x01;
    initializeControl(currentIns->s->inp);

    return 0;
}


int main(int argc, char* argv[]) {
    ////////////////////////
    // Set Up Application //
    ////////////////////////

    // initialize a media bucket item to hold all of our SDL2 structs; can be passed to
    // shared constructor/destructor funcs to centralize our SDL2 init and tear down.
    Media_t *mediaBucket = initMedia();

    Audio audio = {0};

    ins.s = &myCpu;
    setupEmulator(&ins, mediaBucket, &audio);

    ///////////////////////
    // Debug status      //
    ///////////////////////

    int debug;
    struct instructionData *disassembler = NULL;
    if (argc < 2) {
        debug = 0;
    }
    else if (!strcmp(argv[1], "debug")) {
        debug = 1;
        
        // set up secondary CPU for disassembly
        disassembler = &dis;
        dis.s = &disCpu;
        setupMemory(&disCpu, 0x00);
        setupCPU(&disCpu.currentOp);
    }
    else {
        debug = 0;
    }

    ////////////////////////
    // Main Emulator Loop //
    ////////////////////////

    if (mainMenu(mediaBucket, &audio) == MENU_SELECTION_QUIT) {
        SDL_Delay(500);   // let the quit sound finish 
        sdlVideoCleanup(mediaBucket, EXIT_SUCCESS);
        printf(SAFE_SHUTDOWN_MESSAGE);
        return 0;
    }

    // update header
    SDL_SetWindowTitle(mediaBucket->window, WINDOW_TITLE_SPACE_INVADERS);

    // run game loop...
    runIntel8080(&ins, mediaBucket, &audio, debug, disassembler);


    ///////////////////////////
    // Tear Down Application //
    ///////////////////////////

    // audio owns only its own resources, video owns SDL_Quit + exit
    audioFreeResources(&audio);
    sdlVideoCleanup(mediaBucket, EXIT_SUCCESS);
    printf(SAFE_SHUTDOWN_MESSAGE);
    return 0;
}
