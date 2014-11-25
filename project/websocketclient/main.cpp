#include "mbed.h"
#include "EthernetInterface.h"
#include "Websocket.h"

Ticker flash;
DigitalOut led(LED1);
void flashLED(void){led = !led;}

DigitalOut myled2(LED2), myled3(LED3);
//DigitalIn switch_ip1(p5);
DigitalIn switch_ip2(p6);
 
int main() 
{
//    flash.attach(&flashLED, 1.0f);
    
    EthernetInterface eth;
    eth.init(); // let dhcp assign ip address
    int ret = eth.connect();

    if (0 == ret) {
        printf("IP address is %s\n", eth.getIPAddress());
    } else {
        error("eth.connect() returned %d\n\r", ret);
    }

    // open http://sockets.mbed.org/demo/viewer to view
//    Websocket ws("ws://sockets.mbed.org:443/ws/demo/rw");
    // open http://sockets.mbed.org/sensor/viewer to view
    Websocket ws("ws://sockets.mbed.org:443/ws/sensor/rw");
    ws.connect();
    char str[100];
    
    for(int i=0; i<0x7fffffff; ++i) {
        

        myled2 = switch_ip2;
        myled3 = switch_ip2;

        // reflect sensor input
        if (switch_ip2)
            sprintf(str, "%d MOTION", i);
        else
            sprintf(str, "%d no motion", i);
        ws.send(str);
    
        // clear the buffer and wait briefly
        memset(str, 0, sizeof(str));
        wait(0.5f);
    
        // websocket server should echo whatever we sent it
        if (ws.read(str)) {
            printf("rcv'd: %s\n\r", str);
        }
    }
    ws.close();
    eth.disconnect();
    
    while(true);
}
