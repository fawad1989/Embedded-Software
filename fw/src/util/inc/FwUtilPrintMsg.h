/*
 * FwUtilPrintMsg.h
 *
 *  Created on: Jun 12, 2024
 *      Author: alihussa
 */

#ifndef FW_SRC_UTIL_INC_FWUTILPRINTMSG_H_
#define FW_SRC_UTIL_INC_FWUTILPRINTMSG_H_

#if ESS_DEBUG_MESSAGE
void printmsg(char *format,...);
#endif /*ESS_DEBUG_MESSAGE*/

#endif /* FW_SRC_UTIL_INC_FWUTILPRINTMSG_H_ */
