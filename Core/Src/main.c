/*
 * main.c
 *
 *  Created on: Sep 17, 2024
 *      Author: Lenovo
 */

#include "stm32g0xx_hal.h"
#include "main.h"
#include "string.h"

UART_HandleTypeDef huart1;

char* user_data = "The application is running.\r\n";

void SystemClockConfig(void);
void UART1_Init(void);
void Error_handler(void);

uint8_t data_buffer[100]={0};

int main(void)
{
	HAL_Init();
	SystemClockConfig();
	UART1_Init();

	/*
	uint16_t str_size = strlen(user_data);
    while(1){
	if(HAL_UART_Transmit(&huart1, (uint8_t *) user_data, str_size, HAL_MAX_DELAY)!=HAL_OK){
		Error_handler();
	}

	HAL_Delay(1000);

   }
   */

	while(1){
    uint8_t received_data;


    uint32_t count = 0;
    while(1){
    	HAL_UART_Receive(&huart1, &received_data, 1, HAL_MAX_DELAY);
    	if(received_data == '\r'){
    		break;
    			}else{
    		        data_buffer[count++] = received_data;
    			}
    }

    data_buffer[count++]  = '\r';
    data_buffer[count++]  = '\n';

	HAL_UART_Transmit(&huart1, data_buffer, count, HAL_MAX_DELAY);


	}
	return 0;
}

void SystemClockConfig(void)
{




}

void UART1_Init()
{
	huart1.Instance = USART1;
	huart1.Init.BaudRate = 115200;
	huart1.Init.WordLength = UART_WORDLENGTH_8B;
	huart1.Init.StopBits = UART_STOPBITS_1;
	huart1.Init.Parity = UART_PARITY_NONE;
	huart1.Init.Mode = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;

	if(HAL_UART_Init(&huart1) != HAL_OK){
		Error_handler();
	}

}

void Error_handler(void)
{

   while(1);

}
