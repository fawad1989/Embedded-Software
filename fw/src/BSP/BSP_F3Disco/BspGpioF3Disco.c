/*
 * BspGpioF3Disco.c
 *
 *  Created on: Jun 24, 2024
 *      Author: alihussa
 */

#include <stm32f3xx_hal.h>

#include <EssFW.h>

#include <FwHalGpio.h>
#include <FwHalMcu.h>
#include <BspGpioPinsF3Disco.h>
#include <BspGpioF3Disco.h>

static const Gpio_InitStruct PushPullStruct = {OUTPUTPP, NOPULL, LOWSPD, 0};
#if HW_UART
static const GPIO_InitStruct GpioUartStruct = {AF_PP, NOPULL, VHGSPD, AF_7};
#endif

static Gpio_info GpioPortPin_map[GPIO_Limit] =
{
		[LD3_Red]  			= {LD3_Pin, LD3_GPIO_Port},
		[LD4_Blue]  	    = {LD4_Pin, LD4_GPIO_Port},
		[LD5_Orange]        = {LD5_Pin, LD5_GPIO_Port},
		[LD6_Green]         = {LD6_Pin, LD6_GPIO_Port},
		[LD7_Green]         = {LD7_Pin, LD7_GPIO_Port},
		[LD8_Orange]        = {LD8_Pin, LD8_GPIO_Port},
		[LD9_Blue]          = {LD9_Pin, LD9_GPIO_Port},
		[LD10_Red]          = {LD10_Pin, LD10_GPIO_Port},
		[SWDIO]             = {SWDIO_Pin, SWDIO_GPIO_Port},
		[SWCLK]             = {SWCLK_Pin, SWCLK_GPIO_Port},
		[SWO]               = {SWO_Pin, SWO_GPIO_Port},
#if HW_UART
		[UART1_Tx]          = {UART1_Tx_Pin, UART1_Tx_GPIO_Port},
		[UART1_Rx]          = {UART1_Rx_Pin, UART1_Rx_GPIO_Port},
		[UART2_Tx]          = {UART2_Tx_Pin, UART2_Tx_GPIO_Port},
		[UART2_Rx]          = {UART2_Rx_Pin, UART2_Rx_GPIO_Port},
#endif
};

void BspGpioF3DiscoInit(void)
{
	/* Configuration of Gpio Leds*/
	__HAL_RCC_GPIOE_CLK_ENABLE();

	Gpio_info *pUserLedsInfo = NULL;
	pUserLedsInfo->pin =  GpioMap(LD3_Red)->pin    |
						  GpioMap(LD4_Blue)->pin   |
						  GpioMap(LD5_Orange)->pin |
						  GpioMap(LD6_Green)->pin  |
						  GpioMap(LD7_Green)->pin  |
						  GpioMap(LD8_Orange)->pin |
						  GpioMap(LD9_Blue)->pin   |
						  GpioMap(LD10_Red)->pin ;

	pUserLedsInfo->port = GpioMap(LD3_Red)->port;

	FwHalGpioConfig(pUserLedsInfo, &PushPullStruct);

#if HW_UART
	/* Configuration of Gpio Uart1*/
	__HAL_RCC_USART1_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	uint32_t u32Uart1PinMask =  GpioMap(UART1_Tx)->pin   |
								GpioMap(UART1_Rx)->pin;

	GPIO_TypeDef *pUart1PinsPort = GpioMap(UART1_Tx)->port;
	GpioConfig(pUart1PinsPort, u32Uart1PinMask , &GpioUartStruct);

	/* Configuration of Gpio Uart2*/
	__HAL_RCC_USART2_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();


	uint32_t u32Uart2PinMask =  GpioMap(UART2_Tx)->pin   |
								GpioMap(UART2_Rx)->pin;

	GPIO_TypeDef *pUart2PinsPort = GpioMap(UART2_Tx)->port;
	GpioConfig(pUart2PinsPort, u32Uart2PinMask , &GpioUartStruct);

#endif
}

void BspGpioF3DiscoBlinkClockWise(uint32_t delay)
{
	FwHalGpioToggle(GpioMap(LD3_Red));
	FwHalMcuDelayMs(delay);
}

Gpio_info* GpioMap(GPIO_Used gpio)
{
    return &GpioPortPin_map[gpio];
}
