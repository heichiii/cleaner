//
// Created by 14477 on 2024/6/27.
//

#include "bsp_uart.h"
#include "string.h"
uint8_t rx_buff[30]={0};

void initUart(UART_HandleTypeDef *huart_,uint8_t* buf_,uint16_t size)
{
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
    HAL_UART_Receive_DMA(&huart1, (uint8_t*)buf_, size);
}
void USER_UART_IRQHandler(UART_HandleTypeDef *huart)
{	// 判断是否是串口1
    if(USART1 == huart1.Instance)
    {	// 判断是否是空闲中断
        if(RESET != __HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE))
        {	 // 清除空闲中断标志（否则会一直不断进入中断）
            __HAL_UART_CLEAR_IDLEFLAG(&huart1);
            // 调用中断处理函数
            USAR_UART_IDLECallback(huart);
        }
    }
}
void USAR_UART_IDLECallback(UART_HandleTypeDef *huart)
{
    // 停止本次DMA传输
    HAL_UART_DMAStop(huart);
    // 清零接收缓冲区
    //memset(rx_buff,0,30);
    // 重启开始DMA传输 每次255字节数据
    HAL_UART_Receive_DMA(huart, (uint8_t*)rx_buff, 30);
}
