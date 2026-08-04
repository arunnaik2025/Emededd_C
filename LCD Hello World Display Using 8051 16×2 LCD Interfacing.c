#include<reg51.h>
sbit RS=P1^0;
sbit RW=P1^1;
sbit EN=P1^2;
void delay(void);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char ch);
void LCD_string(char *str);
void init(void);
void delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0; i<500; i++){
		for(j=0; j<1275; j++){
		}
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
void LCD_string(char *str){
	while(*str!='\0'){
		LCD_data(*str);
		str++;
	}
}
void init(void){
	LCD_command(0x38);
	LCD_command(0x0C);
	LCD_command(0x06);
	LCD_command(0x01);
}
void main(void){
	init();
	LCD_command(0x80);
	LCD_string("Arun");
	while(1);
}
		