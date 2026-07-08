#pragma once

#include <PubSubClient.h>

extern PubSubClient mqttClient;

bool connectMqtt();
void mqttCallback(char* topic, byte* payload, unsigned int length);