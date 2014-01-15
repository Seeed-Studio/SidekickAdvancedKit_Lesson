/*
  Sidekick Advanced Kit Lesson - Temperature LCD

  Display temperature and humi...

  loovee
  2013-1-15

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en


   The circuit:
  LCD RS pin to digital pin 12
  LCD Enable pin to digital pin 11
  LCD D4 pin to digital pin 5
  LCD D5 pin to digital pin 4
  LCD D6 pin to digital pin 3
  LCD D7 pin to digital pin 2
  LCD R/W pin to ground
  10K resistor:
  ends to +5V and ground
  wiper to LCD VO pin (pin 3)

  temp and humisensor connect to A0
*/


#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTTYPE 	DHT11					// define sensor type


const int DHTPIN = A0;

DHT dht(DHTPIN, DHTTYPE);					// object of temp&humi sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);		// initialize the library with the numbers of the interface pins


void setup()
{
	dht.begin();
	lcd.begin(16, 2);
}

void loop()
{

	float h = dht.readHumidity();
	float t = dht.readTemperature();
	
	lcd.setCursor(0, 0);
	lcd.print(h);
	lcd.setCursor(0, 1);
	lcd.print(t);

}