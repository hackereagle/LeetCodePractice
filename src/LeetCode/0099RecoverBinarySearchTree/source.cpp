#include <iostream>
#include <string>
#include <vector>
#include "LeetcodeTreeMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	void recoverTree(TreeNode* root) {
        FindAbnormalSubTree(root);
        if (_abnormalCount == 1) {
            std::swap(_first.Pre->val, _first.Node->val);
        }
        else {
            std::swap(_first.Pre->val, _second.Node->val);
        }
    }

private:
    typedef struct _abnormalSubTree
    {
        TreeNode* Pre = nullptr;
        TreeNode* Node = nullptr;
    } AbnormalSubTree;
    AbnormalSubTree _first;
    AbnormalSubTree _second;
    int _abnormalCount = 0;
    TreeNode* pre = nullptr;
    TreeNode* cur = nullptr;

    void FindAbnormalSubTree(TreeNode* node)
    {
        if (node) {
            FindAbnormalSubTree(node->left);

            pre = cur;
            cur = node;
            if (pre && cur) {
                CheckCondition(pre, cur);
            }
            FindAbnormalSubTree(node->right);
        }
    }

    void CheckCondition(TreeNode* pre, TreeNode* cur)
    {
        if (pre->val > cur->val) {
            if (_abnormalCount == 0) {
                _first.Pre = pre;
                _first.Node = cur;
                _abnormalCount = _abnormalCount + 1;
            }
            else {
                _second.Pre = pre;
                _second.Node = cur;
                _abnormalCount = _abnormalCount + 1;
            }
        }
    }
};

class TestRecoverTree
{
public:
	TestRecoverTree()
	{}

	~TestRecoverTree()
	{}

	void Example1()
	{
		std::string rootStr = "[1,3,null,null,2]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[3,1,null,null,2]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;

		this->mSolution.recoverTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

	void Example2()
	{
		std::string rootStr = "[3,1,4,null,null,2]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[2,1,4,null,null,3]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;
		// debug
		std::cout << "expected tree = \n";
		PrintBinaryTree(expectedRoot);
		std::cout << "input tree = \n";
		PrintBinaryTree(root);

		this->mSolution.recoverTree(root);
		std::cout << "after recover tree = \n";
		PrintBinaryTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

	void Example3()
	{
		std::string rootStr = "[6,1,10,null,null,7,null,null,13]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[6,1,13,null,null,7,null,null,10]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;
		std::cout << "expected tree = \n";
		PrintBinaryTree(expectedRoot);
		std::cout << "input tree = \n";
		PrintBinaryTree(root);

		this->mSolution.recoverTree(root);
		std::cout << "after recover tree = \n";
		PrintBinaryTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

	void Example4()
	{
		std::string rootStr = "[2,3,1]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[2,1,3]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;
		std::cout << "expected tree = \n";
		PrintBinaryTree(expectedRoot);
		std::cout << "input tree = \n";
		PrintBinaryTree(root);

		this->mSolution.recoverTree(root);
		std::cout << "after recover tree = \n";
		PrintBinaryTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

	void Example5()
	{
		std::string rootStr = "[2,3,4,null,null,1]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[2,1,4,null,null,3]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;

		this->mSolution.recoverTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

	void Example6()
	{
		std::string rootStr = "[146,71,-13,55,null,231,399,321,null,null,null,null,null,-33]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[146,71,321,55,null,231,399,-13,null,null,null,null,null,-33]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;

		this->mSolution.recoverTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

	void Example7()
	{
		std::string rootStr = "[3,4,1,null,2]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[3,1,4,null,2]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;

		this->mSolution.recoverTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

	void Example8()
	{
		std::string rootStr = "[50,30,70,20,40,25,82,10,60,null,null,58,65,75,null,null,null,24,26,null,59,62,null,null,null,22,null,null,null,null,null,null,null,null,23,null,null]";
		TreeNode* root = CreateTreeLeetcodeInputStr(rootStr);
		std::string expectedRootStr = "[50,30,70,20,40,60,82,10,25,null,null,58,65,75,null,null,null,24,26,null,59,62,null,null,null,22,null,null,null,null,null,null,null,null,23]";
		TreeNode* expectedRoot = CreateTreeLeetcodeInputStr(expectedRootStr);
		std::cout << "===== Test root = " << rootStr << ", output = " << expectedRootStr << " =====" << std::endl;

		this->mSolution.recoverTree(root);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expectedRoot, root));
		ReleaseTree(root);
		ReleaseTree(expectedRoot);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestRecoverTree test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	getchar();
	return EXIT_SUCCESS;
}