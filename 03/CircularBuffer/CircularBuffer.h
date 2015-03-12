#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H 1

#include <stddef.h>

int CircularBuffer_Create(const size_t numberOfElements);
void CircularBuffer_Destroy();

#endif
