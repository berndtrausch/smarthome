#include "DoorBellService.h"
#include "LcdService.h"

void UpdateDoorBellState(int buttonPinRight, int &bellRingCount, LiquidCrystal_I2C &mylcd, bool &isDoorBellRinging, music &Music)
{
    int buttonStateRight = digitalRead(buttonPinRight);

    // If button is pressed, ring the door bell
    if (buttonStateRight == LOW)
    {
        delay(100); // Debounce delay
        if(!isDoorBellRinging)
        {
            bellRingCount++;
            UpdateLCDDisplay(mylcd, "Door bell rang:", bellRingCount);
            isDoorBellRinging = true;
        }

        Music.Ode_to_Joy();
    }
    else
    {
        isDoorBellRinging = false;
    }

    delay(500);
}
