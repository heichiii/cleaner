//
// Created by 14477 on 2024/6/30.
//

#ifndef CLEANER_MAGNET_H
#define CLEANER_MAGNET_H
#include "stm32f4xx_hal.h"
typedef struct
{
    TIM_HandleTypeDef *htim;
    uint32_t channel1;
    uint32_t channel2;
    uint8_t flag;
}Magnet;

void initMagnet(Magnet *magnet, TIM_HandleTypeDef *htim_, uint32_t channel1_,uint32_t channel2);
void setMagnet(Magnet *magnet, uint8_t flag);
#endif //CLEANER_MAGNET_H
