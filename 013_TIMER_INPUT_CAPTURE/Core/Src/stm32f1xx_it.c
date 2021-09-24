
#include "main.h"
#include "stm32f1xx_it.h"

extern TIM_HandleTypeDef htim2;
void SysTick_Handler(void)
{
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&htim2);
}
