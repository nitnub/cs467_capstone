#ifndef HANDLER_H
#define HANDLER_H

#include "handleSegment.h"

/*
* ************ LEVEL TWO HANDLER ORGANIZATION *************
* 
*  funcArray is defined as an array of type hfv_i handlers
*  for opcodes in the following ranges:
* 
*  -------------------------
* | (SEGMENT 0: 0x00-0x3F) | 
* | (SEGMENT 1: 0x40-0x7F) | 
* | (SEGMENT 2: 0x80-0xBF) |
* | (SEGMENT 3: 0xC0-0xFF) | 
* --------------------------
*
* **********************************************************/

int handler_a(struct instructionData*);
int handler_b(struct instructionData*);
int handler_c(struct instructionData*);
int handler_d(struct instructionData*);
int getL2Segment(int*);
int dispatchLevel2(struct instructionData *currentIns);

static hfv_i funcArray[] = {handler_a, handler_b, handler_c, handler_d};

#endif