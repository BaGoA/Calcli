#include <gtest/gtest.h>

#include <calcli/core/evaluator.hpp>


TEST(test_evaluator, shunting_yard_operation_between_two_numbers)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Operator, "+"},
		{calcli::token::Number, "9"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::shunting_yard(tokens);

	ASSERT_EQ(tokens_postfix.size(), 3);

	EXPECT_EQ(tokens_postfix[0].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[0].value, "8");

	EXPECT_EQ(tokens_postfix[1].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[1].value, "9");

	EXPECT_EQ(tokens_postfix[2].type, calcli::token::Operator);
	EXPECT_EQ(tokens_postfix[2].value, "+");
}
