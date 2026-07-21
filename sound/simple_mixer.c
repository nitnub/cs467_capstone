/*
 simple_mixer.c -- a small driver that pairs with cpu.c.
 *
 * Build:
 *   gcc -Wall -Wextra -o simple simple_mixer.c \
 *       $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm
 *
 * Run:
 *   ./simple [ROM_file]
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "cpu.c"

// Mix_Chunk is SDL_mixer's internal format for an audio chunk
static Mix_Chunk *shot_sound = NULL;

// The entire hook
// Needed a "switch mechanism" to hinder simultaneous triggers.
// the first write where bit 1 goes from 0->1, and silence on 
// every repeat until it actually drops back to 0
static uint8_t port3_prev = 0;

static void handle_out(uint8_t port, uint8_t value)
{
    if (port == 3)
    {
        uint8_t rising = value & ~port3_prev;
        if (rising & 0x02)
        {
            printf("  -> bit 1 (shot) is set, playing shoot.wav\n");
            Mix_PlayChannel(-1, shot_sound, 0);
        }
        port3_prev = value;
    }
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

    shot_sound = Mix_LoadWAV("shoot.wav");
    
    // If sound file fails to load
    if (shot_sound == NULL)
    {
        fprintf(stderr, "Could not load shoot.wav: %s\n", Mix_GetError());
        return 1;
    }
    printf("Loaded shoot.wav\n");

    // Read the toy ROM from disk.
    uint8_t *memory = calloc(1, 0x10000);  // 64K of memory
    if (!memory) { fprintf(stderr, "allocation failed\n"); return 1; }
    
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

    long n = (long)fread(memory, 1, 0x2000, f); 
    fclose(f);
    if (n == 0)
    {
        fprintf(stderr, "%s: read 0 bytes\n", argv[1]);
        return 1;
    }
    printf("Loaded %s (%ld bytes)\n", argv[1], n);
    

    // declaring & zeroing & assigning
    State8080 state;
    // it's safer to zero out the entire state
    // struct so that the uninitialized fields don't contain garbage.
    memset(&state, 0, sizeof(state));
    state.memory = memory;
    state.pc = 0x0000;
    state.sp = 0x2400;
    state.out_port = handle_out;
    
    // this will be handy later
    const long INSTRUCTIONS_PER_HALF_FRAME = 3000;

    for (long i = 0; i < INSTRUCTIONS_PER_HALF_FRAME; i++)
    {
        Emulate8080(&state);
    }
    SDL_Delay(500);

    Mix_CloseAudio();
    SDL_Quit();
    free(memory);
    return 0;
}


