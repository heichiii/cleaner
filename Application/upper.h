//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_UPPER_H
#define CLEANER_UPPER_H
#include "servo.h"
#include "magnet.h"
#include "motor.h"
typedef struct upper
{
    struct
    {
        int x,y,w,h;
    }block;
    Servo servo_bucket;
    Servo servo_magnet;
    float bucket_angle;
    Magnet magnet;
    Motor besom;

}Upper;

extern Upper upper;
void initUpper(void);
void controlUpper(void);
void updateBlock(uint8_t *rx,Upper *upper_);
#endif //CLEANER_UPPER_H
