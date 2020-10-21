/*
    This sketch trys to Connect to the best AP based on a given list

*/

#include <WiFi.h>
#include <WiFiMulti.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>

WiFiMulti wifiMulti;
WiFiServer server(80);

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
  u8g2.drawStr(0, 20, "Connecting"); // write something to the internal memory
  u8g2.sendBuffer();          // transfer internal memory to the display
  if (wifiMulti.run() == WL_CONNECTED) {
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
    server.begin();

  }
}

void loop()
{
  if (wifiMulti.run() != WL_CONNECTED) {
    Serial.println("WiFi not connected!");
    delay(1000);
  } else {
    WiFiClient client = server.available();   // listen for incoming clients
    if (client) {                             // if you get a client,
      Serial.println("New Client.");           // print a message out the serial port
      String currentLine = "";                // make a String to hold incoming data from the client
      while (client.connected()) {            // loop while the client's connected
        if (client.available()) {             // if there's bytes to read from the client,
          char c = client.read();             // read a byte, then
          Serial.write(c);                    // print it out the serial monitor
          if (c == '\n') {                    // if the byte is a newline character
            // if the current line is blank, you got two newline characters in a row.
            // that's the end of the client HTTP request, so send a response:
            if (currentLine.length() == 0) {
              // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
              // and a content-type so the client knows what's coming, then a blank line:
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println();

              // the content of the HTTP response follows the header:
              client.print("Click <a href=\"/H\">here</a> to turn the LED on.<br>");
              client.print("Click <a href=\"/L\">here</a> to turn the LED off.<br>");

              // The HTTP response ends with another blank line:
              client.println();
              // break out of the while loop:
              break;
            } else {    // if you got a newline, then clear currentLine:
              currentLine = "";
            }
          } else if (c != '\r') {  // if you got anything else but a carriage return character,
            currentLine += c;      // add it to the end of the currentLine
          }

          // Check to see if the client request was "GET /H" or "GET /L":
          if (currentLine.endsWith("GET /H")) {
            digitalWrite(LED_BUILTIN, HIGH);               // GET /H turns the LED on
          }
          if (currentLine.endsWith("GET /L")) {
            digitalWrite(LED_BUILTIN, LOW);                // GET /L turns the LED off
          }
        }
      }
      // close the connection:
      client.stop();
      Serial.println("Client Disconnected.");

    }
  }
}
