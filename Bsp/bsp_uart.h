//
// Created by 14477 on 2024/6/27.
//

#ifndef CLEANER_BSP_UART_H
#define CLEANER_BSP_UART_H

#include "usart.h"
//#include "stm32f4xx_hal_uart.h"
extern uint8_t rx_buff[30];
void initUart(UART_HandleTypeDef *huart_,uint8_t* buf,uint16_t size);
void USER_UART_IRQHandler(UART_HandleTypeDef *huart);
void USAR_UART_IDLECallback(UART_HandleTypeDef *huart);
#endif //CLEANER_BSP_UART_H
