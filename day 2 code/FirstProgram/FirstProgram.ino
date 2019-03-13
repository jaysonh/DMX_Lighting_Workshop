#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

void setup() {             
  
  
    dmx_master.enable ();
}

void loop() 
{ 
    dmx_master.setChannelValue ( 0, 0);    // on
    dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brighest)
    dmx_master.setChannelValue ( 2, 255);  // red
    dmx_master.setChannelValue ( 3, 255);    // green
    dmx_master.setChannelValue ( 4, 0);    // blue
    dmx_master.setChannelValue ( 5, 0);    // white
    dmx_master.setChannelValue ( 6, 0);   // strobe

    delay ( 100 );
}
