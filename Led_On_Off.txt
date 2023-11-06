
#include "stm32f10x.h"



void config(){

	GPIO_InitTypeDef  gpio;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;

	GPIO_Init(GPIOB,&gpio);


}

void delay(uint32_t time){

	while(time--);

}


int main(){
	config();

	while(1){
		GPIO_SetBits(GPIOB,GPIO_Pin_0);
		delay(3600000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		delay(3600000);



	}



}