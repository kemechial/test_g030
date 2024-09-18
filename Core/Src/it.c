/*
 * it.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Lenovo
 */

#include "stm32g0xx_hal.h"


void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();


}


