#ifndef GLOBAL_DEFINE_H
#define GLOBAL_DEFINE_H

/**
 * @brief Error codes of the Firmware,
 * they start from 0(OK) and go on
 * 
 */
typedef enum {
    OK = 1,
    ERROR_HSI,
    ERROR_PLL,
    ERROR_CLOCK_SOURCE,
    ERROR_GPIO_CLOCK,
    ERROR_INVALID_PIN,
    ERROR_INVALID_PORT,
    ERROR_INVALID_MODE,
    ERROR_SERIAL_CLOCK,
}StatusCode;

/**
 * @brief Enum representing GPIO ports to simplify usage of
 * GPIO functions
 * 
 */
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

/**
 * @brief Enum representing USART peripherals to simplify usage of USART functions
 * 
 */
typedef enum {
    SERIAL_USART1,
    SERIAL_USART2,
    SERIAL_USART3,
    SERIAL_UART4,
    SERIAL_UART5,
}SerialEnum;

#endif