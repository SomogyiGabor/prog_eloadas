#ifndef CREATEANDDESTROY_HPP
#define CREATEANDDESTROY_HPP 1

extern "C"
{
#include "CircularBuffer.h"
}

#include <CppUTest/TestHarness.h>
#include <CppUTest/TestHarness_c.h>

TEST_GROUP(CreateAndDestroy)
{
};

TEST(CreateAndDestroy, CreateWithZeroSizeIsInvalid)
{
	const int res = CircularBuffer_Create(0);
	CHECK_EQUAL(-1, res);
}

TEST(CreateAndDestroy, FailingMemoryAllocationAborts)
{
	cpputest_malloc_set_out_of_memory();
	const int res = CircularBuffer_Create(10);
	CHECK_EQUAL(-1, res);
	cpputest_malloc_set_not_out_of_memory();
}

TEST(CreateAndDestroy, DoubleCreateResets)
{
	const int firstResult = CircularBuffer_Create(10);
	CHECK_EQUAL(0, firstResult);

	const int secondResult = CircularBuffer_Create(10);
	CHECK_EQUAL(0, secondResult);

	CircularBuffer_Destroy();
}

TEST(CreateAndDestroy, RegularDestroy)
{
	CircularBuffer_Create(10);
	CircularBuffer_Destroy();
}

TEST(CreateAndDestroy, DestroyBeforeCreateDoesNotCrash)
{
	CircularBuffer_Destroy();
}

TEST(CreateAndDestroy, DoubleDestroyDoesNotCrash)
{
	CircularBuffer_Create(10);
	CircularBuffer_Destroy();
	CircularBuffer_Destroy();
}

TEST(CreateAndDestroy, SecondInitializationClearsTheBuffer)
{
	CircularBuffer_Create(10);
	CircularBuffer_Push(33);
	CHECK_FALSE(CircularBuffer_Empty());

	CircularBuffer_Create(10);
	CHECK_TRUE(CircularBuffer_Empty());

	CircularBuffer_Destroy();
}

TEST(CreateAndDestroy, PushBeforeCreateIsInvalid)
{
	const int pushResult = CircularBuffer_Push(3);
	CHECK_EQUAL(-1, pushResult);

	int poppedElement;
	const int popResult = CircularBuffer_Pop(&poppedElement);
	CHECK_EQUAL(-1, popResult);
}

#endif