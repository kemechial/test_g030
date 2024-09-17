/*
 * main.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Lenovo
 */

#include "stm32g0xx_hal.h"
#include "main.h"

void SystemClockConfig(void);

int main(void)
{
	HAL_Init();
	SystemClockConfig();

	return 0;
}

void SystemClockConfig(void)
{




}
