//
// Created by 14477 on 2024/6/27.
//

#include "upper.h"
#include "tim.h"

Servo servo1;

float angle = 0;
void initUpper(void)
{
    initServo(&servo1, &htim8, TIM_CHANNEL_1);
}
void controlUpper(void)
{

    setAngle(&servo1, angle);

}
void updateBlock(uint8_t *rx,Upper *upper_)
{
    upper_->block_x = rx[0];
}

