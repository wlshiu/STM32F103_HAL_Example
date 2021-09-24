
/* Includes ------------------------------------------------------------------*/
#include "main.h"
extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim2;
void HAL_MspInit(void)
{
    /*se establece el grupo de prioridades del NVIC*/
    HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    //2. se activa las exepciones que requiere el sistema
    SCB->SHCSR |= 0x7 << 16; //usage fault, memory fault and bus fault system exceptions

    //3. se configura la prioridad de exepciones para el sistema
    HAL_NVIC_SetPriority(MemoryManagement_IRQn, 0, 0);
    HAL_NVIC_SetPriority(BusFault_IRQn, 0, 0);
    HAL_NVIC_SetPriority(UsageFault_IRQn, 0, 0);
}
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
    GPIO_InitTypeDef gpio_uart = {0};
    //1.se activa el reloj para el uart1
    __HAL_RCC_USART1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    //2. se asignan pines al uart1
    gpio_uart.Pin = GPIO_PIN_9;
    gpio_uart.Mode = GPIO_MODE_AF_PP;
    gpio_uart.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &gpio_uart);

    gpio_uart.Pin = GPIO_PIN_10;
    gpio_uart.Mode = GPIO_MODE_INPUT;
    gpio_uart.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &gpio_uart);
}

void HAL_TIM_IC_MspInit(TIM_HandleTypeDef *htim)
{
    GPIO_InitTypeDef gpio_ic = {0};
    //1. se activa el reloj para el tim2
    __HAL_RCC_TIM2_CLK_ENABLE();
    //2. se asocia un gpio para la entrada del CH1
    gpio_ic.Pin = GPIO_PIN_0;
    gpio_ic.Mode = GPIO_MODE_AF_INPUT;
    gpio_ic.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &gpio_ic);

    //3. se activa la interrupcion para el tim2
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
    HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);
}
