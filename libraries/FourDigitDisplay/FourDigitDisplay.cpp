
#include <Arduino.h>
#include <Streaming.h>

#include "FourDigitDisplay.h"


#define __BIT(n)    (0x01<<n)
const unsigned char __GNumber[10] =
{
    0x01, 0x4f, 0x12, 0x06, 0x4c, 0x24, 0x20, 0x0f, 0x00, 0x04
};//0~9


unsigned char location        = 0;
unsigned char location_buf    = 0;



void init_timer1(void)          //initialize Timer1 to 1ms overflow
{
    TCCR1A = 0;                 // clear control register A
    TCCR1B = _BV(WGM13);        // set mode as phase and frequency correct pwm, stop the timer
    ICR1=10000;                 //(XTAL * microseconds) / 2000000  1ms cycles
    TIMSK1 = _BV(TOIE1);
    TCNT1 = 0;
    TCCR1B |= _BV(CS10);
    sei();                      //enable global interrupt
}


ISR(TIMER1_OVF_vect)          // Timer1 Service, 1s
{

    location_buf = location;
    location++;
    location = location>3 ? 0 : location;
    
    digitalWrite(display.pinCom[location_buf], LOW);
    
    display.setPin(display.num_disp[location]);
    
    digitalWrite(display.pinCom[location], HIGH);

    

}

void four_digit_display::setPin(int num)
{
    for(int i=0; i<7; i++)
    {
        if(__GNumber[num] & __BIT(i))
        {
            digitalWrite(pinNum[6-i], HIGH);
        }
        else
        {
            digitalWrite(pinNum[6-i], LOW);
        }
    }
}


void four_digit_display::begin(const int *pin)
{

    num_disp[0] = 8;
    num_disp[1] = 9;
    num_disp[2] = 0;
    num_disp[3] = 1;
    
    for(int i=0; i<12; i++)
    {
        pinMode(pin[i], OUTPUT);
        digitalWrite(pin[i], HIGH);
    }

    for(int i=0; i<7; i++)
    {
        pinNum[i] = pin[i];
    }
    
    for(int i=0; i<4; i++)
    {
        pinCom[i] = pin[i+8];
    }
    
    pinDp = pin[7];
    
    init_timer1();
}


void four_digit_display::signalNum(unsigned char loca, unsigned char dta)
{
    num_disp[3-loca] = dta;
}

void four_digit_display::num(int dta)
{
    {
        if(dta < 0 || dta > 9999) return;           // bad data
        
        //clear();
        
        //pointOff();
        if(dta < 10)
        {
            signalNum(0, dta);
            signalNum(1, 0x7f);
            signalNum(2, 0x7f);
            signalNum(3, 0x7f);
        }
        else if(dta < 100)
        {
            signalNum(1, dta/10);
            signalNum(0, dta%10);
            signalNum(2, 0x7f);
            signalNum(3, 0x7f);
        }
        else if(dta < 1000)
        {
            signalNum(2, dta/100);
            signalNum(1, (dta/10)%10);
            signalNum(0, dta%10);
            signalNum(3, 0x7f);
        }
        else
        {
            signalNum(3, dta/1000);
            signalNum(2, (dta/100)%10);
            signalNum(1, (dta/10)%10);
            signalNum(0, dta%10);
        }
    }
}

void four_digit_display::time(unsigned char hour, unsigned char min)                   // display time, such as: 11:26
{
    if(hour > 24 || hour < 0) return;           // bad data
    if(min > 60 || min < 0) return;             // bad data

    signalNum(3, hour/10);
    signalNum(2, hour%10);
    signalNum(1, min/10);
    signalNum(0, min%10);
}


four_digit_display display;
