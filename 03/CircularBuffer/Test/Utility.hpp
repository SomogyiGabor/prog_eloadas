#ifndef UTILITY_HPP
#define UTILITY_HPP 1

extern "C"
{
#include "CircularBuffer.h"
}

#include <CppUTest/TestHarness.h>

TEST_GROUP(Utility)
{};

TEST(Utility, NewlyCreatedIsEmpty)
{
	CircularBuffer_Create(10);
	CHECK_TRUE(CircularBuffer_Empty());
}

TEST(Utility, NewlyCreatedIsNotFull)
{
	CircularBuffer_Create(10);
	CHECK_FALSE(CircularBuffer_Full());
}

#endif
