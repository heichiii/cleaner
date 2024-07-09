//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_ARM_H
#define CLEANER_ARM_H
#include "servo.h"

typedef struct
{
    Servo servo_yaw;
    Servo servo_pitch;
    Servo servo_gripper;

    float yaw;
    float pitch;
    float gripper;

    float x,y;
}Arm;

extern Arm arm;
extern uint32_t time;
void initArm(void);
void controlArm(void);
void updateControlValue(void);
void setArmControl(void);
#endif //CLEANER_ARM_H
