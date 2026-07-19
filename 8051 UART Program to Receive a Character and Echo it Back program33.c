#include<reg51.h>
void UART_init(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
}
void main(void){
	char ch;
	UART_init();
	while(1){
  while(RI==0){
		ch=SBUF;
		RI=0;
	}
	SBUF=ch;
	while(TI==0);
		TI=0;
  }
}