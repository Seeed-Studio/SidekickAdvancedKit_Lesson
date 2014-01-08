/*
  Sidekick Advanced Kit Lesson - Potentiometer and led bar

  Potentiometer control led bar

  loovee
  2013-1-8

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en


  Potentiometer connect to D0
  Led bar connect to D2~D11
*/

const int pinPoten = A0;

// set led bar, 0-10 level.
// 0 led for level-0 and 10 leds for level-10
void setLedBar(int lev)
{
    for(int i=2; i<=11; i++)
    {
        digitalWrite(i, LOW);
    }

    if(lev>0)
    {
        for(int i=0; i<lev; i++)
        {
            digitalWrite(i+2, HIGH);
        }
    }
}


void setup()
{
    for(int i=2; i<=11; i++)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
}

void loop()
{

    int value = analogRead(pinPoten);
    
    int level = map(value, 0, 1023, 0, 10);             // level = 0~10
    setLedBar(level);                                   // set led bar
    
    delay(10);

}