#ifndef LEDDRIVER_H
#define LEDDRIVER_H 1

#include <stdint.h>

void LedDriver_Create(uint16_t* address);

void LedDriver_TurnOn(int ledNumber);

#endif
