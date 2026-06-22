#pragma once

struct SensorData {
    float moisture; 
    float light; 
    float air_quality;
};

SensorData readSensors();
void printSerial(SensorData data);
void initSensors();
