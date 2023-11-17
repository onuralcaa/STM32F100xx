#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM

int sayac=0;
GPIO_InitTypeDef gpio;
TIM_TimeBaseInitTypeDef time;
void config(){
	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0 |GPIO_Pin_1|GPIO_Pin_2;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&gpio);
}



void timerf(){
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
	
	time.TIM_ClockDivision=1;
	time.TIM_CounterMode=TIM_CounterMode_Up;
	time.TIM_Period=3999;
	time.TIM_Prescaler=5999;
	time.TIM_RepetitionCounter=0;
	
	TIM_TimeBaseInit(TIM6,&time);
	TIM_Cmd(TIM6,ENABLE);

}




int main(){
	config();
	timerf();
	
	
	while(1){
		sayac=TIM_GetCounter(TIM6);
		
		if(sayac==1999){
			GPIO_SetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
		
		
		}else if(sayac==3999){
		GPIO_ResetBits(GPIOB,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
		}

	}




}
