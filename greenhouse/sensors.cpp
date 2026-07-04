#include <Arduino.h>

#include "constants.h"
#include "sensors.h"
//#include "Air_Quality_Sensor.h"

//AirQualitySensor sensor(A6);


void initSensors() {
   Serial.println("Sensors initialized");
};

SensorData readSensors(){
    SensorData data;

    //Moisture sensor
    int raw1 = analogRead(MOISTURE_PIN);

    data.moisture = constrain(map(raw1,MOISTURE_DRY, MOISTURE_WET,0,100),0,100);



    // light sensor

    int raw2 = analogRead(LIGHT_PIN);
    int percentage = map(raw2, 0, 1023, 0, 100);
    data.light = percentage ;

    //int raw3 = sensor.slope();

    //data.air_quality = sensor.getValue();



    return data ; 

}

void printSerial(SensorData data){
    Serial.println("---- Sensor Data -- --");
    Serial.print("Moisture: ");
    Serial.print(data.moisture);
    Serial.println("%");

     Serial.print("Light: ");
    Serial.print(data.light);
    Serial.println("%");


     Serial.print("air quaility: ");
    Serial.print(data.air_quality);
    Serial.println("");

    
}