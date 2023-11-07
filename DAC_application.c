#include "stm32f10x.h"                  // Device header
#include "stm32f10x_dac.h"              // Keil::Device:StdPeriph Drivers:DAC

uint16_t i;
GPIO_InitTypeDef gpio;
DAC_InitTypeDef dac;
void config(){
	
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	gpio.GPIO_Mode=GPIO_Mode_AIN;
	gpio.GPIO_Pin=GPIO_Pin_4;
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&gpio);
}


void dacf(){
	

	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC,ENABLE);
	
	dac.DAC_LFSRUnmask_TriangleAmplitude=DISABLE;
	dac.DAC_OutputBuffer=ENABLE;
	dac.DAC_Trigger=DAC_Trigger_None;
	dac.DAC_WaveGeneration=DAC_WaveGeneration_None;
	
	DAC_Init(DAC_Channel_1,&dac);
	DAC_Cmd(DAC_Channel_1,ENABLE);


}

void delay(uint32_t time){
	
	while(time--);



}

int main(){
	config();
	dacf();
	while(1){
		
		for(i=0; i<=4095; i++){
			DAC_SetChannel1Data(DAC_Align_12b_R,i);
			delay(36000);
		}
		for(i=4094; i>0; i--){
			DAC_SetChannel1Data(DAC_Align_12b_R,i);
			delay(36000);
		}
	
	
	}



}
