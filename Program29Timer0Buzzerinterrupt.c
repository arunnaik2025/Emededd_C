#include<reg51.h>
sbit BUZZER=P1^0;
void Timer0_ISR(void)interrupt 1{
	TH0=0xFC;
	TL0=0x66;
	BUZZER=~BUZZER;
}
void main(void){
  BUZZER=1;
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	EA=1;
	ET0=1;
	TR0=1;
	while(1){
	}
}
	