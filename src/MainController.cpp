//#include "Arduino.h"
#include "ESP32_Servo.h"
#include "OneButton.h"
#include "SerialLogger.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <musicESP32_home.h>   

#include "LcdService.h"
#include "DoorService.h"
#include "LedService.h"
#include "DoorBellService.h"

// Define GPIO pins
#define BUTTON_PIN_LEFT 16  // Change to your Button 2 pin (GPIO_NUM_X)
#define BUTTON_PIN_RIGHT 27
#define SERVO_PIN 13   // Change to your Servo motor pin (GPIO_NUM_Y)
#define LED 12

// Create Servo object
Servo myServo;
LiquidCrystal_I2C mylcd(0x27,16,2);
music Music(25);

// Update Door state variables
bool isDoorOpen = false;
int doorOpenCount = 0;

// Update LED state variables
bool isLedOn = false;
int ledOnCount = 0;

// Update Door Bell state variables
int bellRingCount = 0;
bool isDoorBellRinging = false;

void setup() {
  mylcd.init();
  mylcd.backlight();
  pinMode(BUTTON_PIN_LEFT, INPUT_PULLUP);
  pinMode(BUTTON_PIN_RIGHT, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(25, OUTPUT);
  Music.Ode_to_Joy();
  myServo.attach(SERVO_PIN);
  myServo.write(0);
}

void loop() {

  // UpdateDoorState(BUTTON_PIN_RIGHT, myServo, isDoorOpen, doorOpenCount, mylcd);
  UpdateLEDState(BUTTON_PIN_LEFT, LED, isLedOn, ledOnCount, mylcd);

  UpdateDoorBellState(BUTTON_PIN_RIGHT, bellRingCount, mylcd, isDoorBellRinging, Music);
}

