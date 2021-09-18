#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H
#include <Arduino.h>

int rotaryEncoder(int rotaryEncoderValue, byte CLKpin, byte DTpin);
void setPreviousState(byte CLKpin);
#endif
