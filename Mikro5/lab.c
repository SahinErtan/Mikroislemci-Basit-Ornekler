#include <lab.h>
#use delay(crystal=4000000)

#include <LCD.C>

#define use_portd_lcd TRUE

float voltaj;
float sicaklik;
int16 bilgi; 

#int_timer1
void timer()
{
   set_timer1(65527);  //no=170114009 TMR1 65527'den Baþlamalý
   lcd_gotoxy(1,1);
   printf(lcd_putc, "\f ERTAN SAHIN");
   delay_ms(2000);
   printf(lcd_putc, "\f ");
}


void main()
{
   setup_adc_ports(sAN0);  
   setup_adc(ADC_CLOCK_DIV_2);
   lcd_init();
   setup_timer_1(T1_EXTERNAL|T1_DIV_BY_1);  //PRESCALER=1
   set_timer1(65527);  
   enable_interrupts(int_timer1); 
   enable_interrupts(GLOBAL);
   while(TRUE)
   {
      set_adc_channel(0);
      delay_us(20);
      bilgi= read_adc();
      voltaj=0.0048828125*bilgi;
      sicaklik=voltaj*100;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"voltaj= %2.2f", voltaj);
      delay_ms(100);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"sicaklik= %2.2f", sicaklik);
      delay_ms(100);
   }
   
 }
