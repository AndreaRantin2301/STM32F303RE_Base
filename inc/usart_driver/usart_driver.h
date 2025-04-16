#ifndef USART_DRIVER_H
#define USART_DRIVER_H

#include "common/global_define.h"
#include <stdint.h>

StatusCode USART2_Init(void);
void USART2_Write(uint8_t *txData, uint16_t len);
void Debug_Print(char str[]);


#endif