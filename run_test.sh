set -e

# source file list
CORE_C="core/cpu.c core/handler.c core/handleSegment.c core/opcodes.c"
HELPERS_C=helpers/helpers.c
VIDEO_C=video/*.c
AUDIO_C=audio/*.c
SHIFT_C=spike_documents_nb/shift_register/shiftRegister.c
CONTROLLER_C=spike_documents_nb/video_demo/controller_renamed.c

# combine source file list
SOURCE_FILES="main.c $VIDEO_C $CORE_C $HELPERS_C $AUDIO_C $SHIFT_C $CONTROLLER_C"

# compile
gcc -g -Wall $SOURCE_FILES -o main $(pkg-config --cflags --libs sdl2 SDL2_mixer)

# run
./main

# run with valgrind
#valgrind --leak-check=yes --show-reachable=yes --track-origins=yes -s ./main
