/*****************************************************************************************
 * @file FwSysTick.c
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  System Tick Source file
 ****************************************************************************************/
#include <stm32f3xx_hal.h>

void SysTick_Handler(void)
{
  HAL_IncTick();
}
