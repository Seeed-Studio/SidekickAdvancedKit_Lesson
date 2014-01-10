/*
  Sidekick Advanced Kit Lesson - Heart

  heart will beat with pressed button, stop will pressed button again

  loovee
  2013-1-10

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en
  
  About the pin connect, refer to http://arduino.cc/en/Tutorial/RowColumnScanning
  
  button connect to A0
  
*/

#include <LED_Matrix.h>
#include <LED_Matrix_dfs.h>
#include <TimerOne.h>


const int pinBtn = A0;

// matrix of big heart
unsigned char big_heart[8] = {

0b00000000,
0b01100110,
0b11111111,
0b11111111,
0b11111111,
0b01111110,
0b00111100,
0b00011000,
};

// matrix of small heart
unsigned char small_heart[8] = {

0b00000000,
0b00000000,
0b00100100,
0b01111110,
0b01111110,
0b00111100,
0b00011000,
0b00000000,
};

void setup()
{

    matrix.begin();
    
    pinMode(pinBtn, INPUT);
    digitalWrite(pinBtn, HIGH);
    
}

int state = 0;

// delay x ms untill when press button  
void checkBtnAndDelay(int ms)
{
    for(int i=0; i<ms; i++)
    {
        delay(1);
        if(!digitalRead(pinBtn))
        {
            delay(10);
            if(!digitalRead(pinBtn))
            {
                state = 1-state;
            }
            
            while(!digitalRead(pinBtn));
            return;
        }
    }
}

void loop()
{
    
    if(0 == state)                          // no beat
    {
        matrix.dispMatrix(big_heart);
        checkBtnAndDelay(1);
    }
    else                                    // beat
    {
        matrix.dispMatrix(big_heart);
        checkBtnAndDelay(200);
        
        matrix.dispMatrix(small_heart);
        checkBtnAndDelay(800);
    }

}