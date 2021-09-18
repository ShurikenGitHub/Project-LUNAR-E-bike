#include "RPMCalculation.h"

const byte pulsesPerRevolution = 1;
const unsigned long zeroTimeout = 3000000;
const byte numReadings = 2;
volatile unsigned long lastTimeWeMeasured;
volatile unsigned long periodBetweenPulses = zeroTimeout + 1000;
volatile unsigned long periodAverage = zeroTimeout + 1000;
unsigned long frequencyRaw;
unsigned long frequencyReal;
unsigned long pulseCounter = 1;
unsigned long lastTimeCycleMeasure = lastTimeWeMeasured;
unsigned int zeroDebouncingExtra;
unsigned long average;
unsigned long total;
unsigned long readings[numReadings];
unsigned long readIndex;
unsigned long periodSum;
unsigned int amountOfReadings = 1;

int RPMCalculation(unsigned long currentMicros) {

  unsigned long RPM;
  lastTimeCycleMeasure = lastTimeWeMeasured;
  currentMicros = micros();
  if (currentMicros < lastTimeCycleMeasure)
  {
    lastTimeCycleMeasure = currentMicros;
  }
  frequencyRaw = 10000000000 / periodAverage;
  if (periodBetweenPulses > zeroTimeout - zeroDebouncingExtra || currentMicros - lastTimeCycleMeasure > zeroTimeout - zeroDebouncingExtra)
  {
    frequencyRaw = 0;
    zeroDebouncingExtra = 2000;
  }
  else {
    zeroDebouncingExtra = 0;
  }

  frequencyReal = frequencyRaw / 10000;
  RPM = frequencyRaw / pulsesPerRevolution * 60;
  RPM = RPM / 10000;
  total = total - readings[readIndex];
  readings[readIndex] = RPM;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex >= numReadings)
  {
    readIndex = 0;
  }
  average = total / numReadings;
  return RPM;
}

void Pulse_Event()
{

  periodBetweenPulses = micros() - lastTimeWeMeasured;
  lastTimeWeMeasured = micros();
  if (pulseCounter >= amountOfReadings)
  {
    periodAverage = periodSum / amountOfReadings;
    pulseCounter = 1;
    periodSum = periodBetweenPulses;
    int remapedAmountOfReadings = map(periodBetweenPulses, 40000, 5000, 1, 10);
    remapedAmountOfReadings = constrain(remapedAmountOfReadings, 1, 10);
    amountOfReadings = remapedAmountOfReadings;
  }
  else
  {
    pulseCounter++;

    periodSum = periodSum + periodBetweenPulses;
  }
  totalPulses++;
}
