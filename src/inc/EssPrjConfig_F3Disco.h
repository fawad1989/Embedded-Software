/*
 * EssPrjConfig_F3Disco.h
 *
 *  Created on: Jun 14, 2024
 *      Author: alihussain
 */

#ifndef SRC_INC_ESSPRJCONFIG_F3DISCO_H_
#define SRC_INC_ESSPRJCONFIG_F3DISCO_H_

#if (DEF_HW != DISCO_F3)
  #error "Target Not Correct"
#endif

/***************************************************************************
   Hardware vendor and model parameters
****************************************************************************/
#define ESS_DEFHW_VENDOR     				    "STMicro"
#define ESS_DEFHW_NAME                          "DiscoveryF3"
#define ESS_DEF_MCU                             STM32F303xC

/***************************************************************************
   Memory Related parameters
****************************************************************************/
/* Flash Related Macros*/
#define ESS_DEF_BLOCK_SIZE                      (2000u)
#define ESS_DEF_BLOCK_COUNT                     (128u)
#define ESS_DEF_BLOCK_START_ADDRESS             (0x08000000u)
#define ESS_DEF_BLOCK_END_ADDRESS               (0x0803FFFFu)

/* RAM Related macros*/
#define ESS_DEF_SRAM_SIZE                       (40000U)
#define ESS_DEF_SRAM_START_ADDRESS              (0x20000000u)
#define ESS_DEF_SRAM_END_ADDRESS                (0x20009FFFu)

/* OptionBytes Related Macros*/
#define ESS_DEF_OPTION_BYTES_SIZE				(2000u)
#define ESS_DEF_OPTION_BYTES_START_ADDRESS      (0x1FFFF800u)
#define ESS_DEF_OPTION_BYTES_END_ADDRESS		(0x1FFFFFFFu)

/* ROM/System Memory related macros*/
#define ESS_DEF_ROM_SIZE						(8000u)
#define ESS_DEF_ROM_START_ADDRESS      			(0x1FFFD800u)
#define ESS_DEF_ROM_ADDRESS						(0x1FFFF7FFu)

#endif /* SRC_INC_ESSPRJCONFIG_F3DISCO_H_ */
