/*
  Sidekick Advanced Kit Lesson - Clock Buzzer

  A Simple Clock

  loovee
  2013-1-8

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en

  
                12 11 10 9  8  7
                |  |  |  |  |  |
      +-----------------------------------+
      |  +----+  +----+   +----+  +----+  |
      |  |    |  |    | * |    |  |    |  |
      |  +----+  +----+   +----+  +----+  |
      |  |    |  |    | * |    |  |    |  |
      |  +----+. +----+.  +----+. +----+. |
      +-----------------------------------+ 
               |  |  |  |  |  |
               1  2  3  4  5  6
    
    
              A
        +------------+
        |            |
        |            |
      F |            | B
        |     G      |
        +------------+
        |            |
      E |            | C
        |            | 
        |            |  dp
        +------------+  *
              D
    
    1: E        -> D2
    2: D        -> D3
    3: DP       -> D4
    4: C        -> D5
    5: G        -> D6
    6: COM4     -> D7
    7: B        -> D8
    8: COM3     -> D9
    9: COM2     -> D10
    10: F       -> D11
    11: A       -> D12
    12: COM1    -> D13

*/



#include <Streaming.h>

#include "FourDigitDisplay.h"

const int pinBuzzer = A3;                   // buzzer connect to D3

const int pinA      = 12;
const int pinB      = 8;
const int pinC      = 5;
const int pinD      = 3;
const int pinE      = 2;
const int pinF      = 11;
const int pinG      = 6;
const int pinDP     = 4;
const int pinCOM1   = 13;
const int pinCOM2   = 10;
const int pinCOM3   = 9;
const int pinCOM4   = 7;

const int pinAll[12] = {pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP, pinCOM1, pinCOM2, pinCOM3, pinCOM4};


int hour = 14;
int min = 20;


void setup()
{
    Serial.begin(115200);
    
    cout << "hello world" << endl;
    
    display.begin(pinAll);

}

int hour = 14;
int min = 20;
void loop()
{

    display.time(hour, min++);
    display.pointOn();
    delay(500);
    display.pointOff();
    delay(500);
}