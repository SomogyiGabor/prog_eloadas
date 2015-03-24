#include "CircularBuffer.h"

static int* itsBuffer;
static size_t itsUsed;

int CircularBuffer_Create(const size_t numberOfElements)
{
	static int a;

	if (numberOfElements == 0)
		return -1;

	itsUsed = 0;
	itsBuffer = &a;

	return 0;
}

void CircularBuffer_Destroy()
{
	itsBuffer = NULL;
	itsUsed = 0;
}


int CircularBuffer_Push(const int element)
{
	if (itsBuffer == NULL)
		return -1;

	itsUsed++;
	return 0;
}

int CircularBuffer_Pop(int* element)
{
	if (itsBuffer == NULL)
		return -1;

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
