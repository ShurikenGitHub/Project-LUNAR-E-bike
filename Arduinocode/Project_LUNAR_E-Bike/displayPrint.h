#ifndef DISPLAYPRINT_H
#define DISPLAYPRINT_H
#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

void displayPrint(int rotaryEncoderValue, unsigned long RPM);

#endif
