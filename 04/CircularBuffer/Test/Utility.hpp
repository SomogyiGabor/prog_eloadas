#ifndef UTILITY_HPP
#define UTILITY_HPP 1

extern "C"
{
#include "CircularBuffer.h"
}

#include <CppUTest/TestHarness.h>

TEST_GROUP(Utility)
{
	TEST_SETUP()
	{
		CircularBuffer_Create(4);
	}

	TEST_TEARDOWN()
	{
		CircularBuffer_Destroy();
	}
};

TEST(Utility, NewlyCreatedIsEmpty)
{
	CHECK_TRUE(CircularBuffer_Empty());
}

TEST(Utility, NewlyCreatedIsNotFull)
{
	CHECK_FALSE(CircularBuffer_Full());
}

IGNORE_TEST(Utility, PushOneElementMakesBufferNotEmpty)
{}

IGNORE_TEST(Utility, FullBufferIsFull)
{}

#endif
