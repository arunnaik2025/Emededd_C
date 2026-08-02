#include<reg51.h>
sbit SDA=P1^0;
sbit SCL=P1^1;
unsigned char read(void);
void UART_Tx(unsigned char ch);
unsigned count=0;
unsigned char temperature;
bit send_data = 0;
void Timer0_ISR(void)interrupt 1{
	TH0=0xFC;
	TL0=0x66;
	count++;
	if(count>=1000){
		count=0;
		send_data = 1;
   }
}
void init(void){
	SDA=1;
	SCL=1;
}
void delay(void){
	unsigned int i;
	unsigned int j;
	for(i=0; i<500; i++){
		for(j=0; j<1275; j++){
		}
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
void sendACK(void){
	SDA=0;
	SCL=1;
	delay();
	SCL=0;
	SDA=1;
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
	delay();
}
void checkACK(void){
	if(ACK()==0){
		SCL=0;
		while(1);
	}
}
void UART_init(void){
	SCON=0x50;
	TH1=0xFD;
	TL1=0xFD;
	TR1=1;
}
void UART_Tx(unsigned char ch){
	SBUF=ch;
	while(TI==0);
	TI=0;
}
void INTO_ISR(void)interrupt 0{
	TR0=0;
}
void main(void){
	init();
	TMOD=0x21;
	UART_init();
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
			
		start();
		write(0x90);
		checkACK();
		
		write(0x00);
		checkACK();
		
		start();
		write(0x91);
		checkACK();
		
		temperature=read();
		NACK();
		stop();
		
		UART_Tx(temperature);
		}
	}
}
	