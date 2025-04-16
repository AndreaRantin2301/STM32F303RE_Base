#include "clock_driver/clock_driver.h"

int main(void) {

    StatusCode checkError = System_Clock_Init();
    if(checkError != OK) {
        while(1);
    }

    while(1) {
        
    }

    return 0;
}