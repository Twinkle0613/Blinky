#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "Gpio.h"
//#include "stdint.h"
void delay(uint32_t delayCount){

	while(delayCount != 0 ){
		delayCount--;
	}

}


int main(){

	configurePin(GPIO_OUTPUT,GPIO_PIN_13,GPIOG);

	while(1){
	delay(1000000);
	writeOne(GPIO_PIN_13,GPIOG);
	delay(1000000);
	writeZero(GPIO_PIN_13,GPIOG);

	}

	}


