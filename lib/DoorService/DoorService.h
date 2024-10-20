#ifndef DOORSERVICE_H
#define DOORSERVICE_H

#include "ESP32_Servo.h"
#include <LiquidCrystal_I2C.h>

// Declare the function
void UpdateDoorState(int buttonPinRight, Servo &myServo, bool &isDoorOpen, int &doorOpenCount, LiquidCrystal_I2C &mylcd, bool &isHouseLocked);

#endif