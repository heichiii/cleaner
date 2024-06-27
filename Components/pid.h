//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_PID_H
#define CLEANER_PID_H
typedef struct pid
{
    float kp,ki,kd;
    float measure;
    float error;
    float error_last;
    float p_out;
    float i_out;
    float d_out;
    float output;
}PID;
void initPID(PID *pid,float kp_,float ki_,float kd_);
float calculatePID(PID *pid,float measure,float target);
#endif //CLEANER_PID_H
