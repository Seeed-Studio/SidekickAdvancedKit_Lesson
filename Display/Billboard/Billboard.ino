/*
  Sidekick Advanced Kit Lesson - Billboard

  Display SeeedStduio

  loovee
  2013-1-8

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

*/

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("Seeed Studio");
    delay(1000);
}

void loop() {
    // scroll 13 positions (string length) to the left
    // to move it offscreen left:
    for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(150);
    }

    // scroll 29 positions (string length + display length) to the right
    // to move it offscreen right:
    for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
        // scroll one position right:
        lcd.scrollDisplayRight();
        // wait a bit:
        delay(150);
    }

    // scroll 16 positions (display length + string length) to the left
    // to move it back to center:
    for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
        // scroll one position left:
        lcd.scrollDisplayLeft();
        // wait a bit:
        delay(150);
    }

    // delay at the end of the full loop:
    delay(1000);

}
