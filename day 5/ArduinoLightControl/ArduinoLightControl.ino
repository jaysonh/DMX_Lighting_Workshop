#include <SoftwareSerial.h>
#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );
SoftwareSerial mySerial(10, 11); 

int r = 255;
int g = 255;
int b = 255;

void setup() 
{  
    dmx_master.enable ();

    mySerial.begin(4800);
}

void loop() 
{ 
    while(mySerial.available())
    {
        int soundLevel = (int)mySerial.read();
        dmx_master.setChannelValue ( 0, 0);    // on
        dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brightest)
        dmx_master.setChannelValue ( 2, soundLevel);  // red
        dmx_master.setChannelValue ( 3, soundLevel);  // green
        dmx_master.setChannelValue ( 4, soundLevel);  // blue
    }
}
