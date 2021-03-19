/* USER CODE BEGIN Header */
/**
 ******************************************************************************
  * File Name          : App/tsl_user.c
  * Description        : User configuration file for TOUCHSENSING
  *                      middleWare.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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

#include "tsl_user.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/*============================================================================*/
/* Channels                                                                   */
/*============================================================================*/

/* Source and Configuration (ROM) */
CONST TSL_ChannelSrc_T MyChannels_Src[TSLPRM_TOTAL_CHANNELS] =
{
    { CHANNEL_0_SRC, CHANNEL_0_IO_MSK, CHANNEL_0_GRP_MSK },
    { CHANNEL_1_SRC, CHANNEL_1_IO_MSK, CHANNEL_1_GRP_MSK },
    { CHANNEL_2_SRC, CHANNEL_2_IO_MSK, CHANNEL_2_GRP_MSK },
    { CHANNEL_3_SRC, CHANNEL_3_IO_MSK, CHANNEL_3_GRP_MSK },
    { CHANNEL_4_SRC, CHANNEL_4_IO_MSK, CHANNEL_4_GRP_MSK },
    { CHANNEL_5_SRC, CHANNEL_5_IO_MSK, CHANNEL_5_GRP_MSK },
    { CHANNEL_6_SRC, CHANNEL_6_IO_MSK, CHANNEL_6_GRP_MSK },
    { CHANNEL_7_SRC, CHANNEL_7_IO_MSK, CHANNEL_7_GRP_MSK },
    { CHANNEL_8_SRC, CHANNEL_8_IO_MSK, CHANNEL_8_GRP_MSK },
    { CHANNEL_9_SRC, CHANNEL_9_IO_MSK, CHANNEL_9_GRP_MSK },
    { CHANNEL_10_SRC, CHANNEL_10_IO_MSK, CHANNEL_10_GRP_MSK },
    { CHANNEL_11_SRC, CHANNEL_11_IO_MSK, CHANNEL_11_GRP_MSK },
    { CHANNEL_12_SRC, CHANNEL_12_IO_MSK, CHANNEL_12_GRP_MSK },
    { CHANNEL_13_SRC, CHANNEL_13_IO_MSK, CHANNEL_13_GRP_MSK },
    { CHANNEL_14_SRC, CHANNEL_14_IO_MSK, CHANNEL_14_GRP_MSK },
    { CHANNEL_15_SRC, CHANNEL_15_IO_MSK, CHANNEL_15_GRP_MSK },
    { CHANNEL_16_SRC, CHANNEL_16_IO_MSK, CHANNEL_16_GRP_MSK },
    { CHANNEL_17_SRC, CHANNEL_17_IO_MSK, CHANNEL_17_GRP_MSK },
    { CHANNEL_18_SRC, CHANNEL_18_IO_MSK, CHANNEL_18_GRP_MSK },
    { CHANNEL_19_SRC, CHANNEL_19_IO_MSK, CHANNEL_19_GRP_MSK },
    { CHANNEL_20_SRC, CHANNEL_20_IO_MSK, CHANNEL_20_GRP_MSK },
    { CHANNEL_21_SRC, CHANNEL_21_IO_MSK, CHANNEL_21_GRP_MSK },
    { CHANNEL_22_SRC, CHANNEL_22_IO_MSK, CHANNEL_22_GRP_MSK },
    { CHANNEL_23_SRC, CHANNEL_23_IO_MSK, CHANNEL_23_GRP_MSK },
};

