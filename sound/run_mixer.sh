# type ' chmod +x run_diss.sh ' if needed
gcc -Wall -Wextra -o simple simple_mixer.c $(pkg-config --cflags --libs sdl2 SDL2_mixer) -lm
 
./simple sound_test.rom
