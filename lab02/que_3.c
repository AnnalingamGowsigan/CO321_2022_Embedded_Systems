#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 2000

// int count = 0;

int main(void)
{
    DDRD &= ~(1 << 2);                                                             // PD2 (INTO) is input
    DDRB = DDRB | (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); // Set PORTB is output

    EICRA &= ~(1 << ISC00); // set for falling edge detection
    EICRA |= (1 << ISC01);  // set for falling edge detection

    sei(); // enable global interrupts

    EIMSK |= (1 << INT0); // enable external interrupt for int0

    while (1)
    {
    }

    return 0;
}

ISR(INT0_vect)
{
    PORTB = PORTB + 1;
    // PORTB = count++;
    //_delay_ms(BLINK_DELAY_MS);
}