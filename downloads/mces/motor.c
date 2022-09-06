#include<LPC214x.H>
#define CLK    0x00010000
#define ACLK   0x00020000
void delay(unsigned int count)
{
	int j=0,i=0;
	for(j=0;j<count;j++)
	{
		for(i=0;i<500;i++);
	}
}
int main(void)
{
	unsigned char run=1;
	IO1DIR=0x0F000000;
	PINSEL2=0x0;
	{
		while(1)
		{
			if(!(IO1PIN & CLK))
				run=1;
			if(!(IO1PIN & ACLK))
				run=0;
			if(run==1)
			{
				IO1PIN=0x01000000;
				delay(100);
				IO1PIN=0x02000000;
				delay(100);
				IO1PIN=0x04000000;
				delay(100);
				IO1PIN=0x08000000;
				delay(100);
			}
			else
				{
					IO1PIN=0x08000000;
				delay(100);
				IO1PIN=0x04000000;
				delay(100);
				IO1PIN=0x02000000;
				delay(100);
				IO1PIN=0x01000000;
				delay(100);
				}
			}
		}
	}
	
				