//
// Created by 14477 on 2024/6/27.
//

#include "arm.h"
#include "chassis.h"
#include "tim.h"
Arm arm={0};
uint32_t time=0;
uint8_t last_state;
uint8_t flag=0;
void initArm(void)
{
    initServo(&arm.servo_yaw, &htim8, TIM_CHANNEL_1);
    initServo(&arm.servo_pitch, &htim8, TIM_CHANNEL_2);
    initServo(&arm.servo_gripper, &htim8, TIM_CHANNEL_3);
    arm.yaw = 0;//180
    arm.pitch = 30;//77
    arm.gripper = 80;//120
    arm.x = 35;
    arm.y = 57;
}

void controlArm(void)
{
    updateControlValue();
    setArmControl();
}
void updateControlValue(void)
{

    if(chassis.state==WAIT)
    {
        if(last_state==CHASE)
        {
            time=0;
            flag=1;
        }
        if(flag)
        {
            if(time>0 && time <25000)
            {
                arm.yaw=0;
                arm.pitch=30;
                arm.gripper=120;
            }
            else if(time>25000 && time <50000)
            {
                arm.yaw=0;
                arm.pitch=77;
                arm.gripper=120;
            }
            else if(time>50000 && time <75000)
            {
                arm.yaw=0;
                arm.pitch=77;
                arm.gripper=80;
            }
            else if(time>100000 && time <125000)
            {
                arm.yaw=0;
                arm.pitch=30;
                arm.gripper=80;
            }
            else if(time>125000 && time <175000)
            {
                arm.yaw=180;
                arm.pitch=30;
                arm.gripper=80;
            }
            else if(time> 175000&& time <200000)
            {
                arm.yaw=180;
                arm.pitch=30;
                arm.gripper=120;
            }
            else if(time> 200000&& time <250000)
            {
                arm.yaw=0;
                arm.pitch=30;
                arm.gripper=80;
            }
            else if(time>250000)
            {
                arm.yaw=0;
                arm.pitch=30;
                arm.gripper=80;
                chassis.state=ROAM;
            }

        }
    }
    last_state=chassis.state;
}
void setArmControl(void)
{
    setAngle(&arm.servo_gripper,arm.gripper);
    setAngle(&arm.servo_pitch, arm.pitch);
    setAngle(&arm.servo_yaw, arm.yaw);


//    {
//        if(arm.gripper)
//            setAngle(&arm.servo_gripper, 90);
//        else
//            setAngle(&arm.servo_gripper, 0);
//    }
}

