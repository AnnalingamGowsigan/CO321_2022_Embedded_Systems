#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 2000

int count = 0;

int main(void)
{
    DDRD &= ~(1 << 2);                                                             // PD2 (INTO) is input
    DDRD &= ~(1 << 3);                                                             // PD2 (INTO) is input
    DDRB = DDRB | (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // Set PORTB is output

    EICRA |= (1 << ISC00); // set for rising edge detection for INT0
    EICRA |= (1 << ISC01); // set for rising edge detection for INT0

    EICRA |= (1 << ISC10); // set for rising edge detection for INT1
    EICRA |= (1 << ISC11); // set for rising edge detection for INT1

    sei(); // enable global interrupts

    EIMSK |= (1 << INT0); // enable external interrupt for int0
    EIMSK |= (1 << INT1); // enable external interrupt for int1

    PORTB = 0x00;

    while (1)
    {
    }

    return 0;
}

ISR(INT0_vect)
{
    PORTB = (PORTB << 1);
    _delay_ms(BLINK_DELAY_MS);
}

ISR(INT1_vect)
{
    PORTB = (PORTB << 1) + 1;
    //_delay_ms(BLINK_DELAY_MS);
}