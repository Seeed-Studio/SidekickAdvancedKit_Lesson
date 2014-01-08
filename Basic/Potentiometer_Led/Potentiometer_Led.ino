/*
  Sidekick Advanced Kit Lesson - Potentiometer Led
  
  Potentiometer change the brightness of led
  
  loovee
  2013-1-8
  
  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en


  Potentiometer connect to A0
  Led connect to D3
*/

const int pinPoten  = 2;                        // pin of potentiometer
const int pinLed    = 3;                        // pin of led


void setup()
{
    pinMode(pinLed, OUTPUT);
    digitalWrite(pinLed, LOW);                  // led off
}


void loop()
{
    int value = analogRead(pinPoten);           // read adc value of potentiometer
    
    value = map(value, 0, 1023, 0, 255);        // make value to [0, 255];
    
    analogWrite(pinLed, value);                 // set brightness
    
    delay(10);
}