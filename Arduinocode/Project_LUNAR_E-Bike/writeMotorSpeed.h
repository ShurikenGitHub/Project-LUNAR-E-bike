#ifndef WRITEMOTORSPEED_H
#define WRITEMOTORSPEED_H
#include <Arduino.h>
#include <Servo.h>
extern Servo motor;

void calibrateESC(byte motorPin, int minSignal, int maxSignal);
void writeMotorSpeed(int rotaryEncoderValue, int minSignal, int maxSignal);
#endif
