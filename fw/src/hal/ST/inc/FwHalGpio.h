/*****************************************************************************************
 * @file FwHalGpio.h
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Hal GPIO Module Header file
 ****************************************************************************************/
#ifndef FW_SRC_HAL_INC_FWHALGPIO_H_
#define FW_SRC_HAL_INC_FWHALGPIO_H_

#include <stm32f3xx_hal.h>

#if HW_GPIO

/*
 * Gpio Mode Enum
 */
typedef enum
{
	INPUT = 0,		 // Input
	OUTPUTPP = 0x01, // AnalogInput
	ANALOG = 0x03,	 // Output PushPull
	OUTPUTOD = 0X11, // Output OpenDrain
	AF_PP = 0x02,	 // Alternate function Push Pull
} Gpio_Mode;

/*
 * Gpio PullUp PullDown Enum
 */
typedef enum
{
	NOPULL = 0, // No Pull UP/Down
	UPPULL,		// Pull UP
	DNPULL,		// Pull Down
} Gpio_PuPd;

/*
 * Gpio Speed Enum
 */
typedef enum
{
	LOWSPD = 0, // LowSpeed
	MDMSPD,		// Medium Speed
	HGSPD,		// High Speed
	VHGSPD,		// Very High Speed
} Gpio_Speed;

/*
 * Gpio Alternate function Enum
 */
typedef enum
{
	AF_0 = 0,
	AF_1,
	AF_2,
	AF_3,
	AF_4,
	AF_5,
	AF_6,
	AF_7,
	AF_8,
	AF_9,
	AF_10,
	AF_11,
	AF_12,
} Gpio_AF;

typedef enum
{
	PIN_RESET = 0U,
	PIN_SET
} Gpio_PinState;

typedef struct
{
	uint32_t Mode;
	uint32_t Pull;
	uint32_t Speed;
	uint32_t Alternate;
} Gpio_InitStruct;

typedef struct
{
	uint32_t pin;
	GPIO_TypeDef *port;
} Gpio_info;

void FwHalGpioConfig(Gpio_info *gpioInfo, Gpio_InitStruct const *gpioStruct);
void FwHalGpioConfigAsOutputPP(Gpio_info *gpioInfo);
void FwHalGpioConfigAsOutputOD(Gpio_info *gpioInfo);
void FwHalGpioConfigAsLowPower(Gpio_info *gpioInfo);
void FwHalGpioConfigAsInput(Gpio_info *gpioInfo, Gpio_PuPd pull);
void FwHalGpioToggle(Gpio_info *gpioInfo);
void FwHalGpioWrite(Gpio_info *gpioInfo, Gpio_PinState state);

#endif /*HW_GPIO ends*/
#endif /* FW_SRC_HAL_INC_FWHALGPIO_H_ */
