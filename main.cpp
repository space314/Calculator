#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>





int calculator(const std::string & s)
{
	if (s == "")
	{
		return 0;
	}

	std::string delim;

	int i = 0;
	int sum = 0;
	while (isdigit(s[i]))
	{
		sum = 10 * sum + (int)(s[i] - '0');
		i++;
	}
	if (s[i] == '-') 
		throw std::exception("negative value in calculator function");
	if (sum > 1000)
		sum = 0;
	if (s[i] == ',' || s[i] == '\n') 
		return calculator(s.substr(i + 1, s.size())) + sum;

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

TEST_CASE("Multiple numbers delimited by comma")
{
	REQUIRE(calculator("1,2") == 3);
	REQUIRE(calculator("100,26") == 126);
	REQUIRE(calculator("120,60,20") == 200);
}

TEST_CASE("Multiple numbers delimited by new line")
{
	REQUIRE(calculator("1\n2") == 3);
	REQUIRE(calculator("100\n26") == 126);
	REQUIRE(calculator("120\n60\n20") == 200);
}

TEST_CASE("Negative throws exception")
{
	bool flag;
	try
	{
		calculator("-1");
		flag = false;
	}
	catch (...)
	{
		flag = true;
	}
	REQUIRE(flag == true);
	try
	{
		calculator("10,-1");
		flag = false;
	}
	catch (...)
	{
		flag = true;
	}
	REQUIRE(flag == true);
}

TEST_CASE("Values greater than 1000 are ignored")
{
	REQUIRE(calculator("1001") == 0);
	REQUIRE(calculator("1001,1") == 1);
}

TEST_CASE("Defined delim")
{
	REQUIRE(calculator("//t3,4t3") == (3 + 4 + 3));
}