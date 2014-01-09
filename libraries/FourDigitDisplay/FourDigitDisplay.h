/*
  Sidekick Advanced Kit Lesson - Clock Buzzer

  A Simple Clock

  loovee
  2013-1-8

  for more information, please refer to
  http://www.seeedstudio.com/wiki/index.php?title=Sidekick_Advanced_Kit&uselang=en

  
                12 11 10 9  8  7
                |  |  |  |  |  |
      +-----------------------------------+
      |  +----+  +----+   +----+  +----+  |
      |  |    |  |    | * |    |  |    |  |
      |  +----+  +----+   +----+  +----+  |
      |  |    |  |    | * |    |  |    |  |
      |  +----+. +----+.  +----+. +----+. |
      +-----------------------------------+ 
               |  |  |  |  |  |
               1  2  3  4  5  6
    
    
              A
        +------------+
        |            |
        |            |
      F |            | B
        |     G      |
        +------------+
        |            |
      E |            | C
        |            | 
        |            |  dp
        +------------+  *
              D
    
    1: E        -> D2
    2: D        -> D3
    3: DP       -> D4
    4: C        -> D5
    5: G        -> D6
    6: COM4     -> D7
    7: B        -> D8
    8: COM3     -> D9
    9: COM2     -> D10
    10: F       -> D11
    11: A       -> D12
    12: COM1    -> D13

*/

#ifndef __FOURDIGITDISPLAY_H__
#define __FOURDIGITDISPLAY_H__

class four_digit_display{

public:

    int pinNum[7];
    int pinCom[4];
    int pinDp;
    
    unsigned char num_disp[4];


public:

    void setPin(int num);
    

public:

    void begin(const int *pin);
    void signalNum(unsigned char loca, unsigned char dta);  // display a single num(0-9)
    void num(int dta);                                      // display a num (0-9999)    
    void time(unsigned char hour, unsigned char min);                   // display time, such as: 11:26
    
    
    void clear()                                            // clear display
    {
        for(int i=0; i<4; i++)
        {
            num_disp[i] = 0;
        }
        
    }
    
    
    void pointOn()                                          // display :
    {
        digitalWrite(pinDp, LOW);
    }
    
    void pointOff()                                         // undisplay :
    {
        digitalWrite(pinDp, HIGH);
    }
    
};


extern four_digit_display display;

#endif