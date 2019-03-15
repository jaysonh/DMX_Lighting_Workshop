import processing.serial.*;  
import ddf.minim.*;

Minim minim;
AudioInput audioInput; 

Serial arduinoBoard;

 void setup()
{
  size(500,500);
  minim = new Minim(this);
  audioInput = minim.getLineIn();
  println(Serial.list());
  String []devices = Serial.list();
  
  for(int i = 0; i < devices.length;i++)
  {
      println(i + ": " + devices[i]);
  }
  int portNum=2;
  arduinoBoard = new Serial(this, Serial.list()[portNum], 4800);
  
  
  frameRate(30);
  
}
void draw()
{
   background(0); 
   
   int audioLoudness =(int) map(audioInput.mix.level()*10.0, 0,1,0,255);
   if(audioLoudness > 255)
   {
     audioLoudness =255;
   }
   
   if(arduinoBoard!=null)
   {
     arduinoBoard.write(audioLoudness);
   }
   
}
void exit()
{
  println("exit:");
 
  if(arduinoBoard != null)
  {
    arduinoBoard.clear();
    arduinoBoard.stop();
  }
}
void keyPressed()
{ 
  if(arduinoBoard !=null)
  {
    arduinoBoard.write(2);
  }else
  {
     println("not connected to board"); 
  }
}