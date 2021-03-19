/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : stm32l0xx_hal_msp.c
  * Description        : This file provides code for the MSP Initialization
  *                      and de-Initialization codes.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */
extern DMA_HandleTypeDef hdma_spi2_tx;

extern DMA_HandleTypeDef hdma_spi1_rx;

extern DMA_HandleTypeDef hdma_spi1_tx;

extern DMA_HandleTypeDef hdma_tim2_ch1;

extern DMA_HandleTypeDef hdma_tim2_ch3;

extern DMA_HandleTypeDef hdma_tim2_ch4;

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN Define */

/* USER CODE END Define */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN Macro */

/* USER CODE END Macro */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* External functions --------------------------------------------------------*/
/* USER CODE BEGIN ExternalFunctions */

/* USER CODE END ExternalFunctions */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
                    /**
  * Initializes the Global MSP.
  */
void HAL_MspInit(void)
{
  /* USER CODE BEGIN MspInit 0 */

  /* USER CODE END MspInit 0 */

  __HAL_RCC_SYSCFG_CLK_ENABLE();
  __HAL_RCC_PWR_CLK_ENABLE();

  /* System interrupt init*/

  /* USER CODE BEGIN MspInit 1 */

  /* USER CODE END MspInit 1 */
}

/**
* @brief I2S MSP Initialization
* This function configures the hardware resources used in this example
* @param hi2s: I2S handle pointer
* @retval None
*/
void HAL_I2S_MspInit(I2S_HandleTypeDef* hi2s)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hi2s->Instance==SPI2)
  {
  /* USER CODE BEGIN SPI2_MspInit 0 */

  /* USER CODE END SPI2_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_SPI2_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    /**I2S2 GPIO Configuration
    PB15     ------> I2S2_SD
    PD0     ------> I2S2_WS
    PD1     ------> I2S2_CK
    */
    GPIO_InitStruct.Pin = I2S_SPI2_SD_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF0_SPI2;
    HAL_GPIO_Init(I2S_SPI2_SD_GPIO_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = I2S_SPI2_WS_Pin|I2S_SPI2_CK_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF1_SPI2;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /* I2S2 DMA Init */
    /* SPI2_TX Init */
    hdma_spi2_tx.Instance = DMA1_Channel7;
    hdma_spi2_tx.Init.Request = DMA_REQUEST_2;
    hdma_spi2_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi2_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi2_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi2_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi2_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi2_tx.Init.Mode = DMA_NORMAL;
    hdma_spi2_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_spi2_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hi2s,hdmatx,hdma_spi2_tx);

  /* USER CODE BEGIN SPI2_MspInit 1 */

  /* USER CODE END SPI2_MspInit 1 */
  }

}

/**
* @brief I2S MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hi2s: I2S handle pointer
* @retval None
*/
void HAL_I2S_MspDeInit(I2S_HandleTypeDef* hi2s)
{
  if(hi2s->Instance==SPI2)
  {
  /* USER CODE BEGIN SPI2_MspDeInit 0 */

  /* USER CODE END SPI2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI2_CLK_DISABLE();

    /**I2S2 GPIO Configuration
    PB15     ------> I2S2_SD
    PD0     ------> I2S2_WS
    PD1     ------> I2S2_CK
    */
    HAL_GPIO_DeInit(I2S_SPI2_SD_GPIO_Port, I2S_SPI2_SD_Pin);

    HAL_GPIO_DeInit(GPIOD, I2S_SPI2_WS_Pin|I2S_SPI2_CK_Pin);

    /* I2S2 DMA DeInit */
    HAL_DMA_DeInit(hi2s->hdmatx);
  /* USER CODE BEGIN SPI2_MspDeInit 1 */

  /* USER CODE END SPI2_MspDeInit 1 */
  }

}

