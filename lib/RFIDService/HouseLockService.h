#ifndef HOUSELOCKSERVICE_H
#define HOUSELOCKSERVICE_H

#include "MFRC522_I2C.h"
#include <LiquidCrystal_I2C.h>

// Declare the function
void UpdateHouseLockState(MFRC522 &mfrc522, bool &isHouseLocked, LiquidCrystal_I2C &mylcd, String &password);

#endif