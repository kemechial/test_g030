/*
 * msp.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Lenovo
 */


void HAL_MspInit(void)
{
	HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);



}
