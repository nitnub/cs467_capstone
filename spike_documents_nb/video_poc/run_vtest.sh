# -lSDL2 needs to be last
gcc -g -Wall main_v.c video_startup.c -o main -lSDL2

./main
#valgrind --leak-check=yes --show-reachable=yes --track-origins=yes -s ./main
