#pragma once

#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "LeetcodeTreeMiscs.hpp"
#include "AssertClass.hpp"

// class TestLeetcodeTreeMiscsClass
// {
// public:
// 	TestLeetcodeTreeMiscsClass()
// 	{}
// 
// 	~TestLeetcodeTreeMiscsClass()
// 	{}
// 
// 	void TestCreateTreeWithArrayAndRelease()
// 	{
// 		std::string arr[] = {"1", "2", "3", "4", "5", "6", "7"};
// 
// 		TreeNode* root = ConvertLeetcodeArray2BinaryTree(arr, sizeof(arr) / sizeof(std::string));
// 		PrintBinaryTree(root);
// 		AssertClass::GetInstance().Assert(root != nullptr, "Tree already create");
// 
// 		ReleaseTree(root);
// 		AssertClass::GetInstance().Assert(root == nullptr, "Tree already release");
// 	}
// 
// 	void TestCheckingTwoTreeEqual()
// 	{
// 		std::vector<std::string> arr1({"1","2","3","null","null","4","5"});
// 		std::vector<std::string> arr2({"1","2","3","null","null","4","5"});
// 
// 		TreeNode* root1 = ConvertLeetcodeVector2BinaryTree(arr1);
// 		TreeNode* root2 = ConvertLeetcodeVector2BinaryTree(arr2);
// 
// 		AssertClass::GetInstance().Assert(IsTwoTreeEqual(root1, root2), "Two tree equal");
// 
// 		ReleaseTree(root1);
// 		ReleaseTree(root2);
// 	}
// 
// 	void TestCheckingTwoTreeNotEqual()
// 	{
// 		std::vector<std::string> arr1({"1","2","3","null","null","4","5"});
// 		std::vector<std::string> arr2({"1","9","3","null","null","4","5"});
// 
// 		TreeNode* root1 = ConvertLeetcodeVector2BinaryTree(arr1);
// 		TreeNode* root2 = ConvertLeetcodeVector2BinaryTree(arr2);
// 
// 		AssertClass::GetInstance().Assert(!IsTwoTreeEqual(root1, root2), "Two tree not equal");
// 
// 		ReleaseTree(root1);
// 		ReleaseTree(root2);
// 	}
// 
// 	void TestCreateLeftistTree()
// 	{
// 
// 		// verify via check each level
// 		std::vector<std::vector<TreeNode*>> targetLevels;
// 
// 	}
// };

TEST(TestLeetcodeTreeMiscsClass, TestCreateTreeWithArrayAndRelease)
{
	// ARRANGE
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node2 = new TreeNode(2, node4, node5);
	TreeNode* node3 = new TreeNode(3, node6, node7);
	TreeNode* node1 = new TreeNode(1, node2, node3);
	std::string arr[] = {"1", "2", "3", "4", "5", "6", "7"};

	// ACT
	TreeNode* root = ConvertLeetcodeArray2BinaryTree(arr, sizeof(arr) / sizeof(std::string), ConvertMethod::WithLeetcodeStr);
	PrintBinaryTree(root);

	// ASSERT
	EXPECT_NE(root, nullptr);
	EXPECT_TRUE(IsTwoTreeEqual(node1, root));

	ReleaseTree(root);
	EXPECT_EQ(root, nullptr);
}

TEST(TestLeetcodeTreeMiscsClass, TestCheckingTwoTreeEqual)
{
	std::vector<std::string> arr1({"1","2","3","null","null","4","5"});
	std::vector<std::string> arr2({"1","2","3","null","null","4","5"});

	TreeNode* root1 = ConvertLeetcodeVector2BinaryTree(arr1);
	TreeNode* root2 = ConvertLeetcodeVector2BinaryTree(arr2);

	//AssertClass::GetInstance().Assert(IsTwoTreeEqual(root1, root2), "Two tree equal");
	EXPECT_TRUE(IsTwoTreeEqual(root1, root2));

	ReleaseTree(root1);
	ReleaseTree(root2);
}

TEST(TestLeetcodeTreeMiscsClass, TestCheckingTwoTreeNotEqual)
{
	std::vector<std::string> arr1({"1","2","3","null","null","4","5"});
	std::vector<std::string> arr2({"1","9","3","null","null","4","5"});

	TreeNode* root1 = ConvertLeetcodeVector2BinaryTree(arr1);
	TreeNode* root2 = ConvertLeetcodeVector2BinaryTree(arr2);

	EXPECT_FALSE(IsTwoTreeEqual(root1, root2));

	ReleaseTree(root1);
	ReleaseTree(root2);

}

TEST(TestLeetcodeTreeMiscsClass, TestCreateMinLeftistTree)
{
	// ARRANGE
	// This is expected answer
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	node5->left = node4;
	node4->left = node3;
	node3->left = node2;
	node2->left = node1;
	PrintBinaryTree(node5);
	std::string arr[] = {"5", "4", "null", "3", "null", "2", "null", "1"};

	// ACT
	TreeNode* root = ConvertLeetcodeArray2BinaryTree(arr, sizeof(arr) / sizeof(std::string), ConvertMethod::WithLeetcodeStr);
	PrintBinaryTree(root);

	// ASSERT
	EXPECT_TRUE(IsTwoTreeEqual(node5, root));

	ReleaseTree(node1);
	ReleaseTree(root);
}

TEST(TestLeetcodeTreeMiscsClass, TestCreateMaxLeftistTree)
{
	// ARRANGE
	// This is expected answer
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	node1->right = node2;
	node2->right = node3;
	node3->right = node4;
	node4->right = node5;
	PrintBinaryTree(node1);
	std::string arr[] = {"1", "null", "2", "null", "3", "null", "4", "null", "5"};

	// ACT
	TreeNode* root = ConvertLeetcodeArray2BinaryTree(arr, sizeof(arr) / sizeof(std::string), ConvertMethod::WithLeetcodeStr);
	PrintBinaryTree(root);

	// ASSERT
	EXPECT_TRUE(IsTwoTreeEqual(node1, root));

	ReleaseTree(node1);
	ReleaseTree(root);
}

TEST(TestLeetcodeTreeMiscsClass, TestCreateTreeWithLeetcodeStr)
{
	// ARRANGE
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node1 = new TreeNode(1);
	node1->right = node2;
	node2->left = node3;
	node3->left = node4;
	node3->right = node5;
	node4->right = node6;
	node5->left = node7;
	std::string str = "[1,null,2,3,null,4,5,null,6,7]";

	// ACT
	TreeNode* root = CreateTreeLeetcodeInputStr(str);
	PrintBinaryTree(root);

	// ASSERT
	EXPECT_NE(root, nullptr);
	EXPECT_TRUE(IsTwoTreeEqual(node1, root));

	ReleaseTree(root);
	EXPECT_EQ(root, nullptr);
}