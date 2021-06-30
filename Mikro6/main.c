#include <main.h>

#device ADC=10
#use delay(crystal=8000000)

void main()
{
   int16 analog1=0;
   int16 analog2=0;
   int16 deger1=0;
   int16 deger2=0;
   int16 hafiza=255;


   setup_timer_2(T2_DIV_BY_4,hafiza,1);
   setup_ccp1(CCP_PWM);
   set_tris_a(0xFF);
   setup_adc(ADC_CLOCK_DIV_64);
   setup_adc_ports(sAN0|sAN1);
   set_adc_channel(0);


   while(TRUE)
   {
      set_adc_channel(0);
      delay_ms(10);
      analog1=read_adc();
      deger1= (analog1/1023.0)*(hafiza)*4;
      set_pwm1_duty(deger1);
      delay_ms(50);

      set_adc_channel(1);
      delay_ms(10);
      analog2=read_adc();
      deger2=(analog2/1023.0)*(255);
      if(deger2>=255)
      deger2=255;
      setup_timer_2(T2_DIV_BY_4,deger2,1);
      hafiza=deger2;
   }

}
