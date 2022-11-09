#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main(void)
{
    DDRB = DDRB | (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3); /* first 4 of PORTB for output*/
    PORTB = 0x00;

    unsigned char i;
    while (1)
    {

        // Methode- 1
        for (i = 1; i <= 8; i *= 2)
        {
            PORTB = i;
            _delay_ms(BLINK_DELAY_MS);
        }
        for (i = 4; i > 1; i /= 2)
        {
            PORTB = i;
            _delay_ms(BLINK_DELAY_MS);
        }

        //// Methode- 2
        //  for (i = 0; i <= 3; i++)
        //  {
        //    PORTB = PORTB | (1 << i);
        //    _delay_ms(BLINK_DELAY_MS);
        //    PORTB = PORTB & ~(1 << i);
        //  }
        //  for (i = 2; i > 0; i--)
        //  {
        //    PORTB = PORTB | (1 << i);
        //    _delay_ms(BLINK_DELAY_MS);
        //    PORTB = PORTB & ~(1 << i);
        //  }
    }
}