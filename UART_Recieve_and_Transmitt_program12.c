#include<reg51.h>
void UART_init(void){
	TMOD=0x20;
	SCON=0x50;
	TH1=0xFD;
	TL1=0xFD;
	TR1=1;
}
void main(void){
	UART_init();
	while(1){
		while(RI==0);
		SBUF=SBUF;
		RI=0;
		while (TI==0);
		TI=0;
	}
}