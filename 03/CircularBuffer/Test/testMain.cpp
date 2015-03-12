#include <CppUTest/CommandLineTestRunner.h>

#include "CreateAndDestroy.hpp"
#include "PushAndPop.hpp"
#include "Utility.hpp"

int main(const int argc, const char* argv[])
{
	return CommandLineTestRunner::RunAllTests(argc, argv);
}
