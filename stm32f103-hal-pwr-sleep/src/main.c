/**
  ******************************************************************************
  * @file    ../stm32f103-hal-pwr-sleep/src/main.c
  * @author  Erwin Ouyang
  * @version 1.0
  * @date    7 Feb 2017
  * @brief   This example shows how to use PWR HAL API to configure the Sleep
  *          mode.
  ******************************************************************************
  * Copyright(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright
  *      notice, this list of conditions and the following disclaimer in the
  *      documentation and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its
  *      contributors may be used to endorse or promote products derived from
  *      this software without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  * POSSIBILITY OF SUCH DAMAGE.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void RCC_SystemClock_Config(void);
void GPIO_Output_Config(void);
void GPIO_Input_Config(void);
void PWR_Config(void);
void PWR_EnterSleepMode(void);
void Error_Handler(void);

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
    /*## HAL initialization ##################################################*/
    HAL_Init();

    /*## System clocks initialization ########################################*/
    /* Set the SYSCLK at maximum frequency (72 MHz) */
    RCC_SystemClock_Config();

    /*## GPIO initialization #################################################*/
    GPIO_Output_Config();
    GPIO_Input_Config();

    /*## PWR initialization ##################################################*/
    PWR_Config();

    /* Enter Sleep mode */
    PWR_EnterSleepMode();
    /* The codes below will be executed only after waked up from the Sleep
     * mode. */

    /*## Main loop ###########################################################*/
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
        HAL_Delay(1000);
    }
}

/**
  * @brief  System clock configuration:
  *             System clock source = PLL (HSE)
  *             SYSCLK(Hz)          = 72000000
  *             HCLK(Hz)            = 72000000
  *             AHB prescaler       = 1
  *             APB1 prescaler      = 2
  *             APB2 prescaler      = 1
  *             HSE frequency(Hz)   = 8000000
  *             HSE PREDIV1         = 1
  *             PLLMUL              = 9
  *             Flash latency(WS)   = 2
  * @param  None
  * @retval None
  */
void RCC_SystemClock_Config(void)
{
    RCC_ClkInitTypeDef rccClkInit;
    RCC_OscInitTypeDef rccOscInit;

    /*## STEP 1: Configure HSE and PLL #######################################*/
    rccOscInit.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    rccOscInit.HSEState       = RCC_HSE_ON;
    rccOscInit.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    rccOscInit.PLL.PLLState   = RCC_PLL_ON;
    rccOscInit.PLL.PLLSource  = RCC_PLLSOURCE_HSE;
    rccOscInit.PLL.PLLMUL     = RCC_PLL_MUL9;
    if (HAL_RCC_OscConfig(&rccOscInit) != HAL_OK)
    {
        Error_Handler();
    }

    /*## STEP 2: Configure SYSCLK, HCLK, PCLK1, and PCLK2 ####################*/
    rccClkInit.ClockType      = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                                 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
    rccClkInit.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
    rccClkInit.AHBCLKDivider  = RCC_SYSCLK_DIV1;
    rccClkInit.APB2CLKDivider = RCC_HCLK_DIV1;
    rccClkInit.APB1CLKDivider = RCC_HCLK_DIV2;
    if (HAL_RCC_ClockConfig(&rccClkInit, FLASH_LATENCY_2) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief  GPIO configuration:
  *             GPIO  = GPIOB
  *             Pin   = PB6, PB7, PB8, PB9
  *             Mode  = Output push-pull
  *             Speed = Low
  * @param  None
  * @retval None
  */
void GPIO_Output_Config(void)
{
    GPIO_InitTypeDef gpioInit;

    /*## STEP 1: Configure RCC peripheral ####################################*/
    __HAL_RCC_GPIOB_CLK_ENABLE();

    /*## STEP 2: Configure GPIO ##############################################*/
    gpioInit.Pin   = GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
    gpioInit.Mode  = GPIO_MODE_OUTPUT_PP;
    gpioInit.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &gpioInit);
}

/**
  * @brief  GPIO configuration:
  *             GPIO = GPIOC
  *             Pin  = PC15
  *             Mode = Input interrupt falling
  *             Pull = Pull-up
  * @param  None
  * @retval None
  */
void GPIO_Input_Config(void)
{
    GPIO_InitTypeDef gpioInit;

    /*## STEP 1: Configure RCC peripheral ####################################*/
    __HAL_RCC_GPIOC_CLK_ENABLE();

    /*## STEP 2: Configure GPIO ##############################################*/
    gpioInit.Pin  = GPIO_PIN_15;
    gpioInit.Mode = GPIO_MODE_IT_FALLING;
    gpioInit.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &gpioInit);

    /*## STEP 3: Configure NVIC ##############################################*/
    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

/**
  * @brief  EXTI line detection callback.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line.
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_15)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
    }
}

/**
  * @brief  PWR configuration
  * @param  None
  * @retval None
  */
void PWR_Config(void)
{
    /*## STEP 1: Configure RCC peripheral ####################################*/
    __HAL_RCC_PWR_CLK_ENABLE();
}

/**
  * @brief  Enter Sleep mode.
  * @param  None
  * @retval None
  */
void PWR_EnterSleepMode(void)
{
    /* Suspend tick increment to prevent wake up by SysTick interrupt. */
    HAL_SuspendTick();
    /* Enter Sleep mode. */
    HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
    /* The codes below will be executed only after waked up from the Sleep
     * mode. */

    /* Resume tick interrupt if disabled prior to sleep mode entry. */
    HAL_ResumeTick();
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
    /* Turn red LED on */
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    while (1);
}

/******************************** END OF FILE *********************************/
/******************************************************************************/
