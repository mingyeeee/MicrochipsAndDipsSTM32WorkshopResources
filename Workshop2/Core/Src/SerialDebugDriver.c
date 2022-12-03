/*
 * 	SerialDebugDriver.c
 *
 *  Created on: Sep. 5, 2022
 *      Author: mingye chen
 *
 *	General purpose print functions using STM32 UART.
 *	Similar API to arduino Serial.h
 */

#include "SerialDebugDriver.h"

// replace huart2 with a different handle if required
extern UART_HandleTypeDef huart2;
static char messageBuf[MAX_SERIAL_PRINT_LENGTH];

PUBLIC void SerialPrint(const char * message, ...)
{
	va_list args;
	va_start(args, message);
	uint16_t len = vsprintf(messageBuf, message, args);
	HAL_UART_Transmit(&huart2, (uint8_t*)messageBuf, len, HAL_MAX_DELAY);
	va_end(args);

}
PUBLIC void SerialPrintln(const char * message, ...)
{
	va_list args;
	va_start(args, message);
	uint16_t len = vsprintf(messageBuf, message, args);
	messageBuf[len] = '\n';
	messageBuf[len+1] = '\r';
	HAL_UART_Transmit(&huart2, (uint8_t*)messageBuf, len+2, HAL_MAX_DELAY);
	va_end(args);
}
