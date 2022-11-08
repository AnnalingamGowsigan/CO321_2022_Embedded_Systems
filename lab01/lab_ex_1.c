#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 2000

int main(void)
{
    DDRB = 0xFF;
#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

    int main(void)
    {
        DDRB = 0xFF;

        for (unsigned char i = 0; i < 256; i++)
        {
            PORTB = i;
            _delay_ms(BLINK_DELAY_MS);
        }

        return 0;
    }

    PORTB = 0x00;

    for (unsigned int i = 0; i < 256; i++)
    {
        PORTB = i;
    }

    return 0;
}
