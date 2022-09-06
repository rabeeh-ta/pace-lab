#include<LPC214x.H>
void Init_DAC()
{
	PINSEL1=0X00080000;
	DACR=0;
}
void write_DAC(unsigned int dacval)
{
	DACR=dacval<<6;
}
int main(void)
{
	unsigned int i;
	Init_DAC();
	while(1)
	{
		for(i=0;i<1024;i++)
		write_DAC(i);
		for(i=1023;i>0;i--)
		write_DAC(i);
	}
}