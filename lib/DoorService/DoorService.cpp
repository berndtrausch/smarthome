#include "DoorService.h"
#include "LcdService.h"

void UpdateDoorState(int buttonPinRight, Servo &myServo, bool &isDoorOpen, int &doorOpenCount, LiquidCrystal_I2C &mylcd) {
  int buttonStateRight = digitalRead(buttonPinRight);

  // If button is pressed, toggle the door state
  if (buttonStateRight == LOW) {
    // doorOpenCount = getCountFromAzure(getUrl);
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

// int getCountFromAzure(String &getUrl) {
//   if (WiFi.status() == WL_CONNECTED) {
//     HTTPClient http;
//     http.begin(getUrl);
    
//     int httpResponseCode = http.GET();

//     if (httpResponseCode > 0) {
//       String response = http.getString();
//       return response.toInt();
//     }

//     http.end();
//   }
//   return 0;
// }

// void sendCountToAzure(int count, String &postUrl) {
//   if (WiFi.status() == WL_CONNECTED) {
//     HTTPClient http;
//     http.begin(postUrl);
//     http.addHeader("Content-Type", "application/json");
    
//     String payload = "{\"count\": " + String(count) + "}";
//     int httpResponseCode = http.POST(payload);

//     if (httpResponseCode > 0) {
//       String response = http.getString();
//       Serial.println(response);
//     }

//     http.end();
//   }
// }