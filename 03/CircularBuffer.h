#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H 1

struct CircularBufferStruct;
typedef struct CircularBufferStruct* CircularBuffer;

int CircularBuffer_Push(CircularBuffer self, int valueToPush);
int CircularBuffer_Pop(CircularBuffer self, int* poppedValue);

#endif
