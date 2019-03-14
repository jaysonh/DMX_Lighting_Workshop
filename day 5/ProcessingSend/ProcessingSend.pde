 import processing.serial.*;
    
    Serial myPort;

 void setup()
{
  size(500,500);
  println(Serial.list());
    myPort = new Serial(this, Serial.list()[2], 4800);
}
void draw()
{
   background(0); 
}

void keyPressed()
{  
  myPort.write(2);
}