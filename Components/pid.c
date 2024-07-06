//
// Created by 14477 on 2024/6/27.
//

#include "pid.h"
#include "bsp_dwt.h"

void initPID(PID *pid, float kp_, float ki_, float kd_, float max_out_, float max_iout_)
{
    pid->kp = kp_;
    pid->ki = ki_;
    pid->kd = kd_;
    pid->max_out = max_out_;
    pid->max_iout = max_iout_;
    pid->error = 0;
    pid->error_last = 0;
    pid->p_out = 0;
    pid->i_out = 0;
    pid->d_out = 0;
    pid->output = 0;
    pid->dwt_cnt = 0;
    pid->dt = 0;
}

float calculatePID(PID *pid, float measure, float target)
{
    pid->dt = DWT_DeltaTime(&pid->dwt_cnt);
    pid->error = target - measure;
    pid->p_out = pid->kp * pid->error * pid->dt;
    pid->i_out += pid->ki * pid->error * pid->dt;
    pid->d_out = pid->kd * (pid->error - pid->error_last) / pid->dt;
    if (pid->i_out > pid->max_iout)
    {
        pid->i_out = pid->max_iout;
    }
    else if (pid->i_out < -pid->max_iout)
    {
        pid->i_out = -pid->max_iout;
    }
    pid->output = pid->p_out + pid->i_out + pid->d_out;
    if (pid->output > pid->max_out)
    {
        pid->output = pid->max_out;
    }
    else if (pid->output < -pid->max_out)
    {
        pid->output = -pid->max_out;
    }
    pid->error_last = pid->error;
    return pid->output;
}

