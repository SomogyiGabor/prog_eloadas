#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

extern "C"
{
#include "LedDriver.h"
}

TEST_GROUP(LedDriver)
{
	uint16_t virtualLeds;

	TEST_SETUP()
	{
		LedDriver_Create(&virtualLeds);
	}

	TEST_TEARDOWN()
	{}
};

TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds);
	CHECK_EQUAL(0x0000, virtualLeds);
}

TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	CHECK_EQUAL(0x0001, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	CHECK_EQUAL(0x0000, virtualLeds);
}

TEST(LedDriver, TurnOnMultipleTests)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);

	CHECK_EQUAL(0x180, virtualLeds);
}

TEST(LedDriver, TurnOffAnyLed)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);

	CHECK_EQUAL(0xff7f, virtualLeds);
}

TEST(LedDriver, AllOn)
{
	LedDriver_TurnAllOn();
	CHECK_EQUAL(0xffff, virtualLeds);
}

TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	CHECK_EQUAL(0x0080, virtualLeds);
}

int main(const int argc, const char* argv[])
{
	return CommandLineTestRunner::RunAllTests(argc, argv);
}
