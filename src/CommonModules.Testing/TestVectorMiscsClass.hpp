#pragma once

#include <iostream>
#include <gtest/gtest.h>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

TEST(TestVectorMiscsClass, TestPrintAcceptTypeVector)
{
	std::cout << "" << std::endl;
	std::vector<int> test(3, 500);
	PrintVector<int>(test);
}

typedef struct otherStruct{
	otherStruct(int val)
	{
		member = val;
	}
	int member = 0;

	friend std::ostream& operator<<(std::ostream& stream, const otherStruct& s)
	{
		stream << s.member;
		return stream;
	}

}OtherStruct;

TEST(TestVectorMiscsClass, TestPrintNotAcceptTypeVector)
{
	std::vector<struct otherStruct> test;
	test.push_back(OtherStruct(1));
	test.push_back(OtherStruct(1));
	PrintVector<struct otherStruct>(test);
}

TEST(TestVectorMiscsClass, TestCheckingTwoVectorSimilar)
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	PrintVector<int>(v1);

	std::vector<int> v2;
	v2.push_back(2);
	v2.push_back(1);
	v2.push_back(3);
	PrintVector<int>(v2);

	bool isSimilar = IsTwoVectorSimilar<int>(v1, v2);
	EXPECT_TRUE(isSimilar);
}

TEST(TestVectorMiscsClass, TestCheckingTwoVectorNotSimilar)
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	PrintVector<int>(v1);

	std::vector<int> v2;
	v2.push_back(2);
	v2.push_back(1);
	v2.push_back(5);
	PrintVector<int>(v2);

	bool isSimilar = IsTwoVectorSimilar<int>(v1, v2);
	EXPECT_FALSE(isSimilar);
}

TEST(TestVectorMiscsClass, TestVector2Str_VectorVectorInt)
{
	// ARRANGE
	std::vector<std::vector<int>> data;
	data.push_back({1, 2, 3});
	data.push_back({4, 5});

	// ACT
	std::string str = Vector2Str(data);

	// ASSERT
	EXPECT_EQ(str, "[[1, 2, 3], [4, 5]]");
}

TEST(TestVectorMiscsClass, TestVector2Str_VectorVectorChar)
{
	// ARRANGE
	std::vector<std::vector<char>> data({{'a', 'b', 'c'}, {'d', 'e', 'f'}});

	// ACT
	std::string str = Vector2Str(data);

	// ASSERT
	EXPECT_EQ(str, "[[\"a\", \"b\", \"c\"], [\"d\", \"e\", \"f\"]]");
}