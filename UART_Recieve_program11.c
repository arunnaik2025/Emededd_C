#include <reg51.h>

void UART_init(void)
{
    TMOD = 0x20;
    SCON = 0x50;
    TH1 = 0xFD;
    TL1 = 0xFD;
    TR1 = 1;
}

void UART_send(char ch)
{
    SBUF = ch;
    while(RI == 0);
    RI = 0;
}

void main(void)
{
    UART_init();

    while(1)
    {
        UART_send('A');
    }
}