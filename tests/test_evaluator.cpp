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

TEST(test_evaluator, shunting_yard_multiple_operation_plus_multiply)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Operator, "+"},
		{calcli::token::Number, "9"},
		{calcli::token::Operator, "*"},
		{calcli::token::Number, "2"},
		{calcli::token::Operator, "+"},
		{calcli::token::Number, "3"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::shunting_yard(tokens);

	ASSERT_EQ(tokens_postfix.size(), 7);

	EXPECT_EQ(tokens_postfix[0].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[0].value, "8");

	EXPECT_EQ(tokens_postfix[1].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[1].value, "9");

	EXPECT_EQ(tokens_postfix[2].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[2].value, "2");

	EXPECT_EQ(tokens_postfix[3].type, calcli::token::Operator);
	EXPECT_EQ(tokens_postfix[3].value, "*");

	EXPECT_EQ(tokens_postfix[4].type, calcli::token::Operator);
	EXPECT_EQ(tokens_postfix[4].value, "+");

	EXPECT_EQ(tokens_postfix[5].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[5].value, "3");

	EXPECT_EQ(tokens_postfix[6].type, calcli::token::Operator);
	EXPECT_EQ(tokens_postfix[6].value, "+");
}

TEST(test_evaluator, shunting_yard_multiple_operation_minus_divide)
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Operator, "/"},
		{calcli::token::Number, "2"},
		{calcli::token::Operator, "-"},
		{calcli::token::Number, "9"},
		{calcli::token::Operator, "/"},
		{calcli::token::Number, "3"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::shunting_yard(tokens);

	ASSERT_EQ(tokens_postfix.size(), 7);

	EXPECT_EQ(tokens_postfix[0].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[0].value, "8");

	EXPECT_EQ(tokens_postfix[1].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[1].value, "2");

	EXPECT_EQ(tokens_postfix[2].type, calcli::token::Operator);
	EXPECT_EQ(tokens_postfix[2].value, "/");

	EXPECT_EQ(tokens_postfix[3].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[3].value, "9");

	EXPECT_EQ(tokens_postfix[4].type, calcli::token::Number);
	EXPECT_EQ(tokens_postfix[4].value, "3");

	EXPECT_EQ(tokens_postfix[5].type, calcli::token::Operator);
	EXPECT_EQ(tokens_postfix[5].value, "/");

	EXPECT_EQ(tokens_postfix[6].type, calcli::token::Operator);
	EXPECT_EQ(tokens_postfix[6].value, "-");
}
