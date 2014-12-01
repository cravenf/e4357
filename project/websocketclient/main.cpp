#include "mbed.h"
#include "EthernetInterface.h"
#include "Websocket.h"
#include "time.h"

//Serial pc(USBTX,USBRX);
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
    int n, ret = eth.connect();

    printf("\n\r");
    if (0 == ret) {
        printf("IP address is %s\n\r", eth.getIPAddress());
    } else {
        error("eth.connect() returned %d\n\r", ret);
    }

    // open http://sockets.mbed.org/sensor/viewer to view
    Websocket ws("ws://sockets.mbed.org:443/ws/sensor/rw");
    ws.connect();
    char str[100];

    UDPSocket sock;
    ret = sock.init();
//    printf("sock.init() returned %d\n\r", ret);  
    Endpoint nist;
    nist.set_address("utcnist.colorado.edu", 37);  
    char outbuf[4];
    time_t timeRes;
    char localtime[40] = {0}, *p = localtime;
    
    for(;;) {

        ret = sock.sendTo(nist, "\0", 1);
//        printf("sock.sendTo() returned %d\n\r", ret);

        n = sock.receiveFrom(nist, outbuf, sizeof(outbuf));
//        printf("sock.receiveFrom() returned %d\n\r", n);
    
        timeRes = ntohl(*((unsigned int*)outbuf));
//        printf("Received %d bytes from server %s on port %d: %u seconds since 1/01/1900 00:00 GMT\n\r", n, nist.get_address(), nist.get_port(), timeRes);
        // adjust for epoch set as 1/01/1970 00:00 GMT
        timeRes -= 2208988800L;
        p = ctime(&timeRes);

        myled2 = switch_ip2;
        myled3 = switch_ip2;

        // reflect sensor input
        if (switch_ip2)
            sprintf(str, "MOTION %s", p);
        else
            sprintf(str, "no motion %s", p);
        ws.send(str);
    
        // clear the buffer and wait briefly
        memset(str, 0, sizeof(str));
        wait(5);
    
        // websocket server should echo whatever we sent it
        if (ws.read(str)) {
            printf("%s\n\r", str);
        }
    }

    sock.close();
    ws.close();
    eth.disconnect();
}
