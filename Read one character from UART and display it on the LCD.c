#include<reg51.h>
sbit RW=P1^0;
sbit RS=P1^1;
sbit EN=P1^2;
void UART_init(void);
void delay(void);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char ch);
unsigned char UART_Rx(void);
void LCD_init(void);
void UART_init(void){
	SCON=0x50;
	TMOD=0x20;
	TH1=0xFD;
	TL1=0xFD;
	TR1=1;
}
void delay(void){
  unsigned int i;
	unsigned int j;
	for(i=0; i<500; i++){
	  for(j=0; j<1275; j++);
	}
}
void LCD_command(unsigned char cmd){
	RS=0;
	RW=0;
	P2=cmd;
	EN=1;
	delay();
	EN=0;
}
void LCD_data(unsigned char ch){
	RS=1;
	RW=0;
	P2=ch;
	EN=1;
	delay();
	EN=0;
}
unsigned char UART_Rx(void){
	unsigned char ch;
	while(RI==0);
		ch=SBUF;
		RI=0;
		return ch;
}
void LCD_init(void){
	LCD_command(0x38);
	LCD_command(0x0C);
	LCD_command(0x06);
	LCD_command(0x01);
}
void main(void){
	unsigned char character='A';
	LCD_init();
	UART_init();
	LCD_command(0x80);
	character=UART_Rx();
	LCD_data(character);
	while(1);
}
	
	
	

