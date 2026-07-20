#include<reg51.h>
void UART_initi(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
}
void UART_TX(char ch){
	SBUF=ch;
	while(TI==0){
	}
	TI=0;
}
void UART_string(char *str){
	while(*str!=0){
		UART_TX(*str);
		str++;
	}
}
void main(void){
	UART_initi();
	while(1){
		UART_string("Embedded system");
	}
}