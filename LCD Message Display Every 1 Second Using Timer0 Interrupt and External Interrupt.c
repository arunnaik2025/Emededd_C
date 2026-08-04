#include<reg51.h>
sbit RW=P1^0;
sbit RS=P1^1;
sbit EN=P1^2;
void delay(void);
void LCD_command(unsigned char cmd);
void LCD_data(unsigned char ch);
void LCD_string(char *str);
void LCD_init(void);
unsigned count=0;
bit send_data=0;
void Timer0_ISR(void)interrupt 1{
	TH0=0xFC;
	TL0=0x66;
	count++;
	if(count>=1000){
		count=0;
		send_data=1;
	}
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
void LCD_string(char *str){
	while(*str!='\0'){
		LCD_data(*str);
		str++;
	}
}
void LCD_init(void){
	LCD_command(0x38);
	LCD_command(0x0C);
	LCD_command(0x06);
	LCD_command(0x01);
}
void INT0_ISR(void)interrupt 0{
	TR0=0;
}
void main(void){
	LCD_init();
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x66;
	EA=1;
	ET0=1;
	EX0=1;
	IT0=1;
	TR0=1;
	while(1){
		if(send_data==1){
			send_data=0;
			LCD_command(0x01);
			LCD_command(0x80);
			LCD_string("HELLO");
		}
	}
}