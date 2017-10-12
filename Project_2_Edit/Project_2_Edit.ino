#include <Adafruit_CircuitPlayground.h>
#include <SoftwareSerial.h>
#include <Wire.h>

SoftwareSerial port(9, 10);
int rightButton = 0;
int leftButton = 0;

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  port.begin(9600);
  //Wire.begin();
}

void loop() 
{

  bool slideState = CircuitPlayground.slideSwitch();
  bool right = CircuitPlayground.rightButton();
  bool left =CircuitPlayground.leftButton();
  delay(20);

  
  if(slideState)
  {
    //slideStateTrue();
    port.listen();
    char input = port.read();
    Serial.println("  " + input);

    if (input == 'c')
    {
      if(rightButton == 0)
      {
        CircuitPlayground.setPixelColor(4, 100,0,0);

        //delay(500); 
        //CircuitPlayground.clearPixels();
        rightButton++;
      }
      else if(rightButton == 1)
      {

        CircuitPlayground.clearPixels();
        CircuitPlayground.setPixelColor(4, 000,100,0);
        rightButton++;

      }
      else
      {
        rightButton = 0;
        CircuitPlayground.clearPixels();
      }
    }
    else if(input = 'm')
    {
      if(leftButton == 0)
      {
        CircuitPlayground.playTone(600,1000);
        leftButton++;
      }

      else
      {
     

        leftButton = 0;
       
      }
    }
  }
  else
  {
    bool right2 = CircuitPlayground.rightButton();
    bool left2 = CircuitPlayground.leftButton();
    
    if (right && !right2)
    {
      port.write('c');
      Serial.println('c');
    }
    if (left && !left2)
    {
      port.write('m');
      Serial.println('m');
    }
  }

}
