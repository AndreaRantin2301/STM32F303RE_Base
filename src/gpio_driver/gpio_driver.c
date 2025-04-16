#include "gpio_driver/gpio_driver.h"
#include "ST/stm32f303xe.h"
#include <stddef.h>

//TODO DOCS
#define INVALID_PIN     0
#define VALID_PIN       1

//TODO DOCS
#define MAX_PIN_START_BITS    30

//TODO DOCS
static uint8_t Is_PinEnum_Valid(GPIOPinEnum pinEnum){
    if((pinEnum * 2) > MAX_PIN_START_BITS) return INVALID_PIN;
    return VALID_PIN;
}

//TODO DOCS
static GPIO_TypeDef* Get_GPIO_Port(GPIOPortEnum portEnum) {
    switch(portEnum) {
        case GPIO_PORT_A:
            return GPIOA;
        case GPIO_PORT_B:
            return GPIOB;
        case GPIO_PORT_C:
            return GPIOC;
        case GPIO_PORT_D:
            return GPIOD;
        case GPIO_PORT_E:
            return GPIOE;
        case GPIO_PORT_F:
            return GPIOF;
        case GPIO_PORT_G:
            return GPIOG;
        case GPIO_PORT_H:
            return GPIOH;
        default:
            return NULL;
    }
    return NULL;
}

//TODO DOCS
static void GPIO_Set_Mode_Input(GPIO_TypeDef* gpioPort, GPIOPinEnum gpioPin) {
    switch(gpioPin) {
        case GPIO_PIN_0:
            gpioPort->MODER &= ~GPIO_MODER_MODER0;
            break;
        case GPIO_PIN_1:
            gpioPort->MODER &= ~GPIO_MODER_MODER1;
            break;
        case GPIO_PIN_2:
            gpioPort->MODER &= ~GPIO_MODER_MODER2;
            break;
        case GPIO_PIN_3:
            gpioPort->MODER &= ~GPIO_MODER_MODER3;
            break;
        case GPIO_PIN_4:
            gpioPort->MODER &= ~GPIO_MODER_MODER4;
            break;
        case GPIO_PIN_5:
            gpioPort->MODER &= ~GPIO_MODER_MODER5;
            break;
        case GPIO_PIN_6:
            gpioPort->MODER &= ~GPIO_MODER_MODER6;
            break;
        case GPIO_PIN_7:
            gpioPort->MODER &= ~GPIO_MODER_MODER7;
            break;
        case GPIO_PIN_8:
            gpioPort->MODER &= ~GPIO_MODER_MODER8;
            break;
        case GPIO_PIN_9:
            gpioPort->MODER &= ~GPIO_MODER_MODER9;
            break;
        case GPIO_PIN_10:
            gpioPort->MODER &= ~GPIO_MODER_MODER10;
            break;
        case GPIO_PIN_11:
            gpioPort->MODER &= ~GPIO_MODER_MODER11;
            break;
        case GPIO_PIN_12:
            gpioPort->MODER &= ~GPIO_MODER_MODER12;
            break;
        case GPIO_PIN_13:
            gpioPort->MODER &= ~GPIO_MODER_MODER13;
            break;
        case GPIO_PIN_14:
            gpioPort->MODER &= ~GPIO_MODER_MODER14;
            break;
        case GPIO_PIN_15:
            gpioPort->MODER &= ~GPIO_MODER_MODER15;
            break;
        default:
            //TF YOU EXPECT ME TO DO???
            break;
    }
}

