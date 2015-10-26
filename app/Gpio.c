#include "Gpio.h"
#include "stm32f4xx_hal_rcc.h"
#include "Rcc.h"

writeOutHigh(GPIO *port, int pinNum){
 port->ODR &= ~( 1 << (pinNum));
 port->ODR |= 1 << (pinNum);
}

writeOutLow(GPIO *port, int pinNum){
 port->ODR &= ~( 1 << (pinNum));
 port->ODR |= 0 << (pinNum);
}

configureIntPin(int direction,int pinNum, GPIO* port){

	gpioUnresetEnableClock(port);

	 port->MODER &= ~( 3 << (pinNum *2));         //build mask first
	 port->MODER |= direction << (pinNum *2);

	 port->PUPDR &= ~( 3 << (pinNum *2));
	 port->PUPDR |= PULL_DOWN << (pinNum *2);

}


configurePin(int direction, int pinNum, GPIO *port){
	GPIO_InitTypeDef gpio;
	// __HAL_RCC_GPIOG_CLK_ENABLE();
	// __HAL_RCC_GPIOC_CLK_ENABLE();
	// __HAL_RCC_GPIOB_CLK_ENABLE();

	 /*
	 int *ptr = (int*)0x40021800;
	 ptr[0] =0X14000000;  //output = 14 and 13
	 ptr[1] =0x00000000;
	 ptr[2] =0X28000000;
	 int *ptr2 = (int*)0x40020800; //PC
	 ptr2[0] =0X00000400;  //output = 5
	 ptr2[1] =0x00000000;
	 ptr2[2] =0X00000800;
	 int *ptr3 = (int*)0x40020400; //PB
	 ptr3[0] =0X04000000;  //output = 13
	 ptr3[1] =0x00000000;
	 ptr3[2] =0X08000000;
	*/

//	int *ptr =(int*)0x40023800;
//	ptr[((int*)0x40023810)/4] = 0x000007BF;  //offset = 0x10
//	ptr[((int*)0x40023830)/4] = 0x00000040;  //offset = 0x30
/*
	int *ptr2 =(int*)0x40023810;
	ptr2[0] = 0x000007B9;

	int *ptr3 =(int*)0x40023830;
	ptr3[0] = 0x00000046;
*/
	 gpioUnresetEnableClock(port);
	 port->MODER &= ~( 3 << (pinNum *2));         //build mask first
	 port->MODER |= direction << (pinNum *2);

	 port->OTYPER &= ~( 3 << (pinNum));
	 port->OTYPER |= OUTPUT_PUSH_PULL << (pinNum);

	 port->OSPEED &= ~( 3 << (pinNum *2));
	 port->OSPEED |= HIGH_SPEED << (pinNum *2);




	/*
	gpio.Pin = pinNum;
	gpio.Mode =direction;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(port,&gpio);
    */
}

/*
void gpioUnresetEnableClock(GPIO *port){
	rcc *rc = RCC_BASE_ADDRESS;
	int portAdd = (int*)(port);

	switch( portAdd ){

	case GPIOG_BASE_ADDRESS:
    rc->AHB1RSTR  &= ~( 1 << 6 );         //build mask first
    rc->AHB1RSTR |= 0 << 6 ;    // '0' that mean unable reset
    rc->AHB1ENR &= ~( 1 << 6);
    rc->AHB1ENR  |= 1 << 6;     // '1' that mean enable reset
	break;

	case GPIOB_BASE_ADDRESS:
    rc->AHB1RSTR  &= ~( 1 << 1 );         //build mask first
    rc->AHB1RSTR |= 0 << 1 ;    // '0' that mean unable reset
    rc->AHB1ENR &= ~( 1 << 1);
    rc->AHB1ENR  |= 1 << 1;     // '1' that mean enable reset
	break;

	case GPIOC_BASE_ADDRESS:
    rc->AHB1RSTR  &= ~( 1 << 2 );         //build mask first
    rc->AHB1RSTR |= 0 << 2 ;    // '0' that mean unable reset
    rc->AHB1ENR &= ~( 1 << 2);
    rc->AHB1ENR  |= 1 << 2;     // '1' that mean enable reset
	break;

	default:break;

	}


}
*/

void writeOne(int pinNum, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_SET);
}


void writeZero(int pinNum, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_RESET);
}



