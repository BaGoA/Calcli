#include <gtest/gtest.h>

#include <calcli/core/cmap.hpp>


TEST(test_cmap, access_to_key_which_does_not_exist)
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
		ASSERT_TRUE(false);
		EXPECT_EQ(value, 0);
	}
	catch(const std::exception& error)
	{
		const std::string str{error.what()};
		const std::string str_ref{"cmap access error, the key does not exist"};
		EXPECT_EQ(str, str_ref);
	}
}

TEST(test_cmap, access_to_key_which_exist)
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
		EXPECT_EQ(value, 2);
	}
	catch(const std::exception& error)
	{
		ASSERT_TRUE(false);
	}
}