//TODO DOCS
static void Gpio_Set_Mode_Output(GPIO_TypeDef* gpioPort, GPIOPinEnum gpioPin) {
    switch(gpioPin) {
        case GPIO_PIN_0:
            gpioPort->MODER &= ~GPIO_MODER_MODER0;
            gpioPort->MODER |= GPIO_MODER_MODER0_0;
            break;
        case GPIO_PIN_1:
            gpioPort->MODER &= ~GPIO_MODER_MODER1;
            gpioPort->MODER |= GPIO_MODER_MODER1_0;
            break;
        case GPIO_PIN_2:
            gpioPort->MODER &= ~GPIO_MODER_MODER2;
            gpioPort->MODER |= GPIO_MODER_MODER2_0;
            break;
        case GPIO_PIN_3:
            gpioPort->MODER &= ~GPIO_MODER_MODER3;
            gpioPort->MODER |= GPIO_MODER_MODER3_0;
            break;
        case GPIO_PIN_4:
            gpioPort->MODER &= ~GPIO_MODER_MODER4;
            gpioPort->MODER |= GPIO_MODER_MODER4_0;
            break;
        case GPIO_PIN_5:
            gpioPort->MODER &= ~GPIO_MODER_MODER5;
            gpioPort->MODER |= GPIO_MODER_MODER5_0;
            break;
        case GPIO_PIN_6:
            gpioPort->MODER &= ~GPIO_MODER_MODER6;
            gpioPort->MODER |= GPIO_MODER_MODER6_0;
            break;
        case GPIO_PIN_7:
            gpioPort->MODER &= ~GPIO_MODER_MODER7;
            gpioPort->MODER |= GPIO_MODER_MODER7_0;
            break;
        case GPIO_PIN_8:
            gpioPort->MODER &= ~GPIO_MODER_MODER8;
            gpioPort->MODER |= GPIO_MODER_MODER8_0;
            break;
        case GPIO_PIN_9:
            gpioPort->MODER &= ~GPIO_MODER_MODER9;
            gpioPort->MODER |= GPIO_MODER_MODER9_0;
            break;
        case GPIO_PIN_10:
            gpioPort->MODER &= ~GPIO_MODER_MODER10;
            gpioPort->MODER |= GPIO_MODER_MODER10_0;
            break;
        case GPIO_PIN_11:
            gpioPort->MODER &= ~GPIO_MODER_MODER11;
            gpioPort->MODER |= GPIO_MODER_MODER11_0;
            break;
        case GPIO_PIN_12:
            gpioPort->MODER &= ~GPIO_MODER_MODER12;
            gpioPort->MODER |= GPIO_MODER_MODER12_0;
            break;
        case GPIO_PIN_13:
            gpioPort->MODER &= ~GPIO_MODER_MODER13;
            gpioPort->MODER |= GPIO_MODER_MODER13_0;
            break;
        case GPIO_PIN_14:
            gpioPort->MODER &= ~GPIO_MODER_MODER14;
            gpioPort->MODER |= GPIO_MODER_MODER14_0;
            break;
        case GPIO_PIN_15:
            gpioPort->MODER &= ~GPIO_MODER_MODER15;
            gpioPort->MODER |= GPIO_MODER_MODER15_0;
            break;
        default:
            //TF YOU EXPECT ME TO DO???
            break;
    }
}

