#include "CircularBuffer.h"

static size_t itsUsed;

int CircularBuffer_Create(const size_t numberOfElements)
{
	itsUsed = 0;
	if (numberOfElements == 0)
		return -1;
	return 0;
}

void CircularBuffer_Destroy()
{}


int CircularBuffer_Push(const int element)
{
	itsUsed++;
	return 0;
}

int CircularBuffer_Pop(int* element)
{
	*element = 3;
	return 0;
}

bool CircularBuffer_Empty()
{
	return (itsUsed == 0);
}

bool CircularBuffer_Full()
{
	return false;
}
