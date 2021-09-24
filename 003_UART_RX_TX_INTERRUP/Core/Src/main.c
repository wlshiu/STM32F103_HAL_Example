#include "main.h"



/*PROTOTIPO DE FUNCIONES*/
void SystemClock_Config(void);
void UART2_Init(void);
void GPIOA_Init(void);
uint8_t upper(uint8_t ch);
void receiveData(UART_HandleTypeDef *huart);


/*DECLARACION DE VARIABLES GLOBALES*/

UART_HandleTypeDef huart2;
uint8_t data;                                   //para la recepcion de datos
uint8_t data_buffer[100];                       //buffer donde se acumularan los datos
uint8_t reception_complete = FALSE;
uint8_t count = 0;                              //contador para el desplazamiento en el buffer

int main(void)
{

    HAL_Init();
    SystemClock_Config();

    UART2_Init();
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);
    GPIOA_Init();

    /*declaracion de variables */
    char *text = "STM32F103C8T6->USART2 INTERRUP READY!\r\n";
    uint16_t size = strlen(text);
    HAL_UART_Transmit(&huart2, (uint8_t *)text, size, HAL_MAX_DELAY);


    while(1)
    {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
        HAL_Delay(100);
    }

}


void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

    /** Initializes the CPU, AHB and APB busses clocks
    */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
    /** Initializes the CPU, AHB and APB busses clocks
    */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
    {
        Error_Handler();
    }
}

void UART2_Init(void)
{
    //inicializacin de alto nivel
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;

    if(HAL_UART_Init(&huart2) != HAL_OK)
    {
        Error_Handler();
    }
}

void receiveData_IT(UART_HandleTypeDef *huart)
{
    if(__HAL_UART_GET_FLAG(huart, UART_FLAG_RXNE))
    {

        data = huart->Instance->DR;
        if(data == '\r')
        {
            data_buffer[count++] = '\r';
            HAL_UART_Transmit(&huart2, data_buffer, count, HAL_MAX_DELAY);
            count   = 0;
        }
        else
        {
            data_buffer[count++] = upper(data);
        }
    }
}

//funcion que convierte en mayuscula los dados recibidos

uint8_t upper(uint8_t ch)
{
    if( ch >= 'a' && ch <= 'z')
    {
        ch = ch - ( 'a' - 'A');
    }

    return ch;
}

//MANEJADOR DE LA INTERRUPCION USART2
/*void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
     if(data == '\r')
     {
         reception_complete = TRUE;
         data_buffer[count++]='\r';
         HAL_UART_Transmit(huart,data_buffer,count,HAL_MAX_DELAY);
     }
     else
     {
         data_buffer[count++] = data;
     }
}*/
void GPIOA_Init(void)
{
    GPIO_InitTypeDef gpio_init = {0};

    gpio_init.Pin = GPIO_PIN_0;
    gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
    gpio_init.Pull = GPIO_NOPULL;
    gpio_init.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOA, &gpio_init);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
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
