#ifndef CONTROLLER_RENAMED_H
#define CONTROLLER_RENAMED_H

#include <stdint.h>
#include <stdio.h>
#define INITIAL_PORT0 0x00
#define INITIAL_PORT1 0x88
#define INITIAL_PORT2 0x80


/* ***** OUR MAPPING ****** */

/* 
*   commands are numbers we can use to indicate 
*   and switch between incoming commands 
*/
enum commands {
    _COIN,
    _START2PLAYER,
    _START1PLAYER,
    _FIRE1,
    _LEFT1,
    _RIGHT1,
    _FIRE2,
    _LEFT2,
    _RIGHT2,
    _TILT
};

void coin (uint8_t *ports);
void p1_start (uint8_t *ports);
void p2_start (uint8_t *ports);
void p1_fires (uint8_t *ports);
void p1_left (uint8_t *ports);
void p1_right (uint8_t *ports);
void p2_fires (uint8_t *ports);
void p2_left (uint8_t *ports);
void p2_right (uint8_t *ports);
void tilt (uint8_t *ports);

uint8_t getControllerPort (uint8_t *ports, int portNum);
int setControllerPort (uint8_t *ports, int command);
int setClearBit(uint8_t *ports, int portNum, uint8_t bitNum, uint8_t setOrClear);
int initializeControl(uint8_t *ports);

/******* SPACE INVADERS MAPPING *******/

/* 
*   p1bits represents the bit number of each command
*   in the space invaders port 1 mapping
*/
enum p1bits {
    COIN,
    TWOP_START,
    ONEP_START,
    ONEP_FIRES = 4,
    ONEP_LEFT,
    ONEP_RIGHT
};

/*
*   p2bits represents the bit number of each command
*   in the space invaders port 2 mapping
*/
enum p2bits {
    TILT = 2,
    TWOP_FIRES = 4,
    TWOP_LEFT = 5,
    TWOP_RIGHT = 6
};

/*
*   ******* Outline of Input Ports 1 & 2 *******
*
*       *** PORT 0x01 ***
*       -- bit 0: coin/credit  
*       -- bit 1: two-player start
*       -- bit 2: one-player start
*       -- bit 3: (set)
*       -- bit 4: player one fires
*       -- bit 5: player one left
*       -- bit 6: player one right
*       -- bit 7: xx
*
*       *** PORT 0x02 ***
*       -- bit 0: (game configuration)
*       -- bit 1: (game configuration)
*       -- bit 2: tilt
*       -- bit 3: (game configuration)
*       -- bit 4: player two fires
*       -- bit 5: player two left
*       -- bit 6: player two right
*       -- bit 7: (game configuration: coin info on demo screen)
*/

#endif