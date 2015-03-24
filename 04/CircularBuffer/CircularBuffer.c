#include "CircularBuffer.h"

#include <stdlib.h>

static int* itsBuffer;
static size_t itsUsed;
static size_t itsWriteIndex;
static size_t itsReadIndex;

int CircularBuffer_Create(const size_t numberOfElements)
{
	if (numberOfElements == 0)
		return -1;

	if (itsBuffer != NULL)
		CircularBuffer_Destroy();

	itsBuffer = calloc(numberOfElements, sizeof(int));
	if (itsBuffer == NULL)
		return -1;

	itsUsed = 0;
	itsWriteIndex = 0;
	itsReadIndex = 0;

	return 0;
}

void CircularBuffer_Destroy()
{
	free(itsBuffer);
	itsBuffer = NULL;
	itsUsed = 0;
}


int CircularBuffer_Push(const int element)
{
	if (itsBuffer == NULL)
		return -1;

	itsBuffer[itsWriteIndex] = element;

	itsWriteIndex++;
	itsUsed++;

	return 0;
}

int CircularBuffer_Pop(int* element)
{
	if (itsBuffer == NULL)
		return -1;

	if (element == NULL)
		return -1;

	*element = itsBuffer[itsReadIndex];
	itsReadIndex++;

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
