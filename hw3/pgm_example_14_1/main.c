/*
 * Program Example 14.1: Sets up a digital output pin using control registers, and flashes an led.
 */
#define MBED
#ifdef MBED
#include "mbed.h"
DigitalOut myled1(LED1), myled2(LED2), myled3(LED3), myled4(LED4);
#endif
// Define addresses of digital i/o control registers as pointers to volatile data
#define FIO2DIR0    (*(volatile unsigned char *)(0x2009C040))
#define FIO2PIN0    (*(volatile unsigned char *)(0x2009C054))

void delay(float seconds);

int main()
{
   FIO2DIR0=0xFF;  // set port 2, lowest byte to output
    while(1) {
        FIO2PIN0 |= 0x01;  // OR bit 0 with 1 to set pin high
#ifdef MBED
        myled2 = 1;
#endif
        delay(0.25);
        FIO2PIN0 &= ~0x01; // AND bit 0 with 0 to set pin low
#ifdef MBED
        myled2 = 0;
#endif
        delay(0.25);
    }
}

void delay(float seconds)
{
#ifdef MBED
    wait(seconds);
#else
    int j;           //loop variable j
    for (j=0; j<10000000; j++) {
        j++;
        j--;           //waste time
    }
#endif
}
