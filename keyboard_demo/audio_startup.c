#include "audio_startup.h"

int sdlAudioInit(Audio *audio) {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    if (Mix_OpenAudio(AUDIO_FREQUENCY, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_CHUNKSIZE)) {
        fprintf(stderr, "Error opening audio device: %s\n", Mix_GetError());
        return 1;
    }

    // load the sound file
    audio->shot_sound = Mix_LoadWAV(SHOT_SOUND_PATH);
    if (!audio->shot_sound) {
        fprintf(stderr, "Error loading %s: %s\n", SHOT_SOUND_PATH, Mix_GetError());
        return 1;
    }

    return 0;
}

void sdlAudioCleanup(Audio *audio, int exit_status) {
    // note this has to be in the reverse order of how things were initialized in sdlAudioInit
    Mix_FreeChunk(audio->shot_sound);
    Mix_CloseAudio();
    SDL_Quit();
    exit(exit_status);
}
