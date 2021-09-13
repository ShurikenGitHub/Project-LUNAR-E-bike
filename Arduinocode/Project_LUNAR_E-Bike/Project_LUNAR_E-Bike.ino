//Project LUNAR E-bike
//ShurikenGitHub
//Version 0.1

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "displayPrint.h"
#include "rotaryEncoder.h"

#define CLKpin 4
#define DTpin 5

int rotaryEncoderValue = 0;
int currentStateCLK;
int previousStateCLK;

long displayRefreshTime = 500;
unsigned long previousMillis = 0;

LiquidCrystal_I2C lcd(0x3F,20,4);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  pinMode (CLKpin, INPUT);
  pinMode (DTpin, INPUT);
  Serial.begin (9600);
  previousStateCLK = digitalRead(CLKpin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= displayRefreshTime){
    displayPrint(rotaryEncoderValue);
    previousMillis = currentMillis;
  }
  rotaryEncoderValue = rotaryEncoder(currentStateCLK, previousStateCLK, rotaryEncoderValue, CLKpin, DTpin);
}
