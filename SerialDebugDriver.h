/*
 * 	SerialDebugDriver.h
 *
 *  Created on: Sep. 5, 2022
 *      Author: mingye chen
 *
 *	General purpose print functions using STM32 UART.
 *	Similar API to arduino Serial.h
 */

#ifndef USERDRIVERS_SERIALDEBUGDRIVER_H_
#define USERDRIVERS_SERIALDEBUGDRIVER_H_

// STM headers
#include "stm32l4xx_hal.h"

// Standard Lib
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>


#define MAX_SERIAL_PRINT_LENGTH 128
#define PUBLIC
#define PRIVATE
/*
 * NOTE:
 * Initalization of the serial peripheral is done in main.c
 * Auto generated init by the IOC file
 */

PUBLIC void SerialPrint(const char * message, ...);
PUBLIC void SerialPrintln(const char * message, ...);

#endif /* USERDRIVERS_SERIALDEBUGDRIVER_H_ */
