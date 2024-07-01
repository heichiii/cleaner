//
// Created by 14477 on 2024/6/30.
//

#include "magnet.h"

void initMagnet(Magnet *magnet, TIM_HandleTypeDef *htim_, uint32_t channel_)
{
    magnet->htim=htim_;
    magnet->channel=channel_;
    HAL_TIM_PWM_Start(magnet->htim,magnet->channel);
}

void setMagnet(Magnet *magnet, uint8_t flag)
{
    if(flag)
    {
        __HAL_TIM_SET_COMPARE(magnet->htim,magnet->channel,1000);
    }
    else
    {
        __HAL_TIM_SET_COMPARE(magnet->htim,magnet->channel,0);
    }
}
