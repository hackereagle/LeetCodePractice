#include <iostream>
#include <vector>
#include <string>
#include "LeetcodeTreeMiscs.hpp"
#include "AssertClass.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *	 int val;
 *	 TreeNode *left;
 *	 TreeNode *right;
 *	 TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *	 TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *	 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<int> rightSideView(TreeNode* root) {
		std::vector<int> res;

		TraversalRightSide(root, res, 1);
		return res;
	}


private:
	void TraversalRightSide(TreeNode* node, std::vector<int> &res, int level)
	{
		if (!node)
			return;

		if (level > res.size())
			res.push_back(node->val);
			
		if (node->right) {
			TraversalRightSide(node->right, res, level + 1);
		}

		if (node->left) {
			TraversalRightSide(node->left, res, level + 1);
		}
	}
};

class TestThreeSum
{
public:
	TestThreeSum()
	{}

	~TestThreeSum()
	{}

	void Example1()
	{
		// std::string nodes = "[1,2,3,null,5,null,4]";
		// TreeNode* input = CreateBinaryTreeNodeFromArray(nodes);
		// std::cout << "===== Test input \"" << input << "\", output true =====" << std::endl;

		// bool reslut = this->mSolution.isValid(input);

		// AssertClass::GetInstance().Assert(reslut == true);
	}


private:
	Solution mSolution;

	TreeNode* CreateTreeByLeetcodeInputString(std::string str)
	{

	}
};

int main(int argc, char** argv)
{
	TestThreeSum test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}