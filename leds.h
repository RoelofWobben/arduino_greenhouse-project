/**
 * @file leds.h
 * @brief NeoPixel LED strip control interface.
 *
 * Provides functions to initialize and control a WS2812B NeoPixel LED strip
 * to display visual feedback for soil moisture levels and critical states.
 */

#pragma once

/**
 * @brief Initialize the NeoPixel LED strip.
 *
 * Sets up the strip hardware, sets initial brightness to 50%, and clears
 * all pixels. Prints a debug message to serial.
 */
void initLeds();

/**
 * @brief Update LED display based on current moisture level.
 *
 * If moisture is below `MOISTURE_CRITICAL`, triggers the red blink alarm.
 * Otherwise, displays a color-coded moisture bar.
 *
 * @param moisture Soil moisture percentage (0–100).
 */
void updateLeds(float moisture);

/**
 * @brief Display a color-coded moisture bar on the LED strip.
 *
 * Maps the moisture percentage to lit pixels (0–NUM_PIXELS).
 * Colors indicate moisture status:
 * - Red: low moisture (≤ MOISTURE_LOW%)
 * - Orange: adequate moisture (≤ MOISTURE_OK%)
 * - Green: optimal moisture (> MOISTURE_OK%)
 * - Off: unlit pixels
 *
 * @param percentage Soil moisture percentage (0–100).
 */
void setMoistureBar(float percentage);

/**
 * @brief Blink all LEDs red in an emergency pattern.
 *
 * Alternately turns all pixels on (red) and off with 500 ms intervals.
 * Does not return until the blink cycle completes (1 second total).
 */
void blinkAllRed(); 


