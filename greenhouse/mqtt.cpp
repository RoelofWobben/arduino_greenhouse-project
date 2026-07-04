#include <WiFi.h>
#include "mqtt.h"
#include <PubSubClient.h>

const char* MQTT_SERVER = "test.mosquitto.org";
const int MQTT_PORT = 1883;
const char* MQTT_CLIENT_ID = "greenhouse-nano";

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void connectMqtt()
{
    mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
    mqttClient.setCallback(mqttCallback);

    while (!mqttClient.connected())
    {
        Serial.println("Connecting to MQTT...");

        if (mqttClient.connect(MQTT_CLIENT_ID))
        {
            Serial.println("MQTT connected");
        }
        else
        {
            Serial.print("MQTT failed: ");
            Serial.println(mqttClient.state());

            delay(2000);
        }
    }
}

void mqttCallback(char* topic, byte* payload, unsigned int length)
{
    Serial.println(topic);
}