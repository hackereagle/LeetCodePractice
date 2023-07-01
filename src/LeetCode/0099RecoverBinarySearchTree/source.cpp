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

class TestIsValid
{
public:
	TestIsValid()
	{}

	~TestIsValid()
	{}

	void Example1()
	{
		#if 0
		std::string input = "()";
		std::cout << "===== Test input \"" << input << "\", output true =====" << std::endl;

		bool result = this->mSolution.isValid(input);

		AssertClass::GetInstance().Assert(result == true);
		#endif
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsValid test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}