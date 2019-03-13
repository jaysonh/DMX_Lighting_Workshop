#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );
int white = 0;

int whiteSpeed = 5;
void setup() {             
  
  
    dmx_master.enable ();
}

void loop() 
{ 
    dmx_master.setChannelValue ( 0, 0);    // on
    dmx_master.setChannelValue ( 1, 255);  // dimmer (0 - dark 255- brighest)
    dmx_master.setChannelValue ( 2, 255);  // red
    dmx_master.setChannelValue ( 3, 0);    // green
    dmx_master.setChannelValue ( 4, 0);    // blue
    dmx_master.setChannelValue ( 5, white);    // white
    dmx_master.setChannelValue ( 6, 0);   // strobe


   white += whiteSpeed;
   if(white>254)
   {
      whiteSpeed = -5;
      white = 254;
   }
   if(white < 5)
   {
      whiteSpeed = 5;
      white = 0;
   }
    delay ( 100 );
}
