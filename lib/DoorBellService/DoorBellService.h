#ifndef DOORBELLSERVICE_H
#define DOORBELLSERVICE_H

#include <LiquidCrystal_I2C.h>
#include <musicESP32_home.h>   

// Declare the function

void UpdateDoorBellState(int buttonPinRight, int &bellRingCount, LiquidCrystal_I2C &mylcd, bool &isDoorBellRinging, music &Music);

#endif