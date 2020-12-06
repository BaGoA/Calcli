#include <cmath>

#include <gtest/gtest.h>

#include <calcli/core/operator.hpp>


TEST(test_operator, binary_operator_plus)
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double sum = calcli::binary_operation("+", x, y);
		const double sum_ref = x + y;

		ASSERT_NEAR(sum, sum_ref, 0.01 * std::abs(sum_ref));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_operator, binary_operator_minus)
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double diff = calcli::binary_operation("-", x, y);
		const double diff_ref = x - y;

		ASSERT_NEAR(diff, diff_ref, 0.01 * std::abs(diff_ref));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_operator, binary_operator_product)
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double prod = calcli::binary_operation("*", x, y);
		const double prod_ref = x * y;

		ASSERT_NEAR(prod, prod_ref, 0.01 * std::abs(prod_ref));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_operator, binary_operator_divide)
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double div = calcli::binary_operation("/", x, y);
		const double div_ref = x / y;

		ASSERT_NEAR(div, div_ref, 0.01 * std::abs(div_ref));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_operator, binary_operator_divide_by_zero)
{
	try
	{
		const double x = 2.0;
		const double y = 0.0;
		const double div = calcli::binary_operation("/", x, y);
		const double div_ref = x / y;

		ASSERT_NEAR(div, div_ref, 0.01 * std::abs(div_ref));
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"division by zero"};
		ASSERT_EQ(str, str_ref);
	}
}

TEST(test_operator, binary_operator_is_not_defined)
{
	try
	{
		const double x = 2.0;
		const double y = 3.0;
		const double div = calcli::binary_operation(".", x, y);

		ASSERT_TRUE(div == 3.0);
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"binary operator is not defined"};
		ASSERT_EQ(str, str_ref);
	}
}

TEST(test_operator, unary_operator_plus)
{
	try
	{
		const double x = 2.0;
		const double px = calcli::unary_operation("+", x);

		ASSERT_NEAR(px, x, 0.01 * std::abs(x));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_operator, unary_operator_minus)
{
	try
	{
		const double x = 2.0;
		const double mx = calcli::unary_operation("-", x);

		ASSERT_NEAR(mx, -x, 0.01 * std::abs(x));
	}
	catch(const std::exception&)
	{
		ASSERT_TRUE(false);
	}
}

TEST(test_operator, unary_operator_is_not_defined)
{
	try
	{
		const double x = 2.0;
		const double px = calcli::unary_operation("*", x);

		ASSERT_TRUE(px == 3.0);
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"unary operator is not defined"};
		ASSERT_EQ(str, str_ref);
	}
}
