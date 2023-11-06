#include "stm32f10x.h"                  
#include "stm32f10x_exti.h"             
EXTI_InitTypeDef EXTII;
NVIC_InitTypeDef NVICI;
GPIO_InitTypeDef gpio;

void config(){
	
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	
	
	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0 | GPIO_Pin_1 |GPIO_Pin_2;                    //led
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&gpio);
	
	
	gpio.GPIO_Mode=GPIO_Mode_IPD;
	gpio.GPIO_Pin=GPIO_Pin_6;                                             //Buton
	GPIO_Init(GPIOC,&gpio);
}

void extiConfig(){
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource6);
	
	
	
	EXTII.EXTI_Line=EXTI_Line6;
	EXTII.EXTI_LineCmd=ENABLE;
	EXTII.EXTI_Mode=EXTI_Mode_Interrupt;                 //externalI ayari
	EXTII.EXTI_Trigger=EXTI_Trigger_Rising;
	
	EXTI_Init(&EXTII);
	
	
	NVICI.NVIC_IRQChannel=EXTI9_5_IRQn;
	NVICI.NVIC_IRQChannelCmd=ENABLE;
	NVICI.NVIC_IRQChannelPreemptionPriority=1;              //nvic ayari
	NVICI.NVIC_IRQChannelSubPriority=1;
	
	NVIC_Init(&NVICI);

}

void delay(uint32_t time){
	
	while(time--);



}

void EXTI9_5_IRQHandler(){
	
	if(EXTI_GetITStatus(EXTI_Line6)!=RESET){
		
				while(1){
			
			GPIO_ResetBits(GPIOA,GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2);
			delay(3600000);	
		}
		
			
		}
		
   EXTI_ClearITPendingBit(EXTI_Line6);
	
	}





int main(){
	config();
	extiConfig();
	
	
	while(1){
		
	
		  GPIO_SetBits(GPIOA,GPIO_Pin_0);
			delay(360000);
			GPIO_ResetBits(GPIOA,GPIO_Pin_0);
			delay(360000);	
			GPIO_SetBits(GPIOA,GPIO_Pin_1);
			delay(360000);
			GPIO_ResetBits(GPIOA,GPIO_Pin_1);
			delay(360000);
			GPIO_SetBits(GPIOA,GPIO_Pin_2);
			delay(360000);
			GPIO_ResetBits(GPIOA,GPIO_Pin_2);
			delay(360000);
		
		
		
	
	
	
	
	}




}
