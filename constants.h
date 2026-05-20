/**
 * @file constants.h
 * @brief Configuration constants for the Greenhouse Monitor project.
 *
 * Defines pin mappings, LED strip settings, sensor thresholds, and timing
 * intervals used throughout the application.
 */

#pragma once

//--------------------------------------------
// PINS
//--------------------------------------------

/** @brief Analog pin for soil moisture sensor. */
#define MOISTURE_PIN          A2
/** @brief Analog pin for light sensor. */
#define LIGHT_PIN             A1
/** @brief Digital pin for DHT temperature/humidity sensor. */
#define DHT_PIN                2
/** @brief Digital pin for NeoPixel LED strip control. */
#define LED_PIN               6

// -------------------------------------------
// LED STRIP
// -------------------------------------------
/** @brief Number of pixels in the NeoPixel LED strip. */
#define NUM_PIXELS              10

//--------------------------------------------
// MOISTURE CALIBRATION 
//--------------------------------------------

/** @brief ADC value when soil is completely dry. */
#define MOISTURE_DRY           0
/** @brief ADC value when soil is saturated with water. */
#define MOISTURE_WET           400

//--------------------------------------------
// THRESHOLDS
//-------------------------------------------- 

/** @brief Moisture percentage below which emergency red blinking occurs. */
#define MOISTURE_CRITICAL      10
/** @brief Moisture percentage threshold for low moisture (red LED). */
#define MOISTURE_LOW           30     
/** @brief Moisture percentage threshold for acceptable moisture (orange LED). */
#define MOISTURE_OK            60

//--------------------------------------------
// TIMING
//--------------------------------------------  
/** @brief Interval (milliseconds) between sensor readings. */
#define READ_INTERVAL         1000    // 1 seconds
/** @brief Interval (milliseconds) between InfluxDB transmissions. */
#define SEND_INTERVAL         30000   // 1/2 minute



