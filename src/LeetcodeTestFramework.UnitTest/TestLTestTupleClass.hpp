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
TEST(TestLTestTupleClass, TestLTestTupleListHeadCopy)
{
	// arrange
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	// action
	LTestTuple org(head, "OriginTuple");
	std::cout << "head = " << head << ", in LTestTuple::GetListHead() = " << org.GetListHead() << std::endl;

	// assert
	EXPECT_EQ(org.GetListHead(), head);

	// action
	LTestTuple copied = org;
	std::cout << "In original LTestTuple::GetListHead " << org.GetListHead() << ", in copied LTestTuple::GetListHead() = " << copied.GetListHead() << std::endl;

	// assert
	EXPECT_NE(copied.GetListHead(), org.GetListHead());
}