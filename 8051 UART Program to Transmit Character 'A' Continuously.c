#include<reg51.h>
void UART_Init(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TL1=0xFD;
	TR1=1;
}
void UART_Tx(char ch){
	SBUF=ch;
	while(TI==0);
		TI=0;
}
void main(void){
	UART_Init();
	while(1){
		UART_Tx('A');
	}
}