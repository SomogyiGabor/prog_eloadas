#ifndef PUSHANDPOP_HPP
#define PUSHANDPOP_HPP 1

extern "C"
{
#include "CircularBuffer.h"
}

#include <CppUTest/TestHarness.h>

TEST_GROUP(PushAndPop)
{
	static const int BUFFER_SIZE = 10;

	TEST_SETUP()
	{
		CircularBuffer_Create(BUFFER_SIZE);
	}

	TEST_TEARDOWN()
	{
		CircularBuffer_Destroy();
	}
};

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

TEST(PushAndPop, PushAndPopManyElements)
{
	CircularBuffer_Push(1);
	CircularBuffer_Push(2);
	CircularBuffer_Push(3);

	int poppedElement = 0;

	CircularBuffer_Pop(&poppedElement);
	CHECK_EQUAL(1, poppedElement);

	CircularBuffer_Pop(&poppedElement);
	CHECK_EQUAL(2, poppedElement);

	CircularBuffer_Pop(&poppedElement);
	CHECK_EQUAL(3, poppedElement);
}

TEST(PushAndPop, PopIntoNullDoesNotCrash)
{
	CircularBuffer_Push(11);

	const int res = CircularBuffer_Pop(NULL);
	CHECK_EQUAL(-1, res);

	CHECK_FALSE(CircularBuffer_Empty());
}

TEST(PushAndPop, PushIntoFullRaisesAnError)
{
	for (int i = 0; i < BUFFER_SIZE; ++i)
	{
		const int res = CircularBuffer_Push(3 + i);
		CHECK_EQUAL(0, res);
	}

	const int res = CircularBuffer_Push(11);
	CHECK_EQUAL(-1, res);
}

TEST(PushAndPop, PopFromEmptyRaisesAnError)
{
	int poppedElement = 11;
	const int res = CircularBuffer_Pop(&poppedElement);
	CHECK_EQUAL(-1, res);
}

IGNORE_TEST(PushAndPop, PushAndPopAroundTheBoundary)
{}

#endif
