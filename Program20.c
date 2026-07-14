#include<reg51.h>
sbit LED1=P1^0;
sbit LED2=P1^1;
sbit LED3=P1^2;
sbit LED4=P1^3;
void delay(unsigned int t){
	unsigned int i;
	while(t--){
	for(i=0; i<60000; i++);
	}
}
void main(void){
	while(1){
	LED1=0;
	LED2=1;
	LED3=1;
	LED4=1;
	delay(5);
	LED1=1;
	LED2=0;
	LED3=1;
	LED4=1;
	delay(5);
	LED1=1;
	LED2=1;
	LED3=0;
	LED4=1;
	delay(5);
	LED1=1;
	LED2=1;
	LED3=1;
	LED4=0;
	delay(5);
 }
}