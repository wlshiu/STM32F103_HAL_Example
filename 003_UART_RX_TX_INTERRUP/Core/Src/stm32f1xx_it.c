
#include "stm32f1xx_it.h"

extern void receiveData_IT(UART_HandleTypeDef *huart);
extern UART_HandleTypeDef huart2;
void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

void USART2_IRQHandler(void)
{
    receiveData_IT(&huart2);
}
