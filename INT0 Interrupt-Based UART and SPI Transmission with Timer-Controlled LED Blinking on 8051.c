#include<reg51.h>
sbit MOSI=P1^0;
sbit SCK=P1^1;
sbit SS=P1^2;
sbit MISO=P1^3;
sbit LED1=P2^0;
sbit LED2=P2^1;
void UART_init(void){
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}
void SPI_init(void){
	SS=1;
	SCK=0;
	MOSI=0;
}
void Timer_delay(void){
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}
void SPI_delay(void){
		unsigned int i;
		for(i=0; i<20; i++);
}
void UART_Tx(unsigned char ch){
	SBUF=ch;
	while(TI==0);
	TI=0;
}
void SPI_Tx(unsigned char txdata){
	unsigned char i=0;
	while(i<8){
	if(txdata&0x80){
		MOSI=1;
	}
	else{
		MOSI=0;
	}
	SCK=1;
	SPI_delay();
	SCK=0;
	SPI_delay();
	txdata<<=1;
	i++;
  }
}
void INTO_ISR(void)interrupt 0{
	unsigned char i;
	unsigned char event_flag=0;
	while(1){
		if(event_flag==1){
			event_flag=0;
	UART_Tx('A');
	SPI_Tx('A');
	for(i=0; i<5; i++){
		LED1=0;
		Timer_delay();
		LED1=1;
		Timer_delay();
	}
	LED2=0;
	Timer_delay();	
}
		}
	}
void main(void){
	UART_init();
	SPI_init();
	EA=1;
	EX0=1;
	IT0=1;
	while(1){
 }
}

	