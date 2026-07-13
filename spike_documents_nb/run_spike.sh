# simple run script
gcc -g -Wall -o spike main.c cpu.c disassembler.c
# ./spike
valgrind --leak-check=yes --show-reachable=yes --track-origins=yes -s ./spike
