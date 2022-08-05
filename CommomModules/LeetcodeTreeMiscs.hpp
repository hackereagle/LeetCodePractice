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

inline TreeNode* ConvertVector2Tree(std::vector<std::string> tree)
{
    TreeNode* root = 0;
    size_t len = tree.size();

    return root;
}

inline std::vector<std::string> ConvertTree2Vector(TreeNode* root)
{
    std::vector<std::string> tree;

    return tree;
}

inline void ReleaseTree(TreeNode* node)
{
    if(node){
        ReleaseTree(node->left);
        ReleaseTree(node->right);
        delete node;
    }
}