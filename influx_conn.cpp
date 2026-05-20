#include "influx_conn.h"
#include "secrets.h"
#include "sensors.h"
//#include "wifi_conn.h"
#include <ArduinoHttpClient.h>
#include "WiFiNINA.h"

WiFiSSLClient wifi; 
HttpClient httpClient = HttpClient(wifi, "eu-central-1-1.aws.influxdata.com", 443);

 

void sendInfluxDB(float moisture) {
    
    // Build line protocol string
    String body = "greenhouse, device=nano33iot, ";
    body += "moisture=" + String(moisture);

    //Set headers

    httpClient.beginRequest(); 
    httpClient.post("/api/v2/write?org=" + String(SECRET_ORG) +"&bucket=" + String(SECRET_BUCKET) +
"&precision=s");
    httpClient.sendHeader("Authorization", "Token " + String(SECRET_TOKEN));
    httpClient.sendHeader("Content-type", "text/plain");
    httpClient.sendHeader("Content-Length", body.length());
    httpClient.endRequest();
    httpClient.print(body);

    Serial.println(body);

    int statusCode = httpClient.responseStatusCode(); 

    if (statusCode == 204) {
        Serial.println("InfluxDb write OK");
    } else {
        Serial.print("InfluxDb write failed: ");
        Serial.println(statusCode);
    }

    

}


 