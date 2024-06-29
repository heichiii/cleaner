//
// Created by 14477 on 2024/6/28.
//

#ifndef CLEANER_MOTOR_H
#define CLEANER_MOTOR_H
#include "stm32f4xx_hal.h"
typedef struct
{
    TIM_HandleTypeDef *htim;
    uint32_t channel1;//positive
    uint32_t channel2;//negative
    uint32_t output1;
    uint32_t output2;
    float speed;

}Motor;

void initMotor(Motor *motor, TIM_HandleTypeDef *htim_, uint32_t channel1_, uint32_t channel2_);
void setSpeed(Motor *motor, float speed);
#endif //CLEANER_MOTOR_H
