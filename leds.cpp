/**
 * @file leds.cpp
 * @brief Implementation of NeoPixel LED strip control.
 *
 * Manages a WS2812B addressable LED strip to provide visual feedback
 * for soil moisture levels. Uses red for critical/dry, orange for low,
 * and green for adequate moisture conditions.
 */

#include <Adafruit_NeoPixel.h>
#include "leds.h"
#include "constants.h" 

/** @brief Global NeoPixel strip instance (NUM_PIXELS LEDs on LED_PIN). */
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

/**
 * @brief Initialize the NeoPixel LED strip.
 *
 * Starts the strip, sets brightness to 50%, clears all pixels,
 * and prints initialization status to serial.
 */
void initLeds(){
    Serial.println("im in the leds department  2");
    strip.begin();
    strip.setBrightness(50);
    strip.show(); 
    Serial.println("LEDs initialized");
}

/**
 * @brief Update LED display based on soil moisture level.
 *
 * Triggers emergency red blinking if moisture falls below the critical
 * threshold; otherwise displays a color-coded moisture bar.
 *
 * @param moisture Soil moisture percentage (0–100).
 */
void updateLeds(float moisture){
    if (moisture < MOISTURE_CRITICAL) {
        blinkAllRed(); 
    } else {
        setMoistureBar(moisture);
    }
}

/**
 * @brief Blink all LEDs red in an emergency alert pattern.
 *
 * Lights all pixels red for 500 ms, then turns them all off for 500 ms.
 * This blocking call completes one full on-off cycle (1 second total).
 */
void blinkAllRed() {
    for (int i = 0; i < NUM_PIXELS; i++) {
        strip.setPixelColor(i, strip.Color(255, 0, 0)); 
    }
    strip.show();
    delay(500);
    for (int i = 0; i < NUM_PIXELS; i++) {
        strip.setPixelColor(i, strip.Color(0, 0, 0)); 
    }
    strip.show();
    delay(500);
}

/**
 * @brief Display a color-coded moisture level bar on the LED strip.
 *
 * Scales the moisture percentage (0–100) to fill between 0 and NUM_PIXELS
 * with colored LEDs:
 * - Red: moisture ≤ MOISTURE_LOW (dry)
 * - Orange: MOISTURE_LOW < moisture ≤ MOISTURE_OK (acceptable)
 * - Green: moisture > MOISTURE_OK (optimal)
 * - Off (black): unfilled pixels
 *
 * @param percentage Soil moisture level as a percentage (0–100).
 */
void setMoistureBar(float percentage) {
    int ledsToLight = map((int) percentage, 0,100, 0, NUM_PIXELS);
    for (int i = 0; i < NUM_PIXELS; i++) {
        if (i < ledsToLight) {
            int ledPercent = (i+1) * (100 / NUM_PIXELS);

            if (ledPercent <= MOISTURE_LOW) {
                strip.setPixelColor(i, strip.Color(255, 0, 0)); 
            } else if (ledPercent <= MOISTURE_OK) {
                strip.setPixelColor(i, strip.Color(255, 165, 0)); 
            } else {
                strip.setPixelColor(i, strip.Color(0, 255, 0)); 
            } 
        }
    }
}

 