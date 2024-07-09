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
}

void setAngle(Servo *servo, float angle)
{
    servo->pulse=500+(angle/180.0f*2000);

    __HAL_TIM_SET_COMPARE(servo->htim, servo->channel, servo->pulse);

}
