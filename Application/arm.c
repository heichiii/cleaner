//
// Created by 14477 on 2024/6/27.
//

#include "arm.h"
#include "chassis.h"
#include "tim.h"
Arm arm={0};

void initArm(void)
{
    initServo(&arm.servo_yaw, &htim8, TIM_CHANNEL_1);
    initServo(&arm.servo_pitch, &htim8, TIM_CHANNEL_2);
    initServo(&arm.servo_gripper, &htim8, TIM_CHANNEL_3);
    arm.yaw = 0;
    arm.pitch = 0;
    arm.gripper = 0;
    arm.x = 125;
    arm.y = 125;
}

void controlArm(void)
{
    updateControlValue();
    setArmControl();
}
void updateControlValue()
{
    if(chassis.state==WAIT)
    {

    }
}
void setArmControl(void)
{
    setAngle(&arm.servo_yaw, arm.yaw);
    setAngle(&arm.servo_pitch, arm.pitch);
    {
        if(arm.gripper)
            setAngle(&arm.servo_gripper, 90);
        else
            setAngle(&arm.servo_gripper, 0);
    }
}

