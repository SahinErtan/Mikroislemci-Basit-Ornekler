#include <main.h>

void main()
{
set_tris_a(0x01);
set_tris_d(0x00);
output_d(0x00);

int butonsay=0;


   while(TRUE)
   {
      if(input(pin_a0))
      {
      butonsay++;
       
       if(butonsay==1)
       {
       output_d(0x0F); //0000 1111 
       delay_ms(2000);
       }
       if(butonsay==2)
       {
       output_d(0x05); //0000 0101
       delay_ms(3000);
       }
       if(butonsay==3)
       {
       output_d(0x0A); //0000 1010
       delay_ms(5000);
       }
       if(butonsay==4)
       {
       output_d(0x09); //0000 1001
       delay_ms(2000);
       butonsay=0;
       }
       output_d(0x00);
       }
       
      }
     

}
