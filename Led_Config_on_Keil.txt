#include "stm32f10x.h"



void config(){

	GPIO_InitTypeDef  gpio;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);// bus aktifleştirme

	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0;                           // led için ayarlar
	gpio.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(GPIOB,&gpio);                            //init etme


}


int main(){
	config();

	while(1){
		GPIO_SetBits(GPIOB,GPIO_Pin_0);          // ledi yakma
		
	}


}
