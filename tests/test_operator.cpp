#include <cmath>

#include <vendor/catch2/catch.hpp>

#include <calcli/core/operator.hpp>


TEST_CASE("operator - binary operator plus", "[core]")
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double sum = calcli::binary_operation("+", x, y);
		const double sum_ref = x + y;

		REQUIRE(sum == Approx(sum_ref).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("operator - binary operator minus", "[core]")
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double diff = calcli::binary_operation("-", x, y);
		const double diff_ref = x - y;

		REQUIRE(diff == Approx(diff_ref).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("operator - binary operator product", "[core]")
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double prod = calcli::binary_operation("*", x, y);
		const double prod_ref = x * y;

		REQUIRE(prod == Approx(prod_ref).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("operator - binary operator divide", "[core]")
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double div = calcli::binary_operation("/", x, y);
		const double div_ref = x / y;

		REQUIRE(div == Approx(div_ref).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("operator - binary operator divide by zero", "[core]")
{
	try
	{
		const double x = 2.0;
		const double y = 0.0;
		const double div = calcli::binary_operation("/", x, y);
		const double div_ref = x / y;

		REQUIRE(div == Approx(div_ref).epsilon(0.01));
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"division by zero"};
		REQUIRE(str == str_ref);
	}
}

TEST_CASE("operator - binary operator is not defined", "[core]")
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double div = calcli::binary_operation(".", x, y);

		REQUIRE(div == 3.0);
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"binary operator is not defined"};
		REQUIRE(str == str_ref);
	}
}

TEST_CASE("operator - unary operator plus", "[core]")
{
	try
	{
		const double x = 2.0;
		const double px = calcli::unary_operation("+", x);

		REQUIRE(px == Approx(x).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("operator - unary operator minus", "[core]")
{
	try
	{
		const double x = 2.0;
		const double mx = calcli::unary_operation("-", x);

		REQUIRE(mx == Approx(-x).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("operator - unary operator is not defined", "[core]")
{
	try
	{
		const double x = 2.0;
		const double px = calcli::unary_operation("*", x);

		REQUIRE(px == 3.0);
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"unary operator is not defined"};
		REQUIRE(str == str_ref);
	}
}

TEST_CASE("operator - is_operator must return true", "[core]")
{
	REQUIRE(calcli::is_operator('+'));
	REQUIRE(calcli::is_operator('-'));
	REQUIRE(calcli::is_operator('*'));
	REQUIRE(calcli::is_operator('/'));
	REQUIRE(calcli::is_operator('^'));
}

TEST_CASE("operator - is_operator must return false", "[core]")
{
	REQUIRE(!calcli::is_operator('.'));
}
