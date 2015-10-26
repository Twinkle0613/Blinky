#include "Rcc.h"
#include "stm32f4xx_hal_rcc.h"
#include "Gpio.h"



void gpioUnresetEnableClock(GPIO *port){
	rcc *rc = RCC_BASE_ADDRESS;
	int portAddress = (int*)(port);

	switch( portAddress ){

	case GPIOG_BASE_ADDRESS:
    rc->AHB1RSTR  &= ~( 1 << GPIOG_BIT );         //build mask first
    rc->AHB1RSTR |= 0 << GPIOG_BIT ;    // '0' that mean unable reset
    rc->AHB1ENR &= ~( 1 << GPIOG_BIT);
    rc->AHB1ENR  |= 1 << GPIOG_BIT;     // '1' that mean enable reset
	break;

	case GPIOB_BASE_ADDRESS:
    rc->AHB1RSTR  &= ~( 1 << GPIOB_BIT );         //build mask first
    rc->AHB1RSTR |= 0 << GPIOB_BIT ;    // '0' that mean unable reset
    rc->AHB1ENR &= ~( 1 << GPIOB_BIT);
    rc->AHB1ENR  |= 1 << GPIOB_BIT;     // '1' that mean enable reset
	break;

	case GPIOC_BASE_ADDRESS:
    rc->AHB1RSTR  &= ~( 1 << GPIOC_BIT );         //build mask first
    rc->AHB1RSTR |= 0 << GPIOC_BIT ;    // '0' that mean unable reset
    rc->AHB1ENR &= ~( 1 << GPIOC_BIT);
    rc->AHB1ENR  |= 1 << GPIOC_BIT;     // '1' that mean enable reset
	break;

	default:break;

	}


}
