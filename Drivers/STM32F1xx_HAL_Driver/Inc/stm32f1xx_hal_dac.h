/**
  ******************************************************************************
  * @file    stm32f1xx_hal_dac.h
  * @author  MCD Application Team
  * @version V1.1.1
  * @date    12-May-2017
  * @brief   Header file of DAC HAL module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F1xx_HAL_DAC_H
#define __STM32F1xx_HAL_DAC_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined (STM32F100xB) || defined (STM32F100xE) || defined (STM32F101xE) || defined (STM32F101xG) || defined (STM32F103xE) || defined (STM32F103xG) || defined (STM32F105xC) || defined (STM32F107xC)

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal_def.h"

/** @addtogroup STM32F1xx_HAL_Driver
  * @{
  */

/** @addtogroup DAC
  * @{
  */

/* Exported types ------------------------------------------------------------*/

/** @defgroup DAC_Exported_Types DAC Exported Types
  * @{
  */

/**
  * @brief  HAL State structures definition
  */
typedef enum
{
    HAL_DAC_STATE_RESET             = 0x00U,  /*!< DAC not yet initialized or disabled  */
    HAL_DAC_STATE_READY             = 0x01U,  /*!< DAC initialized and ready for use    */
    HAL_DAC_STATE_BUSY              = 0x02U,  /*!< DAC internal processing is ongoing   */
    HAL_DAC_STATE_TIMEOUT           = 0x03U,  /*!< DAC timeout state                    */
    HAL_DAC_STATE_ERROR             = 0x04U   /*!< DAC error state                      */

} HAL_DAC_StateTypeDef;

/**
  * @brief  DAC handle Structure definition
  */
typedef struct
{
    DAC_TypeDef                 *Instance;     /*!< Register base address             */

    __IO HAL_DAC_StateTypeDef   State;         /*!< DAC communication state           */

    HAL_LockTypeDef             Lock;          /*!< DAC locking object                */

    DMA_HandleTypeDef           *DMA_Handle1;  /*!< Pointer DMA handler for channel 1 */

    DMA_HandleTypeDef           *DMA_Handle2;  /*!< Pointer DMA handler for channel 2 */

    __IO uint32_t               ErrorCode;     /*!< DAC Error code                    */

} DAC_HandleTypeDef;

/**
  * @brief   DAC Configuration regular Channel structure definition
  */
typedef struct
{
    uint32_t DAC_Trigger;       /*!< Specifies the external trigger for the selected DAC channel.
                                   This parameter can be a value of @ref DACEx_trigger_selection
                                   Note: For STM32F100x high-density value line devices, additional trigger sources are available. */

    uint32_t DAC_OutputBuffer;  /*!< Specifies whether the DAC channel output buffer is enabled or disabled.
                                   This parameter can be a value of @ref DAC_output_buffer */

} DAC_ChannelConfTypeDef;

/**
  * @}
  */

/* Exported constants --------------------------------------------------------*/

/** @defgroup DAC_Exported_Constants DAC Exported Constants
  * @{
  */

/** @defgroup DAC_Error_Code DAC Error Code
  * @{
  */
#define  HAL_DAC_ERROR_NONE              0x00000000U    /*!< No error                          */
#define  HAL_DAC_ERROR_DMAUNDERRUNCH1    0x00000001U    /*!< DAC channel1 DMA underrun error   */
#define  HAL_DAC_ERROR_DMAUNDERRUNCH2    0x00000002U    /*!< DAC channel2 DMA underrun error   */
#define  HAL_DAC_ERROR_DMA               0x00000004U    /*!< DMA error                         */
/**
  * @}
  */

/** @defgroup DAC_output_buffer DAC output buffer
  * @{
  */
#define DAC_OUTPUTBUFFER_ENABLE            0x00000000U
#define DAC_OUTPUTBUFFER_DISABLE           ((uint32_t)DAC_CR_BOFF1)

/**
  * @}
  */

/** @defgroup DAC_Channel_selection DAC Channel selection
  * @{
  */
#define DAC_CHANNEL_1                      0x00000000U
#define DAC_CHANNEL_2                      0x00000010U

/**
  * @}
  */

/** @defgroup DAC_data_alignement DAC data alignement
  * @{
  */
#define DAC_ALIGN_12B_R                    0x00000000U
#define DAC_ALIGN_12B_L                    0x00000004U
#define DAC_ALIGN_8B_R                     0x00000008U

/**
  * @}
  */

/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/

/** @defgroup DAC_Exported_Macros DAC Exported Macros
  * @{
  */

/** @brief Reset DAC handle state
  * @param  __HANDLE__: specifies the DAC handle.
  * @retval None
  */
#define __HAL_DAC_RESET_HANDLE_STATE(__HANDLE__) ((__HANDLE__)->State = HAL_DAC_STATE_RESET)

/** @brief Enable the DAC channel
  * @param  __HANDLE__: specifies the DAC handle.
  * @param  __DAC_Channel__: specifies the DAC channel
  * @retval None
  */
#define __HAL_DAC_ENABLE(__HANDLE__, __DAC_Channel__) \
((__HANDLE__)->Instance->CR |=  (DAC_CR_EN1 << (__DAC_Channel__)))

