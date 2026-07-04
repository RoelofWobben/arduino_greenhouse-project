#pragma once

#include <PubSubClient.h>

extern PubSubClient mqttClient;

void connectMqtt();
void mqttCallback(char* topic, byte* payload, unsigned int length);