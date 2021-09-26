#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TimeLib.h>

// WiFi connectivity
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "conf.h"

#define RX_PIN 4
#define TX_PIN 5
#define BAUD_RATE 115200

SoftwareSerial sUART(RX_PIN, TX_PIN);

// Defining a NTP client
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

// Saving current epoch time
unsigned long epochTime;

// Grabs current epoch time
unsigned long getTime(void)
{
    timeClient.update();
    unsigned long now = timeClient.getEpochTime();
    return now;
}

// WiFi initialization
void initWiFi(void)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    Serial.print("Connecting to WiFi...");

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print('.');
        delay(1000);
    }

    Serial.println();
    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
}

void setup() 
{
    Serial.begin(BAUD_RATE);
    sUART.begin(BAUD_RATE);

    initWiFi();
    
    timeClient.begin();
}

void loop() 
{
    String msg = "";

    epochTime = getTime();
    // Serial.print("Epoch Time: ");
    // Serial.println(epochTime);

    msg.concat(year(epochTime));
    msg.concat(":");
    msg.concat(month(epochTime));
    msg.concat(":");
    msg.concat(day(epochTime));
    msg.concat(":");
    msg.concat(hour(epochTime));
    msg.concat(":");
    msg.concat(minute(epochTime));

    Serial.println(msg);

    delay(5000);
    // while (sUART.available())
    // {
    //     char x = sUART.available();
    //     Serial.print(x);
    // }
}