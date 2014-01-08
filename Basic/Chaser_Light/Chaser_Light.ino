/*
  Sidekick Advanced Kit Lesson - Chaser_Light
  
  Chaser_Light
  
  loovee
  2013-1-8
  
  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en


  Led1 connect to D2
  Led2 connect to D3
  Led3 connect to D4
  Led4 connect to D5
*/


const int pinLed1    = 2;                       // pin of led1
const int pinLed2    = 3;                       // pin of led2
const int pinLed3    = 4;                       // pin of led3
const int pinLed4    = 5;                       // pin of led4



void setup()
{
    pinMode(pinLed1, OUTPUT);
    pinMode(pinLed2, OUTPUT);
    pinMode(pinLed3, OUTPUT);
    pinMode(pinLed4, OUTPUT);
}


void loop()
{

    digitalWrite(pinLed4, LOW);                 // led4 off
    digitalWrite(pinLed1, HIGH);                // led1 on
    
    delay(100);
    
    digitalWrite(pinLed1, LOW);                 // led1 off
    digitalWrite(pinLed2, HIGH);                // led2 on
    
    delay(100);
    
    digitalWrite(pinLed2, LOW);                 // led2 off
    digitalWrite(pinLed3, HIGH);                // led3 on
    
    delay(100);
    
    digitalWrite(pinLed3, LOW);                 // led3 off
    digitalWrite(pinLed4, HIGH);                // led4 on
    
    delay(100);
    
}