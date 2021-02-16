/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_L_Pin GPIO_PIN_4
#define BUTTON_L_GPIO_Port GPIOE
#define BUTTON_LED_L_Pin GPIO_PIN_5
#define BUTTON_LED_L_GPIO_Port GPIOE
#define BUTTON_R_Pin GPIO_PIN_13
#define BUTTON_R_GPIO_Port GPIOC
#define BUTTON_LED_R_Pin GPIO_PIN_14
#define BUTTON_LED_R_GPIO_Port GPIOC
#define TEST_LED_Pin GPIO_PIN_10
#define TEST_LED_GPIO_Port GPIOH
#define TOUCH_G7_1_SAMP_Pin GPIO_PIN_0
#define TOUCH_G7_1_SAMP_GPIO_Port GPIOC
#define TOUCH_G7_2_STAR_0_Pin GPIO_PIN_1
#define TOUCH_G7_2_STAR_0_GPIO_Port GPIOC
#define TOUCH_G7_3_STAR_1_Pin GPIO_PIN_2
#define TOUCH_G7_3_STAR_1_GPIO_Port GPIOC
#define TOUCH_G7_4_STAR_2_Pin GPIO_PIN_3
#define TOUCH_G7_4_STAR_2_GPIO_Port GPIOC
#define TOUCH_G1_1_SAMP_Pin GPIO_PIN_0
#define TOUCH_G1_1_SAMP_GPIO_Port GPIOA
#define TOUCH_G1_2_STAR_3_Pin GPIO_PIN_1
#define TOUCH_G1_2_STAR_3_GPIO_Port GPIOA
#define TOUCH_G1_3_STAR_4_Pin GPIO_PIN_2
#define TOUCH_G1_3_STAR_4_GPIO_Port GPIOA
#define TOUCH_G1_4_STAR_5_Pin GPIO_PIN_3
#define TOUCH_G1_4_STAR_5_GPIO_Port GPIOA
#define TOUCH_G2_1_SAMP_Pin GPIO_PIN_4
#define TOUCH_G2_1_SAMP_GPIO_Port GPIOA
#define TOUCH_G2_2_STAR_6_Pin GPIO_PIN_5
#define TOUCH_G2_2_STAR_6_GPIO_Port GPIOA
#define TOUCH_G2_3_STAR_7_Pin GPIO_PIN_6
#define TOUCH_G2_3_STAR_7_GPIO_Port GPIOA
#define TOUCH_G2_4_STAR_8_Pin GPIO_PIN_7
#define TOUCH_G2_4_STAR_8_GPIO_Port GPIOA
#define TOUCH_G3_1_SAMP_Pin GPIO_PIN_5
#define TOUCH_G3_1_SAMP_GPIO_Port GPIOC
#define TOUCH_G3_2_STAR_9_Pin GPIO_PIN_0
#define TOUCH_G3_2_STAR_9_GPIO_Port GPIOB
#define TOUCH_G3_3_STAR_10_Pin GPIO_PIN_1
#define TOUCH_G3_3_STAR_10_GPIO_Port GPIOB
#define TOUCH_G3_4_STAR_11_Pin GPIO_PIN_2
#define TOUCH_G3_4_STAR_11_GPIO_Port GPIOB
#define SD_DET_A_Pin GPIO_PIN_7
#define SD_DET_A_GPIO_Port GPIOE
#define SD_DET_B_Pin GPIO_PIN_8
#define SD_DET_B_GPIO_Port GPIOE
#define NEOPIX_STARS_Pin GPIO_PIN_9
#define NEOPIX_STARS_GPIO_Port GPIOE
#define NEOPIX_ROCKET_L_Pin GPIO_PIN_11
#define NEOPIX_ROCKET_L_GPIO_Port GPIOE
#define NEOPIX_ROCKET_R_Pin GPIO_PIN_12
#define NEOPIX_ROCKET_R_GPIO_Port GPIOE
#define SD_SPI1_SCK_Pin GPIO_PIN_13
#define SD_SPI1_SCK_GPIO_Port GPIOE
#define SD_SPI1_MISO_Pin GPIO_PIN_14
#define SD_SPI1_MISO_GPIO_Port GPIOE
#define SD_SPI1_MOSI_Pin GPIO_PIN_15
#define SD_SPI1_MOSI_GPIO_Port GPIOE
#define TOUCH_G6_1_SAMP_Pin GPIO_PIN_11
#define TOUCH_G6_1_SAMP_GPIO_Port GPIOB
#define TOUCH_G6_2_STAR_12_Pin GPIO_PIN_12
#define TOUCH_G6_2_STAR_12_GPIO_Port GPIOB
#define TOUCH_G6_3_STAR_13_Pin GPIO_PIN_13
#define TOUCH_G6_3_STAR_13_GPIO_Port GPIOB
#define TOUCH_G6_4_STAR_14_Pin GPIO_PIN_14
#define TOUCH_G6_4_STAR_14_GPIO_Port GPIOB
#define I2S_SPI2_SD_Pin GPIO_PIN_15
#define I2S_SPI2_SD_GPIO_Port GPIOB
#define AUDIO_SD_N_L_Pin GPIO_PIN_10
#define AUDIO_SD_N_L_GPIO_Port GPIOD
#define AUDIO_SD_N_R_Pin GPIO_PIN_11
#define AUDIO_SD_N_R_GPIO_Port GPIOD
#define MODE_SW_Pin GPIO_PIN_15
#define MODE_SW_GPIO_Port GPIOD
#define TOUCH_G8_1_SAMP_Pin GPIO_PIN_6
#define TOUCH_G8_1_SAMP_GPIO_Port GPIOC
#define TOUCH_G8_2_STAR_15_Pin GPIO_PIN_7
#define TOUCH_G8_2_STAR_15_GPIO_Port GPIOC
#define TOUCH_G8_3_STAR_16_Pin GPIO_PIN_8
#define TOUCH_G8_3_STAR_16_GPIO_Port GPIOC
#define TOUCH_G8_4_STAR_17_Pin GPIO_PIN_9
#define TOUCH_G8_4_STAR_17_GPIO_Port GPIOC
#define TOUCH_G4_1_SAMP_Pin GPIO_PIN_9
#define TOUCH_G4_1_SAMP_GPIO_Port GPIOA
#define TOUCH_G4_2_STAR_18_Pin GPIO_PIN_10
#define TOUCH_G4_2_STAR_18_GPIO_Port GPIOA
#define TOUCH_G4_3_STAR_19_Pin GPIO_PIN_11
#define TOUCH_G4_3_STAR_19_GPIO_Port GPIOA
#define TOUCH_G4_4_STAR_20_Pin GPIO_PIN_12
#define TOUCH_G4_4_STAR_20_GPIO_Port GPIOA
#define SD_SPI1_CS_N_Pin GPIO_PIN_15
#define SD_SPI1_CS_N_GPIO_Port GPIOA
#define I2S_SPI2_WS_Pin GPIO_PIN_0
#define I2S_SPI2_WS_GPIO_Port GPIOD
#define I2S_SPI2_CK_Pin GPIO_PIN_1
#define I2S_SPI2_CK_GPIO_Port GPIOD
#define TOUCH_G4_1_SAMPB3_Pin GPIO_PIN_3
#define TOUCH_G4_1_SAMPB3_GPIO_Port GPIOB
#define TOUCH_G5_2_STAR_21_Pin GPIO_PIN_4
#define TOUCH_G5_2_STAR_21_GPIO_Port GPIOB
#define TOUCH_G5_3_STAR_22_Pin GPIO_PIN_6
#define TOUCH_G5_3_STAR_22_GPIO_Port GPIOB
#define TOUCH_G5_4_STAR_23_Pin GPIO_PIN_7
#define TOUCH_G5_4_STAR_23_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
