#include<reg51.h>
sbit ADC_WR=P3^6;
sbit ADC_RD=P3^7;
sbit ADC_INTR=P3^5;
unsigned char ADC_read(void);
unsigned char adc_value;
unsigned count=0;
unsigned send_data=0;
void Timer0_ISR(void)interrupt 1{
	TH0=0xFC;
	TL0=0x66;
	count++;
	if(count>=1000){
		count=0;
		send_data=1;
}
}
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
unsigned char ADC_read(void){
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
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	EA=1;
	ET0=1;
	TR0=1;
	while(1){
		if(send_data==1){
			send_data=0;
		adc_value=ADC_read();
	}
}
}
	
		
	