#include <main.h>

void main()
{
set_tris_b(0x00);
   
   while(true)
   {
      output_low(pin_a0);
      delay_ms(500);
      output_high(pin_a0);
      delay_ms(500);
   }

}
