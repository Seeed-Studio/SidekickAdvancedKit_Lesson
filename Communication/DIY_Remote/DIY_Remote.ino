/*
  Sidekick Advanced Kit Lesson - diy remote

  diy remote

  loovee
  2013-1-15
  
  first, please refer to here:
  http://www.seeedstudio.com/wiki/index.php?title=IR_Remote&uselang=en


  Infrared Emitter connect to D3

*/


#include <IRSendRev.h>

const int Button = 7;
const int irFreq = 38;                      

unsigned char dtaSend[] = {9, 90, 91, 11, 31, 4, 1, 2, 3, 4};

void setup()
{
    pinMode(Button, INPUT);
}

void loop()
{
    if(digitalRead(Button))                 // button press
    {
        delay(10);
        if(digitalRead(Button))
        {
            IR.Send(dtaSend, irFreq);           // send data
            delay(20);
            while(digitalRead(Button));         // while button release
        }
    }
}