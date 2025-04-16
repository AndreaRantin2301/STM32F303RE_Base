#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

typedef enum {
    OK = 1,
    ERROR_HSI,
    ERROR_PLL,
    ERROR_CLOCK_SOURCE,
    ERROR_GPIO_CLOCK,
    ERROR_INVALID_PIN,
    ERROR_INVALID_PORT,
    ERROR_INVALID_MODE,
}StatusCode;

typedef enum {
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
}GPIOPortEnum;

#endif