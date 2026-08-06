#!/bin/sh
set -e

# source file list
CORE_C="core/cpu.c core/handler.c core/handleSegment.c core/opcodes.c"
HELPERS_C=helpers/helpers.c
VIDEO_C="video/*.c"
AUDIO_C="audio/audio.c"
SHIFT_C="spike_documents_nb/shift_register/shiftRegister.c"
INTERRUPT_C="interrupts/interrupt.c"
CONTROLLER_C="controller/controller.c"

# combine source file list
SOURCE_FILES="main.c $VIDEO_C $CORE_C $HELPERS_C $CONTROLLER_C $INTERRUPT_C $AUDIO_C $SHIFT_C"

# build
gcc -Wall -Wextra $SOURCE_FILES -o main \
    $(pkg-config --cflags --libs sdl2 SDL2_mixer SDL2_ttf) -lm -lpthread

# run
./main invaders.combined

# run with valgrind
#valgrind --leak-check=yes --show-reachable=yes --track-origins=yes -s ./main invaders.combined
