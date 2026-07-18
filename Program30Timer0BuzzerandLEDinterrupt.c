#include<reg51.h>
sbit LED=P1^0;
sbit BUZZER=P1^1;
void Timer1_ISR(void)interrupt 3{
	TH1=0xFC;
	TL1=0x66;
	LED=~LED;
	BUZZER=~BUZZER;
}
void main(void){
	LED=1;
	BUZZER=1;
	TMOD=0x10;
	TH1=0xFC;
	TL1=0x66;
	EA=1;
	ET1=1;
	TR1=1;
	while(1){
	}
}