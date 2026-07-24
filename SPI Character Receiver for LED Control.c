#include<reg51.h>
sbit MOSI=P1^0;
sbit SCK=P1^1;
sbit SS=P1^2;
sbit MISO=P1^3;
sbit LED1=P2^0;
sbit LED2=P2^1;
sbit LED3=P2^3;
void SPI_init(void){
	SS=1;
	SCK=0;
	MOSI=0;
}
void SPI_Delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0; i<500; i++){
		for(j=0; j<1275; j++);
	}
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
	unsigned char rxdata;
	SPI_init();
	while(1){
	rxdata=SPI_Rx();
	if(rxdata=='A'){
		LED1=0;
		SPI_Delay();
	}
	else if(rxdata=='B'){
		LED2=0;
		SPI_Delay();
	}
	else if(rxdata=='C'){
		LED3=0;
		SPI_Delay();
	}
	else{
		LED1=1;
		SPI_Delay();
		LED2=1;
		SPI_Delay();
		LED3=1;
		SPI_Delay();
	}
	}
}

		
	