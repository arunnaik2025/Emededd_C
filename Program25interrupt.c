#include<reg51.h>
sbit LED=P1^0;
void INT0_ISR(void)interrupt 0{
	  LED=1;
}
void main(void){
	LED=0;
	EA=1;
	EX0=1;
	IT0=1;
	while(1){
	}
}