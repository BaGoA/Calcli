#include <vendor/catch2/catch.hpp>

#include <calcli-processing/parse.hpp>


TEST_CASE("infix_to_postfix - operation between two numbers", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "9"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 3);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "8");

	CHECK(tokens_postfix[1].type == calcli::token::Number);
	CHECK(tokens_postfix[1].value == "9");

	CHECK(tokens_postfix[2].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[2].value == "+");
}

TEST_CASE("infix_to_postfix - multiple operation plus multiply", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "3"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 7);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "8");

	CHECK(tokens_postfix[1].type == calcli::token::Number);
	CHECK(tokens_postfix[1].value == "9");

	CHECK(tokens_postfix[2].type == calcli::token::Number);
	CHECK(tokens_postfix[2].value == "2");

	CHECK(tokens_postfix[3].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[3].value == "*");

	CHECK(tokens_postfix[4].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[4].value == "+");

	CHECK(tokens_postfix[5].type == calcli::token::Number);
	CHECK(tokens_postfix[5].value == "3");

	CHECK(tokens_postfix[6].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[6].value == "+");
}

TEST_CASE("infix_to_postfix - multiple operation minus divide", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "-"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Number, "3"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 7);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "8");

	CHECK(tokens_postfix[1].type == calcli::token::Number);
	CHECK(tokens_postfix[1].value == "2");

	CHECK(tokens_postfix[2].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[2].value == "/");

	CHECK(tokens_postfix[3].type == calcli::token::Number);
	CHECK(tokens_postfix[3].value == "9");

	CHECK(tokens_postfix[4].type == calcli::token::Number);
	CHECK(tokens_postfix[4].value == "3");

	CHECK(tokens_postfix[5].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[5].value == "/");

	CHECK(tokens_postfix[6].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[6].value == "-");
}

TEST_CASE("infix_to_postfix - multiple operation plus", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "3"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 7);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "8");

	CHECK(tokens_postfix[1].type == calcli::token::Number);
	CHECK(tokens_postfix[1].value == "2");

	CHECK(tokens_postfix[2].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[2].value == "+");

	CHECK(tokens_postfix[3].type == calcli::token::Number);
	CHECK(tokens_postfix[3].value == "9");

	CHECK(tokens_postfix[4].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[4].value == "+");

	CHECK(tokens_postfix[5].type == calcli::token::Number);
	CHECK(tokens_postfix[5].value == "3");

	CHECK(tokens_postfix[6].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[6].value == "+");
}

TEST_CASE("infix_to_postfix - operation plus multiply parenthesis", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "2"},
		{calcli::token::Right_Parenthesis, ")"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "3"},
		{calcli::token::Right_Parenthesis, ")"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 7);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "8");

	CHECK(tokens_postfix[1].type == calcli::token::Number);
	CHECK(tokens_postfix[1].value == "2");

	CHECK(tokens_postfix[2].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[2].value == "+");

	CHECK(tokens_postfix[3].type == calcli::token::Number);
	CHECK(tokens_postfix[3].value == "9");

	CHECK(tokens_postfix[4].type == calcli::token::Number);
	CHECK(tokens_postfix[4].value == "3");

	CHECK(tokens_postfix[5].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[5].value == "+");

	CHECK(tokens_postfix[6].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[6].value == "*");
}

TEST_CASE("infix_to_postfix - multiple operation parenthesis", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "4"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "1"},
		{calcli::token::Binary_Operator, "-"},
		{calcli::token::Number, "5"},
		{calcli::token::Right_Parenthesis, ")"},
		{calcli::token::Binary_Operator, "^"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "^"},
		{calcli::token::Number, "3"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 13);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "3");

	CHECK(tokens_postfix[1].type == calcli::token::Number);
	CHECK(tokens_postfix[1].value == "4");

	CHECK(tokens_postfix[2].type == calcli::token::Number);
	CHECK(tokens_postfix[2].value == "2");

	CHECK(tokens_postfix[3].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[3].value == "*");

	CHECK(tokens_postfix[4].type == calcli::token::Number);
	CHECK(tokens_postfix[4].value == "1");

	CHECK(tokens_postfix[5].type == calcli::token::Number);
	CHECK(tokens_postfix[5].value == "5");

	CHECK(tokens_postfix[6].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[6].value == "-");

	CHECK(tokens_postfix[7].type == calcli::token::Number);
	CHECK(tokens_postfix[7].value == "2");

	CHECK(tokens_postfix[8].type == calcli::token::Number);
	CHECK(tokens_postfix[8].value == "3");

	CHECK(tokens_postfix[9].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[9].value == "^");

	CHECK(tokens_postfix[10].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[10].value == "^");

	CHECK(tokens_postfix[11].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[11].value == "/");

	CHECK(tokens_postfix[12].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[12].value == "+");
}

