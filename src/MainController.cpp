//#include "Arduino.h"
#include "ESP32_Servo.h"
#include "OneButton.h"
#include "SerialLogger.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


// Define GPIO pins
#define BUTTON_PIN_LEFT 16  // Change to your Button 2 pin (GPIO_NUM_X)
#define BUTTON_PIN_RIGHT 27
#define SERVO_PIN 13   // Change to your Servo motor pin (GPIO_NUM_Y)
#define LED 12

// Create Servo object
Servo myServo;

LiquidCrystal_I2C mylcd(0x27,16,2);

// Door state variable
bool isDoorOpen = false;
bool isLedOn = false;
int doorOpenCount = 0;
int ledOnCount = 0;

void setup() {
  mylcd.init();
  mylcd.backlight();
  // Initialize the button pin as input
  pinMode(BUTTON_PIN_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_PIN_RIGHT, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  myServo.attach(SERVO_PIN);
  myServo.write(0);
}

void UpdateLCDDisplay(String message, int counter)
{
  mylcd.clear();
  mylcd.setCursor(0, 0);
  mylcd.print(message);
  mylcd.setCursor(0, 1);
  mylcd.print(counter);
}

void UpdateDoorState()
{
  // Read button state (LOW when pressed)
  int buttonStateRight = digitalRead(BUTTON_PIN_RIGHT);

  // If button is pressed, toggle the door state
  if (buttonStateRight == LOW) 
  {
    delay(100);  // Debounce delay
    if (!isDoorOpen) {
      // Open the door by rotating the servo to 90 degrees
      myServo.write(180);
      isDoorOpen = true;
      doorOpenCount++;
      UpdateLCDDisplay("Opened door:", doorOpenCount);
    } else {
      // Close the door by rotating the servo to 0 degrees
      myServo.write(0);
      isDoorOpen = false;
    }
    delay(500);  
  }
}

void UpdateLEDState()
{
  // Read button state (LOW when pressed)
  int buttonStateLeft = digitalRead(BUTTON_PIN_LEFT);

  if (buttonStateLeft == LOW) 
  {
    delay(100);
    if (!isLedOn)
    {
      digitalWrite(LED, HIGH);
      isLedOn = true;
      ledOnCount++;
      UpdateLCDDisplay("LED turned on:", ledOnCount);
    } else {
      // Close the door by rotating the servo to 0 degrees
      digitalWrite(LED, LOW);
      isLedOn = false;
    }

    delay(500);  
  };
  
}

void loop() {

  UpdateDoorState();
  UpdateLEDState();

}

