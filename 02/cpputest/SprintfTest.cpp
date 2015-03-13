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
	expect("hey");
	given(sprintf(output, "hey"));
}

TEST(sprintf, InsertStringFormatOperation)
{
	expect("Hello World\n");
	given(sprintf(output, "Hello %s\n", "World"));
}
