#pragma once

#include <iostream>
#include <string>
#include <gtest/gtest.h>
#include "LeetcodeTreeMiscs.hpp"
#include "AssertClass.hpp"

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
	// ARRANGE
	// first tree
	TreeNode* node1_1 = new TreeNode(1);
	TreeNode* node1_2 = new TreeNode(2);
	TreeNode* node1_3 = new TreeNode(3);
	TreeNode* node1_4 = new TreeNode(4);
	TreeNode* node1_5 = new TreeNode(5);
	node1_1->left = node1_2;
	node1_1->right = node1_3;
	node1_3->left = node1_4;
	node1_3->right = node1_5;
	// second tree
	TreeNode* node2_1 = new TreeNode(1);
	TreeNode* node2_2 = new TreeNode(2);
	TreeNode* node2_3 = new TreeNode(3);
	TreeNode* node2_4 = new TreeNode(4);
	TreeNode* node2_5 = new TreeNode(5);
	node2_1->left = node2_2;
	node2_1->right = node2_3;
	node2_3->left = node2_4;
	node2_3->right = node2_5;

	// ACT
	TreeNode* root1 = node1_1;
	TreeNode* root2 = node2_1;

	// ASSERT
	EXPECT_TRUE(IsTwoTreeEqual(root1, root2));

	ReleaseTree(root1);
	ReleaseTree(root2);
}

TEST(TestLeetcodeTreeMiscsClass, TestCheckingTwoTreeNotEqual)
{
	// ARRANGE
	// first tree
	TreeNode* node1_1 = new TreeNode(1);
	TreeNode* node1_2 = new TreeNode(2);
	TreeNode* node1_3 = new TreeNode(3);
	TreeNode* node1_4 = new TreeNode(4);
	TreeNode* node1_5 = new TreeNode(5);
	node1_1->left = node1_2;
	node1_1->right = node1_3;
	node1_3->left = node1_4;
	node1_3->right = node1_5;
	// second tree
	TreeNode* node2_1 = new TreeNode(1);
	TreeNode* node2_2 = new TreeNode(9);
	TreeNode* node2_3 = new TreeNode(3);
	TreeNode* node2_4 = new TreeNode(4);
	TreeNode* node2_5 = new TreeNode(5);
	node2_1->left = node2_2;
	node2_1->right = node2_3;
	node2_3->left = node2_4;
	node2_3->right = node2_5;

	// ACT
	TreeNode* root1 = node1_1;
	TreeNode* root2 = node2_1;

	// ASSERT
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

	ReleaseTree(node5);
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