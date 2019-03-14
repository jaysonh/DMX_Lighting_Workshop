#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int rotate = 0;
void setup() {  
    dmx_master.enable ();

    for(int i = 0; i < 100;i++)
    {

      dmx_master.setChannelValue ( i, 0);    // ignore
    
    }
}

void loop() 
{ 
    // Light 1
    dmx_master.setChannelValue ( 0, 40);    // ignore
    dmx_master.setChannelValue ( 1, 255);  // on/off greater than 11 is on
    dmx_master.setChannelValue ( 2, 32);  // mode (32-95) select pattern without sound
    dmx_master.setChannelValue ( 3, 30);    // choice pattern folder
    dmx_master.setChannelValue ( 4, 40);    // choice pattern 0-15 (off) 16> on ( every 12 new pattern)
    dmx_master.setChannelValue ( 5, rotate);     // rotate (0-127)
    dmx_master.setChannelValue ( 9, 0);     // move left/right (0-127)
    dmx_master.setChannelValue ( 10, 0);     // move up/down (0-127)
    dmx_master.setChannelValue ( 16, 10);   // colour pattern (8-15 white, 16-23 red, 24-31 yellow, 32-39 green, 40-47 light blue, 48-55blue, 56-64 purple)
    
    rotate+=1;
    if(rotate>127)
    {
      rotate =0;
    }
  

    delay ( 100 );
}