TEST_CASE("infix_to_postfix - multiple operation parenthesis function", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Function, "sin"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Function, "sqrt"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "9"},
		{calcli::token::Right_Parenthesis, ")"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Number, "3"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Number, "3.1415"},
		{calcli::token::Right_Parenthesis, ")"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 7);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "9");

	CHECK(tokens_postfix[1].type == calcli::token::Function);
	CHECK(tokens_postfix[1].value == "sqrt");

	CHECK(tokens_postfix[2].type == calcli::token::Number);
	CHECK(tokens_postfix[2].value == "3");

	CHECK(tokens_postfix[3].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[3].value == "/");

	CHECK(tokens_postfix[4].type == calcli::token::Number);
	CHECK(tokens_postfix[4].value == "3.1415");

	CHECK(tokens_postfix[5].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[5].value == "*");

	CHECK(tokens_postfix[6].type == calcli::token::Function);
	CHECK(tokens_postfix[6].value == "sin");
}

TEST_CASE("infix_to_postfix - forget left parenthesis", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "2"},
		{calcli::token::Right_Parenthesis, ")"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "3"},
		{calcli::token::Right_Parenthesis, ")"}
	};

	try
	{
		const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);
		REQUIRE(false);
	}
	catch(const std::exception& error)
	{
		const std::string message(error.what());
		const std::string message_ref("there are mismatched parenthesis in your expression");

		CHECK(message == message_ref);
	}
}

TEST_CASE("infix_to_postfix - forget right parenthesis", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "2"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "3"},
		{calcli::token::Right_Parenthesis, ")"}
	};

	try
	{
		const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);
		REQUIRE(false);
	}
	catch(const std::exception& error)
	{
		const std::string message(error.what());
		const std::string message_ref("there are mismatched parenthesis in your expression");

		CHECK(message == message_ref);
	}
}

TEST_CASE("infix_to_postfix - operation between negative and postive number", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "9"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 4);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "8");

	CHECK(tokens_postfix[1].type == calcli::token::Unary_Operator);
	CHECK(tokens_postfix[1].value == "-");

	CHECK(tokens_postfix[2].type == calcli::token::Number);
	CHECK(tokens_postfix[2].value == "9");

	CHECK(tokens_postfix[3].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[3].value == "+");
}

TEST_CASE("infix_to_postfix - operation unary minus plus multiply parenthesis", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Number, "8"},
		{calcli::token::Binary_Operator, "+"},
		{calcli::token::Number, "2"},
		{calcli::token::Right_Parenthesis, ")"},
		{calcli::token::Binary_Operator, "*"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Number, "9"},
		{calcli::token::Binary_Operator, "/"},
		{calcli::token::Number, "3"},
		{calcli::token::Right_Parenthesis, ")"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 8);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "8");

	CHECK(tokens_postfix[1].type == calcli::token::Number);
	CHECK(tokens_postfix[1].value == "2");

	CHECK(tokens_postfix[2].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[2].value == "+");

	CHECK(tokens_postfix[3].type == calcli::token::Number);
	CHECK(tokens_postfix[3].value == "9");

	CHECK(tokens_postfix[4].type == calcli::token::Unary_Operator);
	CHECK(tokens_postfix[4].value == "-");

	CHECK(tokens_postfix[5].type == calcli::token::Number);
	CHECK(tokens_postfix[5].value == "3");

	CHECK(tokens_postfix[6].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[6].value == "/");

	CHECK(tokens_postfix[7].type == calcli::token::Binary_Operator);
	CHECK(tokens_postfix[7].value == "*");
}

TEST_CASE("infix_to_postfix - function with negative argument", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Function, "acos"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Unary_Operator, "-"},
		{calcli::token::Number, "1"},
		{calcli::token::Right_Parenthesis, ")"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 3);

	CHECK(tokens_postfix[0].type == calcli::token::Number);
	CHECK(tokens_postfix[0].value == "1");

	CHECK(tokens_postfix[1].type == calcli::token::Unary_Operator);
	CHECK(tokens_postfix[1].value == "-");

	CHECK(tokens_postfix[2].type == calcli::token::Function);
	CHECK(tokens_postfix[2].value == "acos");
}

TEST_CASE("infix_to_postfix - function with constant", "[processing]")
{
	const std::vector<calcli::token> tokens = {
		{calcli::token::Function, "cos"},
		{calcli::token::Left_Parenthesis, "("},
		{calcli::token::Constant, "pi"},
		{calcli::token::Right_Parenthesis, ")"}
	};

	const std::vector<calcli::token> tokens_postfix = calcli::infix_to_postfix(tokens);

	REQUIRE(tokens_postfix.size() == 2);

	CHECK(tokens_postfix[0].type == calcli::token::Constant);
	CHECK(tokens_postfix[0].value == "pi");

	CHECK(tokens_postfix[1].type == calcli::token::Function);
	CHECK(tokens_postfix[1].value == "cos");
}
