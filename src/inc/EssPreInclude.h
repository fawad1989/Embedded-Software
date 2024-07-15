/*
 * ESS_PreInclude.h
 *
 *  Created on: Jun 17, 2024
 *      Author: alihussa
 */

#ifndef SRC_INC_ESSPREINCLUDE_H_
#define SRC_INC_ESSPREINCLUDE_H_

#include <EssPrjConfig.h>

#if (ESS_DEF_HW == DISCO_F3)
#define STM32F303xC
#include <EssPrjConfig_F3Disco.h>
#endif

#define DEBUG

#define USE_HAL_DRIVER

#endif /* SRC_INC_ESSPREINCLUDE_H_ */
