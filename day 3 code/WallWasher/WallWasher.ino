#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int r = 64;
void setup() {  
    dmx_master.enable ();
    for(int i =0 ; i < 100;i++)
    {
      dmx_master.setChannelValue ( i, 0); 
    }
}

void loop() 
{ 
    // 9 channel mode
    dmx_master.setChannelValue ( 0,  0);   // 
    dmx_master.setChannelValue ( 1,  0);   // red
    dmx_master.setChannelValue ( 2,  255);   // green
    dmx_master.setChannelValue ( 3,255);   // blue
    
    dmx_master.setChannelValue ( 7, 255);   // dimmer
    
    
    delay ( 100 );
}
