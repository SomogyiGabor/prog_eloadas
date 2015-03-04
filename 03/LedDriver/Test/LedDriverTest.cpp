#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

extern "C"
{
#include "LedDriver.h"
}

TEST_GROUP(LedDriver)
{
	TEST_SETUP()
	{}

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
	uint16_t virtualLeds;
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	CHECK_EQUAL(0x0001, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
	uint16_t virtualLeds;
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	CHECK_EQUAL(0x0000, virtualLeds);
}

int main(const int argc, const char* argv[])
{
	return CommandLineTestRunner::RunAllTests(argc, argv);
}
