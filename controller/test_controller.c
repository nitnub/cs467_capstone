#include <assert.h>
#include "controller.h"

/* 
*   test COIN command 
*       our enumeration: 0
*       port1
*       bit 0
*/
int test_01 (uint8_t *ports) {
    setControllerPort(ports, _COIN);
    assert(getControllerPort(ports, 1) == 0x89);
    return 0;
}

/* 
*   test TWO PLAYER START command 
*       our enumeration: 1
*       port1
*       bit 1
*/
int test_02 (uint8_t *ports) {
    setControllerPort(ports, _START2PLAYER);
    assert(getControllerPort(ports, 1) == 0x8A);
    return 0;
}

/* 
*   test ONE PLAYER START command 
*       our enumeration: 2
*       port1
*       bit 2
*/
int test_03 (uint8_t *ports) {
    setControllerPort(ports, _START1PLAYER);
    assert(getControllerPort(ports, 1) == 0x8C);
    return 0;
}

/* 
*   test FIRE (PLAYER 1) command 
*       our enumeration: 3
*       port1
*       bit 4
*/
int test_04 (uint8_t *ports) {
    setControllerPort(ports, _FIRE1);
    assert(getControllerPort(ports, 1) == 0x98);
    return 0;
}

/* 
*   test LEFT (PLAYER 1) command 
*       our enumeration: 4
*       port1
*       bit 5
*/
int test_05 (uint8_t *ports) {
    setControllerPort(ports, _LEFT1);
    assert(getControllerPort(ports, 1) == 0xA8);
    return 0;
}

/* 
*   test LEFT (PLAYER 1) command 
*       our enumeration: 5
*       port1
*       bit 6
*/
int test_06 (uint8_t *ports) {
    setControllerPort(ports, _RIGHT1);
    assert(getControllerPort(ports, 1) == 0xC8);
    return 0;
}

/* 
*   test FIRE (PLAYER 2) command 
*       our enumeration: 6
*       port2
*       bit 4
*/
int test_07 (uint8_t *ports) {
    setControllerPort(ports, _FIRE2);
    assert(getControllerPort(ports, 2) == 0x90);
    return 0;
}

/* 
*   test LEFT (PLAYER 2) command 
*       our enumeration: 7
*       port2
*       bit 5
*/
int test_08 (uint8_t *ports) {
    setControllerPort(ports, _LEFT2);
    assert(getControllerPort(ports, 2) == 0xA0);
    return 0;
}

/* 
*   test RIGHT (PLAYER 2) command 
*       our enumeration: 8
*       port2
*       bit 6
*/
int test_09 (uint8_t *ports) {
    setControllerPort(ports, _RIGHT2);
    assert(getControllerPort(ports, 2) == 0xC0);
    return 0;
}

/* 
*   test TILT command 
*       our enumeration: 9
*       port2
*       bit 2
*/
int test_0A (uint8_t *ports) {
    setControllerPort(ports, _TILT);
    assert(getControllerPort(ports, 2) == 0x84);
    return 0;
}

int main(void) {

    uint8_t ports[3];   

    test_01(ports);
    test_02(ports);
    test_03(ports);
    test_04(ports);
    test_05(ports);
    test_06(ports);
    test_07(ports);
    test_08(ports);
    test_09(ports);
    test_0A(ports);
    
    return 0;
}
