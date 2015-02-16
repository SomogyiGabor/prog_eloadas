#include <CppUTest/TestHarness.h>

TEST(sprintf, NoFormatOperations)
{
	char output[5] = "";
	memset(output, 0xaa, sizeof output);

	LONGS_EQUAL(3, sprintf(output, "hey"));
	STRCMP_EQUAL("hey", output);
	BYTES_EQUAL(0xaa, output[4]);
}

TEST(sprintf, InsertStringFormatOperation)
{
	char output[20] = "";
	memset(output, 0xaa, sizeof output);

	LONGS_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
	STRCMP_EQUAL("Hello World\n", output);
	BYTES_EQUAL(0xaa, output[13]);
}