/** @brief Disable the DAC channel
  * @param  __HANDLE__: specifies the DAC handle
  * @param  __DAC_Channel__: specifies the DAC channel.
  * @retval None
  */
#define __HAL_DAC_DISABLE(__HANDLE__, __DAC_Channel__) \
((__HANDLE__)->Instance->CR &=  ~(DAC_CR_EN1 << (__DAC_Channel__)))


/**
  * @}
  */

/* Private macro -------------------------------------------------------------*/

/** @defgroup DAC_Private_Macros DAC Private Macros
  * @{
  */
#define IS_DAC_OUTPUT_BUFFER_STATE(STATE) (((STATE) == DAC_OUTPUTBUFFER_ENABLE) || \
                                           ((STATE) == DAC_OUTPUTBUFFER_DISABLE))

#define IS_DAC_CHANNEL(CHANNEL) (((CHANNEL) == DAC_CHANNEL_1) || \
                                 ((CHANNEL) == DAC_CHANNEL_2))

#define IS_DAC_ALIGN(ALIGN) (((ALIGN) == DAC_ALIGN_12B_R) || \
                             ((ALIGN) == DAC_ALIGN_12B_L) || \
                             ((ALIGN) == DAC_ALIGN_8B_R))

#define IS_DAC_DATA(DATA) ((DATA) <= 0xFFF0U)

#define DAC_DHR12R1_ALIGNMENT(__ALIGNMENT__) (0x00000008U + (__ALIGNMENT__))

#define DAC_DHR12R2_ALIGNMENT(__ALIGNMENT__) (0x00000014U + (__ALIGNMENT__))

#define DAC_DHR12RD_ALIGNMENT(__ALIGNMENT__) (0x00000020U + (__ALIGNMENT__))

/**
  * @}
  */


/* Include DAC HAL Extension module */
#include "stm32f1xx_hal_dac_ex.h"

/* Exported functions --------------------------------------------------------*/

/** @addtogroup DAC_Exported_Functions
  * @{
  */

/** @addtogroup DAC_Exported_Functions_Group1
  * @{
  */
/* Initialization and de-initialization functions *****************************/
HAL_StatusTypeDef HAL_DAC_Init(DAC_HandleTypeDef *hdac);
HAL_StatusTypeDef HAL_DAC_DeInit(DAC_HandleTypeDef *hdac);
void HAL_DAC_MspInit(DAC_HandleTypeDef *hdac);
void HAL_DAC_MspDeInit(DAC_HandleTypeDef *hdac);

/**
  * @}
  */

/** @addtogroup DAC_Exported_Functions_Group2
  * @{
  */
/* IO operation functions *****************************************************/
HAL_StatusTypeDef HAL_DAC_Start(DAC_HandleTypeDef *hdac, uint32_t Channel);
HAL_StatusTypeDef HAL_DAC_Stop(DAC_HandleTypeDef *hdac, uint32_t Channel);
HAL_StatusTypeDef HAL_DAC_Start_DMA(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t *pData, uint32_t Length, uint32_t Alignment);
HAL_StatusTypeDef HAL_DAC_Stop_DMA(DAC_HandleTypeDef *hdac, uint32_t Channel);
HAL_StatusTypeDef HAL_DAC_SetValue(DAC_HandleTypeDef *hdac, uint32_t Channel, uint32_t Alignment, uint32_t Data);
uint32_t HAL_DAC_GetValue(DAC_HandleTypeDef *hdac, uint32_t Channel);

/**
  * @}
  */

/** @addtogroup DAC_Exported_Functions_Group3
  * @{
  */
/* Peripheral Control functions ***********************************************/
HAL_StatusTypeDef HAL_DAC_ConfigChannel(DAC_HandleTypeDef *hdac, DAC_ChannelConfTypeDef *sConfig, uint32_t Channel);

/**
  * @}
  */

/** @addtogroup DAC_Exported_Functions_Group4
  * @{
  */
/* Peripheral State functions *************************************************/
HAL_DAC_StateTypeDef HAL_DAC_GetState(DAC_HandleTypeDef *hdac);
uint32_t HAL_DAC_GetError(DAC_HandleTypeDef *hdac);

void HAL_DAC_ConvCpltCallbackCh1(DAC_HandleTypeDef *hdac);
void HAL_DAC_ConvHalfCpltCallbackCh1(DAC_HandleTypeDef *hdac);
void HAL_DAC_ErrorCallbackCh1(DAC_HandleTypeDef *hdac);


/**
  * @}
  */

/**
  * @}
  */

/** @addtogroup DAC_Private_Functions DAC Private Functions
  * @{
  */
void DAC_DMAConvCpltCh1(DMA_HandleTypeDef *hdma);
void DAC_DMAHalfConvCpltCh1(DMA_HandleTypeDef *hdma);
void DAC_DMAErrorCh1(DMA_HandleTypeDef *hdma);

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#endif /* STM32F100xB || STM32F100xE || STM32F101xE || STM32F101xG || STM32F103xE || STM32F103xG || STM32F105xC || STM32F107xC */

#ifdef __cplusplus
}
#endif


#endif /*__STM32F1xx_HAL_DAC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

