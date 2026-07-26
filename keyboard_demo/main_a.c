// SDL setup/teardown mirrors video_startup.h/.c for consistency

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "audio_startup.h"
#include "../core/handler.h"   /* pulls in handleSegment.h -> opcodes.h -> cpu.h */

// Needed a "switch mechanism" to hinder simultaneous triggers.
// Tracks the last value written to port 3, so we can detect the exact
// instant the sound turns on.
static uint8_t port3_prev = 0;

static void poll_sound(state *cpuState, Audio *audio)
{
    // Read the current value of port 3.
    // The CPU writes here whenever the ROM executes OUT #3
    uint8_t value = getPort(cpuState, 3, OUT);
    
    // Full byte status of what just turned on, compare now vs a moment ago
    uint8_t rising = value & ~port3_prev;

    if (rising & 0x02)  // check for this particular bit (bit 1 = shot)
    {
        printf("  -> bit 1 (shot) is set, playing shoot.wav\n");
        Mix_PlayChannel(-1, audio->shot_sound, 0);
    }

    port3_prev = value;
}

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

    // state.memory is a plain embedded array (unsigned char[65536]), not
    // a separately-allocated pointer. static so this ~65KB struct doesn't
    // sit on the stack.
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

    // 3000 is a rough stand-in for half a frame of 60Hz frame's worth of CPU work
    const long INSTRUCTIONS_PER_HALF_FRAME = 3000;

    // The boilerplate SDL loop
    // no window here though, so QUIT/ESCAPE below are dead until this
    // shares a process with the video module's window
    while (true) {
        // handle events
        // if any event types... follow the switch
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

        for (long i = 0; i < INSTRUCTIONS_PER_HALF_FRAME; i++)
        {
            // saving the current PC in local variable
            uint16_t pc = getReg16(&cpuState, PC);

            // Fetch the opcode and the two bytes that follow it.
            struct instructionData currentIns;
            // Clear the struct to avoid garbage values
            memset(&currentIns, 0, sizeof(currentIns));
            // Fetch the opcode byte at pc
            currentIns.instruction = cpuState.memory[pc];
            // Fetch the two bytes after the opcode (if any)
            currentIns.operand1 = cpuState.memory[(uint16_t)(pc + 1)];
            currentIns.operand2 = cpuState.memory[(uint16_t)(pc + 2)];
            currentIns.s = &cpuState;
            
            // From Lia: dispatchLevel2 should return the number of operands
            // that were used (0, 1, or 2).
            int numOperands = dispatchLevel2(&currentIns);
            if (numOperands < 0)
            {
                fprintf(stderr, "dispatch error at pc=0x%04x (opcode 0x%02x)\n",
                        pc, currentIns.instruction);
                sdlAudioCleanup(&audio, EXIT_FAILURE);
            }

            // Some instructions set PC themselves as they execute. Only apply
            // the generic "skip past this instruction" advance if PC is still
            // where it was before dispatch ran.
            uint16_t pc_after_dispatch = getReg16(&cpuState, PC);
            if (pc_after_dispatch == pc)
            {
                setReg16(&cpuState, PC, pc + 1 + numOperands);
            }

            poll_sound(&cpuState, &audio);
        }

        SDL_Delay(8);
    }
}
