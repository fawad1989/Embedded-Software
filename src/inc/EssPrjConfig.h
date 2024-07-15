/*
 * EssPrjConfig.h
 *
 *  Created on: Jun 14, 2024
 *      Author: alihussain
 */

#ifndef SRC_INC_ESSPRJCONFIG_H_
#define SRC_INC_ESSPRJCONFIG_H_

#include <EssPrjConfigDef.h>
/***************************************************************************
    Include project hardware and features configuration
****************************************************************************/
#define ESS_DEF_HW                       		DISCO_F3
#define ESS_DEF_PRJ_NAME              	 		"EmbeddedSystemSoftware(Generic)"

/***************************************************************************
   Peripheral Control Macros
****************************************************************************/
#define HW_GPIO									TRUE
#define HW_ADC 									FALSE
#define HW_SPI_BUS 								FALSE
#define HW_I2C_BUS  							FALSE
#define HW_UART       							FALSE
#define HW_TIMER								FALSE
#define HW_SLEEP_ENABLED                        FALSE
#define HW_CRC_ENGINE                           FALSE

#define HW_OSC								    HW_OSC_HSI
#define HW_MAIN_CLK                             HW_CLK_FRQ_64M
#define HW_SLEEP_CLK_AWAKE						HW_CLK_FRQ_32M

#define ESS_UART_BAUDRATE             			(9600u)

#define ESS_WATCHDOG				  			FALSE

#define ESS_DEBUG_MESSAGE                       FALSE      //Printf messages over uart2

#endif /* SRC_INC_ESSPRJCONFIG_H_ */
