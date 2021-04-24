#include "catch2/catch.hpp"

#include "core/extraction.hpp"


TEST_CASE("extract_number - extract number in expression containing only number", "[core]")
{
	const std::string_view expression{"4347.75"};

	const std::string number_ref{"4347.75"};
	const std::size_t shift_ref = 7;

	const auto [number, shift] = pinky::extract_number(std::cbegin(expression), std::cend(expression));
	REQUIRE(number == number_ref);
	REQUIRE(shift == shift_ref);
}

TEST_CASE("extract_number - extract two numbers in expression representing an addition", "[core]")
{
	const std::string_view expression{"4347.75 + 9799.54"};

	const std::string first_number_ref{"4347.75"};
	const std::size_t first_shift_ref = 7;

	const auto [first_number, first_shift] = pinky::extract_number(std::cbegin(expression), std::cend(expression));
	REQUIRE(first_number == first_number_ref);
	REQUIRE(first_shift == first_shift_ref);

	const std::string second_number_ref{"9799.54"};
	const std::size_t second_shift_ref = 7;

	const auto start_it = std::cbegin(expression) + (first_shift + 3);
	const auto [second_number, second_shift] = pinky::extract_number(start_it, std::cend(expression));
	REQUIRE(second_number == second_number_ref);
	REQUIRE(second_shift == second_shift_ref);
}

TEST_CASE("extract_number - extract number in expression containing also character", "[core]")
{
	const std::string_view expression{"4347add75"};

	const std::string number_ref{"4347"};
	const std::size_t shift_ref = 4;

	const auto [number, shift] = pinky::extract_number(std::cbegin(expression), std::cend(expression));
	REQUIRE(number == number_ref);
	REQUIRE(shift == shift_ref);
}

TEST_CASE("extract_name - extract name in expression containing only name", "[core]")
{
	const std::string_view expression{"sqrt"};

	const std::string name_ref{"sqrt"};
	const std::size_t shift_ref = 4;

	const auto [name, shift] = pinky::extract_name(std::cbegin(expression), std::cend(expression));
	REQUIRE(name == name_ref);
	REQUIRE(shift == shift_ref);
}

TEST_CASE("extract_name - extract two names in expression representing an addition", "[core]")
{
	const std::string_view expression{"cos sin"};

	const std::string first_name_ref{"cos"};
	const std::size_t first_shift_ref = 3;

	const auto [first_name, first_shift] = pinky::extract_name(std::cbegin(expression), std::cend(expression));
	REQUIRE(first_name == first_name_ref);
	REQUIRE(first_shift == first_shift_ref);

	const std::string second_name_ref{"sin"};
	const std::size_t second_shift_ref = 3;

	const auto start_it = std::cbegin(expression) + (first_shift + 1);
	const auto [second_name, second_shift] = pinky::extract_name(start_it, std::cend(expression));
	REQUIRE(second_name == second_name_ref);
	REQUIRE(second_shift == second_shift_ref);
}

TEST_CASE("extract_name - extract name in expression containing also number", "[core]")
{
	const std::string_view expression{"4347add75"};

	const std::string name_ref{"add"};
	const std::size_t shift_ref = 3;

	const auto [name, shift] = pinky::extract_name(std::cbegin(expression) + 4, std::cend(expression));
	REQUIRE(name == name_ref);
	REQUIRE(shift == shift_ref);
}
