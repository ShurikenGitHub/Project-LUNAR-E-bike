#include "displayPrint.h"

void displayPrint(int rotaryEncoderValue, unsigned long RPM, int velocity, float totalDistance) {
  lcd.clear();
  if (rotaryEncoderValue < 10) {
    lcd.setCursor(9, 0);
  }
  if (rotaryEncoderValue < 100 && rotaryEncoderValue >= 10) {
    lcd.setCursor(8, 0);
  }
  if (rotaryEncoderValue == 100) {
    lcd.setCursor(7, 0);
  }
  lcd.print(rotaryEncoderValue);
  lcd.setCursor(10, 0);
  lcd.print("%");

  if (RPM < 10) {
    lcd.setCursor(3, 1);
  }
  if (RPM < 100 && RPM >= 10) {
    lcd.setCursor(2, 1);
  }
  if (RPM < 1000 && RPM >= 100) {
    lcd.setCursor(1, 1);
  }
  if (RPM > 1000) {
    lcd.setCursor(0, 1);
  }
  lcd.print(RPM);

  if (velocity < 10) {
    lcd.setCursor(2, 0);
  }
  if (velocity < 100 && velocity >= 10) {
    lcd.setCursor(1, 0);
  }
  if (velocity >= 100) {
    lcd.setCursor(0, 0);
  }
  lcd.print(velocity, DEC);
  lcd.setCursor(3, 0);
  lcd.write(1);
  lcd.setCursor(4, 0);
  lcd.write(2);

  lcd.setCursor(12, 0);
  lcd.print(totalDistance);
  lcd.setCursor(15, 0);
  lcd.write(3);
}
