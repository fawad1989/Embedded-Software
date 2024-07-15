/*****************************************************************************************
 * @file FwHalMcu.h
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Hal MCU Module Header file
 ****************************************************************************************/

#ifndef FW_SRC_HAL_INC_FWHALMCU_H_
#define FW_SRC_HAL_INC_FWHALMCU_H_

/****************************************************************************
 * Mask for Possible Reset cause
 * **************************************************************************
 */

typedef enum
{
    RESET_PIN,
    RESET_WDT,
    RESET_SOFT,
    RESET_FAULT,
} RESET_REASON;

typedef struct
{
    uint32_t        u32RstCause;          ///< A mask of causes for the most recent reset
    uint32_t        u32ClkFreqHz;    ///< The MCU clock frequency, in megahertz
} CfHalMcuInfo_t;

void FwHalMcuInit();
void FwHalMcuInfo(CfHalMcuInfo_t *pInfo);
void FwHalMcuSoftRst(void);
void FwHalMcuDelayMs(uint32_t u32Ms);
uint32_t FwHalMcuRstCause(void);

#endif /* FW_SRC_HAL_INC_FWHALMCU_H_ */
