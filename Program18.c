#include<reg51.h>
void delay(unsigned int t){
	unsigned int i,j;
	while(t--){
	for(i=0; i<21; i++){
		for(j=0; j<1275; j++);
    }
  }
}
void main(void){
	while(1){
	P1=0xFF;
	delay(20);
	P1=0x00;
	delay(20);
}
}
		