#ifndef RUNTIMEERRORSTUB_H
#define RUNTIMEERRORSTUB_H 1

#include "RuntimeError.h"

void RuntimeErrorStub_Reset();
const char* RuntimeErrorStub_GetLastError();
int RuntimeErrorStub_GetLastParameter();

#endif
