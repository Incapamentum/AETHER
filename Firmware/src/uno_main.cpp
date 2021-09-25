#include <Arduino.h>
#include <SimpleDHT.h>
#include <SoftwareSerial.h>

#define DHTPIN 13
#define RX_PIN 2
#define TX_PIN 3
#define BAUD_RATE 115200

SoftwareSerial sUART(RX_PIN, TX_PIN);
SimpleDHT11 dht11;
String str;

byte temperature = 0;
byte humidity = 0;

void setup()
{
    Serial.begin(BAUD_RATE);
    sUART.begin(BAUD_RATE);
}

void loop()
{
    dht11.read(DHTPIN, &temperature, &humidity, NULL);

    Serial.print("Temperature = "); 
    Serial.print((int)temperature);
    Serial.print(" degC");

    Serial.print(" ");

    Serial.print("Humidity = ");
    Serial.print((int)humidity);
    Serial.println(" %H");

    sUART.print("<");
    sUART.print((int)temperature, DEC);
    sUART.print(",");
    sUART.print((int)humidity, DEC);
    sUART.print(">");
    sUART.println();

    delay(1000);
}