#include <LPC214x.H>                       /* LPC214x definitions */
#define DIG2	           		(1 << 11)
//#define LED_DATA_MASK           0x007F8000
////////// digits are created using bit patterns corresponding to the segments ////////////////////
unsigned char dig[] = {0x88,0xeb,0x4c,0x49,0x2b,0x19,0x18,0xcb,0x8,0x9,0xa,0x38,0x9c,0x68,0x1c,0x1e};

/****************************************************************************
  Function Name : delay()
********************************************************************************/
void delay(unsigned int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    for(i=0;i<120;i++);
  }
}
///////////////////////////////// MAIN  ///////////////////////////////////////
int main (void) 
{
unsigned char count=0;
unsigned short j=0;
unsigned short i=0;
unsigned char data ;
  IO0DIR |= (DIG2 );	//Set Digit control lines as Outputs
  IO0CLR = ( DIG2 );	//Clear Digit control lines
  while(1)
 {
		count++;
		if(count ==16) count = 0;

		for (i=0; i < 800; i++)	//change to inc/dec speed of count
		 {
		  IO0CLR = 0x007F8000;
			IO0SET = (dig[count] << 15);
			IO0DIR |= 0x007F8000; 
			
			IO0SET = DIG2;
			for (j=0;j<2000;j++);	//change to inc/dec brightness of display
			IO0CLR = DIG2;
		 }		
  }
}
