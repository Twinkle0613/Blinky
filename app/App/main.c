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

	configurePin(GPIO_OUTPUT,GPIO_PIN_14,GPIOG);
	configurePin(GPIO_OUTPUT,GPIO_PIN_13,GPIOG);
	configurePin(GPIO_OUTPUT,GPIO_PIN_5,GPIOC);
	configurePin(GPIO_OUTPUT,GPIO_PIN_13,GPIOB);
	while(1){
	delay(100000);
	writeOne(GPIO_PIN_14,GPIOG);
	writeZero(GPIO_PIN_13,GPIOG);
	writeZero(GPIO_PIN_5,GPIOC);
	writeZero(GPIO_PIN_13,GPIOB);
	delay(100000);
	writeZero(GPIO_PIN_14,GPIOG);
	writeOne(GPIO_PIN_13,GPIOG);
	writeOne(GPIO_PIN_5,GPIOC);
	writeOne(GPIO_PIN_13,GPIOB);
	}

	}


