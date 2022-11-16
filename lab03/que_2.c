/*
    (1/p*16)*c=500000
    c/p=16*500000
    c*r=16*500000
    max r=1024
    c=16*500000/1024
    c=7,812.5
    so its not possible to add this count value .
    count value max is 255

*/

#include <avr/io.h>

// function for 2ms
void delay_timer0()
{
    unsigned char i; // variable to count to acheive 500ms

    for (i = 0; i < 250; i++) // 250*2ms = 500ms
    {

        TCNT0 = 131; // Load timer counter register

        TCCR0A = 0x00; // set timer0 under normal mode
        TCCR0B = 0x04; // set prescalar 1:256

        while ((TIFR0 & 0x01) == 0)
            ; // wait until overflow bit (T0V0) is set to 1

        TCCR0A = 0x00; // clear timer settings
        TCCR0B = 0x00;

        TIFR0 = 0X01; // clear the overflow bit (t0v0) for next round
    }
}

int main(void)
{

    DDRB = DDRB | (1 << 5); // set pin 5 of port B as output

    while (1)
    {
        PORTB = PORTB ^ (1 << 5); // toggle pin 5
        delay_timer0();           // calling delay_timer0()
    }
}