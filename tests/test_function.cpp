#include <cmath>

#include <catch2/catch.hpp>

#include <calcli/core/function.hpp>


TEST_CASE("function - apply abs", "[core]")
{
	try
	{
		const double x = -4.0;
		const double value = calcli::apply_function("abs", x);
		const double value_ref = std::abs(x);

		REQUIRE(value == Approx(value_ref).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("function - apply sqrt", "[core]")
{
	try
	{
		const double x = 4.0;
		const double value = calcli::apply_function("sqrt", x);
		const double value_ref = std::sqrt(x);

		REQUIRE(value == Approx(value_ref).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("function - apply cos", "[core]")
{
	try
	{
		const double x = 0.0;
		const double value = calcli::apply_function("cos", x);
		const double value_ref = std::cos(x);

		REQUIRE(value == Approx(value_ref).epsilon(0.01));
	}
	catch(const std::exception&)
	{
		REQUIRE(false);
	}
}

TEST_CASE("function - apply function which is not defined", "[core]")
{
	try
	{
		const double x = 4.0;
		const double value = calcli::apply_function("bunny", x);
		const double value_ref = std::sqrt(x);

		REQUIRE(value == Approx(value_ref).epsilon(0.01));
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"function is not defined"};
		REQUIRE(str == str_ref);
	}
}