/* Destination (ROM) */
CONST TSL_ChannelDest_T MyChannels_Dest[TSLPRM_TOTAL_CHANNELS] =
{
    { CHANNEL_0_DEST },
    { CHANNEL_1_DEST },
    { CHANNEL_2_DEST },
    { CHANNEL_3_DEST },
    { CHANNEL_4_DEST },
    { CHANNEL_5_DEST },
    { CHANNEL_6_DEST },
    { CHANNEL_7_DEST },
    { CHANNEL_8_DEST },
    { CHANNEL_9_DEST },
    { CHANNEL_10_DEST },
    { CHANNEL_11_DEST },
    { CHANNEL_12_DEST },
    { CHANNEL_13_DEST },
    { CHANNEL_14_DEST },
    { CHANNEL_15_DEST },
    { CHANNEL_16_DEST },
    { CHANNEL_17_DEST },
    { CHANNEL_18_DEST },
    { CHANNEL_19_DEST },
    { CHANNEL_20_DEST },
    { CHANNEL_21_DEST },
    { CHANNEL_22_DEST },
    { CHANNEL_23_DEST },
};

/* Data (RAM) */
TSL_ChannelData_T MyChannels_Data[TSLPRM_TOTAL_CHANNELS];

/*============================================================================*/
/* Banks                                                                      */
/*============================================================================*/

/* List (ROM) */
CONST TSL_Bank_T MyBanks[TSLPRM_TOTAL_BANKS] = {
/* TOUCHKEYS bank(s) definition*/
   {&MyChannels_Src[0], &MyChannels_Dest[0], MyChannels_Data, BANK_0_NBCHANNELS, BANK_0_MSK_CHANNELS, BANK_0_MSK_GROUPS},
   {&MyChannels_Src[8], &MyChannels_Dest[8], MyChannels_Data, BANK_1_NBCHANNELS, BANK_1_MSK_CHANNELS, BANK_1_MSK_GROUPS},
   {&MyChannels_Src[16], &MyChannels_Dest[16], MyChannels_Data, BANK_2_NBCHANNELS, BANK_2_MSK_CHANNELS, BANK_2_MSK_GROUPS},
};
/*============================================================================*/
/* Touchkey sensors                                                           */
/*============================================================================*/

/* Data (RAM) */
TSL_TouchKeyData_T MyTKeys_Data[TSLPRM_TOTAL_TKEYS];

/* Parameters (RAM) */
TSL_TouchKeyParam_T MyTKeys_Param[TSLPRM_TOTAL_TKEYS];

/* State Machine (ROM) */

void MyTKeys_ErrorStateProcess(void);
void MyTKeys_OffStateProcess(void);

CONST TSL_State_T MyTKeys_StateMachine[] =
{
  /* Calibration states */
  /*  0 */ { TSL_STATEMASK_CALIB,              TSL_tkey_CalibrationStateProcess },
  /*  1 */ { TSL_STATEMASK_DEB_CALIB,          TSL_tkey_DebCalibrationStateProcess },
  /* Release states */
  /*  2 */ { TSL_STATEMASK_RELEASE,            TSL_tkey_ReleaseStateProcess },
#if TSLPRM_USE_PROX > 0
  /*  3 */ { TSL_STATEMASK_DEB_RELEASE_PROX,   TSL_tkey_DebReleaseProxStateProcess },
#else
  /*  3 */ { TSL_STATEMASK_DEB_RELEASE_PROX,   0 },
#endif
  /*  4 */ { TSL_STATEMASK_DEB_RELEASE_DETECT, TSL_tkey_DebReleaseDetectStateProcess },
  /*  5 */ { TSL_STATEMASK_DEB_RELEASE_TOUCH,  TSL_tkey_DebReleaseTouchStateProcess },
#if TSLPRM_USE_PROX > 0
  /* Proximity states */
  /*  6 */ { TSL_STATEMASK_PROX,               TSL_tkey_ProxStateProcess },
  /*  7 */ { TSL_STATEMASK_DEB_PROX,           TSL_tkey_DebProxStateProcess },
  /*  8 */ { TSL_STATEMASK_DEB_PROX_DETECT,    TSL_tkey_DebProxDetectStateProcess },
  /*  9 */ { TSL_STATEMASK_DEB_PROX_TOUCH,     TSL_tkey_DebProxTouchStateProcess },
#else
  /*  6 */ { TSL_STATEMASK_PROX,               0 },
  /*  7 */ { TSL_STATEMASK_DEB_PROX,           0 },
  /*  8 */ { TSL_STATEMASK_DEB_PROX_DETECT,    0 },
  /*  9 */ { TSL_STATEMASK_DEB_PROX_TOUCH,     0 },
#endif
  /* Detect states */
  /* 10 */ { TSL_STATEMASK_DETECT,             TSL_tkey_DetectStateProcess },
  /* 11 */ { TSL_STATEMASK_DEB_DETECT,         TSL_tkey_DebDetectStateProcess },
  /* Touch state */
  /* 12 */ { TSL_STATEMASK_TOUCH,              TSL_tkey_TouchStateProcess },
  /* Error states */
  /* 13 */ { TSL_STATEMASK_ERROR,              MyTKeys_ErrorStateProcess },
  /* 14 */ { TSL_STATEMASK_DEB_ERROR_CALIB,    TSL_tkey_DebErrorStateProcess },
  /* 15 */ { TSL_STATEMASK_DEB_ERROR_RELEASE,  TSL_tkey_DebErrorStateProcess },
  /* 16 */ { TSL_STATEMASK_DEB_ERROR_PROX,     TSL_tkey_DebErrorStateProcess },
  /* 17 */ { TSL_STATEMASK_DEB_ERROR_DETECT,   TSL_tkey_DebErrorStateProcess },
  /* 18 */ { TSL_STATEMASK_DEB_ERROR_TOUCH,    TSL_tkey_DebErrorStateProcess },
  /* Other states */
  /* 19 */ { TSL_STATEMASK_OFF,                MyTKeys_OffStateProcess }
};

