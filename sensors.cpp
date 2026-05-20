#include <Arduino.h>

#include "constants.h"
#include "sensors.h"

void initSensors() {
   Serial.println("Sensors initialized");
};

SensorData readSensors(){
    SensorData data;

    //Moisture sensor
    int raw1 = analogRead(MOISTURE_PIN);

    data.moisture = constrain(map(raw1,MOISTURE_DRY, MOISTURE_WET,0,100),0,100);

    return data;
}

void printSerial(SensorData data){
    Serial.println("---- Sensor Data -- --");
    Serial.print("Moisture: ");
    Serial.print(data.moisture);
    Serial.println("%");
}