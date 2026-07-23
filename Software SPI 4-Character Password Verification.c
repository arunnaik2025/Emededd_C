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
	while(i<8){
		SCK=1;
		rxdata<<=1;
		if(MISO){
			rxdata|=0x01;
		}
		SCK=0;
		i++;
	}
	return rxdata;
}
void main(void){
	unsigned char value[4];
	unsigned char i=0;
	SPI_init();
	while(1){
		for(i=0; i<4; i++){
			value[i]=SPI_Rx();
		}
		if(value[0]=='A'&&
			 value[1]=='B'&&
		   value[2]=='C'&&
		   value[3]=='D'){
			LED=0;
		}
		else{
			LED=1;
		}
	}
}