#include <gtest/gtest.h>

#include <calcli/processing/parse.hpp>


TEST(test_lexer, tokenization_expression_with_one_number)
{
	const std::string_view expression("8");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 1);
	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8");
}

TEST(test_lexer, tokenization_expression_with_one_floating_number)
{
	const std::string_view expression("8.43");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 1);
	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8.43");
}

TEST(test_lexer, tokenization_expression_containing_numbers_and_operator_plus)
{
	const std::string_view expression("8.43 + 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 3);

	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8.43");

	EXPECT_EQ(tokens[1].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[1].value, "+");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "9.12");
}

TEST(test_lexer, tokenization_expression_containing_numbers_and_operator_minus)
{
	const std::string_view expression("8.43 - 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 3);

	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8.43");

	EXPECT_EQ(tokens[1].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[1].value, "-");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "9.12");
}

TEST(test_lexer, tokenization_expression_containing_numbers_and_operator_multiply)
{
	const std::string_view expression("8.43 * 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 3);

	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8.43");

	EXPECT_EQ(tokens[1].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[1].value, "*");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "9.12");
}

TEST(test_lexer, tokenization_expression_containing_numbers_and_operator_divide)
{
	const std::string_view expression("8.43 / 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 3);

	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8.43");

	EXPECT_EQ(tokens[1].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[1].value, "/");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "9.12");
}

TEST(test_lexer, tokenization_expression_containing_numbers_and_operator_power)
{
	const std::string_view expression("8.43 ^ 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 3);

	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8.43");

	EXPECT_EQ(tokens[1].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[1].value, "^");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "9.12");
}

TEST(test_lexer, tokenization_expression_containing_numbers_operators_and_parenthesis)
{
	const std::string_view expression("8.43 * (9.12 - 4.314)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 7);

	EXPECT_EQ(tokens[0].type, calcli::token::Number);
	EXPECT_EQ(tokens[0].value, "8.43");

	EXPECT_EQ(tokens[1].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[1].value, "*");

	EXPECT_EQ(tokens[2].type, calcli::token::Left_Parenthesis);
	EXPECT_EQ(tokens[2].value, "(");

	EXPECT_EQ(tokens[3].type, calcli::token::Number);
	EXPECT_EQ(tokens[3].value, "9.12");

	EXPECT_EQ(tokens[4].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[4].value, "-");

	EXPECT_EQ(tokens[5].type, calcli::token::Number);
	EXPECT_EQ(tokens[5].value, "4.314");

	EXPECT_EQ(tokens[6].type, calcli::token::Right_Parenthesis);
	EXPECT_EQ(tokens[6].value, ")");
}

TEST(test_lexer, tokenization_expression_containing_function)
{
	const std::string_view expression("sin(1.57)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 4);

	EXPECT_EQ(tokens[0].type, calcli::token::Function);
	EXPECT_EQ(tokens[0].value, "sin");

	EXPECT_EQ(tokens[1].type, calcli::token::Left_Parenthesis);
	EXPECT_EQ(tokens[1].value, "(");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "1.57");

	EXPECT_EQ(tokens[3].type, calcli::token::Right_Parenthesis);
	EXPECT_EQ(tokens[3].value, ")");
}

TEST(test_lexer, tokenization_expression_containing_all)
{
	const std::string_view expression("sin(3.0 * 1.57) + sqrt(9.11 - 1.54)^2");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 15);

	EXPECT_EQ(tokens[0].type, calcli::token::Function);
	EXPECT_EQ(tokens[0].value, "sin");

	EXPECT_EQ(tokens[1].type, calcli::token::Left_Parenthesis);
	EXPECT_EQ(tokens[1].value, "(");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "3.0");

	EXPECT_EQ(tokens[3].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[3].value, "*");

	EXPECT_EQ(tokens[4].type, calcli::token::Number);
	EXPECT_EQ(tokens[4].value, "1.57");

	EXPECT_EQ(tokens[5].type, calcli::token::Right_Parenthesis);
	EXPECT_EQ(tokens[5].value, ")");
	
	EXPECT_EQ(tokens[6].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[6].value, "+");

	EXPECT_EQ(tokens[7].type, calcli::token::Function);
	EXPECT_EQ(tokens[7].value, "sqrt");

	EXPECT_EQ(tokens[8].type, calcli::token::Left_Parenthesis);
	EXPECT_EQ(tokens[8].value, "(");
	
	EXPECT_EQ(tokens[9].type, calcli::token::Number);
	EXPECT_EQ(tokens[9].value, "9.11");

	EXPECT_EQ(tokens[10].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[10].value, "-");

	EXPECT_EQ(tokens[11].type, calcli::token::Number);
	EXPECT_EQ(tokens[11].value, "1.54");

	EXPECT_EQ(tokens[12].type, calcli::token::Right_Parenthesis);
	EXPECT_EQ(tokens[12].value, ")");

	EXPECT_EQ(tokens[13].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[13].value, "^");

	EXPECT_EQ(tokens[14].type, calcli::token::Number);
	EXPECT_EQ(tokens[14].value, "2");
}

