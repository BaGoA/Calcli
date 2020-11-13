#include <gtest/gtest.h>

#include <calcli/core/lexer.hpp>


TEST(test_lexer, lexing_expression_with_one_number)
{
	const std::string_view expression("8");
	const std::vector<calcli::token> tokens = calcli::lexing(expression);

	ASSERT_EQ(tokens.size(), 1);
	EXPECT_TRUE(tokens[0].value == "8");
}

TEST(test_lexer, lexing_expression_with_one_floating_number)
{
	const std::string_view expression("8.43");
	const std::vector<calcli::token> tokens = calcli::lexing(expression);

	ASSERT_EQ(tokens.size(), 1);
	EXPECT_TRUE(tokens[0].value == "8.43");
}
