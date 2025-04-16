#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H

#include "common/global_define.h"
#include <stdint.h>

/**
 * @brief Enum representing GPIO pins for any port to
 * simplify usage of GPIO functions.
 * 
 */
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

/**
 * @brief Enum representing the possible modes that can be assigned to a GPIO pin.
 * 
 */
typedef enum {
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALTERNATE,
}GPIOMode;

/**
 * @brief Enum representing a state assignable to a GPIO pin, reset corresponds to 0 and set
 * corresponds to 1(or 3.3V)
 * 
 */
typedef enum {
    GPIO_STATE_RESET,
    GPIO_STATE_SET,
}GPIOState;

/**
 * @brief Sets the GPIO pin to the given mode
 * 
 * @param gpioPort GPIO port of the pin
 * @param gpioPin GPIO pin
 * @param mode Mode to be set
 * @return StatusCode OK if successfull
 */
StatusCode GPIO_Set_Mode(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin, GPIOMode mode);

/**
 * @brief Toggles the give GPIO pin state
 * 
 * @param gpioPort GPIO port of the pin
 * @param gpioPin GPIO pin to be toggled
 */
void GPIO_Toggle(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin);

/**
 * @brief Writes the gievn state to the given GPIO pin.
 * 
 * @param gpioPort GPIO port of the pin
 * @param gpioPin GPIO pin to be written
 * @param state state to assign to the GPIO pin
 */
void GPIO_Write(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin, GPIOState state);

/**
 * @brief Reads the given GPIO pin and returns its value
 * 
 * @param gpioPort GPIO port of the pin
 * @param gpioPin GPIO pin to be read
 * @return 1 if the state was SET 0 if otherwise
 */
uint8_t GPIO_Read(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin);
#endif