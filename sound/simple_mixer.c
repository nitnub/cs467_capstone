/*
 * simple_mixer.c -- a small driver that runs an 8080 ROM through the
 * dispatcher and plays a sound effect when the ROM writes the shot bit
 * to port 3.
 *
 * Build:
 gcc -Wall -Wextra -o sound_test simple_mixer.c ../core/cpu.c ../core/opcodes.c ../core/handleSegment.c ../core/handler.c $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm -lpthread
 *
 * Run:
 *   ./simple [ROM_file]
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "../core/handler.h"   /* pulls in handleSegment.h -> opcodes.h -> cpu.h */

// Mix_Chunk is SDL_mixer's container for a fully loaded audio chunk
static Mix_Chunk *shot_sound = NULL;


// Needed a "switch mechanism" to hinder simultaneous triggers.
// Tracks the last value written to port 3, so we can detect the exact
// instant the sound turns on.
static uint8_t port3_prev = 0;

static void poll_sound(state *cpuState)
{
    // Read the current value of port 3.
    // The CPU writes here whenever the ROM executes OUT #3
    uint8_t value = getPort(cpuState, 3, OUT);
    
    // Full byte status of what just turned on, compare now vs a moment ago
    uint8_t rising = value & ~port3_prev;

    if (rising & 0x02) // check for this particular bit (bit 1 = shot)
    {
        printf("  -> bit 1 (shot) is set, playing shoot.wav\n");
        Mix_PlayChannel(-1, shot_sound, 0);
    }

    port3_prev = value;
}


int main(int argc, char **argv)
{
    // If init fails
    if (SDL_Init(SDL_INIT_AUDIO) != 0)
    {
        fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return 1;
    }
    // If Mix_OpenAudio fails
    if (Mix_OpenAudio(11025, AUDIO_U8, 1, 1024) != 0)
    {
        fprintf(stderr, "Mix_OpenAudio failed: %s\n", Mix_GetError());
        return 1;
    }

    // Load the sound file
    shot_sound = Mix_LoadWAV("si_sounds/shoot.wav");
    
    // If sound file fails to load
    if (shot_sound == NULL)
    {
        fprintf(stderr, "Could not load shoot.wav: %s\n", Mix_GetError());
        return 1;
    }
    printf("Loaded shoot.wav\n");


    // Read the toy ROM from disk.
    
    // state.memory is a plain embedded array (unsigned char[65536]), not
    // a separately-allocated pointer.
    static state cpuState; // static so this ~65KB struct doesn't sit on the stack.
    memset(&cpuState, 0, sizeof(cpuState));

    FILE *f = fopen(argv[1], "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        return 1;
    }
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s program.rom\n", argv[0]);
        return 1;
    }

    long n = (long)fread(cpuState.memory, 1, MEM_SIZE, f);
    fclose(f);
    if (n == 0)
    {
        fprintf(stderr, "%s: read 0 bytes\n", argv[1]);
        return 1;
    }
    printf("Loaded %s (%ld bytes)\n", argv[1], n);
    
    setReg16(&cpuState, PC, 0x0000);
    setReg16(&cpuState, SP, 0x2400);

    // 3000 is a rough stand-in for half a frame of 60Hz frame's worth of CPU work
    const long INSTRUCTIONS_PER_HALF_FRAME = 3000;

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

        // From Lia: dispatchLevel2 returns should return the number of operands 
        // that were used (0, 1, or 2).
        int numOperands = dispatchLevel2(&currentIns);
        if (numOperands < 0)
        {
            fprintf(stderr, "dispatch error at pc=0x%04x (opcode 0x%02x)\n",
                    pc, currentIns.instruction);
            break;
        }

        // Some instructions set PC as they execute. Only
        // apply the generic "skip past this instruction" advance if PC
        // is still where it was before dispatch ran. 
        uint16_t pc_after_dispatch = getReg16(&cpuState, PC);
        if (pc_after_dispatch == pc)
        {
            setReg16(&cpuState, PC, pc + 1 + numOperands);
        }

        poll_sound(&cpuState);
    }


    printf("Waiting for playback to finish...\n");
    SDL_Delay(500);

    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}


