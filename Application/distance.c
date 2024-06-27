//
// Created by 14477 on 2024/6/27.
//

#include "distance.h"

#include "main.h"
DistanceSensor forward, left, right, back;
Distance dis={0};
void initDistance2(void)
{
    initDistanceSensor(&forward, Trig1_GPIO_Port, Trig1_Pin, Echo1_GPIO_Port, Echo1_Pin);
//    initDistanceSensor(&left, GPIOB, GPIO_PIN_2, GPIOB, GPIO_PIN_3);
//    initDistanceSensor(&right, GPIOB, GPIO_PIN_4, GPIOB, GPIO_PIN_5);
//    initDistanceSensor(&back, GPIOB, GPIO_PIN_6, GPIOB, GPIO_PIN_7);
}
void distanceTask2(void)
{
    dis.distance_f = getDistance(&forward);
//    dis.distance_l = getDistance(&left);
//    dis.distance_r = getDistance(&right);
//    dis.distance_b = getDistance(&back);
}

