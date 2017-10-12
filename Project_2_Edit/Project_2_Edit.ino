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
    int secondInput = port.read();
    Serial.println("  " + input);

    if (input == 'c')
    {
      char thirdInput = port.read();
      if(rightButton == 0)
      {
        if(thirdInput = 'r')
        {
          CircuitPlayground.setPixelColor(secondInput,200,0,0);
        }
        if(thirdInput = 'g')
        {
          CircuitPlayground.setPixelColor(secondInput,0,200,0);
        }
        if(thirdInput = 'b')
        {
          CircuitPlayground.setPixelColor(secondInput,200,0,0);
        }
        //delay(500); 
        
        //CircuitPlayground.clearPixels();
        rightButton++;
      }
      else
      {
        rightButton = 0;
        CircuitPlayground.clearPixels();
      }
    }
    else if(input == 'm')
    {
      if(leftButton == 0)
      {
        int thirdInput = port.read();
        CircuitPlayground.playTone(secondInput,thirdInput);
        //leftButton++;
      }
    }
  }
  else
  {
    bool right2 = CircuitPlayground.rightButton();
    bool left2 = CircuitPlayground.leftButton();
    
    if (right && !right2)
    {
      //light or sound
      port.write('c');
      Serial.println('c');
      //which light
      port.write(1);
      Serial.println(1);
      //which color
      port.write('r');
      Serial.println('r');
    }
    if (left && !left2)
    {
      //light or sound
      port.write('m');
      Serial.println('m');
      //frequency
      port.write(600);
      Serial.println(600);
      //duration
      port.write(1000);
      Serial.println(1000);
    }
  }

}
