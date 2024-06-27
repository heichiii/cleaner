//
// Created by 14477 on 2024/6/27.
//

#include "pid.h"
void initPID(PID *pid,float kp_,float ki_,float kd_)
{
    pid->kp = kp_;
    pid->ki = ki_;
    pid->kd = kd_;
    pid->error = 0;
    pid->error_last = 0;
    pid->p_out = 0;
    pid->i_out = 0;
    pid->d_out = 0;
    pid->output = 0;
}
float calculatePID(PID *pid,float measure,float target)
{
    pid->measure = measure;
    pid->error = target - pid->measure;
    pid->p_out = pid->kp * pid->error;
    pid->i_out += pid->ki * pid->error;
    pid->d_out = pid->kd * (pid->error - pid->error_last);
    pid->output = pid->p_out + pid->i_out + pid->d_out;
    pid->error_last = pid->error;
    return pid->output;
}

