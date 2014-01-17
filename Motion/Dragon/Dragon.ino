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
#include <LED_Matrix.h>
#include <LED_Matrix_dfs.h>
#include <MsTimer2.h>
#include <Servo.h> 
 
#define POWER   0x5D
#define LEDCTRL 0xDD
#define LEFT    0xFD
#define RIGHT   0x3D

const int pinRecv   = A0;
const int pinServo  = A1;
Servo myservo;  // create servo object to control a servo 


int flg_pwr  = 0;
int flg_beat = 0;

int servoPos = 0;


unsigned char dta[20];                  // data buf of ir

unsigned char empty_disp[8] = 
{
0,
0,
0,
0,
0,
0,
0,
0,
};
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

// delay x ms untill when press button  
void checkRecvAndDelay(int ms)
{
    for(int i=0; i<ms; i++)
    {
        delay(1);
        if(IR.IsDta())return;
    }
}


void setup()
{
    matrix.begin();
    myservo.attach(pinServo);
    IR.Init(pinRecv);
}




void loop()
{
    if(IR.IsDta())                  // get IR data
    {
        IR.Recv(dta);               // receive data to dta

        if(dta[9] == POWER)
        {
            flg_pwr = 1-flg_pwr;
            
            if(flg_pwr)
            {
                flg_beat = 1;
            }
            else
            {
                matrix.dispMatrix(empty_disp);
            }
        }
        if(dta[9] == LEDCTRL)
        {
            flg_beat = 1-flg_beat;
        }
        if(dta[9] == LEFT)
        {
            servoPos -= 5;
            if(servoPos<=0)servoPos = 0;
            
            myservo.write(servoPos);
            
            
        }
        if(dta[9] == RIGHT)
        {
            servoPos += 5;
            if(servoPos>180)servoPos = 180;
            
            myservo.write(servoPos);
        }
    }
    
    if(flg_pwr == 1)
    {
        if(0 == flg_beat)                               // no beat
        {
            matrix.dispMatrix(big_heart);
            checkRecvAndDelay(1);
        }
        else                                            // beat
        {
            matrix.dispMatrix(big_heart);
            checkRecvAndDelay(200);
            matrix.dispMatrix(small_heart);
            checkRecvAndDelay(800);
        }
    }
}
