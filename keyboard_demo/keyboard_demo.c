/*
 * keyboard_demo.c - keypress detection + audio + video in one process.
 *
 * Flow:
 *   SDL key event -> setClearBit() on the controller's port array
 *                 -> copied into cpuState.inp[]
 *                 -> ROM's IN instruction reads it
 *
 * Video is here so the port 3 shot bit can be watched against what's
 * actually on screen (confirming the bit stays high while a laser shot
 * is going).
 *
 * Build (run from inside keyboard_demo/):
 *   gcc -Wall -Wextra -DAUDIO_DEBUG -o keyboard_demo \
 *       keyboard_demo.c ../controller/controller.c cpu_timing.c \
 *       ../audio/audio.c ../video/video.c \
 *       ../core/cpu.c ../core/opcodes.c ../core/handleSegment.c ../core/handler.c \
 *       ../interrupts/interrupt.c \
 *       ../spike_documents_nb/shift_register/shiftRegister.c \
 *       $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm -lpthread
 *
 * Run
 *   ./keyboard_demo/keyboard_demo invaders.combined
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

#include "../audio/audio.h"
#include "../video/video.h"
#include "../core/handler.h"
#include "../controller/controller.h"
#include "cpu_timing.h"

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

// polls SDL events, updates controllerPorts
// 0 = quit requested, 1 = keep running
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

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s program.rom\n", argv[0]);
        return 1;
    }

    // video first: sdlVideoInit() calls SDL_Init and makes the window,
    // and sdlVideoCleanup() owns SDL_Quit + exit
    Media_t *mediaBucket = initMedia();
    if (sdlVideoInit(mediaBucket))
    {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }

    Audio audio = { .shot_sound = NULL };
    if (sdlAudioInit(&audio))
    {
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }

    // Read the ROM from disk.
    static state cpuState;
    memset(&cpuState, 0, sizeof(cpuState));

    // Set the controller's default port values once at startup
    initializeControl(controllerPorts);

    FILE *f = fopen(argv[1], "rb");
    if (!f)
    {
        fprintf(stderr, "Could not open %s\n", argv[1]);
        audioFreeResources(&audio);
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }
    long n = (long)fread(cpuState.memory, 1, MEM_SIZE, f);
    fclose(f);
    if (n == 0)
    {
        fprintf(stderr, "%s: read 0 bytes\n", argv[1]);
        audioFreeResources(&audio);
        sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
    }
    printf("Loaded %s (%ld bytes)\n", argv[1], n);
    printf("Controls: C=coin  1/2=start  SPACE=fire  LEFT/RIGHT=move  T=tilt  ESC=quit\n\n");

    setReg16(&cpuState, PC, 0x0000);
    setReg16(&cpuState, SP, 0x2400);

    // alternates 1,2,1,2... - run_half_frame updates it for us
    int next_interrupt = 1;
    int running = 1;
    long halfFrames = 0;

    while (running)
    {
        // Poll input once per frame
        running = poll_keyboard();
        sync_input_ports(&cpuState);

        // runs a real half-frame's worth of 8080 cycles, then fires the next RST1/RST2 interrupt
        if (run_half_frame(&cpuState, &next_interrupt, soundHook, &audio) < 0)
        {
            audioFreeResources(&audio);
            sdlVideoCleanup(mediaBucket, EXIT_FAILURE);
        }

        // two half-frames per screen refresh, so draw on every other pass
        if (++halfFrames % 2 == 0)
        {
            drawScreen(&cpuState, mediaBucket);
        }

        SDL_Delay(8);
    }

    audioFreeResources(&audio);
    sdlVideoCleanup(mediaBucket, EXIT_SUCCESS);
}
