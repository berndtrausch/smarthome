#include "LcdService.h"

// Define the function
void UpdateLCDDisplay(LiquidCrystal_I2C &mylcd, String message, int counter) {
  mylcd.clear();
  mylcd.setCursor(0, 0);
  mylcd.print(message);
  mylcd.setCursor(0, 1);
  mylcd.print(counter);
}
