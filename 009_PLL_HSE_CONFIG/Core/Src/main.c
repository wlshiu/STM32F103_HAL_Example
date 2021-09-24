#include "main.h"

//definicion de variables glabales
UART_HandleTypeDef huart1;

//defininicion de prototipos de funciones
void SystemClock_Config(void);
void UART1_Init(void);

//funciones que permite utilizar la funcion printf
int __io_putchar(int ch)
{
    uint8_t c;
    c = ch & 0x00FF;
    HAL_UART_Transmit(&huart1, &c, 1, 10);
    return ch;
}

int _write(int file, char *ptr, int len)
{
    int DataIdx;
    for(DataIdx = 0; DataIdx < len; DataIdx++)
    {
        __io_putchar(*ptr++);
    }
    return len;
}

//FUNCION PRINCIPAL
int main(void)
{
    HAL_Init();
    SystemClock_Config();
    UART1_Init();
    printf("CONFIGURACION EXITOSA DEL PUERTO UART1\r\n");

    printf("SE IMPRIMEN LOS VALORES DE LOS RELOJES\r\n");
    printf("SYSCLOK->%ld\r\n", HAL_RCC_GetSysClockFreq());
    printf("HBCLCOK->%ld\r\n", HAL_RCC_GetHCLKFreq());
    printf("APB1CLOCK->%ld\r\n", HAL_RCC_GetPCLK1Freq());
    printf("APB2CLOCK->%ld\r\n\n", HAL_RCC_GetPCLK2Freq());
    for(;;)
    {

    }
}

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef osc_init = {0};
    RCC_ClkInitTypeDef clk_init = {0};

    //se inicializa los parametros del reloj
    osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    osc_init.HSEState = RCC_HSE_ON;
    osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    osc_init.PLL.PLLState = RCC_PLL_ON;
    osc_init.PLL.PLLMUL = RCC_PLL_MUL9;

    if(HAL_RCC_OscConfig(&osc_init) != HAL_OK)
    {
        Error_Handler();
    }
    clk_init.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | \
                         RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
    clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
    if(HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_1) != HAL_OK)
    {
        Error_Handler();
    }
}
void UART1_Init(void)
{

    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }

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
