#include<LPC214x.H>
int Init_DAC()
{
	PINSEL1=0x000800000;
	DACR = 0;
}
int Write_DAC(unsigned int dacval)
{
	DACR = dacval<<6;
}

void delay(unsigned int count )
{
	int j=0,i=0;
	for(j=0;j<count;j++)
	{
		for(i=0;i<120;i++);
	}
}
  int main(void)
  {
	   Init_DAC();
	      while(1)
	       {
	       	Write_DAC(00);
					delay(100);
					Write_DAC(1023);
					delay(100);
				 }
	 }