//
// Created by 14477 on 2024/6/28.
//

#include "servo.h"
#include "bsp_dwt.h"
#include "math.h"
void initServo(Servo *servo, TIM_HandleTypeDef *htim_, uint32_t channel_)
{
    servo->htim = htim_;
    servo->channel = channel_;
    servo->pulse = 0;
    servo->angle = 0;
}

void setAngle(Servo *servo, float angle)
{
    if(angle == servo->angle)
        return;
    if(angle >servo->angle)
    {
        servo->pulse = 2500;
    }
    else
    {
        servo->pulse = 500;
    }

    uint32_t time=(uint32_t)(fabsf(angle-servo->angle)/360.0f*1950000.0f);
    servo->angle = angle;
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, servo->pulse);
    DWT_DelayUS(time);
    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, 1500);
}
