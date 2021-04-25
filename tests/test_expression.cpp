#include "catch2/catch.hpp"

#include "api/expression.hpp"


TEST_CASE("expression - evaluate an expression with simple operation", "[api]")
{
	const pinky::expression expression("8.0 * 8.0");
	const double result = expression.evaluate();
	const double result_ref = 64.0;
	REQUIRE(result == Approx(result_ref).epsilon(0.01));
}

TEST_CASE("expression - evaluate an expression containing parenthesis", "[api]")
{
	const pinky::expression expression("8.0 * (5.0 + 3.0)");
	const double result = expression.evaluate();
	const double result_ref = 64.0;
	REQUIRE(result == Approx(result_ref).epsilon(0.01));
}

TEST_CASE("expression - evaluate an expression with unary operation", "[api]")
{
	const pinky::expression expression("-8.0 * (-8.0)");
	const double result = expression.evaluate();
	const double result_ref = 64.0;
	REQUIRE(result == Approx(result_ref).epsilon(0.01));
}

TEST_CASE("expression - evaluate an expression with function", "[api]")
{
	const pinky::expression expression("sqrt(4.0)");
	const double result = expression.evaluate();
	const double result_ref = 2.0;
	REQUIRE(result == Approx(result_ref).epsilon(0.01));
}

TEST_CASE("expression - evaluate an expression with function and constant", "[api]")
{
	const pinky::expression expression("sin(pi / 2.0)");
	const double result = expression.evaluate();
	const double result_ref = 1.0;
	REQUIRE(result == Approx(result_ref).epsilon(0.01));
}

TEST_CASE("expression - evaluate an expression with function composition", "[api]")
{
	const pinky::expression expression("sin(degtorad(90.0))");
	const double result = expression.evaluate();
	const double result_ref = 1.0;
	REQUIRE(result == Approx(result_ref).epsilon(0.01));
}

TEST_CASE("expression - evaluate an complex expression", "[api]")
{
	const pinky::expression expression("(sin(pi / 4.0)^2.0 + cos(pi / 4.0)^2.0) + ((90.0 - (5.0 * 2.0 - 1.0)) / (6.0 + 3.0))");
	const double result = expression.evaluate();
	const double result_ref = 10.0;
	REQUIRE(result == Approx(result_ref).epsilon(0.01));
}