TEST(test_lexer, tokenization_expression_containing_numbers_and_unary_operator)
{
	const std::string_view expression("-8.43 + 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 4);

	EXPECT_EQ(tokens[0].type, calcli::token::Unary_Operator);
	EXPECT_EQ(tokens[0].value, "-");

	EXPECT_EQ(tokens[1].type, calcli::token::Number);
	EXPECT_EQ(tokens[1].value, "8.43");

	EXPECT_EQ(tokens[2].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[2].value, "+");

	EXPECT_EQ(tokens[3].type, calcli::token::Number);
	EXPECT_EQ(tokens[3].value, "9.12");
}

TEST(test_lexer, tokenization_expression_containing_numbers_parenthesis_unary_operator)
{
	const std::string_view expression("-8.43 * (-9.12 + 22.54)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 9);

	EXPECT_EQ(tokens[0].type, calcli::token::Unary_Operator);
	EXPECT_EQ(tokens[0].value, "-");

	EXPECT_EQ(tokens[1].type, calcli::token::Number);
	EXPECT_EQ(tokens[1].value, "8.43");

	EXPECT_EQ(tokens[2].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[2].value, "*");

	EXPECT_EQ(tokens[3].type, calcli::token::Left_Parenthesis);
	EXPECT_EQ(tokens[3].value, "(");

	EXPECT_EQ(tokens[4].type, calcli::token::Unary_Operator);
	EXPECT_EQ(tokens[4].value, "-");

	EXPECT_EQ(tokens[5].type, calcli::token::Number);
	EXPECT_EQ(tokens[5].value, "9.12");

	EXPECT_EQ(tokens[6].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[6].value, "+");

	EXPECT_EQ(tokens[7].type, calcli::token::Number);
	EXPECT_EQ(tokens[7].value, "22.54");

	EXPECT_EQ(tokens[8].type, calcli::token::Right_Parenthesis);
	EXPECT_EQ(tokens[8].value, ")");
}

TEST(test_lexer, tokenization_expression_containing_numbers_unary_operator_function)
{
	const std::string_view expression("acos(-1.0)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 5);

	EXPECT_EQ(tokens[0].type, calcli::token::Function);
	EXPECT_EQ(tokens[0].value, "acos");

	EXPECT_EQ(tokens[1].type, calcli::token::Left_Parenthesis);
	EXPECT_EQ(tokens[1].value, "(");

	EXPECT_EQ(tokens[2].type, calcli::token::Unary_Operator);
	EXPECT_EQ(tokens[2].value, "-");

	EXPECT_EQ(tokens[3].type, calcli::token::Number);
	EXPECT_EQ(tokens[3].value, "1.0");

	EXPECT_EQ(tokens[4].type, calcli::token::Right_Parenthesis);
	EXPECT_EQ(tokens[4].value, ")");
}

TEST(test_lexer, tokenization_expression_containing_function_constant)
{
	const std::string_view expression("cos(pi)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 4);

	EXPECT_EQ(tokens[0].type, calcli::token::Function);
	EXPECT_EQ(tokens[0].value, "cos");

	EXPECT_EQ(tokens[1].type, calcli::token::Left_Parenthesis);
	EXPECT_EQ(tokens[1].value, "(");

	EXPECT_EQ(tokens[2].type, calcli::token::Constant);
	EXPECT_EQ(tokens[2].value, "pi");

	EXPECT_EQ(tokens[3].type, calcli::token::Right_Parenthesis);
	EXPECT_EQ(tokens[3].value, ")");
}

TEST(test_lexer, tokenization_expression_containing_operator_constant)
{
	const std::string_view expression("e^2.0");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	ASSERT_EQ(tokens.size(), 3);

	EXPECT_EQ(tokens[0].type, calcli::token::Constant);
	EXPECT_EQ(tokens[0].value, "e");

	EXPECT_EQ(tokens[1].type, calcli::token::Binary_Operator);
	EXPECT_EQ(tokens[1].value, "^");

	EXPECT_EQ(tokens[2].type, calcli::token::Number);
	EXPECT_EQ(tokens[2].value, "2.0");
}
