#include<reg51.h>
sbit LED=P1^0;
void INT0_ISR(void)interrupt 0{
	TR0=1;
}
unsigned int count;
void TIMER0_ISR(void)interrupt 1{
	TH0=0xFC;
	TL0=0x66;
	count++;
	if(count==5){
		LED=0;
		TR0=0;
		count=0;
  }
}
void main(void){
	LED=1;
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	IT0=1;
	EA=1;
	EX0=1;
	ET0=1;
	TR0=0;
	while(1){
	}
}
	