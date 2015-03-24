#ifndef UTILITY_HPP
#define UTILITY_HPP 1

extern "C"
{
#include "CircularBuffer.h"
}

#include <CppUTest/TestHarness.h>

TEST_GROUP(Utility)
{
	static const int BUFFER_SIZE = 4;
	TEST_SETUP()
	{
		CircularBuffer_Create(BUFFER_SIZE);
	}

	TEST_TEARDOWN()
	{
		CircularBuffer_Destroy();
	}

protected:
	void MakeBufferFull()
	{
		for(int i = 0; i < 4; ++i)
			CircularBuffer_Push(i);
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

TEST(Utility, PushOneElementMakesBufferNotEmpty)
{
	CircularBuffer_Push(2);
	CHECK_FALSE(CircularBuffer_Empty());
}

TEST(Utility, FullBufferIsFull)
{
	MakeBufferFull();
	CHECK_TRUE( CircularBuffer_Full() );
}

#endif
