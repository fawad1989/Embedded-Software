/*
 * BspGpioF3Disco.h
 *
 *  Created on: Jun 24, 2024
 *      Author: alihussa
 */

#ifndef BSP_F3DISCO_INC_BSPGPIOF3DISCO_H_
#define BSP_F3DISCO_INC_BSPGPIOF3DISCO_H_

#if HW_GPIO

#include <FwHalGpio.h>

#define NO_PIN 0
#define NO_PORT NULL
#define DUMMY_PIN       			 {NO_PIN, NO_PORT}

typedef enum
{
	LD3_Red = 0,
	LD4_Blue,
	LD5_Orange,
	LD6_Green,
	LD7_Green,
	LD8_Orange,
	LD9_Blue,
	LD10_Red,
	SWDIO,
	SWCLK,
	SWO,
	#if HW_UART
	UART1_Tx,
	UART1_Rx,
	UART2_Tx,
	UART2_Rx,
	#endif
	GPIO_Limit,
}GPIO_Used;

void BspGpioF3DiscoInit(void);
void BspGpioF3DiscoBlinkClockWise(uint32_t delay);
Gpio_info* GpioMap(GPIO_Used gpio);

#endif /*HW_GPIO*/
#endif /*BSP_F3DISCO_INC_BSPGPIOF3DISCO_H_ */
