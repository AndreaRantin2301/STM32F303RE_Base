#include "usart_driver/usart_driver.h"
#include "gpio_driver/gpio_driver.h"
#include "clock_driver/clock_driver.h"
#include "ST/stm32f303xe.h"
#include "utils/string_utils.h"

#define APB1_CLOCK    36000000

StatusCode USART2_Init(void) {

    //SET PA2 TO ALTERNATE MODE
    StatusCode checkError = GPIO_Set_Mode(GPIO_PORT_A,GPIO_PIN_2,GPIO_MODE_ALTERNATE);
    if(checkError != OK) return checkError;

    GPIOA->AFR[0] &= ~GPIO_AFRL_AFRL2_Msk;

    //SET ALTERNATE FUNCTION 7 TO PA2
    GPIOA->AFR[0] |= (0x7U << GPIO_AFRL_AFRL2_Pos);

    //ENABLE CLOCK TO USART2
    checkError = Serial_Clock_Enable(SERIAL_USART2);
    if(checkError != OK) return checkError;

    //TODO TEST
    USART2->CR1 &= ~USART_CR1_OVER8;
    USART2->CR2 = 0;
    USART2->CR3 = 0;
    USART2->CR1 &= ~USART_CR1_M; // 8-bit data frame
    USART2->CR1 &= ~USART_CR1_PCE; // No parity
    USART2->CR1 &= ~USART_CR1_PS;  // Even parity
    USART2->CR2 &= ~USART_CR2_STOP; // 1 stop bit


    //SET BAUDRATE TO 115200
    USART2->BRR = (uint32_t) (APB1_CLOCK / 115200U);

    //ENABLE TRANSMITTER
    USART2->CR1 |= USART_CR1_TE;

    //ENABLE USART
    USART2->CR1 |= USART_CR1_UE;

    return OK;
}

void USART2_Write(uint8_t *txData, uint16_t len) {

    for(uint16_t i = 0; i < len; i++) {
        while (!(USART2->ISR & USART_ISR_TXE)) {};

        USART2->TDR = txData[i];
    }
}

void Debug_Print(char str[]) {
    USART2_Write((uint8_t*)str,(uint16_t) custom_strlen(str));
}