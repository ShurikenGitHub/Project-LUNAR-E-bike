#ifndef RPMCALCULATION_H
#define RPMCALCULATION_H
#include <Arduino.h>

extern unsigned long totalPulses;

int RPMCalculation(unsigned long currentMicros);
void Pulse_Event();
//unsigned int returnTotal();
#endif
