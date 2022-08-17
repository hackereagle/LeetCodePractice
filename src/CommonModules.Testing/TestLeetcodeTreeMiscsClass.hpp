#pragma once

#include <iostream>
#include <string>
#include "LeetcodeTreeMiscs.hpp"

class TestLeetcodeTreeMiscsClass
{
public:
	TestLeetcodeTreeMiscsClass()
	{}

	~TestLeetcodeTreeMiscsClass()
	{}

	void TestCreateTreeWithArrayAndRelease()
	{
		std::string arr[] = {"1", "2", "3", "4", "5", "6", "7"};

		TreeNode* root = ConvertLeetcodeArray2BinaryTree(arr, sizeof(arr) / sizeof(std::string));
		PrintBinaryTree(root);

		ReleaseTree(root);
	}

	void TestCheckingTwoTreeEqual()
	{

	}

	void TestCheckingTwoTreeNotEqual()
	{

	}
};