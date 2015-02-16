#include <CppUTest/TestHarness.h>

#include <stdio.h>
#include <string.h>

TEST_GROUP(sprintf)
{
	char output[100];
	const char* expected;

	TEST_SETUP()
	{
		memset(output, 0xaa, sizeof output);
		expected = "";
	}

	TEST_TEARDOWN()
	{
	}

	void expect(const char* s)
	{
		expected = s;
	}

	void given(int charsWritten)
	{
		LONGS_EQUAL(strlen(expected), charsWritten);
		STRCMP_EQUAL(expected, output);
		BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
	}
};

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
