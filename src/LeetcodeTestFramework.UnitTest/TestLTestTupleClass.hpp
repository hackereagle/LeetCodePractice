#pragma once

#include <string>
#include <gtest/gtest.h>
#include "LTestTuple.hpp"

TEST(TestLTestTupleClass, TestLTestTupleIntConstructor)
{
	// arrange
	int value = 123;
	std::string paramName = "TestTuple";

	// action
	LTestTuple tuple(value, paramName);

	// assert
	EXPECT_EQ(tuple.GetType(), LTestTupleType::IntType);
	EXPECT_EQ(tuple.GetIntValue(), value);
	EXPECT_EQ(tuple.GetParameterName(), paramName);
}

// Here need to test allocation. Checking two address whether same(should difference) after copy constructor.