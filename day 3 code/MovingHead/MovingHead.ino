#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int r = 64;
void setup() {  
    dmx_master.enable ();

}

void loop() 
{ 
    // 9 channel mode
    dmx_master.setChannelValue ( 0, 0);   // 
    dmx_master.setChannelValue ( 1, 0);   // pan 
    dmx_master.setChannelValue ( 2, 0);   // tilt
    dmx_master.setChannelValue ( 3, 40);   // color select (0-139)
    dmx_master.setChannelValue ( 4, 0);   // pattern (0-63 select pattern), (shake patterns)
    dmx_master.setChannelValue ( 5, 0);   // strobe (0 no strobe, 255- fast strobe)
    dmx_master.setChannelValue ( 6, 255); // dimmer (0-dark 255-brightest)
    dmx_master.setChannelValue ( 7, r);   // not sure
    r+=1;
    if(r>255)r=0;
    
    delay ( 100 );
}
