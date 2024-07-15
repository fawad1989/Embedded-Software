/*
 * EssPrjConfigDef.h
 *
 *  Created on: Jun 22, 2024
 *      Author: alihussa
 */

#ifndef SRC_INC_ESSPRJCONFIGDEF_H_
#define SRC_INC_ESSPRJCONFIGDEF_H_

/***************************************************************************
    TRUE/FALSE Macros defined here because of use in some definations
****************************************************************************/
#ifndef TRUE
#define TRUE    (1)
#define FALSE   (0)
#endif

/***************************************************************************
    Definations for Dev Boards
****************************************************************************/
#define DISCO_F3					(0u)
#define DISCO_F4					(1u)

/***************************************************************************
    Definations for System Oscillator
****************************************************************************/
#define HW_OSC_HSE                  (0u)
#define HW_OSC_HSI                  (1u)

/***************************************************************************
    Definations for System Clocks
****************************************************************************/
#define HW_CLK_FRQ_32M              (0u)
#define HW_CLK_FRQ_64M              (1u)


#endif /* SRC_INC_ESSPRJCONFIGDEF_H_ */
