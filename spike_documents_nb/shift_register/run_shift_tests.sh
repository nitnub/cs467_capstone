gcc shiftRegister.c test_shiftRegister.c -o tests
gcc -g -Wall test_shiftRegister.c  shiftRegister.c -o main
./tests
