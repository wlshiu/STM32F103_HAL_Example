#include "main.h"

extern TIM_HandleTypeDef htim2;

//esta funcion es llamada por la funcion HAL_Init()
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

//inicializacion de bajo nivel del timer2->output compare mode
void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
{
    //1. se activa el reloj del timer y el ioporta
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_TIM2_CLK_ENABLE();

    //2. se asocia los pines a los canales 1-4 del timer 2
    GPIO_InitTypeDef tim_ocGpio = {0};

    tim_ocGpio.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
    tim_ocGpio.Mode = GPIO_MODE_AF_PP;
    tim_ocGpio.Pull = GPIO_NOPULL;
    tim_ocGpio.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &tim_ocGpio);

    //3. se activa las interrupciones si es necesario
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
    HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);
}
