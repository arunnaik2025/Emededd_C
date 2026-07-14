#include<reg51.h>
sbit LED1=P1^0;
sbit LED2=P1^1;
void delay(unsigned int t){
	unsigned int i,j;
	while(t--){
	for(i=0;i<500;i++){
		for(j=0;j<1275;j++);
	}
	}
}
void main(void){
	while(1){
		LED1=0;
		LED2=1;
		delay(10);
		LED1=1;
		LED2=0;
		delay(10);
	}
}
	
	