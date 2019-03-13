#include <Conceptinetics.h>

DMX_Master dmx_master ( 100 , 2 );

int pan = 0;
int panTarget = 100;

int tilt = 0;
int tiltTarget=100;

int col = 40;

void setup() {  
    dmx_master.enable ();

}

void loop() 
{ 
    // 9 channel mode
    dmx_master.setChannelValue ( 0, 0);   // 
    dmx_master.setChannelValue ( 1, pan);   // pan  (0-170)
    dmx_master.setChannelValue ( 2, tilt);   // tilt (0-255)
    dmx_master.setChannelValue ( 3, col);   // color select (0-139)
    dmx_master.setChannelValue ( 4, 0);   // pattern (0-63 select pattern), (shake patterns)
    dmx_master.setChannelValue ( 5, 0);   // strobe (0 no strobe, 255- fast strobe)
    dmx_master.setChannelValue ( 6, 255); // dimmer (0-dark 255-brightest)
    dmx_master.setChannelValue ( 7, 0);   // not sure
    
    // Pan
    int panDirection = panTarget - pan;
    if(panDirection == 0)
    {
      panTarget = random(0,170);
      col = random(0,63);
    }else if(panDirection < 0)
    {
      pan--;
    }else if(panDirection > 0)
    {
      pan++;
    }

    // tilt
    int tiltDirection = tiltTarget - tilt;
    if(tiltDirection == 0)
    {
      tiltTarget = random(0,255);
      col = random(0,63);
    }else if(tiltDirection < 0)
    {
      tilt--;
    }else if(tiltDirection > 0)
    {
      tilt++;
    }
    
    delay ( 50 );
}
