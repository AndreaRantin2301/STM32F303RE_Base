#ifndef CLOCK_DRIVER_H
#define CLOCK_DRIVER_H

#include "common/global_define.h"
#include <stdint.h>

StatusCode System_Clock_Init(void);
void SysTick_Init(void);
void SysTick_Handler(void);
void Delay_Ms(uint32_t delay);
StatusCode Gpio_Clock_Enable(GPIOPortEnum portEnum);
StatusCode Serial_Clock_Enable(SerialEnum serialEnum);

#endif