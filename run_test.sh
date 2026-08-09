# source file list
CORE_C="core/cpu.c core/handler.c core/handleSegment.c core/opcodes.c"
HELPERS_C="helpers/helpers.c"
VIDEO_C="video/*.c"
AUDIO_C="audio/audio.c"
SHIFT_C="spike_documents_nb/shift_register/shiftRegister.c"
INTERRUPT_C="interrupts/interrupt.c"
MENU_C="menu/menu.c"
CONTROLLER_C="controller/controller.c"

# combine source file list
SOURCE_FILES="main.c $VIDEO_C $CORE_C $HELPERS_C $CONTROLLER_C $INTERRUPT_C $AUDIO_C $SHIFT_C $MENU_C"

# compile
gcc -g -Wall $SOURCE_FILES -o main -lSDL2 -lSDL2_mixer -lSDL2_ttf -lm -lpthread

# run
./main

# run with valgrind
#valgrind --leak-check=yes --show-reachable=yes --track-origins=yes -s ./main
