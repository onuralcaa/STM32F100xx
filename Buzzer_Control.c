#include "stm32f10x.h"

void config(){
	
	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&gpio);

}


int main(){
	config();
	
	while(1){
		GPIO_SetBits(GPIOA,GPIO_Pin_0);
		for(int i=0;i<360000;i++);
		GPIO_ResetBits(GPIOA,GPIO_Pin_0);
		for(int i=0;i<360000;i++);
		
		

	
	}



}
