#include<reg51.h>
void delay(void){
	unsigned int i,j;
	for(i=0; i<300; i++){
		for(j=0; j<1275; j++);
	}
}
void main(void){
	while(1){
		P1=0x01;
		delay();
		P1=0x02;
		delay();
		P1=0x04;
		delay();
	}
}