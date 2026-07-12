# type ' chmod +x run_diss.sh ' if needed
gcc -Wall -o disassemble8080 main.c disassemble8080.c
./disassemble8080 invaders.rom > invaders.asm
