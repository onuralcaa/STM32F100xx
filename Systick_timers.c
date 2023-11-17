#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
uint32_t sayac;
GPIO_InitTypeDef gpio;

void config(){

	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
  gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&gpio);

}


void SysTick_Handler()  
{
   if(sayac > 0)
      sayac--;   
}

void delay_ms(uint32_t time)
{
   sayac = time;

   while(sayac);
}

void delayf()
{
   SystemCoreClockUpdate();
   SysTick_Config(SystemCoreClock / 1000);
}




int main(){
	 
	config();
	delayf();

	
	while(1){
		
	
		delay_ms(1000);

	}

}

