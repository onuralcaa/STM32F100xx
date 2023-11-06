#include "stm32f10x.h"                  

void config(){
	
	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_7 |GPIO_Pin_8 | GPIO_Pin_9;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOC,&gpio);

}

void delay(uint32_t time){
	
	while(time--);



}


int main(){
	config();
	
	
	while(1){
//		GPIO_SetBits(GPIOC,GPIO_Pin_7);
//		delay(360000);
//		GPIO_ResetBits(GPIOC,GPIO_Pin_7);
//		delay(360000);
//		GPIO_SetBits(GPIOC,GPIO_Pin_8);
//		delay(360000);
//		GPIO_ResetBits(GPIOC,GPIO_Pin_8);
//		delay(360000);
//		GPIO_SetBits(GPIOC,GPIO_Pin_9);
//		delay(360000);
//		GPIO_ResetBits(GPIOC,GPIO_Pin_9);
//		delay(360000);
//		GPIO_SetBits(GPIOC,GPIO_Pin_7);
//		delay(360000);
//		GPIO_ResetBits(GPIOC,GPIO_Pin_7);
//		delay(360000);
		
		
	
	
	
	
	}




}

