#include <iostream>
#include <string>
#include <vector>
#include "LeetcodeTreeMiscs.hpp"
#include "AssertClass.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	std::vector<TreeNode*> generateTrees(int n) {
        return CreateBst(1, n);
    }

private:
    std::vector<TreeNode*> CreateBst(int l, int r)
    {
        if (l > r) return std::vector<TreeNode*>{nullptr};

        std::vector<TreeNode*> nodes;

        for (int i = l; i <= r; i++) {
            std::vector<TreeNode*> left = CreateBst(l, i - 1);
            std::vector<TreeNode*> right = CreateBst(i + 1, r);

            CombineLeftAndRight2Subtree(i, left, right, nodes);
        }

        //std::cout << "total size = " << nodes.size() << std::endl; // debug
        return nodes;
    }

    void CombineLeftAndRight2Subtree(int rootVal, std::vector<TreeNode*> &left, std::vector<TreeNode*> &right, std::vector<TreeNode*> &subtree) {
        //std::cout << "\tin create subtree " << std::endl; // debug
        //std::cout << "\t\t left size = " << left.size() << ", right size = " << right.size() << std::endl; // debug
        for ( auto ln : left) {
            for (auto rn : right) {
                TreeNode* root = new TreeNode(rootVal, ln, rn);
                subtree.push_back(root);
            }
        }
        //std::cout << "\t\t subtree total size = " << subtree.size() << std::endl; // debug
    }
};

class TestGenerateTrees
{
public:
	TestGenerateTrees()
	{}

	~TestGenerateTrees()
	{}

	void Example1()
	{
		int n = 3;
		int expected = 5;
		std::cout << "===== Test n = " << n << ", expected number of trees = " << expected << std::endl;

		std::vector<TreeNode*> reslut = this->mSolution.generateTrees(n);

		AssertClass::GetInstance().Assert(reslut.size() == expected);
	}

	void Example2()
	{
		int n = 1;
		int expected = 1;
		std::cout << "===== Test n = " << n << ", expected number of trees = " << expected << std::endl;

		std::vector<TreeNode*> reslut = this->mSolution.generateTrees(n);

		AssertClass::GetInstance().Assert(reslut.size() == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestGenerateTrees test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}