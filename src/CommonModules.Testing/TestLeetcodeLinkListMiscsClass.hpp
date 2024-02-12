#pragma once

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include "LeetcodeLinkListMiscs.hpp"

TEST(TestLeetcodeLinkListMiscsClass, TestCreateListFromLeetcodeString)
{
	// arrange
	std::string leetcodeStr = "[1,2,3,4,5]";

	// action
	ListNode* head = CreateListFromLeetcodeString(leetcodeStr);

	// assert
	ListNode* lastNode = new ListNode(5);
	ListNode* node4 = new ListNode(4, lastNode);
	ListNode* node3 = new ListNode(3, node4);
	ListNode* node2 = new ListNode(2, node3);
	ListNode* expectedResult = new ListNode(1, node2);
	
	ListNode* itHead = head;
	ListNode* itExpected = expectedResult;
	while (itHead != nullptr && itExpected != nullptr)
	{
		EXPECT_EQ(itHead->val, itExpected->val);
		itHead = itHead->next;
		itExpected = itExpected->next;
	}
	EXPECT_EQ(itHead, itExpected);
	
	// release
	ReleaseList(head);
	ReleaseList(expectedResult);
}

// The catch std::cout way refer to https://stackoverflow.com/questions/3803465/how-to-capture-stdout-stderr-with-googletest
TEST(TestLeetcodeLinkListMiscsClass, TestStdCout)
{
	// arrange
	testing::internal::CaptureStdout();
	std::string leetcodeStr = "[1,2,3,4,5]";
	ListNode* head = CreateListFromLeetcodeString(leetcodeStr);

	// action
	std::cout << head;
	std::string output = testing::internal::GetCapturedStdout();

	// assert
	EXPECT_EQ(output, "[1, 2, 3, 4, 5]");
	
	// release
	ReleaseList(head);
}