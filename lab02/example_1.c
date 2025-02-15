#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 2000

int main(void)
{
    DDRD &= ~(1 << 2); // PD2 (INTO) is input
    DDRB |= (1 << 5);  // PB5 is output

    EICRA |= (1 << ISC00); // set for rising edge detection
    EICRA |= (1 << ISC01); // set for rising edge detection

    sei(); // enable global interrupts

    EIMSK |= (1 << INT0); // enable external interrupt for int0

    while (1)
    {
    }

    return 0;
}

ISR(INT0_vect)
{
    PORTB &= ~(1 << 5);
    _delay_ms(BLINK_DELAY_MS);
    PORTB |= 1 << 5;
}