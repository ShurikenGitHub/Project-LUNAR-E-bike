//Project LUNAR E-bike
//ShurikenGitHub
//Version 0.1

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "displayPrint.h"
#include "rotaryEncoder.h"
#include "RPMCalculation.h"

#define CLKpin 4
#define DTpin 5

int rotaryEncoderValue = 0;
long displayRefreshTime = 500;
unsigned long previousMillis = 0;
int printRPM = 0;

LiquidCrystal_I2C lcd(0x3F,20,4);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  pinMode (CLKpin, INPUT);
  pinMode (DTpin, INPUT);
  Serial.begin (9600);
  attachInterrupt(digitalPinToInterrupt(2), Pulse_Event, RISING);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= displayRefreshTime){
    displayPrint(rotaryEncoderValue, printRPM);
    previousMillis = currentMillis;
  }
  rotaryEncoderValue = rotaryEncoder(rotaryEncoderValue, CLKpin, DTpin);
  printRPM = RPMCalculation();
}
