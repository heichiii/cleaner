#include "bsp_dwt.h"

void DWT_Init()
{
    DEM_CR  |=  DEM_CR_TRCENA; /*对DEMCR寄存器的位24控制，写1使能DWT外设。*/
    DWT_CYCCNT = 0;/*对于DWT的CYCCNT计数寄存器清0。*/
    DWT_CR  |=  DWT_CR_CYCCNTENA;/*对DWT控制寄存器的位0控制，写1使能CYCCNT寄存器。*/
}

void DWT_DelayUS(uint32_t _ulDelayTime)
{
    uint32_t tCnt, tDelayCnt;
    uint32_t tStart;

    tStart = DWT_CYCCNT; /* 刚进入时的计数器值 */
    tCnt = 0;
    tDelayCnt = _ulDelayTime * (SystemCoreClock / 1000000);
    /* 需要的节拍数 */    /*SystemCoreClock :系统时钟频率*/

    while(tCnt < tDelayCnt)
    {
        tCnt = DWT_CYCCNT - tStart;
        /* 求减过程中，如果发生第一次32位计数器重新计数，依然可以正确计算 */
    }
}

float DWT_DeltaTime(uint32_t *tStart)
{
    uint32_t tDelta = DWT_CYCCNT - *tStart;
    *tStart = DWT_CYCCNT;
    return (float)(tDelta) / SystemCoreClock;
}
//void DWT_DelayMS(uint32_t _ulDelayTime)
//{
//    bsp_DelayUS(1000*_ulDelayTime);
//}