/* Methods for "extended" type (ROM) */
CONST TSL_TouchKeyMethods_T MyTKeys_Methods =
{
  TSL_tkey_Init,
  TSL_tkey_Process
};

/* TouchKeys list (ROM) */

CONST TSL_TouchKey_T MyTKeys[TSLPRM_TOTAL_TOUCHKEYS] =
{
  { &MyTKeys_Data[0], &MyTKeys_Param[0], &MyChannels_Data[CHANNEL_0_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[1], &MyTKeys_Param[1], &MyChannels_Data[CHANNEL_1_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[2], &MyTKeys_Param[2], &MyChannels_Data[CHANNEL_2_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[3], &MyTKeys_Param[3], &MyChannels_Data[CHANNEL_3_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[4], &MyTKeys_Param[4], &MyChannels_Data[CHANNEL_4_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[5], &MyTKeys_Param[5], &MyChannels_Data[CHANNEL_5_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[6], &MyTKeys_Param[6], &MyChannels_Data[CHANNEL_6_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[7], &MyTKeys_Param[7], &MyChannels_Data[CHANNEL_7_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[8], &MyTKeys_Param[8], &MyChannels_Data[CHANNEL_8_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[9], &MyTKeys_Param[9], &MyChannels_Data[CHANNEL_9_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[10], &MyTKeys_Param[10], &MyChannels_Data[CHANNEL_10_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[11], &MyTKeys_Param[11], &MyChannels_Data[CHANNEL_11_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[12], &MyTKeys_Param[12], &MyChannels_Data[CHANNEL_12_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[13], &MyTKeys_Param[13], &MyChannels_Data[CHANNEL_13_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[14], &MyTKeys_Param[14], &MyChannels_Data[CHANNEL_14_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[15], &MyTKeys_Param[15], &MyChannels_Data[CHANNEL_15_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[16], &MyTKeys_Param[16], &MyChannels_Data[CHANNEL_16_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[17], &MyTKeys_Param[17], &MyChannels_Data[CHANNEL_17_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[18], &MyTKeys_Param[18], &MyChannels_Data[CHANNEL_18_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[19], &MyTKeys_Param[19], &MyChannels_Data[CHANNEL_19_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[20], &MyTKeys_Param[20], &MyChannels_Data[CHANNEL_20_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[21], &MyTKeys_Param[21], &MyChannels_Data[CHANNEL_21_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[22], &MyTKeys_Param[22], &MyChannels_Data[CHANNEL_22_DEST], MyTKeys_StateMachine, &MyTKeys_Methods },
  { &MyTKeys_Data[23], &MyTKeys_Param[23], &MyChannels_Data[CHANNEL_23_DEST], MyTKeys_StateMachine, &MyTKeys_Methods }
};

/*============================================================================*/
/* Generic Objects                                                            */
/*============================================================================*/

/* List (ROM) */
CONST TSL_Object_T MyObjects[TSLPRM_TOTAL_OBJECTS] =
{
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[0] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[1] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[2] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[3] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[4] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[5] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[6] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[7] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[8] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[9] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[10] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[11] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[12] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[13] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[14] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[15] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[16] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[17] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[18] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[19] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[20] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[21] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[22] },
  { TSL_OBJ_TOUCHKEY, (TSL_TouchKey_T *)&MyTKeys[23] }
};

/* Group (RAM) */
TSL_ObjectGroup_T MyObjGroup =
{
  &MyObjects[0],        /* First object */
  TSLPRM_TOTAL_OBJECTS, /* Number of objects */
  0x00,                 /* State mask reset value */
  TSL_STATE_NOT_CHANGED /* Current state */
};

/*============================================================================*/
/* TSL Common Parameters placed in RAM or ROM                                 */
/* --> external declaration in tsl_conf.h                                     */
/*============================================================================*/

TSL_Params_T TSL_Params =
{
  TSLPRM_ACQ_MIN,
  TSLPRM_ACQ_MAX,
  TSLPRM_CALIB_SAMPLES,
  TSLPRM_DTO,
#if TSLPRM_TOTAL_TKEYS > 0
  MyTKeys_StateMachine,   /* Default state machine for TKeys */
  &MyTKeys_Methods,       /* Default methods for TKeys */
#endif
#if TSLPRM_TOTAL_LNRTS > 0
  MyLinRots_StateMachine, /* Default state machine for LinRots */
  &MyLinRots_Methods      /* Default methods for LinRots */
#endif
};

/* Private functions prototype -----------------------------------------------*/

/* Global variables ----------------------------------------------------------*/
/* USER CODE BEGIN Global variables */

/* USER CODE END Global variables */

__IO TSL_tTick_ms_T ECSLastTick; /* Hold the last time value for ECS */

/**
  * @brief  Initialize the STMTouch Driver
  * @param  None
  * @retval None
  */
void tsl_user_Init(void)
{
  TSL_obj_GroupInit(&MyObjGroup); /* Init Objects */

  TSL_Init(MyBanks); /* Init acquisition module */

  tsl_user_SetThresholds(); /* Init thresholds for each object individually (optional) */
}

/**
  * @brief  Execute STMTouch Driver main State machine
  * @param  None
  * @retval status Return TSL_STATUS_OK if the acquisition is done
  */
tsl_user_status_t tsl_user_Exec(void)
{
  static uint32_t idx_bank = 0;
  static uint32_t config_done = 0;
  tsl_user_status_t status = TSL_USER_STATUS_BUSY;

  /* Configure and start bank acquisition */
  if (!config_done)
  {
/* USER CODE BEGIN not config_done start*/

/* USER CODE END not config_done start*/
    TSL_acq_BankConfig(idx_bank);
    TSL_acq_BankStartAcq();
    config_done = 1;
/* USER CODE BEGIN not config_done */

/* USER CODE END not config_done */
  }

  /* Check end of acquisition (polling mode) and read result */
  if (TSL_acq_BankWaitEOC() == TSL_STATUS_OK)
  {
/* USER CODE BEGIN end of acquisition start*/

/* USER CODE END end of acquisition start*/
    STMSTUDIO_LOCK;
    TSL_acq_BankGetResult(idx_bank, 0, 0);
    STMSTUDIO_UNLOCK;
    idx_bank++; /* Next bank */
    config_done = 0;
/* USER CODE BEGIN end of acquisition */

/* USER CODE END end of acquisition */
  }

  /* Process objects, DxS and ECS
     Check if all banks have been acquired
  */
  if (idx_bank > TSLPRM_TOTAL_BANKS-1)
  {
/* USER CODE BEGIN before reset*/

/* USER CODE END before reset*/
    /* Reset flags for next banks acquisition */
    idx_bank = 0;
    config_done = 0;

    /* Process Objects */
    TSL_obj_GroupProcess(&MyObjGroup);

    /* DxS processing (if TSLPRM_USE_DXS option is set) */
    TSL_dxs_FirstObj(&MyObjGroup);

    /* ECS every TSLPRM_ECS_DELAY (in ms) */
    if (TSL_tim_CheckDelay_ms(TSLPRM_ECS_DELAY, &ECSLastTick) == TSL_STATUS_OK)
    {
      if (TSL_ecs_Process(&MyObjGroup) == TSL_STATUS_OK)
      {
        status = TSL_USER_STATUS_OK_ECS_ON;
      }
      else
      {
        status = TSL_USER_STATUS_OK_ECS_OFF;
      }
    }
    else
    {
      status = TSL_USER_STATUS_OK_NO_ECS;
    }
/* USER CODE BEGIN Process objects */

/* USER CODE END Process objects */
  }
  else
  {
    status = TSL_USER_STATUS_BUSY;
/* USER CODE BEGIN TSL_USER_STATUS_BUSY */

/* USER CODE END TSL_USER_STATUS_BUSY */
  }

  return status;
}

/**
 * Interrupt TSC management. See below code example for 3 sensors in main.c:
  * while (1)
  {
#define TKEY_DET(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_DETECT)
#define TKEY_PRX(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_PROX)
#define TKEY_REL(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_RELEASE)
#define TKEY_CAL(NB) (MyTKeys[(NB)].p_Data->StateId == TSL_STATEID_CALIB)
    if(tsl_user_Exec_IT() != TSL_USER_STATUS_BUSY){
      if(!TKEY_CAL(0) && !TKEY_CAL(1) && !TKEY_CAL(2) ){
        printf("Delta: sensor0 %3d sensor1 %3d sensor2 %3d\n"
               ,MyTKeys[0].p_ChD->Delta
               ,MyTKeys[1].p_ChD->Delta
               ,MyTKeys[2].p_ChD->Delta);
        if(TKEY_DET(0)){
          HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
        }else if(TKEY_REL(0)){
          HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
        }
        if(TKEY_DET(1)){
          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
        }else if(TKEY_REL(1)){
          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
        }
        if(TKEY_DET(2)){
          HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
        }else if(TKEY_REL(2)){
          HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
        }
      }
    }else{
      HAL_Delay(1); Can be replace by __WFI()
    }
  }
 */

/**
 * Local variable used for interrupt acquisition mode
 */
uint32_t idx_bank_it = 0; // Bank acquisition number (from 0 to TSLPRM_TOTAL_BANKS-1)
uint32_t config_done_it = 0; // Start first TSC acquisition done using bank 0
uint32_t acq_done_it = 0; // TSLPRM_TOTAL_BANKS banks acquisition done

/**
  * @brief  Acquisition completed callback in non blocking mode
  * @param  htsc: pointer to a TSC_HandleTypeDef structure that contains
  *         the configuration information for the specified TSC.
  * @retval None
  */
void HAL_TSC_ConvCpltCallback(TSC_HandleTypeDef* htsc)
{
/* USER CODE BEGIN HAL_TSC_ConvCpltCallback start*/

/* USER CODE END HAL_TSC_ConvCpltCallback start*/
  TSL_acq_BankGetResult(idx_bank_it, 0, 0);
  idx_bank_it++;
  if (idx_bank_it > TSLPRM_TOTAL_BANKS-1)
  {
    // End of all banks acquisition, restart bank 0 in while(1) loop (This is a choice)
    idx_bank_it=0;
    acq_done_it++;
  }else{
    // We restart next bank acquisition
    TSL_acq_BankConfig(idx_bank_it);
    TSL_acq_BankStartAcq_IT();
  }
/* USER CODE BEGIN HAL_TSC_ConvCpltCallback*/

/* USER CODE END HAL_TSC_ConvCpltCallback*/
}

/**
  * @brief  Execute STMTouch Driver main State machine using TSC Interrupt
  * @param  None
  * @retval status Return TSL_STATUS_OK if the acquisition is done
  */
tsl_user_status_t tsl_user_Exec_IT(void)
{
  tsl_user_status_t status = TSL_USER_STATUS_BUSY;

  /* Configure and start bank acquisition */
  if (!config_done_it)
  {
/* USER CODE BEGIN not config_done start*/

/* USER CODE END not config_done start*/
    idx_bank_it = 0;
    acq_done_it = 0;
    TSL_acq_BankConfig(idx_bank_it);
    TSL_acq_BankStartAcq_IT();
    config_done_it = 1;
/* USER CODE BEGIN not config_done */

/* USER CODE END not config_done */
  }

  /* Check end of all group acquisitions (interrupt mode) */
  if (acq_done_it)
  {
/* USER CODE BEGIN acq_done_it start*/

/* USER CODE END acq_done_it start*/

    /* Process Objects */
    TSL_obj_GroupProcess(&MyObjGroup);

    /* DxS processing (if TSLPRM_USE_DXS option is set) */
    TSL_dxs_FirstObj(&MyObjGroup);

    /* ECS every TSLPRM_ECS_DELAY (in ms) */
    if (TSL_tim_CheckDelay_ms(TSLPRM_ECS_DELAY, &ECSLastTick) == TSL_STATUS_OK)
    {
      if (TSL_ecs_Process(&MyObjGroup) == TSL_STATUS_OK)
      {
        status = TSL_USER_STATUS_OK_ECS_ON;
      }
      else
      {
        status = TSL_USER_STATUS_OK_ECS_OFF;
      }
    }
    else
    {
      status = TSL_USER_STATUS_OK_NO_ECS;
    }

    // Restart TSLPRM_TOTAL_BANKS banks acquisition
    idx_bank_it = 0;
    acq_done_it = 0;
    TSL_acq_BankConfig(idx_bank_it);
    TSL_acq_BankStartAcq_IT();
/* USER CODE BEGIN acq_done_it */

/* USER CODE END acq_done_it */
  }
  else
  {
    status = TSL_USER_STATUS_BUSY;
/* USER CODE BEGIN TSL_USER_STATUS_BUSY */

/* USER CODE END TSL_USER_STATUS_BUSY */
  }

/* USER CODE BEGIN Process objects */

/* USER CODE END Process objects */

  return status;
}

/**
  * @brief  Set thresholds for each object (optional).
  * @param  None
  * @retval None
  */
void tsl_user_SetThresholds(void)
{
/* USER CODE BEGIN Tsl_user_SetThresholds */
  /* Example: Decrease the Detect thresholds for the TKEY 0
  MyTKeys_Param[0].DetectInTh -= 10;
  MyTKeys_Param[0].DetectOutTh -= 10;
  */
/* USER CODE END Tsl_user_SetThresholds */
  }

/**
  * @brief  Executed when a sensor is in Error state
  * @param  None
  * @retval None
  */
  void MyTKeys_ErrorStateProcess(void)
{
/* USER CODE BEGIN MyTKeys_ErrorStateProcess */
  /* Add here your own processing when a sensor is in Error state */
/* USER CODE END MyTKeys_ErrorStateProcess */
}

/**
  * @brief  Executed when a sensor is in Off state
  * @param  None
  * @retval None
  */
void MyTKeys_OffStateProcess(void)
{
/* USER CODE BEGIN MyTKeys_OffStateProcess */
  /* Add here your own processing when a sensor is in Off state */
/* USER CODE END MyTKeys_OffStateProcess */
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
