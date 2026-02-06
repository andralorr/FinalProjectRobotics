#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

const byte rs = 9;
const byte en = 8;
const byte d4 = 7;
const byte d5 = 6;
const byte d6 = 5;
const byte d7 = 4;

const int joyX = A0;
const int joyY = A1;
const int joySW = A2;

// buttons (left -> right)
const int btnPins[4] = {2, A3, A4, A5};

const int buzzerPin = 3;

// leds (left -> right)
const int ledPins[4] = {10, 11, 12, 13};

extern const int note_frequencies[4][3];

const unsigned long debounceDelay = 40;

#endif
