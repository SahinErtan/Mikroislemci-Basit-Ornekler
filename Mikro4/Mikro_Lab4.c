#include <Mikro_Lab4.h>
#use delay(crystal=4000000)
//#use fast_io(c)

const int ekran[15]={0b00000110,0b01001111,0b01101101,0b00000111,0b01101111,
                     0b00111111,0b01011011,0b01100110,0b01111101,0b01111111,
                     0b01110111,0b00111001,0b01111001,0b01110001,0b00011110};


//const int tekler[5]={0b00000110,0b01001111,0b01101101,0b00000111,0b01101111};
//const int ciftler[5]={0b00111111,0b01011011,0b01100110,0b01111101,0b01111111};
//const int harfler[5]={0b01110111,0b00111001,0b01111001,0b01110001,0b00011110};
int i=0;
int sayac=0;

#int_timer0
void timer0_kesme()
{
   set_timer0(131);
   
   sayac+=1;
   if(sayac==125)
   {
     
     output_c(ekran[i]);
     i+=1;
     if(i==15) i=0;
     sayac=0;
   }
   
   
}
void main()
{
   set_tris_c(0x00);
   output_c(0x00);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_128 | RTCC_8_bit);
   set_timer0(131);
   enable_interrupts(int_timer0);
   enable_interrupts(GLOBAL);

while(TRUE);
}
