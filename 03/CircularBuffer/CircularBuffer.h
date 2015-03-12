#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H 1

#include <stddef.h>

int CircularBuffer_Create(const size_t numberOfElements);
void CircularBuffer_Destroy();

int CircularBuffer_Push(const int element);
int CircularBuffer_Pop(int* element);

#endif
