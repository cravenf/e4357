embedded_firmware_essentials
============================
classwork repository

This file contains a study record. Entries are in reverse chronological order.

5 Nov (2.5hrs) - connected motion sensor to breadboard and wired power, ground, and data out, but nothing worked.  Discovered later after working with lab partner that I had oriented the component wrong on the breadboard, putting all pins in the same row on the breadboard rather than in different rows.  Working with partner, we completed homework 5.  I programmed my mbed with example 12.7 code (Ethernet sender), and she programmed hers with example 12.8 (Ethernet receiver).  We both set up serial consoles by installing Tera Term on our laptops, as described in Appendix E of Fast and Effective Embedded Systems Design.  We then modified both programs to both send and receive data and integrated the motion sensor, this time oriented correctly on the breadboard.  We connected the sensor's output pin with one of the input pins from the homework 4 exercise (p5, p6).  When the mbeds were powered on and movement detected, the sensor glowed red and stayed lit for about 5 seconds after motion stopped.  Lab partner modified her program to output a different message when motion was detected.  There was a lag of a few seconds between the motion and the change in message appearing on serial console.  We achieved success in phase 1 of our term project, which is to read and handle sensor input.  Future phases include integrating a liquid crystal display and pushing sensor state to a browser through a WebSocket interface.

3 Nov (1hr) - read about Parallax PIR motion sensor online.

1 Nov (3hrs) - met with partner at MV library to complete homework 4 and discuss term project. Bought a liquid crystal display and a motion sensor.  Partner will try out LCD and I will try out motion sensor.  Aim is to integrate these components with mbeds and initially perhaps display sensor readings on the LCD, in a later phase, push sensor readings to a cloud server, which could display the readings in a web browser.

31 Oct (3hrs) - wired up breadboard as required for homework 4 (program example 7.9); entered program 7.9 in mbed environment (https://developer.mbed.org/compiler/#nav:/pgm_example_7_9/main.cpp), compiled and downloaded it to target board; reread Chapter 7 in Fast and Effective Embedded Systems Design.

30 Oct (1hr) - read Chapter 7 in preparation for homework 4; will meet with lab partner on Saturday to complete homework and discuss term project



