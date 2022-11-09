/*
XTAL=16 MHz
Txal_clock=1/16microseconds

---->take prescaler as 1:8
prescaler=1:8
TCounterClock=8 * 1/16
            =0.5microsec
conter increaments needed=2000 /0.5 = 4000
Initial counter value=1+255-4000 = it is inappropiraite


---->take prescaler as 1:64
prescaler=1:64
TCounterClock=64 * 1/16
            =4microsec
conter increaments needed=2000 /4 = 500
Initial counter value=1+255-500 = -244 (inappropriate)


---->take prescaler as 1:1024
prescaler=1:1024
TCounterClock=1024 * 1/16
            =64microsec
conter increaments needed=2000 /64 = 31.25
Initial counter value=1+255-31.25 = it is inappropiraite (it is in decimal)


---->take prescaler as 1:256
prescaler=1:256
TCounterClock=256 * 1/16
            =16microsec
conter increaments needed=2000 /16 = 125
Initial counter value=1+255-125 = 131


So suitable prescaler is  1:256
*/
#include <avr/io.h>

void delay_timer0()
{
    TCNT0 = 131; // load timer counter register with 0

    TCCR0A = 0x00; // set the Timer0 under normal mode with 1:8 perscaler
    TCCR0B = 0x04;

    while ((TIFR0 & 0x01) == 0)
        ; // wait till timer overflow bit (T0V0) is set

    TCCR0A = 0x00; // clear Timer settings (this stops the timer)
    TCCR0B = 0x00;

    TIFR0 = 0x01; // clear the timer overflow bit (T0v0) for next round
                  // strange thing about this flag is in order to clear it we should
                  // write 1 to it This rule applies to all falgs of AVR chip
}

int main(void)
{
    DDRB = DDRB | (1 << 5); // configure pin 5 of PORTB for output

    while (1)
    {
        PORTB = PORTB ^ (1 << 5); // toggle pin 5
        delay_timer0();
    }
}