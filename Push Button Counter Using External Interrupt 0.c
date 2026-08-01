#include<reg51.h>
sbit INTO=P3^2;
sbit LED=P1^0;
unsigned char count=0;
void INT0_ISR(void)interrupt 0{
	count++;
	P1=count;
}
void main(void){
	EA=1;
	EX0=1;
	IT0=1;
	while(1){
	}
}