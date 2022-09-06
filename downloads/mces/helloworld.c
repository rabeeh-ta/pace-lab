#include<lpc214x.h>
void initclock(void);
void inituart0(void);
void U0write(char data);
void send_string(char* stringptr);
char string[]=" hello world \n\r\n";
unsigned int delay;
int main(void)
{
	initclock();
	inituart0();
	{
	 send_string(string);
   for(delay=0;delay<500000;delay++);
	}
}
void inituart0(void)
{
	PINSEL0=0X5;
	U0LCR=0X83;
	U0DLL=110;
	U0DLM=1;
	U0FDR=0XF1;
	U0LCR &=0X0F;
}
void U0write(char data)
{
	while(!(U0LSR &(1<5)));
	U0THR=data;
}
void initclock(void)
{
	PLL0CON=0X01;
	PLL0CFG=0X24;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
	while(!(PLL0STAT & 0X00000040));
	PLL0CON=0X03;
	PLL0FEED=0XAA;
	PLL0FEED=0X55;
	VPBDIV=0X01;
}
void send_string(char*stringptr)
{
	while(*stringptr!=0x00)
	{
		U0write(*stringptr);
		stringptr++;
	}
}