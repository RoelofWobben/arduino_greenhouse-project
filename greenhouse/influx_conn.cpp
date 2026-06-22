#include "influx_conn.h"
#include "secrets.h"
#include "sensors.h"
#include "wifi_conn.h"
#include <WiFiUdp.h>
#include <NTPClient.h>

#include <ArduinoHttpClient.h>
#include <WiFiNINA.h>

WiFiSSLClient wifi;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600);

void syncTime() {
  timeClient.begin();
  while (!timeClient.update()) {
    timeClient.forceUpdate();
  }

  Serial.print("NTP time: ");
  Serial.println(timeClient.getEpochTime());

  WiFi.setTime(timeClient.getEpochTime());
}

HttpClient httpClient(
  wifi,
  "eu-central-1-1.aws.cloud2.influxdata.com",
  443);

void sendInfluxDB(float moisture, float lichtwaarde, float air_quality) {

  String body = "greenhouse,device=nano33iot ";
  body += "moisture=" + String(moisture);
  body += ",light=" + String(lichtwaarde);
  body += ",air_quality=" + String(air_quality);

  Serial.println("----- InfluxDB Write -----");
  Serial.print("Body: ");
  Serial.println(body);

  Serial.print("WiFi status: ");
  Serial.println(WiFi.status());

  Serial.print("Epoch time: ");
  Serial.println(WiFi.getTime());

  // HTTP REQUEST
  httpClient.beginRequest();

  httpClient.post(
    "/api/v2/write?org=" + String(SECRET_ORG) + "&bucket=" + String(SECRET_BUCKET) + "&precision=s");

  httpClient.sendHeader("Authorization", "Token " + String(SECRET_TOKEN));
  httpClient.sendHeader("Content-Type", "text/plain");
  httpClient.sendHeader("Content-Length", body.length());

  httpClient.beginBody();
  httpClient.print(body);

  httpClient.endRequest();

  int statusCode = httpClient.responseStatusCode();
  String response = httpClient.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);

  Serial.print("Response: ");
  Serial.println(response);

  if (statusCode == 204) {
    Serial.println("InfluxDB write OK");
  } else {
    Serial.println("InfluxDB write FAILED");
  }
}