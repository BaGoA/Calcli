#include <cmath>

#include <catch2/catch.hpp>

#include <calcli/processing/evaluation.hpp>


TEST_CASE("postfix_evaluation - operation between two numbers", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = 8.0 + 9.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation plus multiply", "[processing]")
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
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation minus divide", "[processing]")
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
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation plus", "[processing]")
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
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - operation plus multiply parenthesis", "[processing]")
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
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation parenthesis", "[processing]")
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
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation parenthesis function", "[processing]")
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
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - operation between negative and postive number", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = -8.0 + 9.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - operation unary minus plus multiply parenthesis", "[processing]")
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
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - function with negative argument", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "1"},
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Function, "acos"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = std::acos(-1.0);
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - function with constant", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Constant, "pi"},
		{calcli::token::Function, "cos"}
	};

	const double value = calcli::postfix_evaluation(tokens);
	const double value_ref = -1.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}
