/*
 * BspGpioPinsF3Disco.h
 *
 *  Created on: Jun 24, 2024
 *      Author: alihussa
 */

#ifndef BSP_F3DISCO_INC_BSPGPIOPINSF3DISCO_H_
#define BSP_F3DISCO_INC_BSPGPIOPINSF3DISCO_H_

#if HW_GPIO
#define LD3_Pin 						GPIO_PIN_9
#define LD3_GPIO_Port 					GPIOE

#define LD4_Pin 						GPIO_PIN_8
#define LD4_GPIO_Port 					GPIOE

#define LD5_Pin 						GPIO_PIN_10
#define LD5_GPIO_Port 					GPIOE

#define LD6_Pin 						GPIO_PIN_15
#define LD6_GPIO_Port 					GPIOE

#define LD7_Pin 						GPIO_PIN_11
#define LD7_GPIO_Port 					GPIOE

#define LD8_Pin 						GPIO_PIN_14
#define LD8_GPIO_Port 					GPIOE

#define LD9_Pin 						GPIO_PIN_12
#define LD9_GPIO_Port 					GPIOE

#define LD10_Pin 						GPIO_PIN_13
#define LD10_GPIO_Port 					GPIOE

#define SWDIO_Pin 						GPIO_PIN_13
#define SWDIO_GPIO_Port 				GPIOA

#define SWCLK_Pin 						GPIO_PIN_14
#define SWCLK_GPIO_Port 				GPIOA

#define SWO_Pin 						GPIO_PIN_3
#define SWO_GPIO_Port 					GPIOB

#if HW_UART

#define UART1_Tx_Pin 					GPIO_PIN_4
#define UART1_Tx_GPIO_Port 				GPIOC

#define UART1_Rx_Pin 					GPIO_PIN_5
#define UART1_Rx_GPIO_Port 				GPIOC

#define UART2_Tx_Pin 					GPIO_PIN_2
#define UART2_Tx_GPIO_Port 				GPIOA

#define UART2_Rx_Pin 					GPIO_PIN_3
#define UART2_Rx_GPIO_Port 				GPIOA

#endif /*HW_UART*/
#endif /*HW_GPIO*/
#endif /*BSP_F3DISCO_INC_BSPGPIOPINSF3DISCO_H_*/
