#ifndef STRCATTEST_HPP
#define STRCATTEST_HPP 1

#include <CppUTest/TestHarness.h>

#include <string.h>

TEST_GROUP(strcat)
{
};

TEST(strcat, ReturningPointerToDestination)
{
	char dest[20] = "";

	const char* returnedString = strcat(dest, "");
	POINTERS_EQUAL(dest, returnedString);
}

TEST(strcat, TwoEmptyStringsMakesEmptyString)
{
	char dest[20] = "";
	strcat(dest, "");
	STRCMP_EQUAL("", dest);
}

TEST(strcat, AddingEmptyDoesNotChange)
{
	char dest[20] = "alma";
	strcat(dest, "");
	STRCMP_EQUAL("alma", dest);
}

TEST(strcat, AddingToEmpty)
{
	char dest[20] = "";
	strcat(dest, "fa");
	STRCMP_EQUAL("fa", dest);
}

TEST(strcat, AddingTwoNonEmpty)
{
	char dest[20] = "alma";
	const char* src = "fa";

	const char* returnedString = strcat(dest, src);
	POINTERS_EQUAL(dest, returnedString);
	STRCMP_EQUAL("almafa", dest);
}

TEST(strcat, ShouldNotOverrun)
{
	char dest[20];
	memset(dest, 0xaa, sizeof(dest));

	dest[0] = 0;
	strcat(dest, "valami");
	BYTES_EQUAL(0xaa, dest[strlen("valami") + 1]);
}

TEST(strcat, ShouldNotUnderrun)
{
	char dest[20];
	memset(dest, 0xaa, sizeof(dest));

	dest[1] = 0;
	strcat(&dest[1], "valami");
	BYTES_EQUAL(0xaa, dest[0]);

}

#endif
