#include <catch2/catch.hpp>

#include <calcli/core/cmap.hpp>


TEST_CASE("cmap", "[core]")
{
	SECTION("access to key which does not exist")
	{
		constexpr calcli::cmap<char, int, 3> map{
			{{
				 {'a', 1},
				 {'b', 2},
				 {'c', 3}
			}}
		};

		try
		{
			const int value = map.at('e');
			REQUIRE(false);
			CHECK(value == 0);
		}
		catch(const std::exception& error)
		{
			const std::string str{error.what()};
			const std::string str_ref{"cmap access error, the key does not exist"};
			CHECK(str == str_ref);
		}
	}

	SECTION("access to key which exist")
	{
		constexpr calcli::cmap<char, int, 3> map{
			{{
				 {'a', 1},
				 {'b', 2},
				 {'c', 3}
			}}
		};

		try
		{
			const int value = map.at('b');
			CHECK(value == 2);
		}
		catch(const std::exception& error)
		{
			REQUIRE(false);
		}
	}
}
