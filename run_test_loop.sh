# source file list
CORE_C="core/cpu.c core/handler.c core/handleSegment.c core/opcodes.c"
HELPERS_C=helpers/helpers.c
VIDEO_C=video/*.c

# combine source file list
SOURCE_FILES="main.c $VIDEO_C $CORE_C $HELPERS_C"

# compile
gcc -g -Wall $SOURCE_FILES -o main -lSDL2

# run
./main

# run with valgrind
#valgrind --leak-check=yes --show-reachable=yes --track-origins=yes -s ./main
