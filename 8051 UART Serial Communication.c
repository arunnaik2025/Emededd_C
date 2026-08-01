#include<reg51.h>
void UART_init(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TL1=0xFD;
	TR1=1;
}
unsigned char UART_Rx(void){
	unsigned char ch;
	while(RI==0){
	}
	ch=SBUF;
	RI=0;
	return ch;
}
void UART_Tx(unsigned char ch){
	SBUF=ch;
	while(TI==0){
	}
	TI=0;
}
void main(void){
	unsigned char value;
	UART_init();
	while(1){
		value=UART_Rx();
		UART_Tx(value);
	}
}