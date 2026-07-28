#include<reg51.h>
sbit SDA=P1^0;
sbit SCL=P1^1;
void I2C_init(void){
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
	SDA=0;
	SCL=0;
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
bit I2C_ACK(void){
	SDA=1;
	SCL=1;
	delay();
	if(SDA==0){
		SCL=0;
		return 1;
	}
	else{
		SCL=0;
		return 0;
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
void I2C_SendACK(void){
	SDA=0;
	SCL=1;
	delay();
	SCL=0;
	SDA=1;;
	delay();
}
		
void I2C_SendNACK(void){
	SDA=1;
	SCL=1;
	delay();
	SCL=0;
}
void I2C_stop(void){
	SDA=0;
	SCL=1;
	SDA=1;
}
void main(void){
	unsigned char rdata1,rdata2,rdata3;
	I2C_init();
	while(1){
		I2C_start();
		I2C_write(0xA1);
		if(I2C_ACK()==0){
			I2C_stop();
			while(1);
		}
		rdata1=I2C_Read();
		I2C_SendACK();
		
		rdata2=I2C_Read();
		I2C_SendACK();
		
		rdata3=I2C_Read();
		I2C_SendNACK();
		
		I2C_stop();
		while(1);
	}
}
	
	
			