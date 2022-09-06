#include <LPC214x.H>                       /* LPC214x definitions */
#include <stdio.h>
#include "lcd.h"

//////////   Init ADC0  /////////////////
int Init_ADC()
{
  // Convert Port pin 0.28 to function as AD0.2
  PINSEL1 = 0X01000000;
}

//////////   READ ADC0 CH:2  /////////////////
unsigned int Read_ADC()
{
  unsigned int i=0;

		AD0CR = 0x00200D02;  //0x00200D04;
    AD0CR |= 0x01000000; // Start A/D Conversion
    
      do
      {
        i = AD0GDR; // Read A/D Data Register
      } while ((i & 0x80000000) == 0); // Wait for end of A/D Conversion
    
	return (i >> 6) & 0x03FF; // bit 6:15 is 10 bit AD value

}

//////////   DISPLAY ADC VALUE /////////////////
void Display_ADC()
{
 unsigned int adc_value = 0;
 char buf[4] = {4};
 float voltage = 0.0;

  	adc_value = Read_ADC();	
  	sprintf((char *)buf, "%3d", adc_value);
  	lcd_putstring16(0,"ADC VAL = 000   ");
  	lcd_gotoxy(0,10);
		lcd_putstring(buf);
}

//////////   MAIN /////////////////
int main (void) 
{
  init_lcd();
  Init_ADC();
  while(1)
  {
   	Display_ADC();
  	delay(50000);
  }
}
