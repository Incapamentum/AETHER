#include <Arduino.h>
#include <SimpleDHT.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

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

    StaticJsonDocument<64> doc;

    doc["sensor"] = "dht11";
    doc["timestamp"] = -1;

    JsonArray data = doc.createNestedArray("data");
    data.add(temperature);
    data.add(humidity);

    serializeJson(doc, Serial);
    serializeJson(doc, sUART);

    delay(1000);
}