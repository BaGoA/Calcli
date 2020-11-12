#include <gtest/gtest.h>


TEST(test_toto, toto)
{
	const int value = 1;
	const int expected = 1;
	EXPECT_TRUE(value == expected);
}
