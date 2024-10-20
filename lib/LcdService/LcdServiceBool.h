#ifndef LCDSERVICE_H
#define LCDSERVICE_H

#include <LiquidCrystal_I2C.h>

void UpdateLCDDisplayBoolean(LiquidCrystal_I2C &mylcd, String message, bool state);

#endif