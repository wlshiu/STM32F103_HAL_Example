
#include "main.h"

/*se crea una variable para inicializar el periferico USART1*/
UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */


void SystemClock_Config(void);
static void USART1_UART_Init(void);
void GPIO_Init(void);

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

int main(void)
{

    HAL_Init();                                               //inicializacion


    SystemClock_Config();
    USART1_UART_Init();
    GPIO_Init();
    printf("CONFIGURACION EXITOSA\r\n");

    printf("\nSE IMPRIMEN LOS VALORES DE LOS RELOJES\r\n");
    printf("SYSCLOK->%ld\r\n", HAL_RCC_GetSysClockFreq());
    printf("HBCLCOK->%ld\r\n", HAL_RCC_GetHCLKFreq());
    printf("APB1CLOCK->%ld\r\n", HAL_RCC_GetPCLK1Freq());
    printf("APB2CLOCK->%ld\r\n", HAL_RCC_GetPCLK2Freq());
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
        HAL_Delay(2000);

    }
}


void SystemClock_Config(void)
{
    RCC_OscInitTypeDef osc_init = {0};
    RCC_ClkInitTypeDef clk_init = {0};

    //se inicializa primero el oscilador
    osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    osc_init.HSEState = RCC_HSE_ON;
    if(HAL_RCC_OscConfig(&osc_init) != HAL_OK)
        Error_Handler();
    clk_init.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | \
                         RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_SYSCLK;        //se ingresa los valores del reloj que se van a confifurar
    clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;                           //se selecciona la fuente de reloj
    clk_init.AHBCLKDivider = RCC_SYSCLK_DIV2;                               //se devide el reloj del sysclock
    clk_init.APB2CLKDivider = RCC_HCLK_DIV2;
    clk_init.APB1CLKDivider = RCC_HCLK_DIV2;
    if(HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0) != HAL_OK)
        Error_Handler();

}


static void USART1_UART_Init(void)
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

void GPIO_Init(void)
{
    GPIO_InitTypeDef gpio_init = {0};
    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);

    gpio_init.Pin = GPIO_PIN_0;
    gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init.Pull = GPIO_NOPULL;
    gpio_init.Speed = GPIO_SPEED_FREQ_MEDIUM;

    HAL_GPIO_Init(GPIOA, &gpio_init);
}


void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */

    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
