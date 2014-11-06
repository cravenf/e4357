/*
 * Program Example 12.7: Ethernet write
 */
#include "mbed.h"
#include "Ethernet.h"
Ethernet eth;                   // The Ethernet object
char data[] = "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFG";        // Define the data values

// Ethernet object
Serial pc(USBTX, USBRX);    // tx, rx for host terminal coms
char buf[0xFF];             // create a large buffer to store data

int main() {                 
    while (1) {               
        eth.write(data,sizeof(data));   // Write the package
        eth.send();             // Send the package
        wait(0.2);              // wait 200 ms

        int size = eth.receive();                   // get size of incoming data packet
        if (size > 0) {                             // if packet received
            eth.read(buf, size);                    // read packet to data buffer
            pc.printf("size = %d data = ",size);    // print to screen
            for (int i=0;i<size;i++) {              // loop for each data byte
                pc.printf("%c",buf[i]);            // print data to screen
            }
            pc.printf("\n\r");
        }
    }
}
