/*
  Sidekick Advanced Kit Lesson - Temperature and humi... sensor

  temperature sensor control led bar

  loovee
  2013-1-8

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en


  temp and humisensor connect to A0
  Led bar connect to D2~D11
*/


#include <DHT.h>
#include <LiquidCrystal.h>


#define TEMP_L          10                          // low temperature
#define TEMP_H          20                          // high temperature


#define DHTTYPE         DHT11                       // define sensor type

const int DHTPIN = A0;

DHT dht(DHTPIN, DHTTYPE);                           // object of temp&humi sensor


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
    dht.begin();
    for(int i=2; i<=11; i++)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
}

void loop()
{

    int t = dht.readTemperature();
        
    if(t>TEMP_H) t = TEMP_H;
    if(t<TEMP_L) t = TEMP_L;
    
    int level = map(t, TEMP_L, TEMP_H, 0, 10);
    
    setLedBar(level);
    
    delay(100);
    
    

}