#include "displayPrint.h"

void displayPrint(int rotaryEncoderValue, unsigned long RPM){
  lcd.clear();
  if(rotaryEncoderValue < 10){
    lcd.setCursor(2, 0);
  }
  if(rotaryEncoderValue < 100 && rotaryEncoderValue >= 10){
    lcd.setCursor(1, 0);
  }
  if(rotaryEncoderValue == 100){
    lcd.setCursor(0, 0);
  }
  lcd.print(rotaryEncoderValue);
  lcd.setCursor(3, 0);
  lcd.print("%");

  if(RPM < 10){
    lcd.setCursor(8, 0);
  }
  if(RPM < 100 && RPM >= 10){
    lcd.setCursor(7, 0);
  }
  if(RPM > 100){
    lcd.setCursor(5, 0);
  }
  lcd.print(RPM);
  }
