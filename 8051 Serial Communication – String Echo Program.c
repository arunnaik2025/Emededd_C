#include<reg51.h>
void UART_init(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
}
char UART_Rx(void){
	char ch;
	while(RI==0){
		ch=SBUF;
		RI=0;
		return ch;
	}
}
void UART_Tx(char ch){
	SBUF=ch;
  while(TI==0);
		TI=0;
}
void UART_string_Rx(char *str){
	while(1){
		*str=UART_Rx();
		if(*str=='\r'){
			break;
		}
		str++;
	}
	*str='\0';
}
void UART_string_Tx(char *str){
	while(*str=='\0'){
		UART_Tx(*str);
		str++;
	}
}
void main(void){
    char msg[20];
    UART_init();
    while(1) {
        UART_string_Rx(msg);
        UART_string_Tx(msg);
        UART_Tx('\r');
        UART_Tx('\n');
    }
}
	
		