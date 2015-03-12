#include "CircularBuffer.h"

int CircularBuffer_Create(const size_t numberOfElements)
{
	if (numberOfElements == 0)
		return -1;
	return 0;
}

void CircularBuffer_Destroy()
{}


int CircularBuffer_Push(const int element)
{
	return 0;
}

int CircularBuffer_Pop(int* element)
{
	*element = 3;
	return 0;
}
