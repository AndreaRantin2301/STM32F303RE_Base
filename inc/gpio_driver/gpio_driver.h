#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "common/global_define.h"
#include <stdint.h>

typedef enum {
    GPIO_PIN_0 = 0,
    GPIO_PIN_1 = 1,
    GPIO_PIN_2 = 2,
    GPIO_PIN_3 = 3,
    GPIO_PIN_4 = 4,
    GPIO_PIN_5 = 5,
    GPIO_PIN_6 = 6,
    GPIO_PIN_7 = 7,
    GPIO_PIN_8 = 8,
    GPIO_PIN_9 = 9,
    GPIO_PIN_10 = 10,
    GPIO_PIN_11 = 11,
    GPIO_PIN_12 = 12,
    GPIO_PIN_13 = 13,
    GPIO_PIN_14 = 14,
    GPIO_PIN_15 = 15,
}GPIOPinEnum;

typedef enum {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALTERNATE,
}GPIOMode;

typedef enum {
    GPIO_STATE_RESET,
    GPIO_STATE_SET,
}GPIOState;

StatusCode GPIO_Set_Mode(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin, GPIOMode mode);
void GPIO_Toggle(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin);
void GPIO_Write(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin, GPIOState state);
uint8_t GPIO_Read(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin);
#endif