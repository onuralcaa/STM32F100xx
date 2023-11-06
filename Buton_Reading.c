#include "stm32f10x.h"                  


uint16_t butondurum=0;


void config(){
	
	GPIO_InitTypeDef gpio;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	
	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_2;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;            //led ayari
	GPIO_Init(GPIOB,&gpio);
	
	
	gpio.GPIO_Mode=GPIO_Mode_IPD;
	gpio.GPIO_Pin=GPIO_Pin_6;                   //buton ayari
	GPIO_Init(GPIOC,&gpio);

}

void delay(uint32_t time){
	
	while(time--);



}

int main(){
	config();
	
	while(1){
		butondurum=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
		
		

		if(butondurum==1){
			GPIO_SetBits(GPIOB,GPIO_Pin_2);
		
		}
		
		else{
			GPIO_ResetBits(GPIOB,GPIO_Pin_2);
		
	}
	
	
	
	}



}
