#include "velocityCalculation.h"

int velocityCalculation(int RPM) {
  int velocity = 0.1885 * RPM * 0.72;
  return velocity;
}

float totalDistanceCalculation(unsigned long totalPulses) {
  float totalDistance;
  totalDistance = ((totalPulses * 2.2619) / 1000);
  return totalDistance;
}
