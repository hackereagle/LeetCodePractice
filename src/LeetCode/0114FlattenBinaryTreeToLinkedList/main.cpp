#include <iostream>
#include <vector>
#include <queue>
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
        if(root){ 
            std::queue<TreeNode*> treeNodes; 
            GetAllNodesOfTreePreorder(root, treeNodes); 
            //std::cout << "========================" << std::endl; 
            AppendToNodeRight(root, treeNodes); 
        } 
    } 
     
private: 
    void GetAllNodesOfTreePreorder(TreeNode* node, std::queue<TreeNode*> &treeNodes) 
    { 
        if(node){ 
            //std::cout << node->val << "," << std::endl; 
            treeNodes.push(node); 
            GetAllNodesOfTreePreorder(node->left, treeNodes); 
            GetAllNodesOfTreePreorder(node->right, treeNodes); 
        } 
    } 
     
    void AppendToNodeRight(TreeNode* node, std::queue<TreeNode*> &treeNodes) 
    { 
        treeNodes.pop(); 
        while(!treeNodes.empty()){ 
            //std::cout << node->val << "," << std::endl; 
            node->left = nullptr; 
            node->right = treeNodes.front(); 
            node = node->right; 
            treeNodes.pop(); 
        } 
        //std::cout << node->val << "," << std::endl; 
    } 
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