#include<reg51.h>
sbit SDA=P3^0;
sbit SCL=P3^1;
sbit RW=P1^0;
sbit RS=P1^1;
sbit EN=P1^2;
void init(void){
	SDA=1;
	SCL=1;
}
void delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0; i<500; i++){
		for(j=0; j<1275; j++);
	}
}
void I2C_start(void){
	SDA=1;
	SCL=1;
	delay();
	SDA=0;
	SCL=0;
	delay();
}
void I2C_write(unsigned char tdata){
	unsigned char i;
	for(i=0; i<8; i++){
		if(tdata&0x80){
			SDA=1;
		}
		else{
			SDA=0;
		}
		SCL=1;
		delay();
		SCL=0;
		delay();
		tdata<<=1;
	}
}
unsigned char I2C_Read(void){
	unsigned char rdata=0;
	unsigned char i=0;
	SDA=1;
	for(i=0; i<8; i++){
		SCL=1;
		delay();
		rdata<<=1;
		if(SDA){
			rdata|=0x01;
		}
		SCL=0;
		delay();
	}
	return rdata;
}
void EEPROM_write(unsigned char address, unsigned char value){
	I2C_start();
	I2C_write(0xA0);
	I2C_write(address);
	I2C_write(value);
	I2C_stop();
}
unsigned char EEPROM_Read(unsigned char address){
	unsigned char value;
	I2C_start();
	I2C_write(0xA0);
	I2C_write(address);
	I2C_start();
	I2C_write(0xA1);
	value=I2C_Read();
	I2C_stop();
	return value;
}
void LCD_command(unsigned char cmd){
	RS=0;
	RW=0;
	P2=cmd;
	EN=1;
	delay();
	EN=0;
}
void LCD_data(unsigned char rdata){
	RS=1;
	RW=0;
	P2=rdata;
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
	unsigned char value;
	init();
	LCD_init();
	LCD_command(0x80);
	EEPROM_write(0x05,35);
	value=EEPROM_Read(0x05);
	LCD_data((value/10)+'0');
	LCD_data((value%10)+'0');
}
