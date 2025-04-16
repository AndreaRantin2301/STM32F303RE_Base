#include "clock_driver/clock_driver.h"
#include "gpio_driver/gpio_driver.h"
#include "usart_driver/usart_driver.h"

int main(void) {

    StatusCode checkError = System_Clock_Init();
    if(checkError != OK) {
        while(1);
    }

    SysTick_Init();

    checkError = Gpio_Clock_Enable(GPIO_PORT_A);
    if(checkError != OK) {
        while(1);
    }

    checkError = GPIO_Set_Mode(GPIO_PORT_A,GPIO_PIN_5,GPIO_MODE_OUTPUT);
    if(checkError != OK) {
        while(1);
    }

    checkError = Serial_Clock_Enable(SERIAL_USART2);
    if(checkError != OK) {
        while(1);
    }

    checkError = USART2_Init();
    if(checkError != OK) {
        while(1);
    }

    Debug_Print("TEST PRINT\n");

    while(1) {
        GPIO_Toggle(GPIO_PORT_A,GPIO_PIN_5);
        Delay_Ms(3000);
        Debug_Print("TEST PRINT LOOP\n");
    }

    return 0;
}