#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 10;
int ledHIGH    = 1;
int ledLOW     = 0;

MCP_CAN CAN(spiCSPin);

void setup()
{
    Serial.begin(9600);

    while (CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    pinMode(3, INPUT);
    pinMode(2, OUTPUT);
    Serial.println("CAN BUS Shield Init OK!");
}

unsigned char stmp[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    
void loop()
{   
  Serial.println("In loop");
  CAN.sendMsgBuf(0x43, 0, 8, stmp);

  if (digitalRead(3) == true)
  {
    Serial.println("Write HIGH to pin 2");
    digitalWrite(2, HIGH);
  }
  else if (digitalRead(3) == false)
  {
    Serial.println("Write LOW to pin 2");
    digitalWrite(2, LOW);
  }
  delay(1000);
}
