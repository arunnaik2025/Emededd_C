#include<reg51.h>
sbit BUZZER=P1^5;
void INT1_ISR(void)interrupt 2{
	BUZZER=0;//ON
}
void main(void){
	BUZZER=1;
	EA=1;
	EX1=1;
	IT1=1;
	while(1){
	}
}