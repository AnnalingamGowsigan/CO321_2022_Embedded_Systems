#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void)
{
    DDRB &= ~(1 << 7);   // PD7 is input
    DDRC = DDRB(1 << 5); // Set PORTB is output
                         // DDRB = 0b00111111

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
