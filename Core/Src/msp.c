/*
 * msp.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Lenovo
 */
#include "stm32g0xx_hal.h"

void HAL_MspInit(void)
{
	//STM32G030 does not have priority grouping otherwise
	// there would be a HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup) call here.

}

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef gpio_uart;
	//Enable the clock for uart and GPIO pins
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	//Do the pin mux configurations
	gpio_uart.Pin = GPIO_PIN_9;
	gpio_uart.Mode = GPIO_MODE_AF_PP;
	gpio_uart.Pull = GPIO_PULLUP;
	gpio_uart.Speed = GPIO_SPEED_FREQ_LOW;
	gpio_uart.Alternate = GPIO_AF1_USART1; //USART1 TX
	HAL_GPIO_Init(GPIOA, &gpio_uart);

	gpio_uart.Pin = GPIO_PIN_10; //USART1 RX
	HAL_GPIO_Init(GPIOA, &gpio_uart);

	//Enable IRQ and set up the priority
	 HAL_NVIC_EnableIRQ(USART1_IRQn);
	 HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);

}
