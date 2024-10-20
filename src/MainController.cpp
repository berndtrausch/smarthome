//#include "Arduino.h"
#include "ESP32_Servo.h"
#include "OneButton.h"
#include "SerialLogger.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "MFRC522_I2C.h"

#include "LcdService.h"
#include "DoorService.h"
#include "LedService.h"
#include "HouseLockService.h"

// Define GPIO pins
#define BUTTON_PIN_LEFT 16  // Change to your Button 2 pin (GPIO_NUM_X)
#define BUTTON_PIN_RIGHT 27
#define SERVO_PIN 13   // Change to your Servo motor pin (GPIO_NUM_Y)
#define LED 12

// #define SS_PIN 21  // SDA pin
// #define RST_PIN 22 // RST pin

// Create Servo object
Servo myServo;
LiquidCrystal_I2C mylcd(0x27,16,2);
MFRC522 mfrc522(0x28);   // create MFRC522.

// Door state variable
bool isDoorOpen = false;
bool isLedOn = false;
bool isHouseLocked = false;
int doorOpenCount = 0;
int ledOnCount = 0;

String password = "";

void setup() {
  mylcd.init();
  mylcd.backlight();
  pinMode(BUTTON_PIN_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_PIN_RIGHT, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  mfrc522.PCD_Init(); 
  myServo.attach(SERVO_PIN);
  myServo.write(0);
}

void loop() {

  UpdateHouseLockState(mfrc522, isHouseLocked, mylcd, password);
  UpdateDoorState(BUTTON_PIN_RIGHT, myServo, isDoorOpen, doorOpenCount, mylcd, isHouseLocked);
  UpdateLEDState(BUTTON_PIN_LEFT, LED, isLedOn, ledOnCount, mylcd, isHouseLocked);

}

