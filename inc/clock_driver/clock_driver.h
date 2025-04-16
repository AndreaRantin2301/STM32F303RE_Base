#ifndef CLOCK_DRIVER_H
#define CLOCK_DRIVER_H

#include "common/global_define.h"
#include <stdint.h>

/**
 * @brief Initializes system clock using PLL at 72Mhz from HSI input.
 * It then sets APB1 clock to 36MHZ and AP2 and AHB clock to 72MHZ
 * 
 * @return StatusCode this will be a value of @ref StatusCode it will be OK if
 * the function executes correctly or an error if the clock could not be initialized correctly
 */
StatusCode System_Clock_Init(void);

/**
 * @brief Initializes SysTick to start counting every 1ms
 * 
 */
void SysTick_Init(void);

void SysTick_Handler(void);

/**
 * @brief Waits for the given amount of time in milliseconds by using SysTick
 * 
 * @param delay The time in milliseconds that the MCU needs to wait
 */
void Delay_Ms(uint32_t delay);

/**
 * @brief Enables the clock on the given GPIO port
 * 
 * @param portEnum Value of @ref GPIOPortEnum that represents the GPIO port to enable
 * @return StatusCode OK if successfull
 */
StatusCode Gpio_Clock_Enable(GPIOPortEnum portEnum);

/**
 * @brief Enables the clock on the given Serial
 * 
 * @param serialEnum Value of @ref SerialEnum that represents the serial to enable
 * @return StatusCode OK if successfull
 */
StatusCode Serial_Clock_Enable(SerialEnum serialEnum);

#endif