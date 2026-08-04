#include<reg51.h>
sbit RW=P1^0;
sbit RS=P1^1;
sbit EN=P1^2;
void delay(void);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char ch);
void LCD_init(void);
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
void LCD_init(void){
	LCD_command(0x38);
	LCD_command(0x0C);
	LCD_command(0x06);
	LCD_command(0x01);
}
void main(void){
	LCD_init();
	LCD_command(0x80);
	LCD_data('A');
	while(1);
}
	
	