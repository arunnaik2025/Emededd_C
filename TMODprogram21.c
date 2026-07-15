#include<reg51.h>
sbit LED=P1^0;
void timer_delay(void){
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}
	void main(void){
		while(1){
		LED=0;
		timer_delay();
		LED=1;
		timer_delay();
		}
	}
		