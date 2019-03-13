#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int r = 0;
int g = 0;
int b = 0;

long timer = 0;

void setup() {             
  
  
    dmx_master.enable ();
}

void loop() 
{ 
    

    if(timer % 10 == 0) // every ten frames do this code
    {
        r = (int)random(0,255);
        g = (int)random(0,255);
        b = (int)random(0,255);
        dmx_master.setChannelValue ( 0, 0);    // on
        dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brightest)
        dmx_master.setChannelValue ( 2, r);  // red
        dmx_master.setChannelValue ( 3, g);    // green
        dmx_master.setChannelValue ( 4, b);    // blue
        dmx_master.setChannelValue ( 5, 0);    // white
        dmx_master.setChannelValue ( 6, 0);   // strobe
      
    }else
    {
        dmx_master.setChannelValue ( 0, 0);    // on
        dmx_master.setChannelValue ( 1, 0);  // dimmer (0 - dark 255- brightest)
        dmx_master.setChannelValue ( 2, 0);  // red
        dmx_master.setChannelValue ( 3, 0);    // green
        dmx_master.setChannelValue ( 4, 0);    // blue
        dmx_master.setChannelValue ( 5, 0);    // white
        dmx_master.setChannelValue ( 6, 0);   // strobe
    }

    delay ( 50 );
    timer++;
}
