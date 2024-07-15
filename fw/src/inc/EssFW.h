/*****************************************************************************************
 * @file EssFW.h
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Hardware project configuration header.
 ****************************************************************************************/
#ifndef FW_SRC_INC_ESSFW_H_

#define FW_SRC_INC_ESSFW_H_

/***************************************************************************
    Generic C headers
****************************************************************************/
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/***************************************************************************
    Project Configuration headers top level
****************************************************************************/
#include <EssPrjConfig.h>

/***************************************************************************
    Firmware Macros headers
****************************************************************************/
#include <FwMacros.h>

#if ESS_DEBUG_MESSAGE
#include <FwUtilPrintMsg.h>
#endif /*ESS_DEBUG_MESSAGE*/

#endif /* FW_SRC_INC_ESSFW_H_ */
