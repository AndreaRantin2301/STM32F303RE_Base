#include "clock_driver/clock_driver.h"
#include "ST/stm32f303xe.h"

#define SYSTEM_CLOCK    72000000

StatusCode System_Clock_Init(void) {
    
    //INITIALIZE HSI
    RCC->CR |= RCC_CR_HSION;

    //GIVE TIME TO HSI TO STABILIZE
    for(volatile uint32_t i = 0; i < 100000; i++) {};

    //IF HSI IS NOT READY AFTER A WHILE THOW ERROR
    if(!(RCC->CR & RCC_CR_HSIRDY)) return ERROR_HSI;

    //DISABLE PLL
    RCC->CR &= ~RCC_CR_PLLON;

    //RESET PLL CLOCK SOURCE(SO SET HSI/2 BY DEFAULT)
    RCC->CFGR &= ~RCC_CFGR_PLLSRC_Msk;

    //SET NO DIVISION FOR PLL HSI INPUT
    RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_PREDIV;

    //CLEAR PREDIV
    RCC->CFGR2 &= ~RCC_CFGR2_PREDIV_Msk;
    //SET PREDIV TO 1
    RCC->CFGR2 |= RCC_CFGR2_PREDIV_DIV1;

    //CLEAR PLL MULTIPLIER
    RCC->CFGR &= ~RCC_CFGR_PLLMUL_Msk;
    //SET PLL MULTIPLIER TO 9 SO that 8Mhz x 9 = 72Mhz
    RCC->CFGR |= RCC_CFGR_PLLMUL9;

    //SET FLASH LATENCY FOR 72MHZ
    FLASH->ACR |= FLASH_ACR_LATENCY_2;

    //ENABLE PLL
    RCC->CR |= RCC_CR_PLLON;

    //GIVE TIME TO PLL TO STABILIZE
    for(volatile uint32_t i = 0; i < 100000; i++) {};

    //IF PLL NOT READY AFTER A WHILE THROW ERROR
    if(!(RCC->CR & RCC_CR_PLLON)) return ERROR_PLL;
    if (!(RCC->CR & RCC_CR_PLLRDY)) return ERROR_PLL;

    //AHB CLOCK TO 72MHZ
    RCC->CFGR &= ~RCC_CFGR_HPRE;
    RCC->CFGR |= RCC_CFGR_HPRE_DIV1;

    //APB1 CLOCK TO 36MHZ
    RCC->CFGR &= ~RCC_CFGR_PPRE1_Msk;
    RCC->CFGR |= RCC_CFGR_PPRE1_DIV2;

    //APB2 CLOCK TO 72MHZ
    RCC->CFGR &= ~RCC_CFGR_PPRE2_Msk;
    RCC->CFGR |= RCC_CFGR_PPRE2_DIV1;

    //CLEAR SYSTEM CLOCK SOURCE
    RCC->CFGR &= ~RCC_CFGR_SW_Msk;
    
    //SET PLL AS SYSTEM CLOCK SOURCE
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    //GIVE TIME FOR SYSTEM CLOCK TO BE SET
    for(volatile uint32_t i = 0; i < 100000; i++) {};

    if(!(RCC->CFGR & RCC_CFGR_SWS_PLL)) return ERROR_CLOCK_SOURCE;

    return OK;
}

void SysTick_Init(void) {
    
    SysTick->LOAD = (SYSTEM_CLOCK / 1000) - 1;
    SysTick->VAL = 0;
    SysTick->CTRL |= (SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
}

volatile uint32_t currentTick = 0;

void SysTick_Handler(void)
{
    currentTick++;
}

void Delay_Ms(uint32_t delay) {
    uint32_t start = currentTick;
    while ((currentTick - start) < delay);
}

StatusCode Gpio_Clock_Enable(GPIOPortEnum portEnum) {
    switch(portEnum) {
        case GPIO_PORT_A:
            RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
            break;
        case GPIO_PORT_B:
            RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
            break;
        case GPIO_PORT_C:
            RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
            break;
        case GPIO_PORT_D:
            RCC->AHBENR |= RCC_AHBENR_GPIODEN;
            break;
        case GPIO_PORT_E:
            RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
            break;
        case GPIO_PORT_F:
            RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
            break;
        case GPIO_PORT_G:
            RCC->AHBENR |= RCC_AHBENR_GPIOGEN;
            break;
        case GPIO_PORT_H:
            RCC->AHBENR |= RCC_AHBENR_GPIOHEN;
            break;
        default:
            return ERROR_GPIO_CLOCK;
    }

    return OK;
}

StatusCode Serial_Clock_Enable(SerialEnum serialEnum) {
    switch(serialEnum) {
        case SERIAL_USART1:
            RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
            break;
        case SERIAL_USART2:
            RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
            break;
        case SERIAL_USART3:
            RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
            break;
        case SERIAL_UART4:
            RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
            break;
        case SERIAL_UART5:
            RCC->APB1ENR |= RCC_APB1ENR_UART5EN;
            break;
        default:
        return ERROR_SERIAL_CLOCK;
    }

    return OK;
}
