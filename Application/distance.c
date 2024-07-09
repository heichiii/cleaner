//
// Created by 14477 on 2024/6/27.
//

#include "distance.h"

#include "main.h"
DistanceSensor forward, left, right, back;
Distance dis={0};
void initDistance(void)
{
    initDistanceSensor(&forward, Trig1_GPIO_Port, Trig1_Pin, Echo1_GPIO_Port, Echo1_Pin);
    initDistanceSensor(&left, Trig2_GPIO_Port, Trig2_Pin, Echo2_GPIO_Port, Echo2_Pin);
    initDistanceSensor(&right, Trig3_GPIO_Port, Trig3_Pin, Echo3_GPIO_Port, Echo3_Pin);
}
void updateDistance(void)
{
    dis.distance_f = getDistance(&forward);
    dis.distance_l = getDistance(&left);
    dis.distance_r = getDistance(&right);
//    dis.distance_b = getDistance(&back);
}

