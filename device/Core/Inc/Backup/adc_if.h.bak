/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    adc_if.h
  * @author  MCD Application Team
  * @brief   Header for ADC interface configuration
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __ADC_IF_H__
#define __ADC_IF_H__

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "adc.h"
#include "platform.h"
#include "stdint.h"
#include "stm32_adv_trace.h"



/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/**
  * @brief Battery level in mV
  */
#define BAT_CR2032                  ((uint32_t) 3000)
/**
  * @brief Maximum battery level in mV
  */
#define VDD_BAT                     BAT_CR2032
/**
  * @brief Minimum battery level in mV
  */
#define VDD_MIN                     1800

#define APP_PPRINTF(...)  do{ } while( UTIL_ADV_TRACE_OK \
                              != UTIL_ADV_TRACE_COND_FSend(VLEVEL_ALWAYS, T_REG_OFF, TS_OFF, __VA_ARGS__) ) /* Polling Mode */
#define APP_TPRINTF(...)   do{ {UTIL_ADV_TRACE_COND_FSend(VLEVEL_ALWAYS, T_REG_OFF, TS_ON, __VA_ARGS__);} }while(0); /* with timestamp */
#define APP_PRINTF(...)   do{ {UTIL_ADV_TRACE_COND_FSend(VLEVEL_ALWAYS, T_REG_OFF, TS_OFF, __VA_ARGS__);} }while(0);

#if defined (APP_LOG_ENABLED) && (APP_LOG_ENABLED == 1)
#define APP_LOG(TS,VL,...)   do{ {UTIL_ADV_TRACE_COND_FSend(VL, T_REG_OFF, TS, __VA_ARGS__);} }while(0);
#elif defined (APP_LOG_ENABLED) && (APP_LOG_ENABLED == 0) /* APP_LOG disabled */
#define APP_LOG(TS,VL,...)
#endif /* APP_LOG_ENABLED */

/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* External variables --------------------------------------------------------*/
/* USER CODE BEGIN EV */

/* USER CODE END EV */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/

/**
  * @brief  Initializes the ADC input
  */
void SYS_InitMeasurement(void);

/**
  * @brief DeInitializes the ADC
  */
void SYS_DeInitMeasurement(void);

/**
  * @brief  Get the current temperature
  * @return value temperature in degree Celsius( q7.8 )
  */
int16_t SYS_GetTemperatureLevel(void);

/**
  * @brief Get the current battery level
  * @return value battery level in linear scale
  */
uint16_t SYS_GetBatteryLevel(void);

/* USER CODE BEGIN EFP */

/**
  * @brief  callback to get the moisture level in %
  * @retval moisture level
  * @param  ADC channel
  */
uint8_t GetMoistureLevel(uint32_t channel);
uint8_t GetMoistureLevelDfRobot(uint32_t channel);



/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __ADC_IF_H__ */
