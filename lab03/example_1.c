#include <avr/io.h>
// #include <util/delay.h>
// #define BLINK_DELAY_MS 1000

void delay_timer0()
{
    TCNT0 = 0x00; // load timer counter register with 0

    TCCR0A = 0x00;         // set the Timer0 under normal mode with
    TCCR0B |= (1 << CS00); // no perscaler

    while ((TIFR0 & 0x01) == 0)
        ; // wait till timer overflow bit (T0V0) is set

    TCCR0A = 0x00; // clear Timer settings (this stops the timer)
    TCCR0B = 0x00;

    TIFR0 = 0x01; // clear the timer overflow bit (T0v0) for next round
                  // strange thing about this flag is in order to clear it we should
                  // write 1 to it This rule applies to+2 all falgs of AVR chip
}
int main(void)
{
    DDRB = DDRB | (1 << 5); // configure pin 5 of PORTB for output

    while (1)
    {
        PORTB = PORTB | (1 << 5); // set pin 5 high to turn led on
        delay_timer0();

        PORTB = PORTB & ~(1 << 5); // set pin 5 low to turn led off
        delay_timer0();
    }
}