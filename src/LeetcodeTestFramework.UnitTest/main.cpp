#include <iostream>
#include <gtest/gtest.h>
#include "LTestTuple.hpp"

TEST(HelloWorldTest, TestLTestTuple)
{
	LTestTuple tuple(123);

	EXPECT_EQ(tuple.GetType(), LTestTupleType::IntType);
	EXPECT_EQ(tuple.GetIntValue(), 123);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}