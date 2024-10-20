#include "LcdService.h"

void UpdateLCDDisplayBoolean(LiquidCrystal_I2C &mylcd, String message, bool state) {
  mylcd.clear();
  mylcd.setCursor(0, 0);
  mylcd.print(message);
  mylcd.setCursor(0, 1);
  mylcd.print(state ? "true" : "false");
}