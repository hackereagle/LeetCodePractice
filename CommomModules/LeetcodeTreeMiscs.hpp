#pragma once
#include <vector>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline TreeNode* ConvertArray2Tree(int* array, int count)
{
    TreeNode* root = 0;
    return root;
}

void ReleaseTree(TreeNode* node)
{
    if(node){
        ReleaseTree(node->left);
        ReleaseTree(node->right);
        delete node;
    }
}