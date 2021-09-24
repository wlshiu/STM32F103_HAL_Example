/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"

extern TIM_HandleTypeDef htim2;
void SysTick_Handler(void)
{
    /* USER CODE BEGIN SysTick_IRQn 0 */

    /* USER CODE END SysTick_IRQn 0 */
    HAL_IncTick();
    HAL_SYSTICK_IRQHandler();
}

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&htim2);
}
