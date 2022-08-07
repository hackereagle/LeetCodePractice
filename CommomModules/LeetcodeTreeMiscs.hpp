#pragma once
#include <string>
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

// The function is using in Leetcode tree problem
inline TreeNode* ConvertLeetcodeArray2Tree(std::string* tree, int count)
{
    TreeNode* root = 0;

	for(int i = 0; i < count; i++){

        if(!root){

            root = new TreeNode();
        }

    }

    return root;
}

// The function is using in Leetcode tree problem
inline TreeNode* ConvertLeetcodeVector2Tree(std::vector<std::string> tree)
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

inline bool IsTwoTreeEqual(TreeNode* l, TreeNode* r)
{
    if(l->val != r->val){
        return false;
    }

    bool leftEqual = IsTwoTreeEqual(l->left, r->left);
    bool rightEqual = IsTwoTreeEqual(l->right, r->right);

    return leftEqual & rightEqual;
}

inline void ReleaseTree(TreeNode* node)
{
    if(node){
        ReleaseTree(node->left);
        ReleaseTree(node->right);
        std::cout << "node [" << node->val << "] deleted" << std::endl;
        delete node;
    }
}