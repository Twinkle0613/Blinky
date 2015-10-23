#include "Gpio.h"
#include "stm32f4xx_hal_rcc.h"


configurePin(int direction, int pinNum, GPIO_TypeDef *port){
	GPIO_InitTypeDef gpio;
	 __HAL_RCC_GPIOG_CLK_ENABLE();
	 __HAL_RCC_GPIOC_CLK_ENABLE();
	 __HAL_RCC_GPIOB_CLK_ENABLE();
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


	/*
	gpio.Pin = pinNum;
	gpio.Mode =direction;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(port,&gpio);
    */
}


void writeOne(int pinNum, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_SET);
}


void writeZero(int pinNum, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port,pinNum, GPIO_PIN_RESET);
}