/**
* @brief SPI MSP Initialization
* This function configures the hardware resources used in this example
* @param hspi: SPI handle pointer
* @retval None
*/
void HAL_SPI_MspInit(SPI_HandleTypeDef* hspi)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(hspi->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspInit 0 */

  /* USER CODE END SPI1_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_SPI1_CLK_ENABLE();

    __HAL_RCC_GPIOE_CLK_ENABLE();
    /**SPI1 GPIO Configuration
    PE13     ------> SPI1_SCK
    PE14     ------> SPI1_MISO
    PE15     ------> SPI1_MOSI
    */
    GPIO_InitStruct.Pin = SD_SPI1_SCK_Pin|SD_SPI1_MISO_Pin|SD_SPI1_MOSI_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF2_SPI1;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /* SPI1 DMA Init */
    /* SPI1_RX Init */
    hdma_spi1_rx.Instance = DMA1_Channel2;
    hdma_spi1_rx.Init.Request = DMA_REQUEST_1;
    hdma_spi1_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_spi1_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_rx.Init.Mode = DMA_NORMAL;
    hdma_spi1_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_spi1_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hspi,hdmarx,hdma_spi1_rx);

    /* SPI1_TX Init */
    hdma_spi1_tx.Instance = DMA1_Channel3;
    hdma_spi1_tx.Init.Request = DMA_REQUEST_1;
    hdma_spi1_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;
    hdma_spi1_tx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi1_tx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi1_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi1_tx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi1_tx.Init.Mode = DMA_NORMAL;
    hdma_spi1_tx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_spi1_tx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(hspi,hdmatx,hdma_spi1_tx);

  /* USER CODE BEGIN SPI1_MspInit 1 */

  /* USER CODE END SPI1_MspInit 1 */
  }

}

/**
* @brief SPI MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param hspi: SPI handle pointer
* @retval None
*/
void HAL_SPI_MspDeInit(SPI_HandleTypeDef* hspi)
{
  if(hspi->Instance==SPI1)
  {
  /* USER CODE BEGIN SPI1_MspDeInit 0 */

  /* USER CODE END SPI1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**SPI1 GPIO Configuration
    PE13     ------> SPI1_SCK
    PE14     ------> SPI1_MISO
    PE15     ------> SPI1_MOSI
    */
    HAL_GPIO_DeInit(GPIOE, SD_SPI1_SCK_Pin|SD_SPI1_MISO_Pin|SD_SPI1_MOSI_Pin);

    /* SPI1 DMA DeInit */
    HAL_DMA_DeInit(hspi->hdmarx);
    HAL_DMA_DeInit(hspi->hdmatx);
  /* USER CODE BEGIN SPI1_MspDeInit 1 */

  /* USER CODE END SPI1_MspDeInit 1 */
  }

}

/**
* @brief TIM_Base MSP Initialization
* This function configures the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim_base)
{
  if(htim_base->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspInit 0 */

  /* USER CODE END TIM2_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_TIM2_CLK_ENABLE();

    /* TIM2 DMA Init */
    /* TIM2_CH1 Init */
    hdma_tim2_ch1.Instance = DMA1_Channel5;
    hdma_tim2_ch1.Init.Request = DMA_REQUEST_8;
    hdma_tim2_ch1.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_tim2_ch1.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_tim2_ch1.Init.MemInc = DMA_MINC_ENABLE;
    hdma_tim2_ch1.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tim2_ch1.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_tim2_ch1.Init.Mode = DMA_CIRCULAR;
    hdma_tim2_ch1.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_tim2_ch1) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(htim_base,hdma[TIM_DMA_ID_CC1],hdma_tim2_ch1);

    /* TIM2_CH3 Init */
    hdma_tim2_ch3.Instance = DMA1_Channel1;
    hdma_tim2_ch3.Init.Request = DMA_REQUEST_8;
    hdma_tim2_ch3.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_tim2_ch3.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_tim2_ch3.Init.MemInc = DMA_MINC_ENABLE;
    hdma_tim2_ch3.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tim2_ch3.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_tim2_ch3.Init.Mode = DMA_CIRCULAR;
    hdma_tim2_ch3.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_tim2_ch3) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(htim_base,hdma[TIM_DMA_ID_CC3],hdma_tim2_ch3);

    /* TIM2_CH4 Init */
    hdma_tim2_ch4.Instance = DMA1_Channel4;
    hdma_tim2_ch4.Init.Request = DMA_REQUEST_8;
    hdma_tim2_ch4.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_tim2_ch4.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_tim2_ch4.Init.MemInc = DMA_MINC_ENABLE;
    hdma_tim2_ch4.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_tim2_ch4.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
    hdma_tim2_ch4.Init.Mode = DMA_CIRCULAR;
    hdma_tim2_ch4.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_tim2_ch4) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(htim_base,hdma[TIM_DMA_ID_CC4],hdma_tim2_ch4);

  /* USER CODE BEGIN TIM2_MspInit 1 */

  /* USER CODE END TIM2_MspInit 1 */
  }

}

