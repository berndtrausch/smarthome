#ifndef LCDSERVICE_H
#define LCDSERVICE_H

#include <LiquidCrystal_I2C.h>

// Declare the function
void UpdateLCDDisplay(LiquidCrystal_I2C &mylcd, String message, int counter);

#endif