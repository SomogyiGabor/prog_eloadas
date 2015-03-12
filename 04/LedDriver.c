#include "LedDriver.h"
#include "RuntimeError.h"

static uint16_t* ledsAddress;
static uint16_t ledsImage;

enum{ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
enum{FIRST_LED = 1, LAST_LED = 16};

static BOOL IsLedOutOfBounds(int ledNumber)
{
	return (ledNumber < FIRST_LED) || (ledNumber > LAST_LED);
}

static void updateHardware()
{
	*ledsAddress = ledsImage;
}

void LedDriver_Create(uint16_t* address)
{
	ledsAddress = address;
	ledsImage = ALL_LEDS_OFF;
	updateHardware();
}

static uint16_t convertLedNumberToBit(int ledNumber)
{
	return 1 << (ledNumber - 1);
}

static void setLedImageBit(int ledNumber)
{
	ledsImage |= convertLedNumberToBit(ledNumber);
}
void LedDriver_TurnOn(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return;

	setLedImageBit(ledNumber);
	updateHardware();
}

static void clearLedImageBit(int ledNumber)
{
	ledsImage &= ~convertLedNumberToBit(ledNumber);
}
void LedDriver_TurnOff(int ledNumber)
{
	if (IsLedOutOfBounds(ledNumber))
		return;

	clearLedImageBit(ledNumber);
	updateHardware();
}

void LedDriver_TurnAllOn()
{
	ledsImage = ALL_LEDS_ON;
	updateHardware();
}

BOOL LedDriver_IsOn(int ledNumber)
{
	return ledsImage & (convertLedNumberToBit(ledNumber));
}
