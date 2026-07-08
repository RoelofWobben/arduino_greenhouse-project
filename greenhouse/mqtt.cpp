#include <WiFi.h>
#include "mqtt.h"
#include <PubSubClient.h>
#include "leds.h"

const char* MQTT_SERVER = "test.mosquitto.org";
const int MQTT_PORT = 1883;
const char* MQTT_CLIENT_ID = "greenhouse-nano";

WiFiClient espClient;
PubSubClient mqttClient(espClient);

bool connectMqtt()
{
    setStatusRed(); 
    mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
    mqttClient.setCallback(mqttCallback);

    Serial.println("Connecting to MQTT...");

    if (mqttClient.connect(MQTT_CLIENT_ID))
    {
        Serial.println("MQTT connected");
        mqttClient.subscribe("greenhouse/light/set");
        setStatusBlue(); 
        return true;
    }
    else
    {
        Serial.print("MQTT failed: ");
        Serial.println(mqttClient.state());
        return false;
    }
}
void mqttCallback(char* topic, byte* payload, unsigned int length)
{
    Serial.print("Topic: ");
    Serial.println(topic);

    String message;

    for(unsigned int i = 0; i < length; i++) {
        message += (char) payload[i];
    }

    Serial.print("Message: ");
    Serial.println(message);

    if (message == "ON"){
        turnLightOn(); 
        Serial.println("Light on");
    } else if (message == "OFF") {
        turnLightOff(); 
        Serial.println("Light off");
    }
}