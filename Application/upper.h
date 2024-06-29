//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_UPPER_H
#define CLEANER_UPPER_H
#include "servo.h"

typedef struct upper
{
    int block_x,block_y,block_w,block_h;
}Upper;

extern Servo servo1;
void initUpper(void);
void controlUpper(void);
void updateBlock(uint8_t *rx,Upper *upper_);
#endif //CLEANER_UPPER_H
