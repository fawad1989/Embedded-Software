/*****************************************************************************************
 * @file FwHalMcu.c
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Hal MCU Module Source file
 ****************************************************************************************/
#include <stm32f3xx_hal.h>

#include <EssFW.h>

#include <FwHalClk.h>
#include <FwHalMcu.h>

static volatile uint32_t m_u32ResetCause;

static uint32_t       HalGetRstSource(void);

void FwHalMcuInit()
{
	m_u32ResetCause = HalGetRstSource();

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* Configure the system clock */
	FwHalClkInit();
}


static uint32_t HalGetRstSource(void)
{
    uint32_t reset_cause;

    if (__HAL_RCC_GET_FLAG(RCC_FLAG_LPWRRST))
    {
        reset_cause = BIT(RESET_FAULT);
    }
    else if (__HAL_RCC_GET_FLAG(RCC_FLAG_WWDGRST))
    {
        reset_cause = BIT(RESET_WDT);
    }
    else if (__HAL_RCC_GET_FLAG(RCC_FLAG_IWDGRST))
    {
        reset_cause = BIT(RESET_WDT);
    }
    else if (__HAL_RCC_GET_FLAG(RCC_FLAG_SFTRST))
    {
        reset_cause = BIT(RESET_SOFT);
        // This reset is induced by calling the ARM CMSIS `NVIC_SystemReset()` function!
    }
    else if (__HAL_RCC_GET_FLAG(RCC_FLAG_PINRST))
    {
        reset_cause = BIT(RESET_PIN);
    }
    else if (__HAL_RCC_GET_FLAG(RCC_FLAG_OBLRST))
    {
        reset_cause = BIT(RESET_FAULT);
    }
    else
    {
        reset_cause = BIT(RESET_FAULT);
    }

    // Clear all the reset flags or else they will remain set during future resets until system power is fully removed.
    __HAL_RCC_CLEAR_RESET_FLAGS();

    return reset_cause;
}


void FwHalMcuInfo(
	CfHalMcuInfo_t *pInfo)
{
    pInfo->u32RstCause = m_u32ResetCause;
    pInfo->u32ClkFreqHz = SystemCoreClock;
}

uint32_t FwHalMcuRstCause(void)
{
    return m_u32ResetCause;
}

void FwHalMcuSoftRst(void)
{
	NVIC_SystemReset();
}

void FwHalMcuDelayMs(
    uint32_t u32Ms)
{
    HAL_Delay(u32Ms);
}
