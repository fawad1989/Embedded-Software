/*
 * FwMacros.h
 *
 *  Created on: Dec 9, 2023
 *      Author: alihussa
 */
/*****************************************************************************************
 * @file FwMacros.h
 *
 * @copyright 2023 Ali Hussain (ali0403hussain@gmail.com)  All Rights Reserved.
 *  Created on: Dec 8, 2023
 *      Author: alihussa
 *
 *  Firmware Macros Header file
 ****************************************************************************************/
#ifndef FW_SRC_INC_FWMACROS_H_
#define FW_SRC_INC_FWMACROS_H_

#define BIT(bit_pos)                    (1u << bit_pos)
#define BIT_SET(value, bit_pos)         (value |=  BIT(bit_pos))
#define BIT_CLEAR(value, bit_pos)       (value &= ~BIT(bit_pos))
#define BIT_TOGGLE(value, bit_pos)      (value ^=  BIT(bit_pos))

#define FwDoForever()                   while(TRUE)
#define FwDoNothing()                   do{(void)0;} while(FALSE)
#define FwDoOnce(statement)             do{(void)(statement);} while(FALSE)

#define FwMax(a, b)                     ( (a) > (b) ? (a) : (b) )
#define FwMax3(a, b, c)                 FwMax(FwMax((a), (b)), (c))

#define FwMin(a, b)                     ( (a) < (b) ? (a) : (b) )
#define FwMin3(a, b, c)                 FwMin(FwMin((a), (b)), (c))

#endif /* FW_SRC_INC_FWMACROS_H_ */
