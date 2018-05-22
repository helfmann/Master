#include <SoftwareSerial.h>

int PortOneTX = 10;
int PortOneRX = 11;

const String USB = "USB";
const String GRBL = "GRBL";

char endOfLine = '\n';

SoftwareSerial portOne(PortOneRX, PortOneTX);

String grblBytes = "";
String USBBytes = "";

void setup()
{
    Serial.begin(9600);
    while (!Serial)
    {
        ; // Do nothing, just wait till we are connected through USB
    }
    portOne.begin(9600);
    portOne.write("\r\n");
    delay(2);       ;
}

String stringtoWrite = "";

void loop()
{   
    if (portOne.available() > 0)//while (portOne.available())
    {
        stringtoWrite = portOne.readStringUntil(endOfLine); 
        for (int i = 0; i < stringtoWrite.length(); i++)
        { 
            Serial.write(stringtoWrite[i]);
        }   
        Serial.write(endOfLine);

    }
    if (Serial.available() > 0)//while (Serial.available())
    { 
        stringtoWrite = Serial.readStringUntil(endOfLine); 
        for (int i = 0; i < stringtoWrite.length(); i++)
        { 
            portOne.write(stringtoWrite[i]);
        }   
        portOne.write(endOfLine);

    }   
}
