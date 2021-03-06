#ifndef LEDDRIVER_H
#define LEDDRIVER_H 1

#include <stdint.h>

enum BOOL{FALSE = 0, TRUE = 1};
typedef enum BOOL BOOL;

void LedDriver_Create(uint16_t* address);

void LedDriver_TurnOn(int ledNumber);
void LedDriver_TurnOff(int ledNumber);

void LedDriver_TurnAllOn();
void LedDriver_TurnAllOff();

BOOL LedDriver_IsOn(int ledNumber);
BOOL LedDriver_IsOff(int ledNumber);

#endif
