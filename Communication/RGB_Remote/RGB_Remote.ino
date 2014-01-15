/*
  Sidekick Advanced Kit Lesson - IR Remote control RGB LED
  
  1 - R+
  2 - G+
  3 - B+
  
  4 - R-
  5 - G-
  6 - B-

  loovee
  2013-1-8

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en

  ir_receive conncet to D2

*/


#include <IRSendRev.h>

#define DATA_1      0xcf
#define DATA_2      0xe7
#define DATA_3      0x85
#define DATA_4      0xef
#define DATA_5      0xc7
#define DATA_6      0xa5


const int pinRecv = 2;              // ir receiver connect to D2

const int pinR = 9;
const int pinG = 10;
const int pinB = 11;

int colorR = 0;
int colorG = 0;
int colorB = 0;

void setRGB()
{
    analogWrite(pinR, 255-colorR);
    analogWrite(pinG, 255-colorG);
    analogWrite(pinB, 255-colorB);
}


void setup()
{
    IR.Init(pinRecv);
}

unsigned char dta[20];

void loop()
{
    if(IR.IsDta())                  // get IR data
    {
        IR.Recv(dta);               // receive data to dta

        if(dta[9] == DATA_1)
        {
            colorR += 5;
            if(colorR>255)colorR = 0;
        }
        if(dta[9] == DATA_2)
        {
            colorG += 5;
            if(colorG>255)colorG = 0;
        }
        if(dta[9] == DATA_3)
        {
            colorB += 5;
            if(colorB>255)colorB = 0;
        }
        if(dta[9] == DATA_4)
        {
            colorR -= 5;
            if(colorR < 0)colorR = 255;
        }
        if(dta[9] == DATA_5)
        {
            colorG -= 5;
            if(colorG < 0)colorG = 255;
        }
        if(dta[9] == DATA_6)
        {
            colorB -= 5;
            if(colorB < 0)colorB = 255;
        }
        
        setRGB();

    }

}
