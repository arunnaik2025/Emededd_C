#include<reg51.h>
sbit LED=P1^0;
void delay(unsigned int t){
	unsigned int i;
	while(t--){
	for(i=0; i<1275; i++);
	}
}
void main(void){
	while(1){
		LED=0;
		delay(20);
		LED=1;
		delay(80);
	}
}
	
	