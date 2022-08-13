#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeTreeMiscs.hpp"


class Solution {
public: 
    std::vector<int> inorderTraversal(TreeNode* root)     { 
        std::vector<int> result; 
        Travel(root, result); 
        return result; 
    } 
private: 
    void Travel(TreeNode* node, std::vector<int> &nums) 
    { 
        if(node){ 
            Travel(node->left, nums); 
            nums.push_back(node->val); 
            Travel(node->right, nums); 
        } 
    }
};

class TestinorderTraversal
{
public:
	TestinorderTraversal()
	{}

	~TestinorderTraversal()
	{}
	

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestinorderTraversal test;
	getchar();
	return EXIT_SUCCESS;
}