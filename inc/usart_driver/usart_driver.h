#ifndef USART_DRIVER_H
#define USART_DRIVER_H

#include "common/global_define.h"
#include <stdint.h>

/**
 * @brief Initializes USART2 by initializing its clock, enabling the transmitter, setting the baud rate and then
 * enabling the module
 * 
 * @return StatusCode OK if successful
 */
StatusCode USART2_Init(void);

/**
 * @brief Writes the buffer to USART2
 * 
 * @param txData Buffer to be transmitted
 * @param len Lenght of the buffer
 */
void USART2_Write(uint8_t *txData, uint16_t len);

/**
 * @brief Prints a message to the terminal trough USART2
 * 
 * @param str Message to be printed
 */
void Debug_Print(char str[]);


#endif