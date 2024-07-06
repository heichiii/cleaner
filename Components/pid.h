//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_PID_H
#define CLEANER_PID_H
#include "stm32f4xx_hal.h"
typedef struct pid
{
    float kp,ki,kd;

    float error;
    float error_last;
    float p_out;
    float i_out;
    float d_out;
    float output;

    float max_out;
    float max_iout;

    uint32_t dwt_cnt;
    float dt;
}PID;
void initPID(PID *pid,float kp_,float ki_,float kd_,float max_out_,float max_iout_);
float calculatePID(PID *pid,float measure,float target);
#endif //CLEANER_PID_H
