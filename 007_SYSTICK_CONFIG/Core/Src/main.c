#include "main.h"

/*definicion de variables glogables*/
UART_HandleTypeDef huart2;

/*definicion de prototipo de funciones*/
void SystemClock_Config(void);
void UART2_Init(void);
void GPIO_Init(void);



int main(void)
{
    /*se realiza la inicializacion del flash y de bajo nivel*/
    HAL_Init();
    /*se configura el reloj del sistema*/
    SystemClock_Config();
    /*se inicializa el puerto usart2*/
    UART2_Init();
    /*se inicializa los pines de los gpio*/
    GPIO_Init();

    char *text = "configuracion exitosa\r\n";
    uint8_t size = strlen(text);
    HAL_UART_Transmit(&huart2, (uint8_t *)text, size, HAL_MAX_DELAY);
    while(1)
    {

    }
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef osc_init = {0};
    RCC_ClkInitTypeDef clk_init = {0};

    osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    osc_init.HSEState = RCC_HSE_ON;

    if(HAL_RCC_OscConfig(&osc_init) != HAL_OK)
        Error_Handler();

    clk_init.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | \
                         RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
    clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clk_init.APB1CLKDivider = RCC_HCLK_DIV1;
    clk_init.APB2CLKDivider = RCC_HCLK_DIV1;

    if(HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0) != HAL_OK)
        Error_Handler();
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 10);

    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
}

void UART2_Init(void)
{
    /*inicializacion de alto nivel*/
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;

    if(HAL_UART_Init(&huart2) != HAL_OK)
        Error_Handler();
}

void GPIO_Init(void)
{
    //se activa el reloj del IOPORTA*/
    __HAL_RCC_GPIOA_CLK_ENABLE();
    GPIO_InitTypeDef gpio_init = {0};
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);

    gpio_init.Pin = GPIO_PIN_0;
    gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init.Pull = GPIO_NOPULL;
    gpio_init.Speed = GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(GPIOA, &gpio_init);
}
//funcion que se encarga de generar un interrupcion cada 100ms
void HAL_SYSTICK_Callback(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
}
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */

    /* USER CODE END Error_Handler_Debug */
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
