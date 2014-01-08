/*
  Sidekick Advanced Kit Lesson - Joystick RGB 
  
  joystick to control a GRB Led, press button to set the rgb, 
  when finish setting, press the button again.
  x+ r   x- g y+(y-) b
  
  loovee
  2013-1-8
  
  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en


  button connect to D2
  joystick X connect to A1
  joystick Y connect to A2
  RGB led - R connect to D3
  RGB led - G connect to D5
  RGB led - B connect to D6
*/


#define STSET       0                                   // setting
#define STDONE      1                                   // work

int state = STSET;                                      // state, setting or ....

const int pinX    =  A1;
const int pinY    =  A0;

const int pinR    = 3;
const int pinG    = 5;
const int pinB    = 6;

const int pinButton = 2;

int originX = 0;
int originY = 0;

int color_r = 0;
int color_g = 0;
int color_b = 0;


// get value of analog
int getAnalog(int pin)
{

    int sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pin);
    }
    
    return sum >> 5; 
}


void setup()
{   

    originX = getAnalog(pinX);
    originY = getAnalog(pinY);
    
    pinMode(pinR, OUTPUT);
    pinMode(pinG, OUTPUT);
    pinMode(pinB, OUTPUT);
    
    pinMode(pinButton, INPUT);
    digitalWrite(pinButton, HIGH);                      // pull-up 
    
}


// set rgb led
void makeRGB()
{

    int x = getAnalog(pinX) - originX;                  // get value of x
    int y = getAnalog(pinY) - originY;                  // get value of y
    
    if(x < 0)
    {
        x = -x;
        color_r = map(x, 0, 280, 255, 0);
    }
    else if(x > 0)
    {
        color_g = map(x, 0, 280, 255, 0);
    }
    else
    {
        color_r = 255;
        color_g = 255;
    }
    
    y = abs(y);
    
    color_b = map(y, 0, 280, 255, 0);
    
    analogWrite(pinR, color_r);
    analogWrite(pinG, color_g);
    analogWrite(pinB, color_b);
}


void loop()
{

    if(state == STSET)
    {
        makeRGB();
    }
 
    // while button pressed
    if(!digitalRead(pinButton))
    {
        delay(10);
        if(!digitalRead(pinButton))
        {
            state = 1-state;                            // state change
            while(!digitalRead(pinButton));
        }
    }
    
    delay(10);
}