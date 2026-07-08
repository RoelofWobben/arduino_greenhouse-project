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
 *Color
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


void turnLightOn() {
    for(int i = 0; i < NUM_PIXELS; i++) {
        strip.setPixelColor(i, strip.Color(255,0,0));
    }
    strip.show();
}

void turnLightOff() {
    for(int i = 0; i < NUM_PIXELS; i++) {
        strip.setPixelColor(i, strip.Color(0,0,0));
    }
    strip.show();
}

void setStatusColor(uint8_t r, uint8_t g, uint8_t b) {
    for(int i = 0; i < NUM_PIXELS; i++) {
        strip.setPixelColor(i, strip.Color(r,g,b));
    }
    strip.show();
}

void setStatusRed() {
    setStatusColor(255,0,0);
}

void setStatusGreen(){
    setStatusColor(0,255,0);
}

void setStatusBlue(){
    setStatusColor(0,0,255);
}

void setStatusOff() {
    setStatusColor(0,0,0);
}
 