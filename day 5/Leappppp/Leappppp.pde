// Import the leap motion library
import de.voidplus.leapmotion.*;
import processing.serial.*;  

Serial arduinoBoard;


// Create the leap motion object
LeapMotion leap;

void setup()
{
      size(800, 500);
      
      
      // Set up the leap motion
      leap = new LeapMotion(this);
      println(Serial.list());
      String []devices = Serial.list();
      
      for(int i = 0; i < devices.length;i++)
      {
          println(i + ": " + devices[i]);
      }
      int portNum = 1;
      arduinoBoard = new Serial(this, Serial.list()[portNum], 4800);
      
}

void draw()
{
  background(0);
  // if there are hands detected then turn the led strip on
      if( leap.getHands().size() > 0 )
      {
          Hand firstHand = leap.getHands().get(0);
          PVector handPosition       = firstHand.getPosition();
          
          float handX = handPosition.x; // left - right
          float handY = handPosition.y; // up - down 70 -450
          float handZ = handPosition.z; // front - back
          int lightVal = (int)map(handY, 70,450,0,255);
          if(lightVal > 255)
          {
              lightVal = 255;
          }
          if(lightVal < 0)
          {
              lightVal = 0;
          }
          
          arduinoBoard.write(lightVal);
      
    }else
    {
      arduinoBoard.write(0);
    }
      
}