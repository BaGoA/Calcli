#include <cmath>

#include <gtest/gtest.h>

#include <calcli/core/function.hpp>


TEST(test_function, apply_abs)
{
	try
	{
		const double x = -4.0;
		const double value = calcli::apply_function("abs", x);
		const double value_ref = std::abs(x);

		ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_function, apply_sqrt)
{
	try
	{
		const double x = 4.0;
		const double value = calcli::apply_function("sqrt", x);
		const double value_ref = std::sqrt(x);

		ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_function, apply_cos)
{
	try
	{
		const double x = 0.0;
		const double value = calcli::apply_function("cos", x);
		const double value_ref = std::cos(x);

		ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_function, apply_function_not_defined)
{
	try
	{
		const double x = 4.0;
		const double value = calcli::apply_function("bunny", x);
		const double value_ref = std::sqrt(x);

		ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"function is not defined"};
		ASSERT_EQ(str, str_ref);
	}
}
