#include "main.h"

/*definicion de variables globales*/
TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart1;

/*fin */
/*definicion de prototipo de funciones*/
void SystemClock_Config(void);
void TIM2_Init(void);
void UART1_init(void);
/*ESTA FUNCION RECIBE DOS PARAMETROS
 * @CNT_CLK->es igual APB1CLK/(htim2.Init.prescaler+1)
 * @freq_deseado->es el valor de la frecuencia que tenga el pulso de salida
 */
uint32_t computePulse(uint32_t CNT_CLK, uint32_t freq_deseado);
/*fin*/
/*DEFINICION DE VARIABLES GLOBALES*/
uint32_t pulse_ch1 = 1000;
uint32_t pulse_ch2 = 1250;
uint32_t pulse_ch3 = 1666;
uint32_t pulse_ch4  = 2500;
uint32_t CCRx_value ;
/*fin*/
int main(void)
{
    //inicializacion de bajo nivel
    HAL_Init();
    //inicializacion del reloj del MCU
    SystemClock_Config();
    //se inicializa el usart1
    UART1_init();
    //se inicaliza el timer2 ->output compare
    TIM2_Init();

    //se envia un mensaje de inicializacion conrrecta
    printf("configuracion exitosa\r\n");
    /*pulse_ch1 = computePulse(10000,3); no recomendable - toma mucho tiempo en el arranque del conteo
    pulse_ch2 = computePulse(10000,1);
    pulse_ch3 = computePulse(10000,2);
    pulse_ch4 = computePulse(10000,1);*/
    /*inicializacion del timer2 en comparacio de salida con interrupcion*/
    printf("valores de los pulsos establecedidos\r\n");
    if(HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }
    if(HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_2) != HAL_OK)
    {
        Error_Handler();
    }
    if(HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_3) != HAL_OK)
    {
        Error_Handler();
    }
    if(HAL_TIM_OC_Start_IT(&htim2, TIM_CHANNEL_4) != HAL_OK)
    {
        Error_Handler();
    }
    printf("conteo iniciado\r\n");
    while(1)
    {

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

/*funcion que inicializa los parametros del usar1 para la comunicacion uart1*/
void UART1_init(void)
{
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 9600;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Mode = UART_MODE_TX;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    if(HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }

}

//funcion para el manejo del printf
int __io_putchar(int ch)
{
    uint8_t c;
    c = ch & 0x00FF;
    HAL_UART_Transmit(&huart1, &c, 1, 10);
    return ch;
}
//Funcion que inicializa el timer en modo comparacion de salida
void TIM2_Init(void)
{
    TIM_OC_InitTypeDef tim_ocInit = {0};

    htim2.Instance = TIM2;
    htim2.Init.Prescaler = 800 - 1;
    htim2.Init.Period = 0xFFFF;
    if(HAL_TIM_OC_Init(&htim2) != HAL_OK)
    {
        Error_Handler();
    }
    tim_ocInit.OCMode = TIM_OCMODE_TOGGLE;
    tim_ocInit.OCPolarity = TIM_OCPOLARITY_HIGH;
    tim_ocInit.Pulse = pulse_ch1;
    if(HAL_TIM_OC_ConfigChannel(&htim2, &tim_ocInit, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }
    tim_ocInit.Pulse = pulse_ch2;
    if(HAL_TIM_OC_ConfigChannel(&htim2, &tim_ocInit, TIM_CHANNEL_2) != HAL_OK)
    {
        Error_Handler();
    }
    tim_ocInit.Pulse = pulse_ch3;
    if(HAL_TIM_OC_ConfigChannel(&htim2, &tim_ocInit, TIM_CHANNEL_3) != HAL_OK)
    {
        Error_Handler();
    }
    tim_ocInit.Pulse = pulse_ch4;
    if(HAL_TIM_OC_ConfigChannel(&htim2, &tim_ocInit, TIM_CHANNEL_4) != HAL_OK)
    {
        Error_Handler();
    }

}
//esta funcion maneja la interrupcion del timer2->output compare
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
    {
        CCRx_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);
        __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_1, CCRx_value + pulse_ch1);
    }
    if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
    {
        CCRx_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
        __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, CCRx_value + pulse_ch2);
    }
    if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_3)
    {
        CCRx_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_3);
        __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_3, CCRx_value + pulse_ch3);
    }
    if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_4)
    {
        CCRx_value = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_4);
        __HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_4, CCRx_value + pulse_ch4);
    }

}

//funcion que calula el valor que se tiene que sumar al CCR1 para que genera una frecuencia deseada
uint32_t computePulse(uint32_t CNT_CLK, uint32_t freq_deseado)
{

    return (CNT_CLK / (2 * freq_deseado));
}

/*ESTA FUNCION MUESTRA EL PARPADEO DEL LED CONECTADO AL PB12 INDICANDO UN ERROR EN ALGUNA PARTE DE EJ
 * EJECUCION DEL PROGRAMA
 */
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
