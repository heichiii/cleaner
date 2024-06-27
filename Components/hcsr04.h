//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_HCSR04_H
#define CLEANER_HCSR04_H

#define TIMEOUT 38 // 38ms

#include "stm32f4xx_hal.h"

typedef struct
{
    float distance;
    uint16_t time;
    uint16_t time_end;
    GPIO_TypeDef *trig_GPIOx;
    uint16_t trig_GPIO_Pin;
    GPIO_TypeDef *echo_GPIOx;
    uint16_t echo_GPIO_Pin;
} DistanceSensor;

void initDistanceSensor(DistanceSensor *sensor,
                        GPIO_TypeDef *trig_GPIOx_,
                        uint16_t trig_GPIO_Pin_,
                        GPIO_TypeDef *echo_GPIOx_,
                        uint16_t echo_GPIO_Pin_);

float getDistance(DistanceSensor *sensor);

#endif //CLEANER_HCSR04_H
