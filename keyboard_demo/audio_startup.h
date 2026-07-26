#ifndef AUDIO_STARTUP_H
#define AUDIO_STARTUP_H
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#define AUDIO_FREQUENCY 11025
#define AUDIO_FORMAT AUDIO_U8
#define AUDIO_CHANNELS 1
#define AUDIO_CHUNKSIZE 1024

#define SHOT_SOUND_PATH "si_sounds/shoot.wav"

typedef struct {
    Mix_Chunk *shot_sound;
} Audio;

/**
 * Call to initialize the audio module.
 * @param audio the current game's audio data struct
 * @return 0 if no error; non-zero for error
 */
int sdlAudioInit(Audio *audio);

/**
 * Call to safely shut down the audio module.
 * @param audio the current game's audio data struct
 * @param exit_status status / error code to exit with
 */
void sdlAudioCleanup(Audio *audio, int exit_status);

#endif //AUDIO_STARTUP_H
