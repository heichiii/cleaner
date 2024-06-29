//
// Created by 14477 on 2024/6/27.
//

#include "hcsr04.h"
#include "cmsis_os.h"
#include "bsp_dwt.h"

void initDistanceSensor(DistanceSensor *sensor,
                        GPIO_TypeDef *trig_GPIOx_,
                        uint16_t trig_GPIO_Pin_,
                        GPIO_TypeDef *echo_GPIOx_,
                        uint16_t echo_GPIO_Pin_)
{
    sensor->distance = 0;
    sensor->time = 0;
    sensor->time_end = 0;
    sensor->trig_GPIOx = trig_GPIOx_;
    sensor->trig_GPIO_Pin = trig_GPIO_Pin_;
    sensor->echo_GPIOx = echo_GPIOx_;
    sensor->echo_GPIO_Pin = echo_GPIO_Pin_;
    sensor->flag = 0;
    HAL_GPIO_WritePin(sensor->trig_GPIOx, sensor->trig_GPIO_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(sensor->echo_GPIOx, sensor->echo_GPIO_Pin, GPIO_PIN_RESET);
    //DWT_DelayUS(15);
    //Delay_us(15);
}

float getDistance(DistanceSensor *sensor)
{
    //mm
    HAL_GPIO_WritePin(sensor->trig_GPIOx, sensor->trig_GPIO_Pin, GPIO_PIN_SET);
    DWT_DelayUS(15);
    //Delay_us(15);
    HAL_GPIO_WritePin(sensor->trig_GPIOx, sensor->trig_GPIO_Pin, GPIO_PIN_RESET);

    //    if (sensor->flag == 0)
    //    {
    //        sensor->time = 0;
    //        if (HAL_GPIO_ReadPin(sensor->echo_GPIOx, sensor->echo_GPIO_Pin) == 0)
    //        {
    //            if (sensor->time > 100)
    //            {
    //                return 0;
    //            }
    //        }
    //        sensor->time = 0;
    //        sensor->flag = 1;
    //    }
    //    else
    //    {
    //        if (HAL_GPIO_ReadPin(sensor->echo_GPIOx, sensor->echo_GPIO_Pin) == 0)
    //        {
    //            sensor->time_end = sensor->time;
    //        }
    //    }



    sensor->time = 0;
    while (HAL_GPIO_ReadPin(sensor->echo_GPIOx, sensor->echo_GPIO_Pin) == 0)
    {
        if (sensor->time > 3800)
        {
            return 0;
        }
    }        //等待低电平结束
    sensor->time = 0;                                                //计时清零
    while (HAL_GPIO_ReadPin(sensor->echo_GPIOx, sensor->echo_GPIO_Pin) == 1)
    {
    }        //等待高电平结束
    sensor->time_end = sensor->time;                                        //记录结束时的时间


    if (sensor->time_end / 100.0f < 38)                                    //判断是否小于38毫秒，大于38毫秒的就是超时，直接调到下面返回0
    {
        //        Distance=(time_end*346)/2;						//计算距离，25°C空气中的音速为346m/s
        //        Distance_mm=Distance/100;						//因为上面的time_end的单位是10微秒，所以要得出单位为毫米的距离结果，还得除以100
        sensor->distance = (sensor->time_end * 346.0f) / 100.0f;                        //计算距离，25°C空气中的音速为346m/s
    }
    return sensor->distance;                                    //返回测距结果
}
