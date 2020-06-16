    #include "ESP8266.h"
    #include <SoftwareSerial.h>
    #include <math.h>
     
    #define SSID     "RT-WiFi-6F05"
    #define PASSWORD "RfNa2GNv"
    #define TEMP_PIN A0
     
    SoftwareSerial mySerial(4, 5);
    ESP8266 wifi(mySerial);
    String name = "Amperka01031999";
     
    void setup(void) {
      Serial.begin(9600);
      if (wifi.joinAP(SSID, PASSWORD)) {
        Serial.println("https://dweet.io/follow/" + name);
      } else {
        Serial.println("Wi-Fi connection error");
      }
    }
     
    void loop(void) {
      float v_temp = 1023.0 / analogRead(TEMP_PIN) - 1.0;
      float temp = 1.0 / ( -log(v_temp) / 3977.0
                                + 1.0 / 295.0 ) - 273.0;
      if (wifi.createTCP("www.dweet.io", 80)) {
        String data = "GET /dweet/for/" + name + "?";
        data += "temp=" + String(temp) + " HTTP/1.1\r\n";
        data += "Host: dweet.io\r\n\r\n";
        wifi.send(data.c_str(), data.length());
        wifi.releaseTCP();
      } else {
        Serial.println("create TCP error");
      }
      delay(1000);
    }
