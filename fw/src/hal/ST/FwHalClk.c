/*****************************************************************************************
 * @file FwHalClk.c
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Hal Clock Module Source file
 ****************************************************************************************/
#include <stm32f3xx_hal.h>

#include <EssFW.h>

#include <FwHalClk.h>


static void SystemClock_Config(void);
static void PeripClock_Config(void);

void FwHalClkInit(void)
{
	SystemClock_Config();
	PeripClock_Config();
}


static void SystemClock_Config(void)
{
	#ifndef HW_MAIN_CLK
	  #error Unknown clock definition. HW_MAIN_CLk must be defined.
	#endif

	#ifndef HW_SLEEP_CLK_AWAKE
	  #error Unknown clock definition. HW_SLEEP_CLK_AWAKE must be defined.
	#endif

	#if (HW_MAIN_CLK == HW_CLK_FRQ_32M)
		RCC_OscInitTypeDef RCC_OscInitStruct = {0};

		/** Initializes the RCC Oscillators according to the specified parameters
		* in the RCC_OscInitTypeDef structure.
		*/
		#if(HW_OSC == HW_OSC_HSI)
		  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
		  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
		  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
		#elif (HW_OSC == HW_OSC_HSE)
		  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
		  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
		  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
		  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
		#endif

		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
		RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL8;
		if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
		{
			//Error_Handler();
		}

	#elif (HW_MAIN_CLK == HW_CLK_FRQ_64M)

		RCC_OscInitTypeDef RCC_OscInitStruct = {0};

		/** Initializes the RCC Oscillators according to the specified parameters
		* in the RCC_OscInitTypeDef structure.
		*/
		#if(HW_OSC == HW_OSC_HSI)
		  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
		  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
		  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
		#elif (HW_OSC == HW_OSC_HSE)
		  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
		  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
		  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
		  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
		#endif

		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
		RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
		if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
		{
			//Error_Handler();
		}

	#endif
}

static void PeripClock_Config(void)
{
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	/** Initializes the CPU, AHB and APB buses clocks
	*/
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
								|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		//Error_Handler();
	}
}
