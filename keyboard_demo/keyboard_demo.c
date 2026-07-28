/*
 * keyboard_demo.c -- adds real keypress detection to the controller.
 *
 * Flow:
 *   SDL key event -> setClearBit() on the controller's port array
 *                 -> copied into cpuState.inp[]
 *                 -> ROM's IN instruction reads it
 *
 * Build:
 *   gcc -Wall -Wextra -o keyboard_demo keyboard_demo.c controller_renamed.c \
 *       audio_startup.c ../core/cpu.c ../core/opcodes.c ../core/handleSegment.c ../core/handler.c \
 *       $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm -lpthread
 *
 * Run:
 *   ./keyboard_demo [ROM_file]
 *
 * Controls: C=coin  1=1P start  2=2P start
 *           SPACE=fire  LEFT/RIGHT=move  T=tilt  ESC=quit
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "audio_startup.h"
#include "../core/handler.h"
#include "controller_renamed.h"

static uint8_t port3_prev = 0;

// The controller module's own port array.
// Separate from cpuState.inp[] - synced over in sync_input_ports()

static uint8_t controllerPorts[3];

// one key = one bit; setClearBit so other held keys aren't disturbed
static void handle_key(SDL_Keycode key, uint8_t pressed)
{
    switch (key)
    {
        case SDLK_c:      setClearBit(controllerPorts, 1, COIN,       pressed); break;
        case SDLK_1:      setClearBit(controllerPorts, 1, ONEP_START, pressed); break;
        case SDLK_2:      setClearBit(controllerPorts, 1, TWOP_START, pressed); break;
        case SDLK_SPACE:  setClearBit(controllerPorts, 1, ONEP_FIRES, pressed); break;
        case SDLK_LEFT:   setClearBit(controllerPorts, 1, ONEP_LEFT,  pressed); break;
        case SDLK_RIGHT:  setClearBit(controllerPorts, 1, ONEP_RIGHT, pressed); break;
        case SDLK_t:      setClearBit(controllerPorts, 2, TILT,       pressed); break;
        default: break;
    }
}

// polls SDL events, updates controllerPorts; 0 = quit requested, 1 = keep running
static int poll_keyboard(void)
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
        {
            return 0;
        }
        else if (e.type == SDL_KEYDOWN)
        {
            if (e.key.keysym.sym == SDLK_ESCAPE) return 0;

            // no auto-repeat (old habit from live electronic music) - bit's set already
            if (!e.key.repeat) handle_key(e.key.keysym.sym, 1);
        }
        else if (e.type == SDL_KEYUP)
        {
            handle_key(e.key.keysym.sym, 0);
        }
    }
    return 1;
}


// pushes controllerPorts into cpuState.inp[] -- once/frame, not per-instr
static void sync_input_ports(state *cpuState)
{
    //controller state, within CPU port
    setPort(cpuState, 1, IN, getControllerPort(controllerPorts, 1));
    setPort(cpuState, 2, IN, getControllerPort(controllerPorts, 2));
}

// For audio triggering demo
static void poll_sound(state *cpuState, Audio *audio)
{
    // Read the current value of port 3.
    uint8_t value = getPort(cpuState, 3, OUT); //needs to be CPU's getPort
    
    // Full byte status of what just turned on, compare now vs a moment ago
    uint8_t rising = value & ~port3_prev;

    if (rising & 0x02) // check for this particular bit (bit 1 = shot)
    {
        printf("  -> shot fired, playing shoot.wav\n");
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

    // need a window for SDL to send key events at all - just for this demo
    SDL_Window *window = SDL_CreateWindow("SI sound trigger test",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          320, 256, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        sdlAudioCleanup(&audio, EXIT_FAILURE);
    }

    // Read the toy ROM from disk.
    static state cpuState;
    memset(&cpuState, 0, sizeof(cpuState));

    // Set the controller's default port values once at startup
    initializeControl(controllerPorts);

    FILE *f = fopen(argv[1], "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        SDL_DestroyWindow(window);
        sdlAudioCleanup(&audio, EXIT_FAILURE);
    }
    long n = (long)fread(cpuState.memory, 1, MEM_SIZE, f);
    fclose(f);
    if (n == 0)
    {
        fprintf(stderr, "%s: read 0 bytes\n", argv[1]);
        SDL_DestroyWindow(window);
        sdlAudioCleanup(&audio, EXIT_FAILURE);
    }
    printf("Loaded %s (%ld bytes)\n", argv[1], n);
    printf("Controls: C=coin  1/2=start  SPACE=fire  LEFT/RIGHT=move  T=tilt  ESC=quit\n\n");

    setReg16(&cpuState, PC, 0x0000);
    setReg16(&cpuState, SP, 0x2400);
    
    // 3000 is a rough stand-in for half a frame of 60Hz frame's worth of CPU work
    const long INSTRUCTIONS_PER_HALF_FRAME = 3000;
    int running = 1;

    while (running)
    {
        // Poll input once per frame
        running = poll_keyboard();
        sync_input_ports(&cpuState);

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
                SDL_DestroyWindow(window);
                sdlAudioCleanup(&audio, EXIT_FAILURE);
            }
            // if PC is still where it was before dispatch ran, advance past this instruction    
            uint16_t pc_after_dispatch = getReg16(&cpuState, PC);
            if (pc_after_dispatch == pc)
            {
                setReg16(&cpuState, PC, pc + 1 + numOperands);
            }

            poll_sound(&cpuState, &audio);
        }

        SDL_Delay(8);
    }

    SDL_DestroyWindow(window);
    sdlAudioCleanup(&audio, EXIT_SUCCESS);
}
