/*****************************************************************************************
 * @file FwHalGpio.c
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Hal GPIO Module Source file
 ****************************************************************************************/

#include <stm32f3xx_hal.h>

#include <EssFW.h>

#if HW_GPIO

#include <FwHalGpio.h>

/****************************************************************************
 * Configure GPIO single / Multiple pins as Input/Output
	@param gpioInfo - Pins and Port
	@param gpioStruct Parameters for Gpio including
	Mode
	Pullup/Pulldown
	Speed
	Alternate function
	@returns Nothing.
*****************************************************************************/
void FwHalGpioConfig(Gpio_info *gpioInfo, Gpio_InitStruct const *gpioStruct)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = gpioInfo->pin;
	GPIO_InitStruct.Mode = gpioStruct->Mode;
	GPIO_InitStruct.Pull = gpioStruct->Pull;
	GPIO_InitStruct.Speed = gpioStruct->Speed;
	GPIO_InitStruct.Alternate = gpioStruct->Alternate;
	HAL_GPIO_Init(gpioInfo->port, &GPIO_InitStruct);
}

/****************************************************************************
 * Configure GPIO as Output Push Pull
	@param gpioInfo - Pins and Port
	@returns Nothing.
*****************************************************************************/
void FwHalGpioConfigAsOutputPP(Gpio_info *gpioInfo)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = gpioInfo->pin;
	GPIO_InitStruct.Mode = OUTPUTPP;
	GPIO_InitStruct.Pull = NOPULL;
	GPIO_InitStruct.Speed = LOWSPD;
	HAL_GPIO_Init(gpioInfo->port, &GPIO_InitStruct);
}

/****************************************************************************
 * Configure GPIO as Output Open Drain
	@param gpioInfo - Pins and Port
	@returns Nothing.
*****************************************************************************/
void FwHalGpioConfigAsOutputOD(Gpio_info *gpioInfo)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = gpioInfo->pin;
	GPIO_InitStruct.Mode = OUTPUTOD;
	GPIO_InitStruct.Pull = NOPULL;
	GPIO_InitStruct.Speed = VHGSPD;
	HAL_GPIO_Init(gpioInfo->port, &GPIO_InitStruct);
}

/****************************************************************************
 * Configure GPIO as Low Power
	@param gpioInfo - Pins and Port
	@returns Nothing.
*****************************************************************************/
void FwHalGpioConfigAsLowPower(Gpio_info *gpioInfo)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = gpioInfo->pin;
	GPIO_InitStruct.Mode = ANALOG;
	GPIO_InitStruct.Pull = NOPULL;
	HAL_GPIO_Init(gpioInfo->port, &GPIO_InitStruct);
}

/****************************************************************************
 * Configure GPIO as Input
	@param gpioInfo - Pins and Port
	@param pull - Pull Up/Down
	@returns Nothing.
*****************************************************************************/
void FwHalGpioConfigAsInput(Gpio_info *gpioInfo, Gpio_PuPd pull)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	GPIO_InitStruct.Pin = gpioInfo->pin;
	GPIO_InitStruct.Mode = INPUT;
	GPIO_InitStruct.Pull = pull;
	HAL_GPIO_Init(gpioInfo->port, &GPIO_InitStruct);
}

/****************************************************************************
 * Toggle Gpio
	@param gpioInfo - Pins and Port
	@returns Nothing.
*****************************************************************************/
void FwHalGpioToggle(Gpio_info *gpioInfo)
{
	HAL_GPIO_TogglePin(gpioInfo->port, gpioInfo->pin);
}

/****************************************************************************
 * Write Gpio with On /Off
	@param gpioInfo - Pins and Port
	@param value - Data to write
	@returns Nothing.
*****************************************************************************/
void FwHalGpioWrite(Gpio_info *gpioInfo, Gpio_PinState state)
{
	HAL_GPIO_WritePin(gpioInfo->port, gpioInfo->pin, state);
}

#endif /*HW_GPIO ends*/
