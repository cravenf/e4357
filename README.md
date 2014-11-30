embedded_firmware_essentials
============================
classwork repository

This file contains a study record. Entries are in reverse chronological order.

30 Nov (several hours) - added content to project presentation slides.

29 Nov (3hrs) - debugged timestamp display with lab partner; discussed and outlined content of class presentation; discussed homework 7.

25 Nov, evening (2hrs) - met with lab partner (Sohani) to integrate project work.  Our set-up in library conference room resulted in lots of false positive readings from sensor because of small size of room and proximity of components.  While Sohani devised an algorithm to average out readings, I looked into getting time of day from the mbed development environment, so human-readable time could be displayed with each sensor reading on websocket server.  We also discussed how we would present project work at the last class.

25 Nov (several hours) - stripped ends of RD and TD wires at one end of Ethernet cable and plugged these directly into breadboard next to mbed RD and TD pins:  http://www.efele.net/cravenf/ucsc/e4357/project/websocket_sensor_setup.jpg.  Though not very stable, this configuration worked and enabled communication through the socket.  Exercised several embed developer programs, including TCP and UDP HelloWorld programs and programs from Effective Embedded Systems Design.  Found and modified http://developer.mbed.org/teams/mbed/code/Websocket_Ethernet_HelloWorld.  Viewed its output at http://sockets.mbed.org/demo/viewer and continued to modify the program by integrating a motion sensor and incorporating earlier code used with that.  Succeeded in reflecting motion detection to the web server and reflected back to mbed and displayed on Tera Term console:

Websocket server
Rapid deployment and real-time communication by Mbed
mbed.org
SenderChannel HomeWS Home
Websockets Viewer on channel: sensor 

message: 21 no motion
message: 20 no motion
message: 19 MOTION
message: 18 MOTION
message: 17 MOTION
message: 16 MOTION
message: 15 MOTION
message: 14 MOTION
message: 13 MOTION
message: 12 MOTION
message: 11 MOTION
message: 10 MOTION
message: 9 MOTION
message: 8 MOTION
message: 7 MOTION
message: 6 MOTION
message: 5 no motion
message: 4 no motion
message: 3 no motion
message: 2 no motion
message: 1 no motion
message: 0 no motion
© ARM Online Tools Group        website templates by styleshout | Valid XHTML | CSS

The web server reflected output back to the mbed microcontroller through the socket and the mbed displayed the received data on the Tera Term console:
rcv'd: 253 no motion
rcv'd: 254 no motion
rcv'd: 255 no motion
rcv'd: 256 MOTION
rcv'd: 257 MOTION
rcv'd: 258 MOTION
rcv'd: 259 MOTION
rcv'd: 260 MOTION
rcv'd: 261 MOTION
rcv'd: 262 MOTION
rcv'd: 263 MOTION
rcv'd: 264 MOTION
rcv'd: 265 MOTION
rcv'd: 266 MOTION
rcv'd: 267 no motion
rcv'd: 268 no motion
rcv'd: 269 no motion
rcv'd: 270 no motion
Data samples are about a second apart.

24 Nov (several hours) - set up RJ45 connector with breakout board using my own mbed to replicate previous day's results.  Tried different configurations, finally connected other end of Ethernet cable directly to home router.  Was able to get DHCP-assigned IP address, but not successful in exchanging data through Ethernet socket.  RJ45 connections are too loose.

23 Nov (2 hrs) - worked with Sohani at MV library on integrating Ethernet interface for project.  Connected mbed and RJ45 breakout board according to Figure 12-10 in Fast and Effective Embedded Systems Design, then connected RJ45 connector to laptop's Ethernet port via cable.  Imported EthernetInterface library by following instructions on mbed developer web site, under Cookbook (http://developer.mbed.org/cookbook/Homepage), TCP/IP Networking, Getting started with networking and mbed.  Assigned an IPv4 address to the mbed using the EthernetInterface class's init method but did not succeed in bringing up the interface via the connect method.  Tried debugging by inserting printfs in the EthernetInterface code and displaying output on Teraterm console.

20 or 21 Nov - received RJ45 8-pin connector and break-out board.

18 Nov (0.5hr) - ordered RJ45 8-pin connector and break-out board from SparkFun for term project.

16 Nov (4hrs) - coded and tested hw6's CircularBuffer interface, adding init and deinit interfaces and a test driver; tested at several starting points in the buffer to verify wrap-around and buffer full/empty conditions.

15 Nov (<1hr) - discussed project with lab partner, Sohani.  LCD we purchased is not compatible with our breadboards so we will not be able to use it.  We will move ahead instead with WebSockets.  Sohani will order a part that would enable us to connect wires from an Ethernet connector to an MBED and push sensor data from our board to a server.

5 Nov (2.5hrs) - connected motion sensor to breadboard and wired power, ground, and data out, but nothing worked.  Discovered later after working with lab partner that I had oriented the component wrong on the breadboard, putting all pins in the same row on the breadboard rather than in different rows.  Working with partner, we completed homework 5.  I programmed my mbed with example 12.7 code (Ethernet sender), and she programmed hers with example 12.8 (Ethernet receiver).  We both set up serial consoles by installing Tera Term on our laptops, as described in Appendix E of Fast and Effective Embedded Systems Design.  We then modified both programs to both send and receive data and integrated the motion sensor, this time oriented correctly on the breadboard.  We connected the sensor's output pin with one of the input pins from the homework 4 exercise (p5, p6).  When the mbeds were powered on and movement detected, the sensor glowed red and stayed lit for about 5 seconds after motion stopped.  Lab partner modified her program to output a different message when motion was detected.  There was a lag of a few seconds between the motion and the change in message appearing on serial console.  We achieved success in phase 1 of our term project, which is to read and handle sensor input.  Future phases include integrating a liquid crystal display and pushing sensor state to a browser through a WebSocket interface.  View images of our homework 5 set-up at efele.net/cravenf/ucsc/e4357/hw5/hw5_setup.jpg and at
efele.net/cravenf/ucsc/e4357/hw5/hw5_with_sensor.jpg.

3 Nov (1hr) - read about Parallax PIR motion sensor online.

1 Nov (3hrs) - met with partner at MV library to complete homework 4 and discuss term project. Bought a liquid crystal display and a motion sensor.  Partner will try out LCD and I will try out motion sensor.  Aim is to integrate these components with mbeds and initially perhaps display sensor readings on the LCD, in a later phase, push sensor readings to a cloud server, which could display the readings in a web browser.  View images of our homework 4 set-up at efele.net/cravenf/ucsc/e4357/hw4/hw4_setup_p5_p6_different.jpg and at efele.net/cravenf/ucsc/e4357/hw4/hw4_setup_p5_p6_identical.jpg.

31 Oct (3hrs) - wired up breadboard as required for homework 4 (program example 7.9); entered program 7.9 in mbed environment (https://developer.mbed.org/compiler/#nav:/pgm_example_7_9/main.cpp), compiled and downloaded it to target board; reread Chapter 7 in Fast and Effective Embedded Systems Design.

30 Oct (1hr) - read Chapter 7 in preparation for homework 4; will meet with lab partner on Saturday to complete homework and discuss term project



