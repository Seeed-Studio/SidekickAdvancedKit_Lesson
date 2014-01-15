 /*
  Sidekick Advanced Kit Lesson - Conveyor

  Conveyor, speed controled by potentiometer

  loovee
  2013-1-15
  
  first, please refer to here:
  http://www.seeedstudio.com/wiki/index.php?title=IR_Remote&uselang=en


  potentiometer connect to A0

*/

#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,9,10,11);

int stepCount = 0;  // number of steps the motor has taken

void setup() 
{
    // nothing to do inside the setup
}

void loop() 
{
    // read the sensor value:
    int sensorReading = analogRead(A0);
    // map it to a range from 0 to 100:
    int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
    // set the motor speed:
    if (motorSpeed > 0) {
        myStepper.setSpeed(motorSpeed);
        // step 1/100 of a revolution:
        myStepper.step(stepsPerRevolution/100);
    }
}

