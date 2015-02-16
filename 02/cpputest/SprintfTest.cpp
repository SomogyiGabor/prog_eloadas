#include <CppUTest/TestHarness.h>

TEST(sprintf, NoFormatOperations)
{
	char output[5] = "";

	LONGS_EQUAL(3, sprintf(output, "hey"));
	STRCMP_EQUAL("hey", output);
}
