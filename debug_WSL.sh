# source file list
CORE_C="core/cpu.c core/handler.c core/handleSegment.c core/opcodes.c"
HELPERS_C="core/helpers/helpers.c"
VIDEO_C="hardware/video/*.c"
AUDIO_C="hardware/audio/audio.c"
SHIFT_C="hardware/shift_register/shiftRegister.c"
INTERRUPT_C="hardware/interrupts/interrupt.c"
CONTROLLER_C="hardware/controller/controller.c"
MENU_C="menu/menu.c"

# combine source file list
SOURCE_FILES="main.c $VIDEO_C $CORE_C $HELPERS_C $CONTROLLER_C $INTERRUPT_C $AUDIO_C $SHIFT_C $MENU_C"

# ignore GPU (to avoid slowdown)
export SDL_RENDER_DRIVER=software

# turn off VSYNC (to avoid slowdown)
__GL_SYNC_TO_VBLANK=0

# compile
gcc -g -Wall $SOURCE_FILES -o main -lSDL2 -lSDL2_mixer -lSDL2_ttf -lm -lpthread

# run
./main debug

# run with valgrind
#valgrind --leak-check=yes --show-reachable=yes --track-origins=yes -s ./main
