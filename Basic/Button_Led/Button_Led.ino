/*
  Sidekick Advanced Kit Lesson - Button and Led
  
  When the Button pressed, an led will on
  
  loovee
  2013-1-8
  
  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en


  Button connect to D2
  Led connect to D13
*/

const int pinButton = 2;                        // pin of button
const int pinLed    = 13;                       // pin of led


void setup()
{
    pinMode(pinButton, INPUT);
    digitalWrite(pinButton, HIGH);              // pull up
    pinMode(pinLed, OUTPUT);
    digitalWrite(pinLed, LOW);                  // led off
}


void loop()
{
    if(LOW == digitalRead(pinButton))           // if button pressed
    {
        digitalWrite(pinLed, HIGH);             // led on
    }
    else
    {
        digitalWrite(pinLed, LOW);              // otherwise led off
    }
}