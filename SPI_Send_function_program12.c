#include<reg51.h>

sbit MOSI=P1^0;
sbit SCK=P1^2;

void spi_send(unsigned char value)
{
unsigned char i;
for(i=0;i<8;i++)
{
if(value&0x80)
MOSI=1;
else
MOSI=0;
SCK=1;
SCK=0;
value=value<<1;
}
}

void main(void)
{
while(1)
{
spi_send(0xA5);
}
}