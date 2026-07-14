#include<reg51.h>
sbit LED=P1^0;
void delay(unsigned int t){
	unsigned int i,j;
	while(t--){
		for(i=0; i<500; i++){
			for(j=0; j<1275; j++);
		}
	}
}
void main(void){
	while(1){
	LED=0;
	delay(5);
	LED=1;
	delay(5);
	LED=0;
	delay(10);
	LED=1;
	delay(10);
	LED=0;
	delay(15);
	LED=1;
	delay(15);
	}
}