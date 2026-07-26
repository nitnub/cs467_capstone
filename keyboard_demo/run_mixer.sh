# type ' chmod +x run_mixer.sh ' if needed
gcc -Wall -Wextra -o keyboard_demo keyboard_demo.c controller_renamed.c audio_startup.c ../core/cpu.c ../core/opcodes.c ../core/handleSegment.c ../core/handler.c $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm -lpthread

./keyboard_demo fire_test.rom


