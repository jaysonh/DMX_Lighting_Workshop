import processing.serial.*;  

Serial arduinoBoard;

 void setup()
{
  size(500,500);
  
  println(Serial.list());
  String []devices = Serial.list();
  
  for(int i = 0; i < devices.length;i++)
  {
      println(i + ": " + devices[i]);
  }
  int portNum = 2;
  arduinoBoard = new Serial(this, Serial.list()[portNum], 4800);
  
  
  frameRate(30);
  
}
void draw()
{
   background(0); 
   if(keyPressed)
  {
      arduinoBoard.write(255);
  }else
  {
      arduinoBoard.write(0);
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