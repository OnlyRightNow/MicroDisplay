/*
 *  This sketch trys to Connect to the best AP based on a given list
 *
 */

#include <WiFi.h>
#include <WiFiMulti.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>

WiFiMulti wifiMulti;

#define LED_BUILTIN 21

U8G2_LD7032_60X32_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 18, /* data=*/ 23, /* cs=*/ 5, /* dc=*/ 2, /* reset=*/ 19);  // SW SPI esp32

void setup()
{
    Serial.begin(115200);
    u8g2.begin();
    delay(10);
    pinMode(LED_BUILTIN, OUTPUT);

    wifiMulti.addAP("Admiral Boom", "du kommst hier ned rein hahaha");
    wifiMulti.addAP("Pingu 1", "WG 3.OG li St0773r");
    wifiMulti.addAP("Pingu 2", "WG 3.OG li St0773r");
    digitalWrite(LED_BUILTIN, LOW);

    Serial.println("Connecting Wifi...");
    u8g2.clearBuffer();          // clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(0,20, "Connecting");  // write something to the internal memory
    u8g2.sendBuffer();          // transfer internal memory to the display
    if(wifiMulti.run() == WL_CONNECTED) {
        Serial.println("");
        Serial.println("WiFi connected");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        Serial.print("WiFi name: ");
        Serial.println(WiFi.SSID());
        digitalWrite(LED_BUILTIN, HIGH);
        u8g2.clearBuffer();          // clear the internal memory
        u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
        u8g2.setCursor(0, 15);
        u8g2.print(WiFi.SSID());
        u8g2.setCursor(0, 25);
        u8g2.print(WiFi.localIP());  // write something to the internal memory
        u8g2.sendBuffer();          // transfer internal memory to the display
        delay(1000);  
        
    }
}

void loop()
{
    if(wifiMulti.run() != WL_CONNECTED) {
        Serial.println("WiFi not connected!");
        delay(1000);
    }
}
