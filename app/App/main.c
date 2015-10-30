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

	configurePin(GPIO_MODE_OUTPUT,PIN_14,PORTG);
	configurePin(GPIO_MODE_OUTPUT,PIN_13,PORTG);
	//configurePin(GPIO_MODE_OUTPUT,PIN_5,PORTC);
	//configurePin(GPIO_MODE_OUTPUT,PIN_13,PORTB);
	configureIntPin(GPIO_MODE_INPUT,PIN_0,PORTA);
	int realSignal;
	int inputSignal;

while(1){
   realSignal = PORTA->IDR;
   inputSignal = filterSignal(PORTA->IDR);
   if( inputSignal != 1 ){
	//writeOutHigh(PORTG,14);
	writeSet(PORTG,14);
	writeReset(PORTG,13);
	//writeOutLow(PORTG,13);
   }else{
	//writeOutHigh(PORTG,13);
	//writeOutLow(PORTG,14);
	writeSet(PORTG,13);
	writeReset(PORTG,14);
   }
}




/*
	delay(100000);
	writeOutHigh(PORTG,14);
	writeOutLow(PORTG,13);
	writeOutLow(PORTC,5);
	writeOutLow(PORTB,13);
	//writeOne(GPIO_PIN_14,GPIOG);
	//writeZero(GPIO_PIN_13,GPIOG);
	//writeZero(GPIO_PIN_5,GPIOC);
	//writeZero(GPIO_PIN_13,GPIOB);
	delay(100000);
	writeOutLow(PORTG,14);
	writeOutHigh(PORTG,13);
	writeOutHigh(PORTC,5);
	writeOutHigh(PORTB,13);
	//writeZero(GPIO_PIN_14,GPIOG);
	//writeOne(GPIO_PIN_13,GPIOG);
	//writeOne(GPIO_PIN_5,GPIOC);
	//writeOne(GPIO_PIN_13,GPIOB);
*/

	}




