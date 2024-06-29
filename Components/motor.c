//
// Created by 14477 on 2024/6/28.
//

#include "motor.h"
#include "math.h"
#include "bsp_dwt.h"
void initMotor(Motor *motor, TIM_HandleTypeDef *htim_, uint32_t channel1_, uint32_t channel2_)
{
    motor->htim = htim_;
    motor->channel1 = channel1_;
    motor->channel2 = channel2_;
    motor->output1 = 0;
    motor->output2 = 0;
    motor->speed = 0;
}

void setSpeed(Motor *motor, float speed)
{
    if(speed>0)
    {
        motor->output1 = (uint32_t)(speed);
        motor->output2 = 0;
    }
    else if(speed<0)
    {
        motor->output1 = 0;
        motor->output2 = (uint32_t)(-speed);
    }
    else
    {
        motor->output1 = 0;
        motor->output2 = 0;
    }

    __HAL_TIM_SET_COMPARE(motor->htim, motor->channel1, motor->output1);
    __HAL_TIM_SET_COMPARE(motor->htim, motor->channel2, motor->output2);

}
