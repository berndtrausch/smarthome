#include "DoorBellService.h"
#include "LcdService.h"

void UpdateDoorBellState(int buttonPinRight, int &bellRingCount, LiquidCrystal_I2C &mylcd, bool &isDoorBellRinging, music &Music)
{
    int buttonStateRight = digitalRead(buttonPinRight);

    // If button is pressed, ring the door bell
    if (buttonStateRight == LOW)
    {
        delay(100); // Debounce delay
        bellRingCount++;
        UpdateLCDDisplay(mylcd, "Door bell rang:", bellRingCount);
        isDoorBellRinging = false;
    }
    else
    {
        isDoorBellRinging = false;
    }

    while (isDoorBellRinging)
    {
        // Play the door bell music
        Music.Ode_to_Joy();
    }
    delay(500);
}
