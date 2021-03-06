#ifndef PUSHANDPOP_HPP
#define PUSHANDPOP_HPP 1

extern "C"
{
#include "CircularBuffer.h"
}

#include <CppUTest/TestHarness.h>

TEST_GROUP(PushAndPop)
{
};

IGNORE_TEST(PushAndPop, PushBeforeCreateIsInvalid)
{}

TEST(PushAndPop, PushAnElement)
{
	const int res = CircularBuffer_Push(3);
	CHECK_EQUAL(0, res);
}

TEST(PushAndPop, PopOneElement)
{
	CircularBuffer_Push(3);

	int poppedValue = 432;
	const int res = CircularBuffer_Pop(&poppedValue);
	CHECK_EQUAL(0, res);
	CHECK_EQUAL(3, poppedValue);
}

IGNORE_TEST(PushAndPop, PopIntoNullDoesNotCrash)
{}

#endif
