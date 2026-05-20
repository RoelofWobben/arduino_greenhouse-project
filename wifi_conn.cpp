#include "Arduino.h"

#include "wifi_conn.h"
#include "secrets.h"
#include "WiFiNINA.h"

void connectWifi() {
   Serial.begin(9600);
  while (!Serial){}

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with wifi module failed");
  }

  while(WiFi.status() != WL_CONNECTED) {
    //Serial.print("Attempt to connect to: ");
    //Serial.println(SECRET_SSID);
    //Serial.println(".");
    WiFi.begin(SECRET_SSID,  SECRET_PASS);
    //delay(1000);
  }

  Serial.println("Wifi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}





void checkWifi() {
  if (WiFi.status()  != WL_CONNECTED) {
    Serial.println("Wifi lost! Reconnecting");
    connectWifi(); 
  }
}