#include "stm32f10x.h"                  // Device header
#include "stm32f10x_usart.h"            // Keil::Device:StdPeriph Drivers:USART

char test[25]="test\n";
uint16_t veri=0;
GPIO_InitTypeDef gpio;
USART_InitTypeDef uart;

void config(){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	
	gpio.GPIO_Mode=GPIO_Mode_AF_PP;
	gpio.GPIO_Pin=GPIO_Pin_9;                        //iletici
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&gpio);
	
	
	gpio.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	gpio.GPIO_Pin=GPIO_Pin_10;                        //alici
	GPIO_Init(GPIOA,&gpio);
	

	gpio.GPIO_Mode=GPIO_Mode_Out_PP;
	gpio.GPIO_Pin=GPIO_Pin_0;                         	//LED
	gpio.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&gpio);

}

void uartf(){
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	uart.USART_BaudRate=9600;
	uart.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	uart.USART_Mode=USART_Mode_Tx | USART_Mode_Rx;
	uart.USART_Parity=USART_Parity_No;
	uart.USART_StopBits=USART_StopBits_1;
	uart.USART_WordLength=USART_WordLength_8b;
	
	USART_Init(USART1,&uart);
	USART_Cmd(USART1,ENABLE);

}

void uartTransmit(char *string){
	while(*string){
		while(!(USART1->SR & 0x00000040));
		USART_SendData(USART1,*string);
		*string++;

	}
}


int main(){
	
	config();
	uartf();
	
	
	while(1){
		
		veri=USART_ReceiveData(USART1);             //iletici;
		
		if(veri=='1'){
			GPIO_SetBits(GPIOB,GPIO_Pin_0);
                                                //alici
		}if(veri=='0'){
			GPIO_ResetBits(GPIOB,GPIO_Pin_0);
		}
		
	}




}

