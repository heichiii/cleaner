#ifndef DELAY_H
#define DELAY_H


#include "stm32f4xx_hal.h"

#define  DEM_CR      *(volatile uint32_t *)0xE000EDFC
#define  DWT_CR      *(volatile uint32_t *)0xE0001000
#define  DWT_CYCCNT  *(volatile uint32_t *)0xE0001004
#define  DEM_CR_TRCENA                   (1 << 24)
#define  DWT_CR_CYCCNTENA                (1 <<  0)

void DWT_Init();

void DWT_DelayUS(uint32_t _ulDelayTime);


//void DWT_DelayMS(uint32_t _ulDelayTime);



#endif
