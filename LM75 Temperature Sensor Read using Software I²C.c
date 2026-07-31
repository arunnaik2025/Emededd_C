#include<reg51.h>
sbit SDA=P1^0;
sbit SCL=P1^1;
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
void start(void){
	SDA=1;
	SCL=1;
	delay();
	SDA=0;
	SCL=0;
	delay();
}
void write(unsigned char tdata){
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
bit ACK(void){
	SDA=1;
	SCL=1;
	delay();
	if(SDA==0){
		SCL=0;
		return 1;
	}
	SCL=0;
	return 0;
}
unsigned char read(void){
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
void NACK(void){
	SDA=1;
	SCL=1;
	delay();
	SCL=0;
	delay();
}
void stop(void){
	SDA=0;
	SCL=1;
	delay();
	SDA=1;
}
void checkACK(void){
	if(ACK()==0){
		SCL=0;
		while(1);
	}
}
void main(void){
	unsigned char temparature;
	init();
	while(1){
		start();
		write(0x90);
		checkACK();
		
		write(0x00);
		checkACK();
	  
		start();
		write(0x91);
		checkACK();
		
		temparature=read();
		NACK();
		stop();
	}
}
	
		