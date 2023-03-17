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

// TODO: Here need to test different constructor with different type

// TODO: Here need to test allocation as test LinkList, Graph and Tree types. Checking two address whether same(should difference) after copy constructor.