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

// all sounds
#define SHOT_SOUND_PATH "audio/si_sounds/shoot.wav"
#define PLAYER_DEATH_SOUND_PATH "audio/si_sounds/explosion.wav"
#define INVADER_DEATH_SOUND_PATH "audio/si_sounds/invaderkilled.wav"
#define UFO_SOUND_PATH "audio/si_sounds/ufo_highpitch.wav"
#define UFO_HIT_SOUND_PATH "audio/si_sounds/ufo_lowpitch.wav"
// quick&dirty fix: order changed so that it starts with the highest tone
#define FLEET_STEP0_SOUND_PATH "audio/si_sounds/fastinvader3.wav"
#define FLEET_STEP1_SOUND_PATH "audio/si_sounds/fastinvader0.wav"
#define FLEET_STEP2_SOUND_PATH "audio/si_sounds/fastinvader1.wav"
#define FLEET_STEP3_SOUND_PATH "audio/si_sounds/fastinvader2.wav"

// port 3 bit assignments
#define SND_UFO 0x01
#define SND_SHOT 0x02
#define SND_PLAYER_DEATH 0x04
#define SND_INVADER_DEATH 0x08

// port 5 bit assignments
#define SND_FLEET_STEP0 0x01
#define SND_FLEET_STEP1 0x02
#define SND_FLEET_STEP2 0x04
#define SND_FLEET_STEP3 0x08
#define SND_UFO_HIT 0x10

typedef struct {
    Mix_Chunk *shot_sound;
    Mix_Chunk *player_death_sound;
    Mix_Chunk *invader_death_sound;
    Mix_Chunk *ufo_sound;
    int ufo_channel;   // -1 when not playing- since UFO sound is something continuous that appears when UFO shows up

    Mix_Chunk *ufo_hit_sound;
    Mix_Chunk *fleet_step_sound[4];
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

//TODO: make it PollSoundPort3
void pollSound(state *cpuState, Audio *audio);

/**
 * Check output port 5 for a rising edge on a sound bit and trigger playback.
 * All five bits here are one-shots, no looping.
 * @param cpuState
 * @param audio
 */
void pollSoundPort5(state *cpuState, Audio *audio);

/**
 * Adapter used to keep cpu_timing.c agnostic of the audio module.
 * Called after every instruction in run_half_frame.
 * Must be passed to run_half_frame as the hook parameter, and userdata must be an Audio*.
 * Polls both port 3 and port 5.
 * @param cpuState pointer to the current program's CPU state
 * @param userdata an Audio* passed through unchanged by run_half_frame
 */
void soundHook(state *cpuState, void *userdata);

#endif //AUDIO_H
