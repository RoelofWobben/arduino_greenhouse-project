#pragma once

struct SensorData {
    float moisture; 
};

SensorData readSensors();
void printSerial(SensorData data);
void initSensors();
