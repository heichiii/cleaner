//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_DISTANCE_H
#define CLEANER_DISTANCE_H
#include "hcsr04.h"
typedef struct
{
    float distance_l;
    float distance_r;
    float distance_f;
    float distance_b;
}Distance;
extern DistanceSensor forward, left, right, back;
void initDistance2(void);
void distanceTask2(void);
#endif //CLEANER_DISTANCE_H
