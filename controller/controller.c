#include "controller.h"

/* 
*   function: getPort
*   description: retrieves the port as an unsigned 8-bit integer
*
*   @param: ports, a pointer to the array of unsigned integer ports
*   @param: portNum, the index/number of the port we are interested in
*
*   @returns: 1-byte contents of the port in question as an unsigned integer
*/
uint8_t getControllerPort (uint8_t *ports, int portNum) {
    return ports[portNum];
}

/*
*   function: setPort
*   populates the ports array apporpriately based on the 
*   enumerated index for a command.
*
*   @param: a pointer to the array of ports
*   @param: command: an integer representing the command as enumerated 
*           under commands: [_COIN, _START2PLAYER, _START1PLAYER, 
*                            _FIRE1, _LEFT1, _RIGHT1,
*                            _FIRE2, _LEFT2, _RIGHT2, _TILT]
*
*           [note: the underscore denotes this is our arbitrary command
*           number rather than something baked into space invaders] 
*/
int setControllerPort (uint8_t *ports, int command) {

    initializeControl(ports);

    switch(command) {

        case _COIN: coin(ports); break;
        case _START2PLAYER: p2_start(ports); break;
        case _START1PLAYER: p1_start(ports); break;
        case _FIRE1: p1_fires(ports); break;
        case _LEFT1: p1_left(ports); break; //coin?
        case _RIGHT1: p1_right(ports); break;
        case _FIRE2: p2_fires(ports); break;
        case _LEFT2: p2_left(ports); break;
        case _RIGHT2: p2_right(ports); break;
        case _TILT: tilt(ports); break;

    }

    return 0;
}


/*
*   function: initializeControl
*   sets ports to the default values, including game configuration bits
*/
int initializeControl(uint8_t *ports) {
    ports[0] = INITIAL_PORT0;
    ports[1] = INITIAL_PORT1;
    ports[2] = INITIAL_PORT2;
    return 0;
}

/*
*   function: sets or clears a specific bit (by number 0-7) in a given port
*
*   @param: ports -- a pointer to the array of ports
*   @param: portNum -- an integer index representing the port number
*   @param: bitNum -- the index / number of the bit that should be set or cleared
*   @param: setOrClear -- an unsigned 8-bit integer representing a boolean value.
*                         0 indicates to clear, nonzero indicates to set
*/
int setClearBit(uint8_t *ports, int portNum, uint8_t bitNum, uint8_t setOrClear) {

    // restrict setOrClear to 0 and 1
    setOrClear = (setOrClear != 0); 

    // mask out the byte except for bit in question
    uint8_t mask = ~(1 << bitNum);

    // set or clear the bit in question
    uint8_t newBit = 0xFF & (setOrClear << bitNum);
    ports[portNum] = (ports[portNum] & mask) | newBit;

    return 0;
}

/* wrapper function for the "coin" command */
void coin (uint8_t *ports) {
    setClearBit(ports, 1, COIN, 1);
}

/* wrapper function for the "one player start" */
void p1_start (uint8_t *ports) {
    setClearBit(ports, 1, ONEP_START, 1);
}

/* wrapper function for the "two player start" */
void p2_start (uint8_t *ports) {
    setClearBit(ports, 1, TWOP_START, 1);
}

/* wrapper function for the "player one fires "*/
void p1_fires (uint8_t *ports) {
    setClearBit(ports, 1, ONEP_FIRES, 1);
}

/* wrapper function for "player one left "*/
void p1_left (uint8_t *ports) {
    setClearBit(ports, 1, ONEP_LEFT, 1); 
}

/* wrapper function for "player one right" */
void p1_right (uint8_t *ports) {
    setClearBit(ports, 1, ONEP_RIGHT, 1);
}

/* wrapper function for "tilt "*/
void tilt (uint8_t *ports) {
    setClearBit(ports, 2, TILT, 1);
}

/* wrapper function for "player two fires" */
void p2_fires (uint8_t *ports) {
    setClearBit(ports, 2, TWOP_FIRES, 1);
}

/* wrapper function for "player 2 left" */
void p2_left (uint8_t *ports) {
    setClearBit(ports, 2, TWOP_LEFT, 1);
}

/* wrapper function for "player two right" */
void p2_right (uint8_t *ports) {
    setClearBit(ports, 2, TWOP_RIGHT, 1);
}
