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
	Logic logic;

	TEST_SETUP()
	{
		logic = NEGALT;
		LedDriver_Create(&virtualLeds, logic);
	}

	TEST_TEARDOWN()
	{}

	void AssertVirtualLeds(uint16_t expectedState)
	{
		if (logic == PONALT)
		{
			CHECK_EQUAL(expectedState, virtualLeds);
		}
		else
		{
			CHECK_EQUAL(~expectedState & 0xffff, virtualLeds);
		}
	}
};

TEST(LedDriver, LedsOffAfterCreate)
{
	uint16_t virtualLeds = 0xffff;
	LedDriver_Create(&virtualLeds, PONALT);
	AssertVirtualLeds(0x0000);
}

TEST(LedDriver, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	AssertVirtualLeds(0x0001);
}

TEST(LedDriver, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	AssertVirtualLeds(0x0000);
}

TEST(LedDriver, TurnOnMultipleTests)
{
	LedDriver_TurnOn(9);
	LedDriver_TurnOn(8);

	AssertVirtualLeds(0x0180);
}

TEST(LedDriver, TurnOffMultipleLeds)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(9);
	LedDriver_TurnOff(8);
	AssertVirtualLeds(~(0x0180) & 0xffff);
}

TEST(LedDriver, TurnOffAnyLed)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(8);

	AssertVirtualLeds(0xff7f);
}

TEST(LedDriver, AllOn)
{
	LedDriver_TurnAllOn();
	AssertVirtualLeds(0xffff);
}

TEST(LedDriver, AllOff)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnAllOff();
	AssertVirtualLeds(0x0000);
}

TEST(LedDriver, LedMemoryIsNotReadable)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOn(8);
	AssertVirtualLeds(0x0080);
}

TEST(LedDriver, UpperAndLowerBounds)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOn(16);
	AssertVirtualLeds(0x8001);
}

TEST(LedDriver, OutOfBoundsTurnOnDoesNotHarm)
{
	LedDriver_TurnOn(-1);
	LedDriver_TurnOn(0);
	LedDriver_TurnOn(17);
	LedDriver_TurnOn(3141);
	AssertVirtualLeds(0);
}

TEST(LedDriver, OutOfBoundsTurnOffDoesNotHarm)
{
	LedDriver_TurnAllOn();
	LedDriver_TurnOff(-1);
	LedDriver_TurnOff(0);
	LedDriver_TurnOff(17);
	LedDriver_TurnOff(3141);
	AssertVirtualLeds(0xffff);
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
