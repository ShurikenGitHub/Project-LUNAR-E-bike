#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H
#include <Arduino.h>

int rotaryEncoder(int currentStateCLK, int previousStateCLK, int rotaryEncoderValue, byte CLKpin, byte DTpin);

#endif
