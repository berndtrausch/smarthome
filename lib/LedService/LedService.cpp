#include "LedService.h"
#include "LcdService.h"

void UpdateLEDState(int buttonPinLeft, int ledPin, bool &isLedOn, int &ledOnCount, LiquidCrystal_I2C &mylcd, bool &isHouseLocked)
{
  int buttonStateLeft = digitalRead(buttonPinLeft);

  if (!isHouseLocked)
  {
    if (buttonStateLeft == LOW)
    {
      delay(100); // Debounce delay
      if (!isLedOn)
      {
        digitalWrite(ledPin, HIGH); // Turn LED on
        isLedOn = true;
        ledOnCount++;
        UpdateLCDDisplay(mylcd, "LED turned on:", ledOnCount);
      }
      else
      {
        digitalWrite(ledPin, LOW); // Turn LED off
        isLedOn = false;
      }
      delay(200);
    }
  }
  else
  {
    if (isLedOn)
    {
      digitalWrite(ledPin, LOW); // Turn LED off
      isLedOn = false;
    }
    delay(200);
  }
}
