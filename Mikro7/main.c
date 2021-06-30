#include <main.h>

#device ADC=10
#use delay(crystal=800000) //Timer1 için 50Hz degerine ulasabilmek için 800KHz

int16 analog; //1024'e kadar deger kullanilacagindan int16 tanimlanmistir.
int16 deger;  

int i=0;
int j=0;

#int_timer0
void kesme()
{
   set_timer0(6);  //Timer0 Kesmesi tekrar kuruluyor.
   /*
   TMR0=6 icin 5x4x250 = 5ms kesme olusuyor.
   1.5 saniye icin 300 dongu gerektiginden 
   */
   i++;
   if(i==20) //20
   {
      i=0;  //i degeri 20'ye ulastigi icin sifirlaniyor
      j++;
   }
   if(j==15) //i ve j deðeri 20x15 olaraktan 300 tekrar sagliyor
   {
      analog=read_adc();
      deger=analog/72;  //Potansiyometreden Gelen 1024 deðer 14 farklý deger icin bolmelendiriliyor
      set_pwm1_duty((int)(deger+12)); //PWM Duty int deger ile calýsýyor ve 1ms 12 degerine karsýlýk geliyor.
      j=0;  //j degeri 15 e ulastigi icin sifirlaniyor i zaten sifirlanmisti bu asamada
      output_toggle(pin_c7);  //Kesmenin ani görülebilsin diye bir led tanimlandi.

   }

}

void main()
{

   set_tris_c(0x00);  //C pinleri cikis olarak ayarlaniyor
   output_c(0x00);  //C pin cikislari sifirlaniyor

   
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_4 | RTCC_8_bit); //8 bit icin 4 Prescaler degerli timer0 kuruldu
   set_timer0(6); // 5x4x300x(256-6)=1.5ms
   
   setup_timer_2(T2_DIV_BY_16,250,1); // 16 Pre ve 1 Postscale ile timer2 kuruldu, Motor icin 50Hz frekans degeri TMR1=250 deðeri ile elde edildi
   setup_ccp1(CCP_PWM); 
   set_pwm1_duty(12);  //Baslangicta pwm'in duty degeri motorun -90 derece olmasi icin ayarlanmistir.
   
   
   setup_adc(ADC_CLOCK_DIV_16);
   setup_adc_ports(sAN0); //AN0 kanali analog giris ayarlandi
   set_adc_channel(0); //ADC'nin okuyacagi kanal AN0 ayarlandi.
   delay_us(20); 
   
   enable_interrupts(int_timer0); //Timer0 Kesmesi Aktif Edildi
   enable_interrupts(GLOBAL);  //Tüm Kesmeler Aktif Edildi
   

   while(TRUE)
   {
       //Burada Ýslem Yapilmiyor Programin Calismaya Devam Etmesi Ýcin Bos Birakilmistir
   }

}
