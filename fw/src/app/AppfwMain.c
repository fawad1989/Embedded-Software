/*****************************************************************************************
 * @file AppfwMain.h
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Main Entry Point.
 ****************************************************************************************/
#include <EssFW.h>

#include <FwHalInit.h>
#include <FwHalGpio.h>
#include <FwHalMcu.h>

#define LD3_Pin 						GPIO_PIN_9
#define LD3_GPIO_Port 					GPIOE

#define THREAD_DELAY            (500U)

void AppfwMain(void)
{
	FwHalInit();
	Gpio_info pLed3 = {GPIO_PIN_9, GPIOE};
	FwHalGpioConfigAsOutputPP(&pLed3);
	FwDoForever()
	{
		FwHalGpioToggle(&pLed3);
		FwHalMcuDelayMs(THREAD_DELAY);
	}
}

