#include <Arduino.h>
#include <SoftwareSerial.h>

#define RX_PIN 4
#define TX_PIN 5
#define BAUD_RATE 115200

SoftwareSerial sUART(RX_PIN, TX_PIN);

void setup() 
{
    Serial.begin(BAUD_RATE);
    sUART.begin(BAUD_RATE);
}

void loop() 
{
    while (sUART.available())
    {
        char x = sUART.available();
        Serial.print(x);
    }
}