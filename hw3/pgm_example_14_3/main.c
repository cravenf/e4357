/*
 * Program Example 14.3:
 *  Program control registers to flash different color LEDs. LEDs connect to mbed pins 25 and 26. Switch input to pin 9.
 */
//#define MBED
#ifdef MBED
#include "mbed.h"
DigitalOut redled(p5);   //define and name a digital output on pin 5
DigitalOut greenled(p6);  //define and name a digital output on pin 6
#endif
void delay(float);

// Define digital I/O registers
#define FIO0DIR0 (*( volatile unsigned char *)(0x2009C000))
#define FIO0PIN0 (*( volatile unsigned char *)(0x2009C014))
#define FIO2DIR0 (*(volatile unsigned char *)(0x2009C040))
#define FIO2PIN0 (*(volatile unsigned char *)(0x2009C054))

int main() {
    char a, b, i;
    // set all bits of port 0 byte 0 to input
    FIO0DIR0=0x00;
    // set port 2 byte 0 to output
    FIO2DIR0=0xFF;
    while(1) {
        // Reverse the order of LED flashing based on switch position
        if (FIO0PIN0&0x01==1){  // bit test port 0 pin 0 (mbed pin 9)
            a=0x01;
            b=0x02;
#ifdef MBED
            redled = 1;
            greenled = 0;
#endif
        } else {
            a=0x02;
            b=0x01;
#ifdef MBED
            redled = 0;
            greenled = 1;
#endif
        }
        FIO2PIN0 |= a;
        delay(0.25);
        FIO2PIN0 &= ~a;
        delay(0.25);
        for (i=0;i<3;i++){
            FIO2PIN0 |= b;
            delay(0.25);
            FIO2PIN0 &= ~b;
            delay(0.25);
        }
    } // end while
}

void delay(float seconds) {
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
