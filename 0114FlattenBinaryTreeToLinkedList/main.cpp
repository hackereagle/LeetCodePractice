#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeTreeMiscs.hpp"


class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}

	void flatten(TreeNode* root) {
        
    }

private:
};

class TestFlattenBinaryTreeToLinkedList
{
public:
	TestFlattenBinaryTreeToLinkedList()
	{}

	~TestFlattenBinaryTreeToLinkedList()
	{}
	
	void TestInput_1_2_5_3_4_null_6()
	{
	}

	void TestInput_Empty()
	{
	}

	void TestInput_0()
	{
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestFlattenBinaryTreeToLinkedList test;
	test.TestInput_1_2_5_3_4_null_6();
	test.TestInput_Empty();
	test.TestInput_0();
	getchar();
	return EXIT_SUCCESS;
}