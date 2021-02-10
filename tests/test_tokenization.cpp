#include <vendor/catch2/catch.hpp>

#include <calcli/processing/parse.hpp>


TEST_CASE("tokenization - expression with one number", "[processing]")
{
	const std::string_view expression("8");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 1);
	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8");
}

TEST_CASE("tokenization - expression with one floating number", "[processing]")
{
	const std::string_view expression("8.43");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 1);
	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8.43");
}

TEST_CASE("tokenization - expression containing numbers and operator plus", "[processing]")
{
	const std::string_view expression("8.43 + 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 3);

	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8.43");

	CHECK(tokens[1].type == calcli::token::Binary_Operator);
	CHECK(tokens[1].value == "+");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "9.12");
}

TEST_CASE("tokenization - expression containing numbers and operator minus", "[processing]")
{
	const std::string_view expression("8.43 - 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 3);

	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8.43");

	CHECK(tokens[1].type == calcli::token::Binary_Operator);
	CHECK(tokens[1].value == "-");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "9.12");
}

TEST_CASE("tokenization - expression containing numbers and operator multiply", "[processing]")
{
	const std::string_view expression("8.43 * 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 3);

	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8.43");

	CHECK(tokens[1].type == calcli::token::Binary_Operator);
	CHECK(tokens[1].value == "*");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "9.12");
}

TEST_CASE("tokenization - expression containing numbers and operator divide", "[processing]")
{
	const std::string_view expression("8.43 / 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 3);

	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8.43");

	CHECK(tokens[1].type == calcli::token::Binary_Operator);
	CHECK(tokens[1].value == "/");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "9.12");
}

TEST_CASE("tokenization - expression containing numbers and operator power", "[processing]")
{
	const std::string_view expression("8.43 ^ 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 3);

	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8.43");

	CHECK(tokens[1].type == calcli::token::Binary_Operator);
	CHECK(tokens[1].value == "^");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "9.12");
}

TEST_CASE("tokenization - expression containing numbers operators and parenthesis", "[processing]")
{
	const std::string_view expression("8.43 * (9.12 - 4.314)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 7);

	CHECK(tokens[0].type == calcli::token::Number);
	CHECK(tokens[0].value == "8.43");

	CHECK(tokens[1].type == calcli::token::Binary_Operator);
	CHECK(tokens[1].value == "*");

	CHECK(tokens[2].type == calcli::token::Left_Parenthesis);
	CHECK(tokens[2].value == "(");

	CHECK(tokens[3].type == calcli::token::Number);
	CHECK(tokens[3].value == "9.12");

	CHECK(tokens[4].type == calcli::token::Binary_Operator);
	CHECK(tokens[4].value == "-");

	CHECK(tokens[5].type == calcli::token::Number);
	CHECK(tokens[5].value == "4.314");

	CHECK(tokens[6].type == calcli::token::Right_Parenthesis);
	CHECK(tokens[6].value == ")");
}

TEST_CASE("tokenization - expression containing function", "[processing]")
{
	const std::string_view expression("sin(1.57)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 4);

	CHECK(tokens[0].type == calcli::token::Function);
	CHECK(tokens[0].value == "sin");

	CHECK(tokens[1].type == calcli::token::Left_Parenthesis);
	CHECK(tokens[1].value == "(");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "1.57");

	CHECK(tokens[3].type == calcli::token::Right_Parenthesis);
	CHECK(tokens[3].value == ")");
}

TEST_CASE("tokenization - expression containing all", "[processing]")
{
	const std::string_view expression("sin(3.0 * 1.57) + sqrt(9.11 - 1.54)^2");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 15);

	CHECK(tokens[0].type == calcli::token::Function);
	CHECK(tokens[0].value == "sin");

	CHECK(tokens[1].type == calcli::token::Left_Parenthesis);
	CHECK(tokens[1].value == "(");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "3.0");

	CHECK(tokens[3].type == calcli::token::Binary_Operator);
	CHECK(tokens[3].value == "*");

	CHECK(tokens[4].type == calcli::token::Number);
	CHECK(tokens[4].value == "1.57");

	CHECK(tokens[5].type == calcli::token::Right_Parenthesis);
	CHECK(tokens[5].value == ")");
	
	CHECK(tokens[6].type == calcli::token::Binary_Operator);
	CHECK(tokens[6].value == "+");

	CHECK(tokens[7].type == calcli::token::Function);
	CHECK(tokens[7].value == "sqrt");

	CHECK(tokens[8].type == calcli::token::Left_Parenthesis);
	CHECK(tokens[8].value == "(");
	
	CHECK(tokens[9].type == calcli::token::Number);
	CHECK(tokens[9].value == "9.11");

	CHECK(tokens[10].type == calcli::token::Binary_Operator);
	CHECK(tokens[10].value == "-");

	CHECK(tokens[11].type == calcli::token::Number);
	CHECK(tokens[11].value == "1.54");

	CHECK(tokens[12].type == calcli::token::Right_Parenthesis);
	CHECK(tokens[12].value == ")");

	CHECK(tokens[13].type == calcli::token::Binary_Operator);
	CHECK(tokens[13].value == "^");

	CHECK(tokens[14].type == calcli::token::Number);
	CHECK(tokens[14].value == "2");
}

