#include <IRSendRev.h>
//#include <IRSendRevInt.h>

#define BIT_LEN         0
#define BIT_START_H     1
#define BIT_START_L     2
#define BIT_DATA_H      3
#define BIT_DATA_L      4
#define BIT_DATA_LEN    5
#define BIT_DATA        6

void setup()
{
    Serial.begin(38400);
    IR.Init(2);
    Serial.println("init over");
}

unsigned char dta[20];

void loop()
{
    if(IR.IsDta())
    {
        IR.Recv(dta);

        Serial.println("+------------------------------------------------------+");
        Serial.print("START_H: ");
        Serial.print(dta[BIT_START_H]);
        Serial.print("\tSTART_L: ");
        Serial.println(dta[BIT_START_L]);
        
        
        Serial.print("DATA_H: ");
        Serial.print(dta[BIT_DATA_H]);
        Serial.print("\tDATA_L: ");
        Serial.println(dta[BIT_DATA_L]);
        
        
        Serial.print("\r\nDATA_LEN = ");
        Serial.println(dta[BIT_DATA_LEN]);
        
        for(int i=0; i<dta[BIT_DATA_LEN]; i++)
        {
            Serial.print("0x");
            Serial.print(dta[i+BIT_DATA], HEX);
            Serial.print("\t");
        }
        
        Serial.println();
        Serial.println("+------------------------------------------------------+\r\n\r\n");
        
    }

}
