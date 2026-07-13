#include<reg51.h>
sbit LED=P1^0;
void delay(unsigned int t){
	unsigned int i;
	while(t--){
		for(i=0; i<1275; i++);
}
}
void main(void){
	unsigned char j;
	while(1){
		for(j=0; j<3; j++){
	LED=0;
	delay(10);
	LED=1;
	delay(20);
	}
		delay(30);
}
}
	