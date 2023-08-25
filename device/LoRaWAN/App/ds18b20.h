/*
 * ds18b20.h
 *
 *  Created on: Jul 17, 2023
 *      Author: mikolajklosowski
 */

#ifndef APP_DS18B20_H_
#define APP_DS18B20_H_

#include "dwt_delay.h"
#include "stm32wlxx_hal_def.h"

#define DS18B20_PORT GPIOA
#define DS18B20_PIN GPIO_PIN_2

float DS18B20_GetTemperature(void);

#endif /* APP_DS18B20_H_ */
