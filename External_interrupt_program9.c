#include<reg51.h>
sbit LED=P1^0;
void external_isr(void) interrupt 0{
	LED=~LED;
}
void main(void){
	LED=0;
	EA=1;//Enable Global interrupt
	EX0=1;//Enable External interrupt
	IT0=1;// Falling Edge trigered
	while(1);
}