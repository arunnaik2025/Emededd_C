#include<reg51.h>
sbit MOSI=P1^0;
sbit SS=P1^1;
sbit SCK=P1^2;
sbit MISO=P1^3;
sbit LED=P2^0;
void SPI_init(void){
	SS=1;
	SCK=0;
}
unsigned char SPI_Rx(void){
	unsigned char rxdata=0;
	unsigned char i=0;
	for(i=0; i<8; i++){
		SCK=1;
		rxdata=rxdata<<=1;
		if(MISO){
			rxdata|=0x01;
		}
		SCK=0;
	}
	return rxdata;
}
void main(void){
	unsigned char rxdata;
	SPI_init();
	while(1){
		rxdata=SPI_Rx();
		if(rxdata=='A'){
			LED=0;//On
		}
		else{
			LED=1;//off
		}
	}
}