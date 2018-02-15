#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>





int calculator(const std::string & s)
{
	if (s == "")
	{
		return 0;
	}

	int i = 0;
	int sum = 0;
	while (isdigit(s[i]))
	{
		sum = 10 * sum + (int)(s[i] - '0');
		i++;
	}

	return sum;
}



TEST_CASE("NULL STRING TEST", "[NULL]")
{
	REQUIRE(calculator("") == 0);
}

TEST_CASE("Single Digit", "[Single Digit]")
{
	REQUIRE(calculator("5") == 5);
	REQUIRE(calculator("0") == 0);
	REQUIRE(calculator("9") == 9);
}