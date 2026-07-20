#include<reg51.h>
void UART_init(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
}
char UART_Rx(void){
	char ch;
	while(RI==0);
		ch=SBUF;
		RI=0;
		return ch;
}
void UART_String(char *str){
	while(1){
	  *str=UART_Rx();
		if(*str=='\r'){
		  break;
		}
		str++;
		*str='\0';
	}
}
void main(void){
	unsigned int i;
	char msg[20];
	UART_init();
	while(1){
		i=0;
		while(1){
		    msg[i]=UART_Rx();
			  if(msg[i]=='\r'){
			     break;
				}
				i++;
	  }
		msg[i]='\0';
  }
}