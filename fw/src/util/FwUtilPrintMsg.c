/*
 * fwUtilPrintMsg.c
 *
 *  Created on: Jun 12, 2024
 *      Author: alihussa
 */

#include <EssFW.h>

#if ESS_DEBUG_MESSAGE
#include <FwHalUart.h>
#include <FwUtilPrintMsg.h>

void printmsg(char *format,...)
{
	char str[50] = {""};

	va_list args;
	va_start(args, format);
	vsprintf(str, format, args);
	Uart2Write(&str, strlen(str));
	va_end(args);
}
#endif /*ESS_DEBUG_MESSAGE*/
