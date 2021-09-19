//Project LUNAR E-bike
//ShurikenGitHub
//Version 0.1

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include "displayPrint.h"
#include "rotaryEncoder.h"
#include "RPMCalculation.h"
#include "velocityCalculation.h"
#include "createChar.h"
#include "writeMotorSpeed.h"

#define maxSignal 2400
#define minSignal 900
#define motorPin 9
#define CLKpin 4
#define DTpin 5
#define buttonPin 6

int rotaryEncoderValue = 0;
long displayRefreshTime = 500;
unsigned long previousMillis = 0;
int RPM = 0;
int velocity = 0;
unsigned long totalPulses = 0;
float totalDistance = 0;

LiquidCrystal_I2C lcd(0x3F, 20, 4);
Servo motor;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.print("Initializing...");
  pinMode (CLKpin, INPUT);
  pinMode (DTpin, INPUT);
  pinMode (buttonPin, INPUT_PULLUP);
  createChar();
  attachInterrupt(digitalPinToInterrupt(2), Pulse_Event, RISING);
  setPreviousState(CLKpin);
  Serial.begin (9600);
  calibrateESC(motorPin, minSignal, maxSignal);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  unsigned long currentMicros = micros();
  if (currentMillis - previousMillis >= displayRefreshTime) {
    displayPrint(rotaryEncoderValue, RPM, velocity, totalDistance);
    previousMillis = currentMillis;
  }
  rotaryEncoderValue = rotaryEncoder(rotaryEncoderValue, CLKpin, DTpin, buttonPin);
  writeMotorSpeed(rotaryEncoderValue, minSignal, maxSignal);
  RPM = RPMCalculation(currentMicros);
  velocity = velocityCalculation(RPM);
  totalDistance = totalDistanceCalculation(totalPulses);

}
