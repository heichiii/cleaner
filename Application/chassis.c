//
// Created by 14477 on 2024/6/27.
//

#include "chassis.h"
#include "tim.h"
#include "upper.h"
#include "arm.h"
#include "distance.h"
#include "math.h"
#include "bsp_dwt.h"

Chassis chassis = {0};

void initChassis(void)
{
    initMotor(&chassis.wheel[0], &htim2, TIM_CHANNEL_1, TIM_CHANNEL_2);
    initMotor(&chassis.wheel[1], &htim2, TIM_CHANNEL_3, TIM_CHANNEL_4);
    initMotor(&chassis.wheel[2], &htim3, TIM_CHANNEL_1, TIM_CHANNEL_2);
    initMotor(&chassis.wheel[3], &htim3, TIM_CHANNEL_3, TIM_CHANNEL_4);

    initPID(&chassis.pid_x, 0.1, 0.01, 0.01, 1000, 1000);
    initPID(&chassis.pid_y, 0.1, 0.01, 0.01, 1000, 1000);

    initPID(&chassis.pid_vx, 0.1, 0.01, 0.01, 1000, 1000);
    initPID(&chassis.pid_vy, 0.1, 0.01, 0.01, 1000, 1000);

    chassis.x_ref = 0;
    chassis.y_ref = 0;
    chassis.x = 0;
    chassis.y = 0;

    chassis.vx_ref = 0;
    chassis.vy_ref = 0;
    chassis.vx = 0;
    chassis.vy = 0;
    chassis.vr = 0;

    chassis.v1 = 0;
    chassis.v2 = 0;
    chassis.v3 = 0;
    chassis.v4 = 0;

//    chassis.state = ROAM;
    chassis.state = ROAM;
    DWT_DelayUS(2000000);
    chassis.dt = 0;
    chassis.dwt_cnt = 0;
}

void controlChassis(void)
{
    setChassisMode();
    updateChassisRef();
    setChassisControl();
}

void setChassisMode(void)
{
    if(chassis.state==CHASE)
    {
        if (dis.distance_f <= 1000 && dis.distance_f!=0)
        {
            chassis.state = WAIT;
        }
    }

//    if (upper.block.x > 10 && upper.block.y > 10 && upper.block.x<150 && upper.block.y<110) //找到了
//    {
////        chassis.dt = DWT_DeltaTime(&chassis.dwt_cnt);
////        chassis.x_last = chassis.x;
////        chassis.y_last = chassis.y;
//        chassis.x = upper.block.x-arm.x;
//        chassis.y =  upper.block.y-arm.y;
////        chassis.vx = (chassis.x - chassis.x_last) / chassis.dt;
////        chassis.vy = (chassis.y - chassis.y_last) / chassis.dt;
////        chassis.vx_ref = calculatePID(&chassis.pid_x, chassis.x, chassis.x_ref);
////        chassis.vy_ref = calculatePID(&chassis.pid_y, chassis.y, chassis.y_ref);
//        if (fabsf(chassis.x) < 10 && fabsf(chassis.y) < 10)
//        {
//            chassis.state = WAIT;
//        }
//        else
//        {
//            chassis.state = CHASE;
//        }
//    }
//    else
//    {
//        chassis.state=ROAM;
//    }
}

void updateChassisRef(void)
{
    switch (chassis.state)
    {
        case WAIT:
            chassis.vx_ref=0;
            chassis.vy_ref=0;
            chassis.vr=0;
            break;
        case ROAM:
            if(isClose(dis.distance_f))
            {
                chassis.vy_ref=0;
                chassis.vx_ref=0;
                if(!isClose(dis.distance_l))
                {
                    chassis.vr=1000;
                }
                else
                {
                    chassis.vr=-1000;
                }
            }
            else
            {
                chassis.vr=0;
                chassis.vy_ref=800;
                if(isClose(dis.distance_l) && !isClose(dis.distance_r))
                {
                    chassis.vx_ref=500;
                    chassis.vy_ref=500;
                }
                else if(!isClose(dis.distance_l) && isClose(dis.distance_r))
                {
                    chassis.vx_ref=-500;
                    chassis.vy_ref=500;
                }
                else
                {
                    chassis.vx_ref=0;
                }
            }
            break;
        case CHASE:
//            if(chassis.x>15)
//            {
//                chassis.vx_ref=-800;
//            }
//            else if(chassis.x<-15)
//            {
//                chassis.vx_ref=800;
//            }
//            else
//            {
//                chassis.vx_ref=0;
//            }
//
//            if(chassis.y>15)
//            {
//                chassis.vy_ref=800;
//            }
//            else if(chassis.y<-15)
//            {
//                chassis.vy_ref=-800;
//            }
//            else
//            {
//                chassis.vy_ref=0;
//            }
//            break;

            chassis.vy_ref=600;
//            if(time>500000)
//                chassis.vy_ref=0;

            break;

    }

}

void setChassisControl(void)
{

    chassis.v1 = chassis.vx_ref + chassis.vy_ref - chassis.vr;
    chassis.v2 = -chassis.vx_ref + chassis.vy_ref - chassis.vr;
    chassis.v3 = chassis.vx_ref + chassis.vy_ref + chassis.vr;
    chassis.v4 = -chassis.vx_ref + chassis.vy_ref + chassis.vr;

    setSpeed(&chassis.wheel[0], chassis.v1);
    setSpeed(&chassis.wheel[1], chassis.v2);
    setSpeed(&chassis.wheel[2], chassis.v3);
    setSpeed(&chassis.wheel[3], chassis.v4);

    if(chassis.vr!=0)
    {
        DWT_DelayUS(500000);
    }
}

uint8_t isClose(float direction)
{
    if (direction > 0 && direction < 500)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
