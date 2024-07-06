//
// Created by 14477 on 2024/6/30.
//

#include "magnet.h"

void initMagnet(Magnet *magnet, TIM_HandleTypeDef *htim_, uint32_t channel1_,uint32_t channel2)
{
    magnet->htim=htim_;
    magnet->channel1=channel1_;
    magnet->channel2=channel2;
}

void setMagnet(Magnet *magnet, uint8_t flag)
{

}
