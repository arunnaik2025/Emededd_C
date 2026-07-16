#include<reg51.h>
sbit LED=P1^0;
void INTO_ISR(void)interrupt 0{
   LED=0;//ON
}
void main(void){
	 LED=1;//initially off
   EA=1;
	 EX0=1;
	 IT0=1;
	 while(1);
}