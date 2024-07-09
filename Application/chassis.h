//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_CHASSIS_H
#define CLEANER_CHASSIS_H
#include "motor.h"
#include "pid.h"
typedef enum
{

    ROAM,
    CHASE,
    WAIT

}State;
typedef struct chassis
{
    State state;
    float x_ref,y_ref;//0
    float x,y,x_last,y_last;

    float vx_ref,vy_ref;
    float vx,vy,vr;

    float v1,v2,v3,v4;

    Motor wheel[4];

    PID pid_x;
    PID pid_y;

    PID pid_vx;
    PID pid_vy;

    float dt;
    uint32_t dwt_cnt;
}Chassis;

extern Chassis chassis;

void initChassis(void);
void controlChassis(void);
void setChassisMode(void);
void updateChassisRef(void);
void setChassisControl(void);
uint8_t isClose(float direction);
#endif //CLEANER_CHASSIS_H
