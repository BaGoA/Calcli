#include <cmath>

#include <gtest/gtest.h>

#include <calcli/core/evaluator.hpp>


TEST(test_evaluator, postfix_evaluation_operation_between_two_numbers)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = 8.0 + 9.0;
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_multiple_operation_plus_multiply)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Number, "9"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "+"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = 8.0 + 9.0 * 2.0 + 3.0;
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_multiple_operation_minus_divide)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Number, "9"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Binary_Operator, "-"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = 8.0 / 2.0 - 9.0 / 3.0;
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_multiple_operation_plus)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "+"}
	};
	
	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = 8.0 + 2.0 + 9.0 + 3.0;
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_operation_plus_multiply_parenthesis)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "9"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Binary_Operator, "*"}
	};
	
	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = (8.0 + 2.0) * (9.0 + 3.0);
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_multiple_operation_parenthesis)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "3"},
		{calcli::token::Number, "4"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Number, "1"},
		{calcli::token::Number, "5"},
		{calcli::token::Binary_Operator, "-"},
		{calcli::token::Number, "2"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "^"},
		{calcli::token::Binary_Operator, "^"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Binary_Operator, "+"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = 3.0 + 4.0 * 2.0 / std::pow(16.0, 3.0);
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_multiple_operation_parenthesis_function)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "9"},
		{calcli::token::Function, "sqrt"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Number, "3.1415"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Function, "sin"},
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = std::sin(std::sqrt(9.0) / 3.0 * 3.1415);
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_operation_between_negative_and_postive_number)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = -8.0 + 9.0;
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_operation_unary_minus_plus_multiply_parenthesis)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "9"},
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Binary_Operator, "*"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = (8.0 + 2.0) * (-9.0 / 3.0);
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_function_with_negative_argument)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "1"},
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Function, "acos"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = std::acos(-1.0);
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}

TEST(test_evaluator, postfix_evaluation_function_with_constant)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Constant, "pi"},
		{calcli::token::Function, "cos"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = -1.0;
	ASSERT_NEAR(value, value_ref, 0.01 * std::abs(value_ref));
}
