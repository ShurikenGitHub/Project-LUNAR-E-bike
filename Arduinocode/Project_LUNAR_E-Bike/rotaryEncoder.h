#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H
#include <Arduino.h>

int rotaryEncoder(int rotaryEncoderValue, byte CLKpin, byte DTpin, byte buttonPin);
void setPreviousState(byte CLKpin);
#endif
