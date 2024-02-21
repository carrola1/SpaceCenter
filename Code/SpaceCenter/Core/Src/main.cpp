/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "diskio.h"
#include "ff.h"
#include "WavPlayer.hpp"
#include "TouchBoard.hpp"
#include "TouchBoardGroup.hpp"
#include "LedButton.hpp"
#include "RocketStream.hpp"
//#include "StarCountAudio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NUM_BOARDS 24
#define NUM_STAR_COLORS 4
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2S_HandleTypeDef hi2s2;
DMA_HandleTypeDef hdma_spi2_tx;

SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi1_tx;

TIM_HandleTypeDef htim2;
DMA_HandleTypeDef hdma_tim2_ch1;
DMA_HandleTypeDef hdma_tim2_ch3;
DMA_HandleTypeDef hdma_tim2_ch4;

RNG_HandleTypeDef hrng;

/* USER CODE BEGIN PV */

// Objects
FATFS FatFs;
TouchBoardGroup touchGroup0 = TouchBoardGroup(NUM_BOARDS, htim2, TIM_CHANNEL_1, hdma_tim2_ch1);
std::vector<TouchState_enum> touchStates(NUM_BOARDS);
std::vector<TouchEvent_enum> touchEvents(NUM_BOARDS);
WavPlayer audioPlayer = WavPlayer(hi2s2);
RocketStream rocketStream = RocketStream(htim2, TIM_CHANNEL_3, hdma_tim2_ch3);
LedButton buttonL = LedButton(BUTTON_LED_L_GPIO_Port, BUTTON_LED_L_Pin, BUTTON_L_GPIO_Port, BUTTON_L_Pin);
LedButton buttonR = LedButton(BUTTON_LED_R_GPIO_Port, BUTTON_LED_R_Pin, BUTTON_R_GPIO_Port, BUTTON_R_Pin);

// Variables
ButtonTriggerEvent_enum buttonTriggerEventL;
ButtonTriggerEvent_enum buttonTriggerEventR;
uint8_t rocketInd = 0;
uint8_t streamInd = 0;
uint8_t starGameCount = 0;
uint8_t colorInd = 0;
uint32_t timer = 0;
uint32_t timer2 = 0;

char* starCountAudioFiles[24] =
{"One.wav", "Two.wav", "Three.wav", "Four.wav", "Five.wav", "Six.wav", "Seven.wav",
 "Eight.wav", "Nine.wav", "Ten.wav", "Eleven.wav", "Twelve.wav", "Thirteen.wav",
 "Fourteen.wav", "Fifteen.wav", "Sixteen.wav", "Seventeen.wav", "Eighteen.wav",
 "Nineteen.wav", "Twenty.wav", "Twenty-One.wav", "Twenty-Two.wav", "Twenty-Three.wav",
 "Twenty-Four.wav"};

// Colors
PixelColor_s starColorDef = PixelColor_s{50, 50, 50};
std::vector<PixelColor_s> starColors = {
    {200, 10, 200},
    {50, 50, 200},
    {200, 50, 50},
    {50, 200, 100}
};

// States
typedef enum states {ST_off, ST_reset, ST_idle, ST_imAStar, ST_rocketCountdown,
                     ST_rocketLaunch, ST_rocketExplode, ST_rocketSong} states;
states state = ST_off;

