#include <CppUTest/TestHarness.h>

TEST(sprintf, NoFormatOperations)
{
	char output[5] = "";

	LONGS_EQUAL(3, sprintf(output, "hey"));
	STRCMP_EQUAL("hey", output);
}

TEST(sprintf, InsertStringFormatOperation)
{
	char output[20] = "";

	LONGS_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
	STRCMP_EQUAL("Hello World\n", output);
}
