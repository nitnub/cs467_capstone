# source file list
CORE_C="core/cpu.c core/handler.c core/handleSegment.c core/opcodes.c"
HELPERS_C="core/helpers/helpers.c"
VIDEO_C="hardware/video/*.c"
AUDIO_C="hardware/audio/audio.c"
SHIFT_C="hardware/shift_register/shiftRegister.c"
INTERRUPT_C="hardware/interrupts/interrupt.c"
CONTROLLER_C="hardware/controller/controller.c hardware/controller/windowManager_temp.c"
MENU_C="menu/menu.c"

# combine source file list
SOURCE_FILES="main.c $VIDEO_C $CORE_C $HELPERS_C $CONTROLLER_C $INTERRUPT_C $AUDIO_C $SHIFT_C $MENU_C"

# compile
gcc -g -Wall $SOURCE_FILES -o main $(pkg-config --cflags --libs sdl2 SDL2_image SDL2_mixer SDL2_ttf)

# run
./main

