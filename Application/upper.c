//
// Created by 14477 on 2024/6/27.
//

#include "upper.h"
#include "chassis.h"
#include "tim.h"


Upper upper={0};
void initUpper(void)
{
    initMotor(&upper.besom,&htim4, TIM_CHANNEL_1, TIM_CHANNEL_2);
    initMagnet(&upper.magnet, &htim4, TIM_CHANNEL_3, TIM_CHANNEL_4);
    initServo(&upper.servo_bucket, &htim5, TIM_CHANNEL_1);
    initServo(&upper.servo_magnet, &htim5, TIM_CHANNEL_2);
    upper.bucket_angle=90;
}
void controlUpper(void)
{
    setSpeed(&upper.besom,300);
    setAngle(&upper.servo_bucket,upper.bucket_angle);
}
void updateBlock(uint8_t *rx,Upper *upper_)
{
    upper_->block.x = rx[2];
    upper_->block.y = rx[3];
    upper_->block.w = rx[4];
    upper_->block.h = rx[5];
}

