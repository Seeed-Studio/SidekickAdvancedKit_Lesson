/*
  Sidekick Advanced Kit Lesson - RFID_LOCK

  a Lock with servo and rfid reader

  loovee
  2013-1-15
  
  first, please refer to here:
  http://www.seeedstudio.com/wiki/index.php?title=IR_Remote&uselang=en


  rfid reader rx connect to D2, tx connect to D3
  
  Servo connect to D9

*/

#include <Servo.h>
#include <SoftwareSerial.h>


Servo myservo;                                          // create servo object to control a servo

const int pin_servo  = 9;

const int loca_open  = 50;                              // servo location when open
const int loca_close = 60;                              // servo location when close

SoftwareSerial SoftSerial(2, 3);

unsigned char buffer[64];                               // buffer array for data recieve over serial port

int count = 0;                                          // counter for buffer array
int status_led = 0;


void OpenDoor()
{
    myservo.attach(pin_servo);
    myservo.write(loca_open);
    delay(100);
    myservo.detach();
}

void CloseDoor()
{   
    myservo.attach(pin_servo);
    myservo.write(loca_close);
    delay(100);
    myservo.detach();
}

void setup()
{
    SoftSerial.begin(9600);                             // the SoftSerial baud rate
    Serial.begin(9600);                                 // the Serial port of Arduino baud rate.

    myservo.attach(pin_servo);
    myservo.write(loca_open);
}

void loop()
{
    if (SoftSerial.available())                         // if date is comming from softwareserial port ==> data is comming from SoftSerial shield
    {
        while(SoftSerial.available())                   // reading data into char array
        {
            buffer[count++]=SoftSerial.read();          // writing data into array

            if(buffer[count-1] == 0x03)                 // end
            {
                OpenDoor();
                delay(1000);
                CloseDoor();
            }
            if(count == 64)break;
        }
        Serial.write(buffer,count);                     // if no data transmission ends, write buffer to hardware serial port
        clearBufferArray();                             // call clearBufferArray function to clear the storaged data from the array
        count = 0;                                      // set counter of while loop to zero
    }
}

void clearBufferArray()                                 // function to clear buffer array
{
    for (int i=0; i<count;i++)
    { buffer[i]=NULL;}                                  // clear all index of array with command NULL
}