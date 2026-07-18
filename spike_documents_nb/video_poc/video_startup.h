

#ifndef VIDEO_STARTUP_H
#define VIDEO_STARTUP_H
#include <SDL2/SDL_rect.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>


#define PIXEL_WIDTH 224
#define PIXEL_HEIGHT 256
#define SCREEN_WIDTH 940 // 800
#define SCREEN_HEIGHT 1272 // 600

#define HEX_SIZE 16
#define BYTE_SIZE 8
#define SET_BIT = 1
#define CLEAR_BIT = 0
// #define PIXEL_WIDTH 256
// #define PIXEL_HEIGHT 224
// #define SCREEN_WIDTH 672 //768 // 800
// #define SCREEN_HEIGHT 768 //672 // 600

// typedef struct {
//     SDL_Point white[681];
//     SDL_Point *green[681];
//     SDL_Point *red;
// } Points_t;

// struct Game {
//     SDL_Window *window;
//     SDL_Renderer *renderer;
//     SDL_Texture *texture;
//     // SDL_Point *points;
//     Points_t *pointsArray;
// };
typedef struct {
    int white;
    int green;
    int red;
} Point_Counter_t;

typedef struct {
    SDL_Point white[681];
    SDL_Point green[681];
    SDL_Point red[681];

    int wCount;
    int gCount;
    int rCount;
} Points_t;

struct Game {
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    // SDL_Point *points;
    Points_t pointsArray;
};




void printStartup();

// int getPointsArray(SDL_Point **points);
// SDL_Point *getPointsArray(int *pCount);

int getPointsArray(Points_t *points);
SDL_Point *getPointArrayTest();
#endif //VIDEO_STARTUP_H
