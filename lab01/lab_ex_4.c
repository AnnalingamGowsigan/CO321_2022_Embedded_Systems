#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB &= ~(1 << 5);      // PB5 is input
    DDRC = DDRC | (1 << 7); // Set PORTC5 is output

    while (1)
    {
        if (PINB & (1 << 5))
        {
            PORTC |= (1 << 7);
        }
        else
        {
            PORTC &= ~(1 << 7);
        }
    }

    return 0;
}
