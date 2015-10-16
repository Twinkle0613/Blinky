#include "Gpio.h"
#include "stm32f4xx_hal_rcc.h"


configurePin(int direction, int pinNum, GPIO_TypeDef *port){
	 __HAL_RCC_GPIOG_CLK_ENABLE();
	GPIO_InitTypeDef gpio;
	gpio.Pin = pinNum;
	gpio.Mode =direction;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_MEDIUM;

	HAL_GPIO_Init(port,&gpio);

}


void writeOne(int pinNum, GPIO_TypeDef *port){


	HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_SET);


}


void writeZero(int pinNum, GPIO_TypeDef *port){


	HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_RESET);


}
