# build
gcc -Wall -Wextra -o keyboard_demo \
    keyboard_demo.c ../controller/controller.c cpu_timing.c \
    ../audio/audio.c ../video/video.c \
    ../core/cpu.c ../core/opcodes.c ../core/handleSegment.c ../core/handler.c \
    ../interrupts/interrupt.c \
    ../spike_documents_nb/shift_register/shiftRegister.c \
    $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm -lpthread

# run from repo root
cd ..
./keyboard_demo/keyboard_demo invaders.combined
