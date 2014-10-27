Program assignment 3 instructions:
Read Chapters 1-3 and 14
Program Example 14.1 Manipulating control registers to flash an LED
Program Example 14.3 Combined digital input and output
Compile and download Program Examples 14.1 and 14.3 to your mbed board.

First versions of the example programs were done with the mbed library because I did not yet have red and green leds to connect to the breadboard, so the on-board LEDs served to show activity.

Updated versions, with mbed library disabled, were run with colored LEDs inserted in breadboard and wires connecting GND to cathode ends of LEDs.  For program 14.3, a wire connecting GND and pin 9 was used as a switch, so that when connected, flashing LED pattern was green-red-red-red, and when lifted, pattern was red-green-green-green.
