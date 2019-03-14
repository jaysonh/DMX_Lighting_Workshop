#include <Conceptinetics.h>
#include <SoftwareSerial.h>

DMX_Master dmx_master ( 100 , 2 );
SoftwareSerial mySerial(10, 11); 
int r = 255;
int g = 255;
int b = 255;

void setup() {  
    dmx_master.enable ();
 mySerial.begin(4800);
}

void loop() 
{ 
    // Light 1
    dmx_master.setChannelValue ( 0, 0);    // on
    dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brightest)
    dmx_master.setChannelValue ( 2, r);  // red
    dmx_master.setChannelValue ( 3, g);    // green
    dmx_master.setChannelValue ( 4, b);    // blue
    dmx_master.setChannelValue ( 5, 0);    // white
    dmx_master.setChannelValue ( 6, 0);   // strobe

    mySerial.write("ehllo");
    /*char c = mySerial.read();
      
    if(c != -1)
    //if (mySerial.available()) 
    {
      r = (int)random(0,255);
      g = (int)random(0,255);
      b = (int)random(0,255); 
    }*/

    delay ( 100 );
}
