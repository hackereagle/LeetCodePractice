#pragma once

#include <iostream>
#include <string>
#include "LeetcodeTreeMiscs.hpp"
#include "AssertClass.hpp"

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
		AssertClass::GetInstance().Assert(root != nullptr, "Tree already create");

		ReleaseTree(root);
		AssertClass::GetInstance().Assert(root == nullptr, "Tree already release");
	}

	void TestCheckingTwoTreeEqual()
	{
		std::vector<std::string> arr1({"1","2","3","null","null","4","5"});
		std::vector<std::string> arr2({"1","2","3","null","null","4","5"});

		TreeNode* root1 = ConvertLeetcodeVector2BinaryTree(arr1);
		TreeNode* root2 = ConvertLeetcodeVector2BinaryTree(arr2);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(root1, root2), "Two tree equal");

		ReleaseTree(root1);
		ReleaseTree(root2);
	}

	void TestCheckingTwoTreeNotEqual()
	{
		std::vector<std::string> arr1({"1","2","3","null","null","4","5"});
		std::vector<std::string> arr2({"1","9","3","null","null","4","5"});

		TreeNode* root1 = ConvertLeetcodeVector2BinaryTree(arr1);
		TreeNode* root2 = ConvertLeetcodeVector2BinaryTree(arr2);

		AssertClass::GetInstance().Assert(!IsTwoTreeEqual(root1, root2), "Two tree not equal");

		ReleaseTree(root1);
		ReleaseTree(root2);
	}

	void TestCreateLeftistTree()
	{

		// verify via check each level
		std::vector<std::vector<TreeNode*>> targetLevels;

	}
};