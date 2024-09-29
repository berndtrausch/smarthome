#include "DoorService.h"
#include "LcdService.h"

void UpdateDoorState(int buttonPinRight, Servo &myServo, bool &isDoorOpen, int &doorOpenCount, LiquidCrystal_I2C &mylcd) {
  int buttonStateRight = digitalRead(buttonPinRight);

  // If button is pressed, toggle the door state
  if (buttonStateRight == LOW) {
    delay(100);  // Debounce delay
    if (!isDoorOpen) {
      myServo.write(180);  // Open the door
      isDoorOpen = true;
      doorOpenCount++;
      UpdateLCDDisplay(mylcd, "Opened door:", doorOpenCount);
    } else {
      myServo.write(0);  // Close the door
      isDoorOpen = false;
    }
    delay(500);  
  }
}
