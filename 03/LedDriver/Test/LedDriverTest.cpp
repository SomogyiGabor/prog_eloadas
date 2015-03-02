#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>

TEST_GROUP(LedDriver)
{
	TEST_SETUP()
	{}

	TEST_TEARDOWN()
	{}
};

TEST(LedDriver, LedsOffAfterCreate)
{
	FAIL("Start here");
}

int main(const int argc, const char* argv[])
{
	return CommandLineTestRunner::RunAllTests(argc, argv);
}
