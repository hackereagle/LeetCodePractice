#include <iostream>
#include <string>
#include "LeetcodeTreeMiscs.hpp"
#include "OtherMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool isValidBST(TreeNode* root) {
		if (root == nullptr)
			return true;

		bool _isValidBst = true;
		if (root->left) {
			if(IsAllSubtreeLessThanParents(root, root->left)) {
				_isValidBst = _isValidBst && isValidBST(root->left);
			}
			else {
				return false;
			}
		}

		if (root->right) {
			if(IsAllSubtreeBiggerThanParents(root, root->right)) {
				_isValidBst = _isValidBst && isValidBST(root->right);
			}
			else {
				return false;
			}
		}

		return _isValidBst;
	}

private:

	bool IsAllSubtreeLessThanParents(TreeNode* parent, TreeNode* subtree)
	{
		if (subtree == nullptr)
			return true;
		
		if (subtree->val >= parent->val)
			return false;
		
		bool leftLess = IsAllSubtreeLessThanParents(parent, subtree->left);
		bool rightLess = IsAllSubtreeLessThanParents(parent, subtree->right);
		return leftLess && rightLess;
	}

	bool IsAllSubtreeBiggerThanParents(TreeNode* parent, TreeNode* subtree)
	{
		if (subtree == nullptr)
			return true;

		if (subtree->val <= parent->val)
			return false;

		bool leftBigger = IsAllSubtreeBiggerThanParents(parent, subtree->left);
		bool rightBigger = IsAllSubtreeBiggerThanParents(parent, subtree->right);
		return leftBigger && rightBigger;
	}
};

class TestIsValidBST
{
public:
	TestIsValidBST()
	{}

	~TestIsValidBST()
	{}

	void Example1()
	{
		// ARRANGE
		TreeNode* root = CreateTreeLeetcodeInputStr("[2,1,3]");
		bool expectedOutput = true;
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isValidBST(root);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
		delete root;
	}

	void Example2()
	{
		// ARRANGE
		TreeNode* root = CreateTreeLeetcodeInputStr("[5,1,4,null,null,3,6]");
		bool expectedOutput = false;
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isValidBST(root);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
		delete root;
	}

	void Example3()
	{
		// ARRANGE
		TreeNode* root = CreateTreeLeetcodeInputStr("[1,1]");
		bool expectedOutput = false;
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isValidBST(root);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
		delete root;
	}

	void Example4()
	{
		// ARRANGE
		TreeNode* root = CreateTreeLeetcodeInputStr("[1,null,1]");
		bool expectedOutput = false;
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isValidBST(root);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
		delete root;
	}

	void Example5()
	{
		// ARRANGE
		TreeNode* root = CreateTreeLeetcodeInputStr("[5,4,6,null,null,3,7]");
		bool expectedOutput = false;
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isValidBST(root);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
		delete root;
	}

	void Example6()
	{
		// ARRANGE
		TreeNode* root = CreateTreeLeetcodeInputStr("[120,70,140,50,100,130,160,20,55,75,110,119,135,150,200]");
		bool expectedOutput = false;
		std::cout << "===== Test root = " << ToLeetcodeStr(root) << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isValidBST(root);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
		delete root;
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsValidBST test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}