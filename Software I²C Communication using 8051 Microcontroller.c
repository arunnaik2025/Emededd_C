#include<reg51.h>
sbit SDA=P2^0;
sbit SCL=P2^1;
void I2C_init(void){
	SDA=1;
	SCL=1;
}
void delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0; i<8; i++){
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
void I2C_stop(void){
	SDA=0;
	SCL=1;
	SDA=1;
}
void I2C_Write(unsigned char tdata){
	unsigned char i=0;
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
char I2C_Read(void){
	unsigned char i=0;
	unsigned char rdata=0;
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
void main(void){
	unsigned char value;
	I2C_init();
	I2C_start();
	I2C_Write(0x55);
	value=I2C_Read();
	I2C_stop();
	while(1){
	}
}
