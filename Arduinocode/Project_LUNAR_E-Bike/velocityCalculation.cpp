#include "velocityCalculation.h"

int velocityCalculation(int RPM){
  int velocity = 0.1885*RPM*0.72;

  return velocity;
  }

float totalDistanceCalculation(unsigned long totalPulses){
  float totalDistance;
  Serial.println(totalPulses);
  totalDistance = ((totalPulses*2.2619)/1000);
  Serial.println(totalDistance);
  return totalDistance;
  }
