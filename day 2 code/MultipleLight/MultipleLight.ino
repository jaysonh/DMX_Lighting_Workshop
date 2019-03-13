#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int red = 255;

void setup() {  
    dmx_master.enable ();
}

void loop() 
{ 
    // Light 1
    dmx_master.setChannelValue ( 0, 0);    // on
    dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brightest)
    dmx_master.setChannelValue ( 2, 255);  // red
    dmx_master.setChannelValue ( 3, 0);    // green
    dmx_master.setChannelValue ( 4, 0);    // blue
    dmx_master.setChannelValue ( 5, 0);    // white
    dmx_master.setChannelValue ( 6, 0);   // strobe

    // Light 2
    dmx_master.setChannelValue ( 8, 0);    // on
    dmx_master.setChannelValue ( 9, 255);  // dimmer (0 - dark 255- brightest)
    dmx_master.setChannelValue ( 10, 0);  // red
    dmx_master.setChannelValue ( 11, 255);    // green
    dmx_master.setChannelValue ( 12, 0);    // blue
    dmx_master.setChannelValue ( 13, 0);    // white
    dmx_master.setChannelValue ( 14, 0);   // strobe

    delay ( 100 );
}
