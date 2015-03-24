#ifndef CREATEANDDESTROY_HPP
#define CREATEANDDESTROY_HPP 1

extern "C"
{
#include "CircularBuffer.h"
}

#include <CppUTest/TestHarness.h>

TEST_GROUP(CreateAndDestroy)
{
};

TEST(CreateAndDestroy, CreateWithZeroSizeIsInvalid)
{
	const int res = CircularBuffer_Create(0);
	CHECK_EQUAL(-1, res);
}

TEST(CreateAndDestroy, DoubleCreateResets)
{
	const int firstResult = CircularBuffer_Create(10);
	CHECK_EQUAL(0, firstResult);

	const int secondResult = CircularBuffer_Create(10);
	CHECK_EQUAL(0, secondResult);
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

IGNORE_TEST(CreateAndDestroy, SecondInitializationClearsTheBuffer)
{}

#endif
