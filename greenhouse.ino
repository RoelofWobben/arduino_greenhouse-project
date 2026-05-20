/**
 * @file main.cpp
 * @brief Greenhouse Monitor - main entry point.
 *
 * Initializes peripherals, reads sensor data periodically and forwards
 * measurements to InfluxDB. Uses `READ_INTERVAL` and `SEND_INTERVAL`
 * defined in `constants.h` to schedule reads and sends.
 */

#include <Arduino.h>
#include "constants.h"
#include "leds.h"
#include "sensors.h"
#include "influx_conn.h"
#include "wifi_conn.h"


/**
 * @brief Time (milliseconds) of the last sensor read.
 *
 * Updated from `millis()` whenever sensor values are sampled.
 * @type unsigned long
 */
unsigned long lastRead = 0;

/**
 * @brief Time (milliseconds) of the last data send to InfluxDB.
 *
 * Updated from `millis()` whenever buffered values are transmitted.
 * @type unsigned long
 */
unsigned long lastSend = 0;

/**
 * @brief Arduino setup routine.
 *
 * Performs serial initialization, peripheral initialisation and
 * establishes network and database connections. This function runs
 * once at boot.
 *
 * Steps performed:
 * - Initialize Serial at 9600 baud and wait briefly for connection
 * - Initialize LEDs and sensors
 * - Connect to WiFi
 * - Prepare InfluxDB client
 *
 * @see initLeds()
 * @see initSensors()
 * @see connectWifi()
 * @see setupInfluxDb()
 */

 int test = 0;

void setup() {
  Serial.begin(115200);

  while(!Serial) {}

  Serial.println("=== Greenhouse Monitor V1 ===");

  //initLeds();
  //initSensors();
  connectWifi();
  
  

  //Serial.println("Setup complete");
}

/**
 * @brief Arduino main loop.
 *
 * This function runs repeatedly. It performs two periodic tasks:
 * 1) Read sensors at intervals defined by `READ_INTERVAL` and update
 *    local state / LEDs.
 * 2) Send data to InfluxDB at intervals defined by `SEND_INTERVAL`.
 *
 * The timing is driven from `millis()` and `lastRead` / `lastSend`.
 */
void loop() {

  /*
  //checkWifi();
  Serial.print("loop");
  static SensorData data;

  if (millis() - lastRead >= READ_INTERVAL) {
    lastRead = millis();

    data = readSensors();
    printSerial(data);
    updateLeds(data.moisture);
  }

  if (millis() - lastSend >= SEND_INTERVAL){
    lastSend = millis();
    sendInfluxDB(data.moisture);
  }
  */
}

