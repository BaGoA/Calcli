#include <cmath>

#include <vendor/catch2/catch.hpp>

#include <pinky/evaluation.hpp>


TEST_CASE("postfix_evaluation - operation between two numbers", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "8"},
		{pinky::token::Number, "9"},
		{pinky::token::Binary_Operator, "+"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = 8.0 + 9.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation plus multiply", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "8"},
		{pinky::token::Number, "9"},
		{pinky::token::Number, "2"},
		{pinky::token::Binary_Operator, "*"},
		{pinky::token::Binary_Operator, "+"},
		{pinky::token::Number, "3"},
		{pinky::token::Binary_Operator, "+"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = 8.0 + 9.0 * 2.0 + 3.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation minus divide", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "8"},
		{pinky::token::Number, "2"},
		{pinky::token::Binary_Operator, "/"},
		{pinky::token::Number, "9"},
		{pinky::token::Number, "3"},
		{pinky::token::Binary_Operator, "/"},
		{pinky::token::Binary_Operator, "-"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = 8.0 / 2.0 - 9.0 / 3.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation plus", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "8"},
		{pinky::token::Number, "2"},
		{pinky::token::Binary_Operator, "+"},
		{pinky::token::Number, "9"},
		{pinky::token::Binary_Operator, "+"},
		{pinky::token::Number, "3"},
		{pinky::token::Binary_Operator, "+"}
	};
	
	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = 8.0 + 2.0 + 9.0 + 3.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - operation plus multiply parenthesis", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "8"},
		{pinky::token::Number, "2"},
		{pinky::token::Binary_Operator, "+"},
		{pinky::token::Number, "9"},
		{pinky::token::Number, "3"},
		{pinky::token::Binary_Operator, "+"},
		{pinky::token::Binary_Operator, "*"}
	};
	
	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = (8.0 + 2.0) * (9.0 + 3.0);
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation parenthesis", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "3"},
		{pinky::token::Number, "4"},
		{pinky::token::Number, "2"},
		{pinky::token::Binary_Operator, "*"},
		{pinky::token::Number, "1"},
		{pinky::token::Number, "5"},
		{pinky::token::Binary_Operator, "-"},
		{pinky::token::Number, "2"},
		{pinky::token::Number, "3"},
		{pinky::token::Binary_Operator, "^"},
		{pinky::token::Binary_Operator, "^"},
		{pinky::token::Binary_Operator, "/"},
		{pinky::token::Binary_Operator, "+"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = 3.0 + 4.0 * 2.0 / std::pow(16.0, 3.0);
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - multiple operation parenthesis function", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "9"},
		{pinky::token::Function, "sqrt"},
		{pinky::token::Number, "3"},
		{pinky::token::Binary_Operator, "/"},
		{pinky::token::Number, "3.1415"},
		{pinky::token::Binary_Operator, "*"},
		{pinky::token::Function, "sin"},
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = std::sin(std::sqrt(9.0) / 3.0 * 3.1415);
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - operation between negative and postive number", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "8"},
		{pinky::token::Unary_Operator, "-"},
		{pinky::token::Number, "9"},
		{pinky::token::Binary_Operator, "+"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = -8.0 + 9.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - operation unary minus plus multiply parenthesis", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "8"},
		{pinky::token::Number, "2"},
		{pinky::token::Binary_Operator, "+"},
		{pinky::token::Number, "9"},
		{pinky::token::Unary_Operator, "-"},
		{pinky::token::Number, "3"},
		{pinky::token::Binary_Operator, "/"},
		{pinky::token::Binary_Operator, "*"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = (8.0 + 2.0) * (-9.0 / 3.0);
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - function with negative argument", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Number, "1"},
		{pinky::token::Unary_Operator, "-"},
		{pinky::token::Function, "acos"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = std::acos(-1.0);
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}

TEST_CASE("postfix_evaluation - function with constant", "[processing]")
{
	const std::vector<pinky::token> tokens = {
		{pinky::token::Constant, "pi"},
		{pinky::token::Function, "cos"}
	};

	const double value = pinky::postfix_evaluation(tokens);
	const double value_ref = -1.0;
	REQUIRE(value == Approx(value_ref).epsilon(0.01));
}