void HAL_TIM_MspPostInit(TIM_HandleTypeDef* htim)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(htim->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspPostInit 0 */

  /* USER CODE END TIM2_MspPostInit 0 */

    __HAL_RCC_GPIOE_CLK_ENABLE();
    /**TIM2 GPIO Configuration
    PE9     ------> TIM2_CH1
    PE11     ------> TIM2_CH3
    PE12     ------> TIM2_CH4
    */
    GPIO_InitStruct.Pin = NEOPIX_STARS_Pin|NEOPIX_ROCKET_L_Pin|NEOPIX_ROCKET_R_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF0_TIM2;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM2_MspPostInit 1 */

  /* USER CODE END TIM2_MspPostInit 1 */
  }

}
/**
* @brief TIM_Base MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htim_base: TIM_Base handle pointer
* @retval None
*/
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef* htim_base)
{
  if(htim_base->Instance==TIM2)
  {
  /* USER CODE BEGIN TIM2_MspDeInit 0 */

  /* USER CODE END TIM2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TIM2_CLK_DISABLE();

    /* TIM2 DMA DeInit */
    HAL_DMA_DeInit(htim_base->hdma[TIM_DMA_ID_CC1]);
    HAL_DMA_DeInit(htim_base->hdma[TIM_DMA_ID_CC3]);
    HAL_DMA_DeInit(htim_base->hdma[TIM_DMA_ID_CC4]);
  /* USER CODE BEGIN TIM2_MspDeInit 1 */

  /* USER CODE END TIM2_MspDeInit 1 */
  }

}

/**
* @brief TSC MSP Initialization
* This function configures the hardware resources used in this example
* @param htsc: TSC handle pointer
* @retval None
*/
void HAL_TSC_MspInit(TSC_HandleTypeDef* htsc)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(htsc->Instance==TSC)
  {
  /* USER CODE BEGIN TSC_MspInit 0 */

  /* USER CODE END TSC_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_TSC_CLK_ENABLE();

    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**TSC GPIO Configuration
    PC0     ------> TSC_G7_IO1
    PC1     ------> TSC_G7_IO2
    PC2     ------> TSC_G7_IO3
    PC3     ------> TSC_G7_IO4
    PA0     ------> TSC_G1_IO1
    PA1     ------> TSC_G1_IO2
    PA2     ------> TSC_G1_IO3
    PA3     ------> TSC_G1_IO4
    PA4     ------> TSC_G2_IO1
    PA5     ------> TSC_G2_IO2
    PA6     ------> TSC_G2_IO3
    PA7     ------> TSC_G2_IO4
    PC5     ------> TSC_G3_IO1
    PB0     ------> TSC_G3_IO2
    PB1     ------> TSC_G3_IO3
    PB2     ------> TSC_G3_IO4
    PB11     ------> TSC_G6_IO1
    PB12     ------> TSC_G6_IO2
    PB13     ------> TSC_G6_IO3
    PB14     ------> TSC_G6_IO4
    PC6     ------> TSC_G8_IO1
    PC7     ------> TSC_G8_IO2
    PC8     ------> TSC_G8_IO3
    PC9     ------> TSC_G8_IO4
    PA9     ------> TSC_G4_IO1
    PA10     ------> TSC_G4_IO2
    PA11     ------> TSC_G4_IO3
    PA12     ------> TSC_G4_IO4
    PB3     ------> TSC_G5_IO1
    PB4     ------> TSC_G5_IO2
    PB6     ------> TSC_G5_IO3
    PB7     ------> TSC_G5_IO4
    */
    GPIO_InitStruct.Pin = TOUCH_G7_1_SAMP_Pin|TOUCH_G3_1_SAMP_Pin|TOUCH_G8_1_SAMP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = TOUCH_G7_2_STAR_0_Pin|TOUCH_G7_3_STAR_1_Pin|TOUCH_G7_4_STAR_2_Pin|TOUCH_G8_2_STAR_15_Pin
                          |TOUCH_G8_3_STAR_16_Pin|TOUCH_G8_4_STAR_17_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = TOUCH_G1_1_SAMP_Pin|TOUCH_G2_1_SAMP_Pin|TOUCH_G4_1_SAMP_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = TOUCH_G1_2_STAR_3_Pin|TOUCH_G1_3_STAR_4_Pin|TOUCH_G1_4_STAR_5_Pin|TOUCH_G2_2_STAR_6_Pin
                          |TOUCH_G2_3_STAR_7_Pin|TOUCH_G2_4_STAR_8_Pin|TOUCH_G4_2_STAR_18_Pin|TOUCH_G4_3_STAR_19_Pin
                          |TOUCH_G4_4_STAR_20_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = TOUCH_G3_2_STAR_9_Pin|TOUCH_G3_3_STAR_10_Pin|TOUCH_G3_4_STAR_11_Pin|TOUCH_G6_2_STAR_12_Pin
                          |TOUCH_G6_3_STAR_13_Pin|TOUCH_G6_4_STAR_14_Pin|TOUCH_G5_2_STAR_21_Pin|TOUCH_G5_3_STAR_22_Pin
                          |TOUCH_G5_4_STAR_23_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = TOUCH_G6_1_SAMP_Pin|TOUCH_G4_1_SAMPB3_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN TSC_MspInit 1 */

  /* USER CODE END TSC_MspInit 1 */
  }

}

