/**
  ******************************************************************************
  * @file    ../stm32f103-hal-tim-time-base/src/main.c
  * @author  Erwin Ouyang
  * @version 1.0
  * @date    1 Feb 2017
  * @brief   This example code shows how to use TIM HAL API to generate a time
  *          base of one second with the corresponding interrupt request.
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
TIM_HandleTypeDef timHandle;

/* Private function prototypes -----------------------------------------------*/
void RCC_SystemClock_Config(void);
void GPIO_Output_Config(void);
void TIM_Config(void);
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

    /*## TIM initialization ##################################################*/
    TIM_Config();

    /*## Main loop ###########################################################*/
    while (1);
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
  * @brief  TIM configuration:
  *             TIM                = TIM1
  *             Prescaler          = 7200
  *             Counter mode       = Up
  *             Period             = 10000
  *             Clock division     = 0
  *             Repetition counter = 0
  * @param  None
  * @retval None
  */
void TIM_Config(void)
{
    /*## STEP 1: Configure TIM ###############################################*/
    /* Configure TIM base */
    timHandle.Instance               = TIM1;
    /* TIM1CLK = CK_INT = 72 MHz
     * Prescaler = 7200
     * CK_PSC = CK_CNT = clock counter = 72 MHz/7200 = 10 kHz (0.1ms) */
    timHandle.Init.Prescaler         = 7200 - 1;
    timHandle.Init.CounterMode       = TIM_COUNTERMODE_UP;
    /* ARR = counter overflow = period = 10000 count
     * TIM interrupt period = 0.1ms * 10000 = 1s */
    timHandle.Init.Period            = 10000 - 1;
    timHandle.Init.ClockDivision     = 0;
    timHandle.Init.RepetitionCounter = 0;
    if (HAL_TIM_Base_Init(&timHandle) != HAL_OK)
    {
        Error_Handler();
    }

    /*## STEP 2: Start TIM ###################################################*/
    if (HAL_TIM_Base_Start_IT(&timHandle) != HAL_OK)
    {
        Error_Handler();
    }
}

/**
  * @brief  TIM MSP configuration callback.
  * @param  None
  * @retval None
  */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef *htim)
{
    /*## STEP 1: Configure RCC peripheral ####################################*/
    __HAL_RCC_TIM1_CLK_ENABLE();

    /*## STEP 2: Configure NVIC ##############################################*/
    HAL_NVIC_SetPriority(TIM1_UP_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(TIM1_UP_IRQn);
}

/**
  * @brief  Period elapsed callback in non blocking mode.
  * @param  htim: TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    /* Toggle yellow LED */
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
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
