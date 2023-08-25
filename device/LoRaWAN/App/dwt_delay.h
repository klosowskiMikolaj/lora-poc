/*
 * dwt_delay.h
 *
 *  Created on: Jul 17, 2023
 *      Author: mikolajklosowski
 */

#ifndef APP_DWT_DELAY_H_
#define APP_DWT_DELAY_H_

#include "stm32wlxx_hal.h"


uint32_t DWT_Delay_Init(void);


/**
 * @brief  This function provides a delay (in microseconds)
 * @param  microseconds: delay in microseconds
 */
__STATIC_INLINE void DWT_Delay_us(volatile uint32_t microseconds)
{
  uint32_t clk_cycle_start = DWT->CYCCNT;

  /* Go to number of cycles for system */
  microseconds *= (HAL_RCC_GetHCLKFreq() / 1000000);

  /* Delay till end */
  while ((DWT->CYCCNT - clk_cycle_start) < microseconds);
}

#endif /* APP_DWT_DELAY_H_ */