//TODO DOCS
static void Gpio_Set_Mode_Alternate(GPIO_TypeDef* gpioPort, GPIOPinEnum gpioPin) {
    switch(gpioPin) {
        case GPIO_PIN_0:
            gpioPort->MODER &= ~GPIO_MODER_MODER0;
            gpioPort->MODER |= GPIO_MODER_MODER0_1;
            break;
        case GPIO_PIN_1:
            gpioPort->MODER &= ~GPIO_MODER_MODER1;
            gpioPort->MODER |= GPIO_MODER_MODER1_1;
            break;
        case GPIO_PIN_2:
            gpioPort->MODER &= ~GPIO_MODER_MODER2;
            gpioPort->MODER |= GPIO_MODER_MODER2_1;
            break;
        case GPIO_PIN_3:
            gpioPort->MODER &= ~GPIO_MODER_MODER3;
            gpioPort->MODER |= GPIO_MODER_MODER3_1;
            break;
        case GPIO_PIN_4:
            gpioPort->MODER &= ~GPIO_MODER_MODER4;
            gpioPort->MODER |= GPIO_MODER_MODER4_1;
            break;
        case GPIO_PIN_5:
            gpioPort->MODER &= ~GPIO_MODER_MODER5;
            gpioPort->MODER |= GPIO_MODER_MODER5_1;
            break;
        case GPIO_PIN_6:
            gpioPort->MODER &= ~GPIO_MODER_MODER6;
            gpioPort->MODER |= GPIO_MODER_MODER6_1;
            break;
        case GPIO_PIN_7:
            gpioPort->MODER &= ~GPIO_MODER_MODER7;
            gpioPort->MODER |= GPIO_MODER_MODER7_1;
            break;
        case GPIO_PIN_8:
            gpioPort->MODER &= ~GPIO_MODER_MODER8;
            gpioPort->MODER |= GPIO_MODER_MODER8_1;
            break;
        case GPIO_PIN_9:
            gpioPort->MODER &= ~GPIO_MODER_MODER9;
            gpioPort->MODER |= GPIO_MODER_MODER9_1;
            break;
        case GPIO_PIN_10:
            gpioPort->MODER &= ~GPIO_MODER_MODER10;
            gpioPort->MODER |= GPIO_MODER_MODER10_1;
            break;
        case GPIO_PIN_11:
            gpioPort->MODER &= ~GPIO_MODER_MODER11;
            gpioPort->MODER |= GPIO_MODER_MODER11_1;
            break;
        case GPIO_PIN_12:
            gpioPort->MODER &= ~GPIO_MODER_MODER12;
            gpioPort->MODER |= GPIO_MODER_MODER12_1;
            break;
        case GPIO_PIN_13:
            gpioPort->MODER &= ~GPIO_MODER_MODER13;
            gpioPort->MODER |= GPIO_MODER_MODER13_1;
            break;
        case GPIO_PIN_14:
            gpioPort->MODER &= ~GPIO_MODER_MODER14;
            gpioPort->MODER |= GPIO_MODER_MODER14_1;
            break;
        case GPIO_PIN_15:
            gpioPort->MODER &= ~GPIO_MODER_MODER15;
            gpioPort->MODER |= GPIO_MODER_MODER15_1;
            break;
        default:
            //TF YOU EXPECT ME TO DO???
            break;
    }
}

StatusCode GPIO_Set_Mode(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin, GPIOMode mode) {
    if(Is_PinEnum_Valid(gpioPin) != VALID_PIN) return ERROR_INVALID_PIN;

    GPIO_TypeDef* port = Get_GPIO_Port(gpioPort);

    if(port == NULL) return ERROR_INVALID_PORT;

    switch(mode) {
        case GPIO_MODE_INPUT:
            GPIO_Set_Mode_Input(port,gpioPin);
            break;
        case GPIO_MODE_OUTPUT:
            Gpio_Set_Mode_Output(port,gpioPin);
            break;
        case GPIO_MODE_ALTERNATE:
            Gpio_Set_Mode_Alternate(port,gpioPin);
            break;
        default:
            return ERROR_INVALID_MODE;
    }

    return OK;
}

void GPIO_Toggle(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin) {
    GPIO_TypeDef* port = Get_GPIO_Port(gpioPort);

    port->ODR ^= (1U << gpioPin);
}

void GPIO_Write(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin, GPIOState state) {
    GPIO_TypeDef* port = Get_GPIO_Port(gpioPort);

    port->ODR &= ~(1U << gpioPin);

    if(state == GPIO_STATE_SET) {
        port->ODR |= (1U << gpioPin);
    }
}

uint8_t GPIO_Read(GPIOPortEnum gpioPort, GPIOPinEnum gpioPin) {
    GPIO_TypeDef* port = Get_GPIO_Port(gpioPort);
    return (uint8_t)((port->IDR & (1U << gpioPin)) != 0);
}