#ifndef AUDIO_H
#define AUDIO_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "../core/cpu.h"

#define AUDIO_FREQUENCY 11025
#define AUDIO_FORMAT AUDIO_U8
#define AUDIO_CHANNELS 1
#define AUDIO_CHUNKSIZE 1024

#define SHOT_SOUND_PATH "audio/si_sounds/shoot.wav"
#define PLAYER_DEATH_SOUND_PATH "audio/si_sounds/explosion.wav"
#define INVADER_DEATH_SOUND_PATH "audio/si_sounds/invaderkilled.wav"
#define UFO_SOUND_PATH "audio/si_sounds/ufo_highpitch.wav"

// port 3 bit assignments
// TODO: ufo_lowpitch.wav (UFO death) is port 5 bit 4, not wired yet
#define SND_UFO 0x01
#define SND_SHOT 0x02
#define SND_PLAYER_DEATH 0x04
#define SND_INVADER_DEATH 0x08

typedef struct {
    Mix_Chunk *shot_sound;
    Mix_Chunk *player_death_sound;
    Mix_Chunk *invader_death_sound;
    Mix_Chunk *ufo_sound;
    int ufo_channel;   // -1 when not playing; tracks what to halt on falling edge
} Audio;

/**
 * Call to init the audio module.
 * @param audio the current game's audio data struct
 * @return 0 if no error, non-zero for error
 */
int sdlAudioInit(Audio *audio);

/**
 * Frees audio resources, no exit(). Video owns SDL_Quit.
 * @param audio the current game's audio data struct
 */
void audioFreeResources(Audio *audio);

/**
 * Never actually gets called since video owns the exit. This is here because main_a.c needs something to call exit() with.
 * @param audio
 * @param exit_status
 */
void sdlAudioCleanup(Audio *audio, int exit_status);

/**
 * Check output port 3 for a rising edge on a sound bit and trigger playback.
 * UFO also stops on the falling edge, since it loops while its bit is held.
 * @param cpuState
 * @param audio
 */
void pollSound(state *cpuState, Audio *audio);

/**
 * Adapter used to keep cpu_timing.c agnostic of the audio module.
 * Called after every instruction in run_half_frame.
 * Must be passed to run_half_frame as the hook parameter, and userdata must be an Audio*.
 * @param cpuState pointer to the current program's CPU state
 * @param userdata an Audio* passed through unchanged by run_half_frame
 */
void soundHook(state *cpuState, void *userdata);

#endif //AUDIO_H
