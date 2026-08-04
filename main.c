#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#include "core/cpu.h"
#include "helpers/helpers.h"
#include "video/video.h"
#include "video/windowManager_temp.h"
#include "audio/audio.h"


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
    
    // video already called SDL_Init
    Audio audio = { .shot_sound = NULL };
    if (sdlAudioInit(&audio)) {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }

    // get file
    char romName[] = "./invaders.combined";

    // load rom to a new CPU state struct
    static state cpuState; // static so this ~65KB struct doesn't sit on the stack.
    loadRomToMemory(&cpuState,romName);




    ///////////////////////
    // Main Program Loop //
    ///////////////////////

    // simulate game loop... temp for now
    int done = 0;
    while (!done) {

        // advance the CPU state
        stepCPU(&cpuState);
        
        // per instruction poll sound
        pollSound(&cpuState, &audio);

        // check for user inputs (filler for now so that we can close the window)
        done = readControls(&cpuState);

        // draw video memory to the screen
        drawScreen(&cpuState, mediaBucket);
    }

    // debugging
    // printRomAddresses(&cpuState);
    // printVideoMemoryAddresses(&cpuState);



    ///////////////////////////
    // Tear Down Application //
    ///////////////////////////

    sdlVideoCleanup(mediaBucket, EXIT_SUCCESS);

    printf("\nShutting down...\n");
    return 0;
}
