#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int r = 0;
int g = 0;
int b = 0;

int timer = 0;

void setup() {             
  
  
    dmx_master.enable ();
}

void loop() 
{ 
    dmx_master.setChannelValue ( 0, 0);    // on
    dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brightest)
    dmx_master.setChannelValue ( 2, r);  // red
    dmx_master.setChannelValue ( 3, g);    // green
    dmx_master.setChannelValue ( 4, b);    // blue
    dmx_master.setChannelValue ( 5, 0);    // white
    dmx_master.setChannelValue ( 6, 0);   // strobe

    if(timer % 100 == 0) // every ten frames do this code
    {
        r = random(0,255);
        g = random(0,255);
        b = random(0,255);
      
    }

    delay ( 100 );

    dmx_master.disable();
    Serial.println(9600);
    dmx_master.enable();
    timer++;
}
