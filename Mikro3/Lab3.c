#include <Lab3.h>

int butonSay=0;

#int_ext
void hariciKesme()  //Harici Kesmenin yap�laca�� fonksiyon
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

enable_interrupts(int_ext); //int_ext kesmesini aktifle�tir
enable_interrupts(GLOBAL);  //T�m kesmeleri aktifle�tir

   while(TRUE)
   {
   if(input(pin_b1))
   {
   delay_ms(20);
   if(butonSay==15)  //ButonSay binary olarak 4biti a�mas�n diye s�f�rland�
      butonSay=0;
   butonSay++;
   while(input(pin_b1)); //Buton b�rak�lana kadar bekle
   output_d(butonSay);  //Binary ButonSay de�erini yazd�r
   delay_ms(2000);  //2Saniye Bekle
   output_d(0x00);  //Ledlerin hepsini s�nd�r
   }
   
      
   }

}