/**
* @brief TSC MSP De-Initialization
* This function freeze the hardware resources used in this example
* @param htsc: TSC handle pointer
* @retval None
*/
void HAL_TSC_MspDeInit(TSC_HandleTypeDef* htsc)
{
  if(htsc->Instance==TSC)
  {
  /* USER CODE BEGIN TSC_MspDeInit 0 */

  /* USER CODE END TSC_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_TSC_CLK_DISABLE();

    /**TSC GPIO Configuration
    PC0     ------> TSC_G7_IO1
    PC1     ------> TSC_G7_IO2
    PC2     ------> TSC_G7_IO3
    PC3     ------> TSC_G7_IO4
    PA0     ------> TSC_G1_IO1
    PA1     ------> TSC_G1_IO2
    PA2     ------> TSC_G1_IO3
    PA3     ------> TSC_G1_IO4
    PA4     ------> TSC_G2_IO1
    PA5     ------> TSC_G2_IO2
    PA6     ------> TSC_G2_IO3
    PA7     ------> TSC_G2_IO4
    PC5     ------> TSC_G3_IO1
    PB0     ------> TSC_G3_IO2
    PB1     ------> TSC_G3_IO3
    PB2     ------> TSC_G3_IO4
    PB11     ------> TSC_G6_IO1
    PB12     ------> TSC_G6_IO2
    PB13     ------> TSC_G6_IO3
    PB14     ------> TSC_G6_IO4
    PC6     ------> TSC_G8_IO1
    PC7     ------> TSC_G8_IO2
    PC8     ------> TSC_G8_IO3
    PC9     ------> TSC_G8_IO4
    PA9     ------> TSC_G4_IO1
    PA10     ------> TSC_G4_IO2
    PA11     ------> TSC_G4_IO3
    PA12     ------> TSC_G4_IO4
    PB3     ------> TSC_G5_IO1
    PB4     ------> TSC_G5_IO2
    PB6     ------> TSC_G5_IO3
    PB7     ------> TSC_G5_IO4
    */
    HAL_GPIO_DeInit(GPIOC, TOUCH_G7_1_SAMP_Pin|TOUCH_G7_2_STAR_0_Pin|TOUCH_G7_3_STAR_1_Pin|TOUCH_G7_4_STAR_2_Pin
                          |TOUCH_G3_1_SAMP_Pin|TOUCH_G8_1_SAMP_Pin|TOUCH_G8_2_STAR_15_Pin|TOUCH_G8_3_STAR_16_Pin
                          |TOUCH_G8_4_STAR_17_Pin);

    HAL_GPIO_DeInit(GPIOA, TOUCH_G1_1_SAMP_Pin|TOUCH_G1_2_STAR_3_Pin|TOUCH_G1_3_STAR_4_Pin|TOUCH_G1_4_STAR_5_Pin
                          |TOUCH_G2_1_SAMP_Pin|TOUCH_G2_2_STAR_6_Pin|TOUCH_G2_3_STAR_7_Pin|TOUCH_G2_4_STAR_8_Pin
                          |TOUCH_G4_1_SAMP_Pin|TOUCH_G4_2_STAR_18_Pin|TOUCH_G4_3_STAR_19_Pin|TOUCH_G4_4_STAR_20_Pin);

    HAL_GPIO_DeInit(GPIOB, TOUCH_G3_2_STAR_9_Pin|TOUCH_G3_3_STAR_10_Pin|TOUCH_G3_4_STAR_11_Pin|TOUCH_G6_1_SAMP_Pin
                          |TOUCH_G6_2_STAR_12_Pin|TOUCH_G6_3_STAR_13_Pin|TOUCH_G6_4_STAR_14_Pin|TOUCH_G4_1_SAMPB3_Pin
                          |TOUCH_G5_2_STAR_21_Pin|TOUCH_G5_3_STAR_22_Pin|TOUCH_G5_4_STAR_23_Pin);

  /* USER CODE BEGIN TSC_MspDeInit 1 */

  /* USER CODE END TSC_MspDeInit 1 */
  }

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
