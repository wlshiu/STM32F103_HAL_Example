
#include "main.h"


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

void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    //1. se activa el reloj del TIM2
    __HAL_RCC_TIM2_CLK_ENABLE();

    //2. se activa la interrupcion para el timer 2
    HAL_NVIC_EnableIRQ(TIM2_IRQn);

    //3. se establece la prioridad de la interrupcion
    HAL_NVIC_SetPriority(TIM2_IRQn, 15, 0);
}
