#include<reg51.h>
sbit ADC_WR=P3^6;
sbit ADC_RD=P3^7;
sbit ADC_INTR=P3^5;
unsigned char adc_value;
void init(void){
	ADC_WR=1;
	ADC_RD=1;
}
void delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0; i<500; i++){
		for(j=0; j<1275; j++);
	}
}
unsigned char ADC_Read(void){
	ADC_WR=0;
	delay();
	ADC_WR=1;
	while(ADC_INTR==1){
	}
	ADC_RD=0;
	adc_value=P2;
	ADC_RD=1;
	return adc_value;
}
void main(void){
	init();
	while(1){
		adc_value=ADC_Read();
		P1=adc_value;
	}
}
		
	
  