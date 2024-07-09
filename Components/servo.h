//
// Created by 14477 on 2024/6/28.
//

#ifndef CLEANER_SERVO_H
#define CLEANER_SERVO_H
#include "stm32f4xx_hal.h"
typedef struct Servo
{
    TIM_HandleTypeDef *htim;
    uint32_t channel;
    uint32_t pulse;
} Servo;

void initServo(Servo *servo, TIM_HandleTypeDef *htim_, uint32_t channel_);
void setAngle(Servo *servo, float angle);
#endif //CLEANER_SERVO_H
