#pragma once

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
		int arr[] = {1, 2, 3, 4, 5, 6, 7};

		TreeNode* root = ConvertLeetcodeArray2BinaryTree(arr, sizeof(arr) / sizeof(int));
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