// Timers
uint32_t INACTIVITY_TO_MS = 600;
uint32_t ROCKET_EXPLOSION_TRANS_MS = 50;
uint32_t ROCKET_SONG_TRANS_MS = 200;
uint32_t ROCKET_SONG_STAR_TRANS_MS = 600;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2S2_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM2_Init(void);
static void MX_RNG_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// Mount SD Card
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2S2_Init();
  MX_SPI1_Init();
  MX_TIM2_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */

  // Mount SD Card
  HAL_GPIO_WritePin(SD_SPI1_CS_N_GPIO_Port, SD_SPI1_CS_N_Pin, GPIO_PIN_SET);
  FRESULT fr;
  fr = f_mount(&FatFs, "", 1);

  // Set LED defaults
  HAL_GPIO_WritePin(TEST_LED_GPIO_Port, TEST_LED_Pin, GPIO_PIN_SET);

  touchGroup0.setAllPixelColor(0,0,0);
  touchGroup0.showPixels();
  rocketStream.setAllRocketColor(0, 0, 0);
  rocketStream.setAllStreamColor(0, 0, 0);
  rocketStream.showPixels();

  buttonR.setLedState(OFF);
  buttonL.setLedState(OFF);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {

    switch(state) {
      
      ///////////////////////////////////////////////////////////////////////////////////
      // Off State
      // Press a button to turn on
      ///////////////////////////////////////////////////////////////////////////////////
      case ST_off:
        touchGroup0.setAllPixelColor(0,0,0);
        touchGroup0.showPixels();
        while (1) {
          buttonR.updateButtonState();
          buttonL.updateButtonState();
          buttonTriggerEventR = buttonR.getTriggerEvent();
          buttonTriggerEventL = buttonL.getTriggerEvent();
          if (buttonTriggerEventR == RISING || buttonTriggerEventL == RISING) {
            buttonR.setLedState(ON);
            buttonL.setLedState(ON);
            touchGroup0.setAllPixelColor(starColorDef.r,starColorDef.g,starColorDef.b);
            touchGroup0.showPixels();
            state = ST_idle;
            break;
          }
        }

      ///////////////////////////////////////////////////////////////////////////////////
      // Reset State
      ///////////////////////////////////////////////////////////////////////////////////
      case ST_reset:
        touchGroup0.setAllPixelColor(starColorDef.r,starColorDef.g,starColorDef.b);
        touchGroup0.showPixels();
        rocketStream.reset();
        state = ST_idle;
        break;

      ///////////////////////////////////////////////////////////////////////////////////
      // Idle State
      ///////////////////////////////////////////////////////////////////////////////////
      case ST_idle:

        // Star Count Game
        buttonR.updateButtonState();
        buttonTriggerEventR = buttonR.getTriggerEvent();
        if (buttonTriggerEventR == RISING) {
          if (starGameCount == NUM_BOARDS-1){
            touchGroup0.setBoardColor(starGameCount, starColors[colorInd].r, starColors[colorInd].g, starColors[colorInd].b);
            touchGroup0.showPixels();
            audioPlayer.play_atomic(starCountAudioFiles[starGameCount]);
            starGameCount = 0;
            colorInd = 0;
            HAL_Delay(200);
            touchGroup0.imAStarSetup();
            HAL_Delay(1000);
            audioPlayer.open_wav("ImAStar.wav");
            state = ST_imAStar;
          } else {
            touchGroup0.setBoardColor(starGameCount, starColors[colorInd].r, starColors[colorInd].g, starColors[colorInd].b);
            touchGroup0.showPixels();
            audioPlayer.play_atomic(starCountAudioFiles[starGameCount]);
            if (colorInd == NUM_STAR_COLORS-1) {
              colorInd = 0;
            } else {
              colorInd++;
            }
            starGameCount++;
          }
        }

        // Check for Rocket Launch
        buttonL.updateButtonState();
        buttonTriggerEventL = buttonL.getTriggerEvent();
        if (buttonTriggerEventL == RISING) {
          touchGroup0.setAllPixelColor(0, 0, 0);
          touchGroup0.showPixels();
          starGameCount = 0;
          colorInd = 0;
          rocketStream.rocketLaunch(true);
          audioPlayer.open_wav("RocketBuilding.wav");
          state = ST_rocketCountdown;
        }

        // Detect Touches
        touchGroup0.updateTouchStates();
        touchEvents = touchGroup0.getTouchEvents();
        for (int i=0; i<NUM_BOARDS; i++) {
          if (touchEvents[i] == TOUCH_RISING) {
            touchGroup0.twinkleBoard(i);
            audioPlayer.open_wav("Twinkle.wav");
            audioPlayer.play_chunk();
          }
        }

        if (audioPlayer.audioPlaying) {
          audioPlayer.play_chunk();
        }

        break;


      ///////////////////////////////////////////////////////////////////////////////////
      // I'm A Star
      ///////////////////////////////////////////////////////////////////////////////////
      case ST_imAStar:
        if (touchGroup0.imAStarUpdate()) {
          audioPlayer.close_wav();
          touchGroup0.setAllPixelColor(0, 0, 0);
          touchGroup0.showPixels();
          HAL_Delay(1000);
          state = ST_reset;
        } else {
          audioPlayer.play_chunk();
        }
        break;


      ///////////////////////////////////////////////////////////////////////////////////
      // Rocket Countdown
      ///////////////////////////////////////////////////////////////////////////////////
      case ST_rocketCountdown:
        // Check for Rocket Launch
        buttonL.updateButtonState();
        buttonTriggerEventL = buttonL.getTriggerEvent();
        LaunchState_enum launchState;

        if (buttonTriggerEventL == RISING) {
          launchState = rocketStream.rocketLaunch(true);
        } else {
          launchState = rocketStream.rocketLaunch(false);
        }

        if (launchState == INCREMENT) {
          rocketStream.incrementLaunch();
          audioPlayer.play_chunk();
          rocketStream.showPixels();
        } else if (launchState == DECREMENT){
          rocketStream.decrementLaunch();
          audioPlayer.play_chunk();
          rocketStream.showPixels();
        } else if (launchState == LAUNCHED) {
          audioPlayer.close_wav();
          HAL_Delay(500);
          timer = HAL_GetTick();
          audioPlayer.open_wav("Explosion.wav");
          state = ST_rocketExplode;
          break;
        } else if (launchState == LANDED) {
          audioPlayer.close_wav();
          state = ST_reset;
          break;
        } else {
          //DO NOTHING
        }
        audioPlayer.play_chunk();
        break;

      ///////////////////////////////////////////////////////////////////////////////////
      // Rocket Explosion
      ///////////////////////////////////////////////////////////////////////////////////
      case ST_rocketExplode:
        if (audioPlayer.play_chunk()) {
          uint32_t timer_new = HAL_GetTick();
          if (timer_new - timer > ROCKET_EXPLOSION_TRANS_MS) {
            rocketStream.incrementLaunch();
            audioPlayer.play_chunk();
            rocketStream.showPixels();
            audioPlayer.play_chunk();
            timer = timer_new;
          }
        } else {
          audioPlayer.open_wav("ToTheMoon.wav");
          state = ST_rocketSong;
        }
        break;

      ///////////////////////////////////////////////////////////////////////////////////
      // Rocket Song
      ///////////////////////////////////////////////////////////////////////////////////
      case ST_rocketSong:
        if (audioPlayer.play_chunk()) {
          uint32_t timer_new = HAL_GetTick();
          if (timer_new - timer > ROCKET_SONG_TRANS_MS) {
            rocketStream.incrementLaunch();
            audioPlayer.play_chunk();
            rocketStream.showPixels();
            audioPlayer.play_chunk();
            timer = timer_new;
          }
          if (timer_new - timer2 > ROCKET_SONG_STAR_TRANS_MS) {
            uint8_t star1 = (HAL_RNG_GetRandomNumber(&hrng) % NUM_BOARDS);
            uint8_t star2 = (HAL_RNG_GetRandomNumber(&hrng) % NUM_BOARDS);
            uint8_t star3 = (HAL_RNG_GetRandomNumber(&hrng) % NUM_BOARDS);
            uint8_t star4 = (HAL_RNG_GetRandomNumber(&hrng) % NUM_BOARDS);
            touchGroup0.setAllPixelColor(0, 0, 0);
            touchGroup0.setBoardColor(star1, starColorDef.r, starColorDef.g, starColorDef.b);
            touchGroup0.setBoardColor(star2, starColorDef.r, starColorDef.g, starColorDef.b);
            touchGroup0.setBoardColor(star3, starColorDef.r, starColorDef.g, starColorDef.b);
            touchGroup0.setBoardColor(star4, starColorDef.r, starColorDef.g, starColorDef.b);
            touchGroup0.showPixels();
            timer2 = timer_new;
          }
        } else {
          state = ST_reset;
        }
        break;

      default:
        state = ST_idle;
    }

	/* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
  RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2S2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2S2_Init(void)
{

  /* USER CODE BEGIN I2S2_Init 0 */

  /* USER CODE END I2S2_Init 0 */

  /* USER CODE BEGIN I2S2_Init 1 */

  /* USER CODE END I2S2_Init 1 */
  hi2s2.Instance = SPI2;
  hi2s2.Init.Mode = I2S_MODE_MASTER_TX;
  hi2s2.Init.Standard = I2S_STANDARD_PHILIPS;
  hi2s2.Init.DataFormat = I2S_DATAFORMAT_16B;
  hi2s2.Init.MCLKOutput = I2S_MCLKOUTPUT_DISABLE;
  hi2s2.Init.AudioFreq = I2S_AUDIOFREQ_44K;
  hi2s2.Init.CPOL = I2S_CPOL_HIGH;
  if (HAL_I2S_Init(&hi2s2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2S2_Init 2 */

  /* USER CODE END I2S2_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 35;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_ENABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  /* DMA1_Channel2_3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel2_3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel2_3_IRQn);
  /* DMA1_Channel4_5_6_7_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_5_6_7_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_5_6_7_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BUTTON_LED_L_GPIO_Port, BUTTON_LED_L_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(BUTTON_LED_R_GPIO_Port, BUTTON_LED_R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(TEST_LED_GPIO_Port, TEST_LED_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, AUDIO_SD_N_L_Pin|AUDIO_SD_N_R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SD_SPI1_CS_N_GPIO_Port, SD_SPI1_CS_N_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : BUTTON_L_Pin SD_DET_A_Pin SD_DET_B_Pin */
  GPIO_InitStruct.Pin = BUTTON_L_Pin|SD_DET_A_Pin|SD_DET_B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : BUTTON_LED_L_Pin */
  GPIO_InitStruct.Pin = BUTTON_LED_L_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BUTTON_LED_L_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : BUTTON_R_Pin TOUCH_STAR_0_Pin TOUCH_STAR_1_Pin TOUCH_STAR_2_Pin
                           TOUCH_STAR_15_Pin TOUCH_STAR_16_Pin TOUCH_STAR_17_Pin */
  GPIO_InitStruct.Pin = BUTTON_R_Pin|TOUCH_STAR_0_Pin|TOUCH_STAR_1_Pin|TOUCH_STAR_2_Pin
                          |TOUCH_STAR_15_Pin|TOUCH_STAR_16_Pin|TOUCH_STAR_17_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : BUTTON_LED_R_Pin */
  GPIO_InitStruct.Pin = BUTTON_LED_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(BUTTON_LED_R_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TEST_LED_Pin */
  GPIO_InitStruct.Pin = TEST_LED_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(TEST_LED_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TOUCH_G7_1_SAMP_Pin */
  GPIO_InitStruct.Pin = TOUCH_G7_1_SAMP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF3_TSC;
  HAL_GPIO_Init(TOUCH_G7_1_SAMP_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : TOUCH_STAR_3_Pin TOUCH_STAR_4_Pin TOUCH_STAR_5_Pin TOUCH_STAR_6_Pin
                           TOUCH_STAR_7_Pin TOUCH_STAR_8_Pin TOUCH_STAR_18_Pin TOUCH_STAR_19_Pin
                           TOUCH_STAR_20_Pin */
  GPIO_InitStruct.Pin = TOUCH_STAR_3_Pin|TOUCH_STAR_4_Pin|TOUCH_STAR_5_Pin|TOUCH_STAR_6_Pin
                          |TOUCH_STAR_7_Pin|TOUCH_STAR_8_Pin|TOUCH_STAR_18_Pin|TOUCH_STAR_19_Pin
                          |TOUCH_STAR_20_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : TOUCH_STAR_9_Pin TOUCH_STAR_10_Pin TOUCH_STAR_11_Pin TOUCH_STAR_12_Pin
                           TOUCH_STAR_13_Pin TOUCH_STAR_14_Pin TOUCH_STAR_21_Pin TOUCH_STAR_22_Pin
                           TOUCH_STAR_23_Pin */
  GPIO_InitStruct.Pin = TOUCH_STAR_9_Pin|TOUCH_STAR_10_Pin|TOUCH_STAR_11_Pin|TOUCH_STAR_12_Pin
                          |TOUCH_STAR_13_Pin|TOUCH_STAR_14_Pin|TOUCH_STAR_21_Pin|TOUCH_STAR_22_Pin
                          |TOUCH_STAR_23_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : AUDIO_SD_N_L_Pin */
  GPIO_InitStruct.Pin = AUDIO_SD_N_L_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(AUDIO_SD_N_L_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : AUDIO_SD_N_R_Pin */
  GPIO_InitStruct.Pin = AUDIO_SD_N_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(AUDIO_SD_N_R_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MODE_SW_Pin */
  GPIO_InitStruct.Pin = MODE_SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MODE_SW_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SD_SPI1_CS_N_Pin */
  GPIO_InitStruct.Pin = SD_SPI1_CS_N_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(SD_SPI1_CS_N_GPIO_Port, &GPIO_InitStruct);

}

/* RNG init function */
static void MX_RNG_Init(void)
{
  hrng.Instance = RNG;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_I2S_TxCpltCallback(I2S_HandleTypeDef* hi2s) {
  return;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
