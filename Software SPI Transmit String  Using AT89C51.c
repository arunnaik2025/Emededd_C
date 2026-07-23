#include<reg51.h>
sbit MOSI=P1^0;
sbit SS=P1^1;
sbit SCK=P1^2;
sbit MISO=P1^3;
void SPI_init(void){
	SS=1;
	SCK=0;
	MOSI=0;
}
void SPI_Delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0;i<500;i++){
		for(j=0; j<1275; j++){
		}
	}
}
void SPI_Tx(unsigned char txdata){
	unsigned char i=0;
	for(i=0; i<8; i++){
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
	}
}
void main(void){
	unsigned char list[]="Arun";
	unsigned char i=0;
	SPI_init();
	while(1){
		if(list[i]=='\0'){
			break;
		}
		SPI_Tx(list[i]);
		i++;
	}
}