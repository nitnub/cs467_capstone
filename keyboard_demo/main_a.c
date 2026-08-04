#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "../audio/audio.h"
#include "../core/handler.h"   /* pulls in handleSegment.h -> opcodes.h -> cpu.h */
#include "cpu_timing.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s program.rom\n", argv[0]);
        return 1;
    }
    
    Audio audio = { .shot_sound = NULL };
    
    if (sdlAudioInit(&audio))
    {
        sdlAudioCleanup(&audio, EXIT_FAILURE);
    }
    

    static state cpuState;
    memset(&cpuState, 0, sizeof(cpuState));
    
    FILE *f = fopen(argv[1], "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        sdlAudioCleanup(&audio, EXIT_FAILURE);
    }
    
    long n = (long)fread(cpuState.memory, 1, MEM_SIZE, f);
    fclose(f);
    if (n == 0)
    {
        fprintf(stderr, "%s: read 0 bytes\n", argv[1]);
        sdlAudioCleanup(&audio, EXIT_FAILURE);
    }
    printf("Loaded %s (%ld bytes)\n", argv[1], n);
    
    setReg16(&cpuState, PC, 0x0000);
    setReg16(&cpuState, SP, 0x2400);
    
    int next_interrupt = 1;   // alternates 1,2,1,2 - run_half_frame updates it
    

    // The boilerplate SDL loop
    while (true) {
        // handle events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    sdlAudioCleanup(&audio, EXIT_SUCCESS);
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            sdlAudioCleanup(&audio, EXIT_SUCCESS);
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        
        if (run_half_frame(&cpuState, &next_interrupt, soundHook, &audio) < 0)
        {
            sdlAudioCleanup(&audio, EXIT_FAILURE);
        }
        
        // debug: periodic status check
        extern long dbg_int_fired, dbg_int_dropped;
        static long frames = 0;
        if (++frames % 60 == 0)
            printf("fired=%ld dropped=%ld pc=%04x\n",
                   dbg_int_fired, dbg_int_dropped, getReg16(&cpuState, PC));
        
        SDL_Delay(8);
    }
}
