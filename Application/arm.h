//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_ARM_H
#define CLEANER_ARM_H
#include "servo.h"

typedef struct
{
    Servo servo1;
}Arm;

extern Arm arm;

void initArm(void);
void controlArm(void);

#endif //CLEANER_ARM_H
