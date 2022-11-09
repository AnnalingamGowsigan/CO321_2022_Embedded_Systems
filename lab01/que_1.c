#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 1000
int main(void)
{
    DDRB = DDRB | (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3); /* first 4 of PORTB for output*/
    PORTB = 0x0F;

    while (1)
    {

        PORTB = ~PORTB;
        _delay_ms(BLINK_DELAY_MS);
    }
}