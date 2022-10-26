#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int count = 0;

int main(void)
{
    DDRD &= ~(1 << 7);                                                             // PD7 is input
    DDRB = DDRB | (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // Set PORTB is output

    while (1)
    {
        if (PIND & (1 << 7))
        {
            PORTB = ++count;
            _delay_ms(BLINK_DELAY_MS);
        }
    }

    return 0;
}
