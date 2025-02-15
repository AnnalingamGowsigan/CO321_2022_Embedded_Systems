#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main(void)
{
  DDRB = DDRB | (1 << 0); /* configure pin 5 of PORTB for output*/
  while (1)
  {
    PORTB = PORTB | (1 << 0); /* set pin 5 high to turn led on */
    _delay_ms(BLINK_DELAY_MS);
    PORTB = PORTB & ~(1 << 0); /* set pin 5 low to turn led off */
    _delay_ms(BLINK_DELAY_MS);
  }
}