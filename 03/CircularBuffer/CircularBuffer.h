#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H 1

#include <stddef.h>
#include <stdbool.h>

int CircularBuffer_Create(const size_t numberOfElements);
void CircularBuffer_Destroy();

int CircularBuffer_Push(const int element);
int CircularBuffer_Pop(int* element);

bool CircularBuffer_Empty();
bool CircularBuffer_Full();

#endif
