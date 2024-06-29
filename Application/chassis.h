//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_CHASSIS_H
#define CLEANER_CHASSIS_H
#include "motor.h"
#include "pid.h"
typedef struct chassis
{
    float x_ref,y_ref;
    float x,y;

    float vx_ref,vy_ref;
    float vx,vy,vr;

    float v1,v2,v3,v4;

    Motor wheel[4];

    PID pid_x;
    PID pid_y;

    PID pid_vx;
    PID pid_vy;
}Chassis;

extern Chassis chassis;

void initChassis(void);
void controlChassis(void);

#endif //CLEANER_CHASSIS_H
