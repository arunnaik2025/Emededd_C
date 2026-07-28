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
void I2C_stop(void){
	SDA=0;
	SCL=1;
	delay();
	SDA=1;
}
void main(void){
	I2C_init();
	while(1){
		I2C_start();
		I2C_write(0xA0);
		if(I2C_ACK()==0){
			I2C_stop();
			while(1);
		}
		I2C_write(0x55);
		if(I2C_ACK()==0){
			I2C_stop();
			while(1);
		}
		I2C_stop();
}
}