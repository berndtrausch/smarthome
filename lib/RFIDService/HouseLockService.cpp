#include "HouseLockService.h"
#include "LcdServiceBool.h"

void UpdateHouseLockState(MFRC522 &mfrc522, bool &isHouseLocked, LiquidCrystal_I2C &mylcd, String &password)
{
    if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
    {
        return; // Exit if no card is present or it cannot be read
    }

    // save UID
    password = ""; // Reset the password before reading a new card
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i]);
        password = password + String(mfrc522.uid.uidByte[i]);
    }

    UpdateLCDDisplayBoolean(mylcd, password, true);

    if (password == "496218276") // The card number is correct, open the door
    {
        isHouseLocked = !isHouseLocked;

        UpdateLCDDisplayBoolean(mylcd, "House locked:", isHouseLocked);

        password = "";
    }
    else // The card number is wrong，LCD displays error
    {
        UpdateLCDDisplayBoolean(mylcd, "Unauthorized card", true);
        delay(2000);
        isHouseLocked = true;
        UpdateLCDDisplayBoolean(mylcd, "House locked:", isHouseLocked);
    }
    mfrc522.PICC_HaltA();
}
