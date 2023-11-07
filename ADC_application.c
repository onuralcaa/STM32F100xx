#include "stm32f10x.h"                  // Device header
#include "stm32f10x_adc.h"              // Keil::Device:StdPeriph Drivers:ADC

uint16_t adcValue=0;
GPIO_InitTypeDef gpio;
ADC_InitTypeDef adc;

void config(){


	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);

	gpio.GPIO_Mode=GPIO_Mode_AIN;
	gpio.GPIO_Pin=GPIO_Pin_0;

	GPIO_Init(GPIOA,&gpio);

}


void adcf(){
	

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1,ENABLE);

	adc.ADC_ContinuousConvMode=ENABLE;
	adc.ADC_DataAlign= ADC_DataAlign_Right;
	adc.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;
	adc.ADC_Mode=ADC_Mode_Independent;
	adc.ADC_NbrOfChannel=1;
	adc.ADC_ScanConvMode=DISABLE;

	ADC_Init(ADC1,&adc);
	ADC_Cmd(ADC1,ENABLE);
}

uint16_t readADC(){

	ADC_RegularChannelConfig(ADC1,ADC_Channel_0,1,ADC_SampleTime_55Cycles5);

	ADC_SoftwareStartConvCmd(ADC1,ENABLE);

	while(ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC)==RESET);

	return ADC_GetConversionValue(ADC1);
}


int main(){
	config();
	adcf();

	while(1){
		adcValue=readADC();


	}




}