TEST_CASE("tokenization - expression containing numbers and unary operator", "[processing]")
{
	const std::string_view expression("-8.43 + 9.12");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 4);

	CHECK(tokens[0].type == calcli::token::Unary_Operator);
	CHECK(tokens[0].value == "-");

	CHECK(tokens[1].type == calcli::token::Number);
	CHECK(tokens[1].value == "8.43");

	CHECK(tokens[2].type == calcli::token::Binary_Operator);
	CHECK(tokens[2].value == "+");

	CHECK(tokens[3].type == calcli::token::Number);
	CHECK(tokens[3].value == "9.12");
}

TEST_CASE("tokenization - expression containing numbers parenthesis unary operator", "[processing]")
{
	const std::string_view expression("-8.43 * (-9.12 + 22.54)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 9);

	CHECK(tokens[0].type == calcli::token::Unary_Operator);
	CHECK(tokens[0].value == "-");

	CHECK(tokens[1].type == calcli::token::Number);
	CHECK(tokens[1].value == "8.43");

	CHECK(tokens[2].type == calcli::token::Binary_Operator);
	CHECK(tokens[2].value == "*");

	CHECK(tokens[3].type == calcli::token::Left_Parenthesis);
	CHECK(tokens[3].value == "(");

	CHECK(tokens[4].type == calcli::token::Unary_Operator);
	CHECK(tokens[4].value == "-");

	CHECK(tokens[5].type == calcli::token::Number);
	CHECK(tokens[5].value == "9.12");

	CHECK(tokens[6].type == calcli::token::Binary_Operator);
	CHECK(tokens[6].value == "+");

	CHECK(tokens[7].type == calcli::token::Number);
	CHECK(tokens[7].value == "22.54");

	CHECK(tokens[8].type == calcli::token::Right_Parenthesis);
	CHECK(tokens[8].value == ")");
}

TEST_CASE("tokenization - expression containing numbers unary operator function", "[processing]")
{
	const std::string_view expression("acos(-1.0)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 5);

	CHECK(tokens[0].type == calcli::token::Function);
	CHECK(tokens[0].value == "acos");

	CHECK(tokens[1].type == calcli::token::Left_Parenthesis);
	CHECK(tokens[1].value == "(");

	CHECK(tokens[2].type == calcli::token::Unary_Operator);
	CHECK(tokens[2].value == "-");

	CHECK(tokens[3].type == calcli::token::Number);
	CHECK(tokens[3].value == "1.0");

	CHECK(tokens[4].type == calcli::token::Right_Parenthesis);
	CHECK(tokens[4].value == ")");
}

TEST_CASE("tokenization - expression containing function constant", "[processing]")
{
	const std::string_view expression("cos(pi)");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 4);

	CHECK(tokens[0].type == calcli::token::Function);
	CHECK(tokens[0].value == "cos");

	CHECK(tokens[1].type == calcli::token::Left_Parenthesis);
	CHECK(tokens[1].value == "(");

	CHECK(tokens[2].type == calcli::token::Constant);
	CHECK(tokens[2].value == "pi");

	CHECK(tokens[3].type == calcli::token::Right_Parenthesis);
	CHECK(tokens[3].value == ")");
}

TEST_CASE("tokenization - expression containing operator constant", "[processing]")
{
	const std::string_view expression("e^2.0");
	const std::vector<calcli::token> tokens = calcli::tokenize(expression);

	REQUIRE(tokens.size() == 3);

	CHECK(tokens[0].type == calcli::token::Constant);
	CHECK(tokens[0].value == "e");

	CHECK(tokens[1].type == calcli::token::Binary_Operator);
	CHECK(tokens[1].value == "^");

	CHECK(tokens[2].type == calcli::token::Number);
	CHECK(tokens[2].value == "2.0");
}
