#include<reg51.h>
sbit ADC_WR=P3^6;
sbit ADC_RD=P3^7;
sbit ADC_INTR=P3^5;
void delay(void){
	unsigned int i;
	for(i=0; i<1000; i++){
	}
}
void ADC_init(void){
	WR=1;
	RD=1;
}
unsigned char ADC_Read(void){
	unsigned char adc_value;
	WR=0;
	delay();
	WR=1;
	while(ADC_INTR==1){
	}
	RD=0;
	adc_value=P2;
	RD=1;
	return adc_value;
}
void main(void){
	unsigned char value;
	ADC_init();
	while(1){
		value=ADC_Read();
	}
}
			
		