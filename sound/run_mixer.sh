# type ' chmod +x run_diss.sh ' if needed
gcc -Wall -Wextra -o sound_test simple_mixer.c ../core/cpu.c ../core/opcodes.c ../core/handleSegment.c ../core/handler.c $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm -lpthread

./sound_test sound_test.rom
