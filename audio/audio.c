#include "audio.h"

// audioFreeResources(): use in main.c, video owns exit
// sdlAudioCleanup(): also exits, for standalone harnesses

// Tracks the last value written to port 3, so we can detect the exact
// instant a sound bit turns on.
static uint8_t port3_prev = 0;

// same idea as port3_prev, but for port 5
static uint8_t port5_prev = 0;

// loads one chunk, reports which file failed
static int loadChunk(Mix_Chunk **dest, const char *path) {
    *dest = Mix_LoadWAV(path);
    if (!*dest) {
        fprintf(stderr, "Error loading %s: %s\n", path, Mix_GetError());
        return 1;
    }
    return 0;
}

int sdlAudioInit(Audio *audio) {
    if (Mix_OpenAudio(AUDIO_FREQUENCY, AUDIO_FORMAT, AUDIO_CHANNELS, AUDIO_CHUNKSIZE)) {
        fprintf(stderr, "Error opening audio device: %s\n", Mix_GetError());
        return 1;
    }

    // load the sound files
    if (loadChunk(&audio->shot_sound, SHOT_SOUND_PATH)) return 1;
    if (loadChunk(&audio->player_death_sound, PLAYER_DEATH_SOUND_PATH)) return 1;
    if (loadChunk(&audio->invader_death_sound, INVADER_DEATH_SOUND_PATH)) return 1;
    if (loadChunk(&audio->ufo_sound, UFO_SOUND_PATH)) return 1;
    if (loadChunk(&audio->ufo_hit_sound, UFO_HIT_SOUND_PATH)) return 1;
    if (loadChunk(&audio->fleet_step_sound[0], FLEET_STEP0_SOUND_PATH)) return 1;
    if (loadChunk(&audio->fleet_step_sound[1], FLEET_STEP1_SOUND_PATH)) return 1;
    if (loadChunk(&audio->fleet_step_sound[2], FLEET_STEP2_SOUND_PATH)) return 1;
    if (loadChunk(&audio->fleet_step_sound[3], FLEET_STEP3_SOUND_PATH)) return 1;

    // reset edge state so a reinit doesn't inherit a stale port value
    port3_prev = 0;
    port5_prev = 0;
    audio->ufo_channel = -1;

    return 0;
}

void audioFreeResources(Audio *audio) {
    // note this has to be in the reverse order of how things were initialized in sdlAudioInit
    Mix_FreeChunk(audio->fleet_step_sound[3]);
    Mix_FreeChunk(audio->fleet_step_sound[2]);
    Mix_FreeChunk(audio->fleet_step_sound[1]);
    Mix_FreeChunk(audio->fleet_step_sound[0]);
    Mix_FreeChunk(audio->ufo_hit_sound);
    Mix_FreeChunk(audio->ufo_sound);
    Mix_FreeChunk(audio->invader_death_sound);
    Mix_FreeChunk(audio->player_death_sound);
    Mix_FreeChunk(audio->shot_sound);
    Mix_CloseAudio();
}

void sdlAudioCleanup(Audio *audio, int exit_status) {
    audioFreeResources(audio);
    exit(exit_status);
}

void pollSound(state *cpuState, Audio *audio) {
    // Read the current value of port 3.
    // The CPU writes here whenever the ROM executes OUT #3
    const uint8_t value = getPort(cpuState, 3, OUT);

    // Full byte status of what just turned on: compare now vs a moment ago
    const uint8_t rising = value & ~port3_prev;

    // bits that just turned off, for the UFO's stop
    const uint8_t falling = port3_prev & ~value;

#ifdef AUDIO_DEBUG
    // compile with -DAUDIO_DEBUG to enable; this runs per-instruction,
    // so leaving it on will throttle the emulator badly
    if (value != port3_prev) {
        printf("port3: %02x -> %02x\n", port3_prev, value);
    }
#endif

    if (rising & SND_SHOT) {
        Mix_PlayChannel(-1, audio->shot_sound, 0);
    }

    if (rising & SND_PLAYER_DEATH) {
        Mix_PlayChannel(-1, audio->player_death_sound, 0);
    }

    if (rising & SND_INVADER_DEATH) {
        Mix_PlayChannel(-1, audio->invader_death_sound, 0);
    }

    // UFO loops while its bit is held, so -1 repeats and we keep the channel
    if (rising & SND_UFO) {
        audio->ufo_channel = Mix_PlayChannel(-1, audio->ufo_sound, -1);
    }

    // stop the loop once the ROM clears the bit
    if ((falling & SND_UFO) && audio->ufo_channel != -1) {
        Mix_HaltChannel(audio->ufo_channel);
        audio->ufo_channel = -1;
    }

    port3_prev = value;
}

// same as before, but for Port 5
void pollSoundPort5(state *cpuState, Audio *audio) {
    const uint8_t value = getPort(cpuState, 5, OUT);
    const uint8_t rising = value & ~port5_prev;

#ifdef AUDIO_DEBUG
    if (value != port5_prev) {
        printf("port5: %02x -> %02x\n", port5_prev, value);
    }
#endif

    // fleet steps and UFO hit are all one-shots, no looping needed
    if (rising & SND_FLEET_STEP0) Mix_PlayChannel(-1, audio->fleet_step_sound[0], 0);
    if (rising & SND_FLEET_STEP1) Mix_PlayChannel(-1, audio->fleet_step_sound[1], 0);
    if (rising & SND_FLEET_STEP2) Mix_PlayChannel(-1, audio->fleet_step_sound[2], 0);
    if (rising & SND_FLEET_STEP3) Mix_PlayChannel(-1, audio->fleet_step_sound[3], 0);
    if (rising & SND_UFO_HIT)     Mix_PlayChannel(-1, audio->ufo_hit_sound, 0);

    port5_prev = value;
}

void soundHook(state *cpuState, void *userdata) {
    Audio *audio = (Audio *)userdata;
    pollSound(cpuState, audio); //TODO: make it PollSoundPort3
    pollSoundPort5(cpuState, audio);
}
