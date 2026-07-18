#include<reg51.h>
sbit LED1=P1^0;
sbit LED2=P1^1;
sbit INTO=P3^2;
void INT0_ISR(void)interrupt 0{
	TR0=1;
}
void TIMER0_ISR(void)interrupt 1{
	TH0=0xFC;
	TL0=0x66;
	LED1=~LED1;//toggle
	LED2=~LED2;	//toggle
}
void main(void){
	LED1=1;//off
	LED2=1;//off
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	IT0=1;
	EA=1;
	EX0=1;
	ET0=1;
	TR1=0;
	while(1){
	}
}