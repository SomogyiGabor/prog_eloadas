#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

extern "C"
{
#include "LedDriver.h"
#include "RuntimeErrorStub.h"
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

TEST(LedDriver, TurnOffMultipleLeds)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(9);
	LedDriver_TurnOff(8);
	CHECK_EQUAL(~(0x0180) & 0xffff, virtualLeds);
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

TEST(LedDriver, AllOff)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnAllOff();
	CHECK_EQUAL(0x0000, virtualLeds);
}

TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	CHECK_EQUAL(0x0080, virtualLeds);
}

TEST(LedDriver, UpperAndLowerBounds)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	CHECK_EQUAL(0x8001, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOnDoesNotHarm)
{
	LedDriver_TurnOn(-1);
	LedDriver_TurnOn(0);
	LedDriver_TurnOn(17);
	LedDriver_TurnOn(3141);
	CHECK_EQUAL(0, virtualLeds);
}

TEST(LedDriver, OutOfBoundsTurnOffDoesNotHarm)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(-1);
	LedDriver_TurnOff(0);
	LedDriver_TurnOff(17);
	LedDriver_TurnOff(3141);
	CHECK_EQUAL(0xffff, virtualLeds);
}

IGNORE_TEST(LedDriver, OutOfBoundsProducesRuntimeError)
{
	// TODO What should we do during runtime?
}

TEST(LedDriver, IsOn)
{
	CHECK_FALSE(LedDriver_IsOn(11));
	LedDriver_TurnOn(11);
	CHECK_TRUE(LedDriver_IsOn(11));
}

TEST(LedDriver, OutOfBoundsLedsAreAlwaysOff)
{
	CHECK_FALSE(LedDriver_IsOn(0));
	CHECK_FALSE(LedDriver_IsOn(17));
	CHECK_TRUE(LedDriver_IsOff(0));
	CHECK_TRUE(LedDriver_IsOff(17));
}

TEST(LedDriver, IsOff)
{
	CHECK_TRUE(LedDriver_IsOff(7));
	LedDriver_TurnOn(7);
	CHECK_FALSE(LedDriver_IsOff(7));
}

int main(const int argc, const char* argv[])
{
	return CommandLineTestRunner::RunAllTests(argc, argv);
}
