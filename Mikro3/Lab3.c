#include <Lab3.h>

int butonSay=0;

#int_ext
void hariciKesme()  //Harici Kesmenin yapýlacaðý fonksiyon
{
output_c(0x00);
butonSay=0;
}

void main()
{
set_tris_b(0x02);
set_tris_d(0xFF);

output_b(0x00);
output_d(0x00);

enable_interrupts(int_ext); //int_ext kesmesini aktifleþtir
enable_interrupts(GLOBAL);  //Tüm kesmeleri aktifleþtir

   while(TRUE)
   {
   if(input(pin_b1))
   {
   delay_ms(20);
   if(butonSay==15)  //ButonSay binary olarak 4biti aþmasýn diye sýfýrlandý
      butonSay=0;
   butonSay++;
   while(input(pin_b1)); //Buton býrakýlana kadar bekle
   output_d(butonSay);  //Binary ButonSay deðerini yazdýr
   delay_ms(2000);  //2Saniye Bekle
   output_d(0x00);  //Ledlerin hepsini söndür
   }
   
      
   }

}
