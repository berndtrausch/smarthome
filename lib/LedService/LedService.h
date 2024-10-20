#ifndef LEDSERVICE_H
#define LEDSERVICE_H

#include <LiquidCrystal_I2C.h>

// Declare the function
void UpdateLEDState(int buttonPinLeft, int ledPin, bool &isLedOn, int &ledOnCount, LiquidCrystal_I2C &mylcd, bool &isHouseLocked);

#endif
