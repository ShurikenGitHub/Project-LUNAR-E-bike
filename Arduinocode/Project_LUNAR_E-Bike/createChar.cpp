#include "createChar.h"

void createChar(){

byte k[] = {
  0x08,
  0x0A,
  0x0C,
  0x0A,
  0x0A,
  0x00,
  0x00,
  0x00
};

byte ph[] = {
  0x1C,
  0x14,
  0x1C,
  0x10,
  0x15,
  0x07,
  0x05,
  0x05
};

byte km[] = {
  0x08,
  0x0A,
  0x0C,
  0x0A,
  0x11,
  0x1B,
  0x15,
  0x11
};
  lcd.createChar(1, k);
  lcd.createChar(2, ph);
  lcd.createChar(3, km);
  }