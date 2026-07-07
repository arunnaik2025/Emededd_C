#include<reg51.h>
sbit LED=P1^0;
void main(void){
     while(1)
	 {
	 LED=1;
	 LED=0;
	}
}