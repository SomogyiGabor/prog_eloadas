#include "RuntimeErrorStub.h"

static const char* message = "No Error";
static int parameter = -1;
const char* file = 0;
static int line = -1;

void RuntimeErrorStub_Reset()
{
	message = "No Error";
	parameter = -1;
}

const char* RuntimeErrorStub_GetLastError()
{
	return message;
}

int RuntimeErrorStub_GetLastParameter()
{
	return parameter;
}


void RuntimeError(const char* aMessage,
		  int aParameter,
		  const char* aFile,
		  int aLine)
{
	message = aMessage;
	parameter = aParameter;
	file = aFile;
	line = aLine;
}
