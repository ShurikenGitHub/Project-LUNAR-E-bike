#include "rotaryEncoder.h"

int currentStateCLK;
int previousStateCLK;

void setPreviousState(byte CLKpin){
  previousStateCLK = digitalRead(CLKpin);
  }

int rotaryEncoder(int rotaryEncoderValue, byte CLKpin, byte DTpin) {
  currentStateCLK = digitalRead(CLKpin);

  if ( currentStateCLK != previousStateCLK ) {

    if (digitalRead(DTpin) != currentStateCLK) {
      rotaryEncoderValue --;
      if (rotaryEncoderValue < 0) {
        rotaryEncoderValue = 0;
      }
    }
    else {
      rotaryEncoderValue++;
      if (rotaryEncoderValue > 100) {
        rotaryEncoderValue = 100;
      }
    }
  }
  previousStateCLK = currentStateCLK;
  return rotaryEncoderValue;
}
