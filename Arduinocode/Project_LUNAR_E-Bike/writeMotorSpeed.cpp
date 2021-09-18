#include "writeMotorSpeed.h"

void calibrateESC(byte motorPin, int minSignal, int maxSignal){
  delay(2500);
  motor.attach(motorPin);
  motor.writeMicroseconds(maxSignal);
  delay(2000);
  motor.writeMicroseconds(minSignal);
  }

void writeMotorSpeed(int rotaryEncoderValue, int minSignal, int maxSignal) {
  int setSpeed = 900;
  setSpeed = map(rotaryEncoderValue, 0, 100, minSignal, maxSignal);
  motor.writeMicroseconds(setSpeed);
}
