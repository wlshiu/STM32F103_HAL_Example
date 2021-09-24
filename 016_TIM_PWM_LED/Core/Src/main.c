#include "main.h"

/*definicion de variables globales*/
TIM_HandleTypeDef htim2;


/*fin */
/*definicion de prototipo de funciones*/
void SystemClock_Config(void);
void TIM2_Init(void);
/*fin*/

int main(void)
{
    int brillo = 21;
    //inicializacion de bajo nivel
    HAL_Init();
    //inicializacion del reloj del MCU
    SystemClock_Config();
    //se inicializa el timer2
    TIM2_Init();
    //se inicia el pwm
    if(HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }
    if(HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2) != HAL_OK)
    {
        Error_Handler();
    }
    if(HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3) != HAL_OK)
    {
        Error_Handler();
    }
    if(HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_4) != HAL_OK)
    {
        Error_Handler();
    }
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 500);
    HAL_Delay(500);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, 0);
    while(1)
    {
        while( brillo < htim2.Init.Period)
        {
            brillo += 10;
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, brillo);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, brillo);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, brillo);
            HAL_Delay(1);

        }

        while(brillo >= 10)
        {
            brillo -= 10;
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, brillo);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, brillo);
            __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, brillo);
            HAL_Delay(1);

        }
    }
}
/*****************DEFINICION DE FUNCIONES******************************************/

/*funcion que configura el reloj del MCU */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef osc_init = {0};
    RCC_ClkInitTypeDef clk_init = {0};

    osc_init.OscillatorType  = RCC_OSCILLATORTYPE_HSE;
    osc_init.HSEState = RCC_HSE_ON;
    if(HAL_RCC_OscConfig(&osc_init) != HAL_OK)
    {
        Error_Handler();
    }
    clk_init.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_SYSCLK;
    clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
    clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clk_init.APB1CLKDivider = RCC_HCLK_DIV1;
    clk_init.APB2CLKDivider = RCC_HCLK_DIV1;
    if(HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
    //inicializamos la interrupcion el systick
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);
    //configura la fuente de reloj del systick
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
    //se activa la interrupcion del timer;
    HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

//funcion qu inicializa los parametros del timer2
void TIM2_Init(void)
{
    TIM_OC_InitTypeDef tim_ocPWM = {0};

    htim2.Instance = TIM2;
    htim2.Init.Period = 1000 - 1;
    htim2.Init.Prescaler = 16 - 1;
    if(HAL_TIM_PWM_Init(&htim2) != HAL_OK)
    {
        Error_Handler();
    }

    tim_ocPWM.OCMode = TIM_OCMODE_PWM1;
    tim_ocPWM.OCPolarity = TIM_OCPOLARITY_HIGH;
    tim_ocPWM.Pulse = 0;

    if(HAL_TIM_PWM_ConfigChannel(&htim2, &tim_ocPWM, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }

    if(HAL_TIM_PWM_ConfigChannel(&htim2, &tim_ocPWM, TIM_CHANNEL_2) != HAL_OK)
    {
        Error_Handler();
    }

    if(HAL_TIM_PWM_ConfigChannel(&htim2, &tim_ocPWM, TIM_CHANNEL_3) != HAL_OK)
    {
        Error_Handler();
    }

    if(HAL_TIM_PWM_ConfigChannel(&htim2, &tim_ocPWM, TIM_CHANNEL_4) != HAL_OK)
    {
        Error_Handler();
    }

}




//funcion encargado del manejo de errores
void Error_Handler(void)
{
    __HAL_RCC_GPIOB_CLK_ENABLE();
    GPIO_InitTypeDef GPIO_ERROR;
    GPIO_ERROR.Pin = GPIO_PIN_12;
    GPIO_ERROR.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_ERROR.Pull = GPIO_NOPULL;
    GPIO_ERROR.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_ERROR);
    while(1)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12);
        HAL_Delay(100);
    }
}
#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
