
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/*DECLARACION DE VARIABLES GLOBALES*/
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart1;

uint32_t input_capture[2] = {0};
uint8_t count = 1;
double freq_ic = 0.0;
double diferencia;

/*fin de declaracion*/

void SystemClock_Config(void);
void UART1_Init(void);
void TIM2_Init(void);
void GPIO_Init(void);

int main(void)
{
    //inicializacion de bajo nivel
    HAL_Init();
    //inicializacion del reloj
    SystemClock_Config();
    //inicializacion del USART1
    UART1_Init();
    //inicializacion del timer2
    TIM2_Init();
    //se inicializa el pin GPIO_PIN_2 como salida
    GPIO_Init();

    printf("INICIALIZACION DEL UART1 EXITOSA\r\n");
    printf("\nSE IMPRIMEN LOS VALORES DE LOS RELOJES\r\n");
    printf("SYSCLOK->%ld\r\n", HAL_RCC_GetSysClockFreq());
    printf("HBCLCOK->%ld\r\n", HAL_RCC_GetHCLKFreq());
    printf("APB1CLOCK->%ld\r\n", HAL_RCC_GetPCLK1Freq());
    printf("APB2CLOCK->%ld\r\n", HAL_RCC_GetPCLK2Freq());
    /*Se inicia la captura de entrada*/
    HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
    //bucle infinito
    while(1)
    {
        printf("frecuencia medida->%.2f Hz\r\n", freq_ic);
        HAL_Delay(300);
    }
}


void SystemClock_Config(void)
{
    RCC_OscInitTypeDef osc_init;
    RCC_ClkInitTypeDef clk_init;
    //configuracion de parametros para la configuracion del reloj
    osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    osc_init.HSEState = RCC_HSE_ON;

    //se configura el reloj
    if(HAL_RCC_OscConfig(&osc_init) != HAL_OK)
    {
        Error_Handler();
    }
    clk_init.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | \
                         RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_SYSCLK;
    clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
    clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;
    clk_init.APB1CLKDivider = RCC_HCLK_DIV1;
    clk_init.APB2CLKDivider = RCC_HCLK_DIV1;
    //se configura la fuente de reloj y los prescaler del reloj
    if(HAL_RCC_ClockConfig(&clk_init, FLASH_ACR_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
    //se inicializa los paramentros del systick
    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / 1000);           //1kHZ
    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
    //se elige la señal de salida por el MCO1
    HAL_RCC_MCOConfig(RCC_MCO1, RCC_MCO1SOURCE_SYSCLK, RCC_MCODIV_1);

}

void UART1_Init(void)
{
    //inicializacion de parametros del UART1
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 115200;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Mode = UART_MODE_TX;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart1.Init.OverSampling = UART_OVERSAMPLING_16;
    //se iniciliza el uart1
    if(HAL_UART_Init(&huart1) != HAL_OK)
    {
        Error_Handler();
    }
}

void TIM2_Init(void)
{
    TIM_IC_InitTypeDef tim_ic = {0};
    //time-base init
    htim2.Instance = TIM2;
    htim2.Init.Prescaler = 0;
    htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim2.Init.Period = 0xFFFF - 1;
    if(HAL_TIM_IC_Init(&htim2) != HAL_OK)
    {
        Error_Handler();
    }
    //configuracion de parametros para el mode captura de entrada
    tim_ic.ICFilter = 0x0;
    tim_ic.ICPolarity = TIM_ICPOLARITY_RISING;          //deteccion de flanco ascendente
    tim_ic.ICPrescaler = TIM_ICPSC_DIV1;                //prescaler de la señal de entrada
    tim_ic.ICSelection = TIM_ICSELECTION_DIRECTTI;      //se selecciona canal de entrada directo
    if(HAL_TIM_IC_ConfigChannel(&htim2, &tim_ic, TIM_CHANNEL_1) != HAL_OK)
    {
        Error_Handler();
    }
}

void GPIO_Init(void)
{
    GPIO_InitTypeDef gpio_init = {0};
    gpio_init.Pin = GPIO_PIN_2;
    gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init.Pull = GPIO_NOPULL;
    gpio_init.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &gpio_init);
}
/*FUNCIONES QUE MANEJAN LAS INTERRUPCIONES*/
void HAL_SYSTICK_Callback(void)
{
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
    {
        if(count == 1)
        {
            input_capture[0] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
            count++;
        }
        else if(count == 2)
        {
            input_capture[1] = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
            count = 1;
            //se calcula la frecuencia
            if(input_capture[1] > input_capture[0])
            {
                diferencia = (double)(input_capture[1] - input_capture[0]);
            }
            else if(input_capture[0] > input_capture[1])
            {
                diferencia = (double)(0xFFFF - input_capture[0] + input_capture[1] + 1);
            }
            else
            {
                Error_Handler();
            }
            freq_ic = ((HAL_RCC_GetPCLK1Freq() / (htim->Init.Prescaler + 1)) / diferencia)    ;

        }

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

void Error_Handler(void)
{
    while(1);
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
