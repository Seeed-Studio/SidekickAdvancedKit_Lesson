/*
  Sidekick Advanced Kit Lesson - dragon

  loovee
  2013-1-20

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en

*/


#include <IRSendRev.h>
#include <LED_Matrix.h>
#include <LED_Matrix_dfs.h>
#include <Servo.h>

#include <Streaming.h>

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

unsigned char empty_disp[8] = {0, 0, 0, 0, 0, 0, 0, 0};

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
        matrix.timer_();
        if(IR.IsDta())return;
    }
}

void setup()
{
    Serial.begin(9600);

    matrix.begin();
    myservo.attach(pinServo);
    IR.Init(pinRecv);
}

long tiemr_tmp = 0;


void loop()
{
    if(IR.IsDta())                  // get IR data
    {
        IR.Recv(dta);               // receive data to dta

        
        if(dta[9] == POWER)         // POWER
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

            cout << "POWER: " << endl;
            cout << "flg_pwr = " << flg_pwr << endl;
        }
        else if(dta[9] == LEDCTRL)                  // LED control, beat or no beat
        {
            flg_beat = 1-flg_beat;

            cout << "LEDCTRL: " << endl;
            cout << "flg_beat = " << flg_beat << endl;

            if(!flg_beat)                                   // no beat
            {
                matrix.dispMatrix(big_heart);
            }
        }
        else if(dta[9] == LEFT)                     // servo turn left
        {
            servoPos -= 5;
            if(servoPos<=0)servoPos = 0;

            myservo.write(servoPos);

            cout << "LEFT:" << endl;
            cout << "servoPos = " << servoPos << endl;

        }
        else if(dta[9] == RIGHT)                    // servo turn right
        {
            servoPos += 5;
            if(servoPos>150)servoPos = 150;

            myservo.write(servoPos);

            cout << "RIGHT" << endl;
            cout << "servoPos = " << servoPos << endl;
        }
    }

    if(flg_pwr && flg_beat)                         // heart beat
    {
        matrix.dispMatrix(big_heart);
        checkRecvAndDelay(200);
        matrix.dispMatrix(small_heart);
        checkRecvAndDelay(800);
    }

    if((micros() - tiemr_tmp) > 1000)               // timer isr
    {
        tiemr_tmp = micros();
        matrix.timer_();
    }

}
