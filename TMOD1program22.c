#include<reg51.h>
sbit LED=P1^2;
void timer_delay(void){
	TMOD=0x10;
	TH1=0xFC;
	TL1=0x66;
	TR1=1;
	while(TF1==0);
	TR1=0;
	TF1=0;
}
	void main(void){
		while(1){
		LED=0;
		timer_delay();
		LED=1;
		timer_delay();
		}
	}
		