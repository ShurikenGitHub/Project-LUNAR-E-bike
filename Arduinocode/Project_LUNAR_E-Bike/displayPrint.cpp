#include "displayPrint.h"

void displayPrint(int rotaryEncoderValue){
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
  }
