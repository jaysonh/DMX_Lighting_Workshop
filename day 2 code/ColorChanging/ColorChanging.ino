#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int r = 255;
void setup() {  
    dmx_master.enable ();

    Serial.begin(9600);
}

void loop() 
{ 
    // Light 1
    dmx_master.setChannelValue ( 0, 0);    // on
    dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brightest)
    dmx_master.setChannelValue ( 2, r);  // red
    dmx_master.setChannelValue ( 3, 0);    // green
    dmx_master.setChannelValue ( 4, 0);    // blue
    dmx_master.setChannelValue ( 5, 0);    // white
    dmx_master.setChannelValue ( 6, 0);   // strobe

    r += 25;
    if(r > 255)
    {
        r = 0;
    }

    
    delay ( 100 );
}
