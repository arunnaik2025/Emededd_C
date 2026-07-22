#include<reg51.h>
sbit MOSI=P1^0;
sbit SS=P1^1;
sbit SCK=P1^2;
sbit MISO=P1^3;
void SPI_init(void){
	SS=1;
	MOSI=0;
	SCK=0;
}
void SPI_Delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0; i<500; i++){
		for (j=0; j<1275; j++);
	}
}
void SPI_Tx(unsigned char txdata){
	unsigned int i=0;
	while(i<8){
		if(txdata&0x80){
			MOSI=1;
		}
		else{
			MOSI=0;
		}
		SPI_Delay();
		SCK=1;
		SPI_Delay();
		SCK=0;
	  txdata=txdata<<1;
		i++;
	}
}
void main(void){
	unsigned char parameter[]={0xAA,0x55,0xFF};
	SPI_init();
	while(1){
		unsigned char i;
		for(i=0; i<3; i++){
			SPI_Tx(parameter[i]);
		}
	}
}
		
		
		