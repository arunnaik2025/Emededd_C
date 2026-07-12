#include<reg51.h>
sfr WDTCON=0xA7;
void WDT_initi(void){
	WDTCON=0xE1;
}
void WDT_reset(void){
	WDTCON=0x1E;
}
void delay(void){
	unsigned int i,j;
	for(i=0; i<500; i++){
		for(j=0; j<1275; j++);
	}
}
void main(void){
	WDT_initi();
	while(1){
		delay();
		WDT_reset();
	}
}