#include<reg51.h>
void UART_init(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
}
char UART_Rx(void){
	unsigned char ch;
	while(RI==0);
		ch=SBUF;
		RI=0;
		return ch;
}
void UART_Tx(char ch){
	SBUF=ch;
	while(TI==0){
	}
	TI=0;
}
void UART_String_Rx(char *str){
	while(1){
		*str=UART_Rx();
		if(*str=='\r'){
			break;
		}
		str++;
	}
	*str='\0';
}
void UART_String_Tx(char *str){
	while(*str!='\0'){
		UART_Tx(*str);
		str++;
	}
}
unsigned char Password_check(char *password,char *correct){
	while(*password!='\0'&& *correct!='\0'){
		if(*password!=*correct){
			return 0;
		}
		password++;
		correct++;
	}
	if(*password=='\0'&& *correct=='\0'){
		return 1;
	}
	return 0;
}


void main(void){
	unsigned char password[10];
	unsigned char correct[]="1234";
	UART_init();
		while(1){
			UART_String_Rx(password);
			if(Password_check(password,correct)){
				UART_String_Tx("Access granted");
			}
				else{
					UART_String_Tx("Not granted");
				}
			}
		}
			
		
	