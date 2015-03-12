#include <CppUTest/CommandLineTestRunner.h>

#include "CreateAndDestroy.hpp"

int main(const int argc, const char* argv[])
{
	return CommandLineTestRunner::RunAllTests(argc, argv);
}
