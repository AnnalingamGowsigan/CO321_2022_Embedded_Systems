// toggle PB 200 times
#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void)
{
    DDRB = 0xFF;

    PORTB = 0xAA;

    for (unsigned char i = 0; i < 200; i++)
    {
        PORTB = ~PORTB;
        _delay_ms(BLINK_DELAY_MS);
    }

    return 0;
}
