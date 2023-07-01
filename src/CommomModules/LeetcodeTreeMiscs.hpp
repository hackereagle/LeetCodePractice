#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <string.h>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline TreeNode* CreateBinaryTreeNodeFromArray(std::string *arr, int len, int idx)
{
    TreeNode* node = nullptr;
    if(*(arr + idx) != "null"){
        int val = atoi((arr + idx)->c_str());
        node = new TreeNode(val);

        int lIdx = (idx * 2) + 1;
        if(lIdx < len){
            node->left = CreateBinaryTreeNodeFromArray(arr, len, lIdx);
        }

        int rIdx = (idx * 2) + 2;
        if(rIdx < len){
            node->right = CreateBinaryTreeNodeFromArray(arr, len, rIdx);
        }
    }

    return node;
}

// The function is using in Leetcode tree problem
inline TreeNode* ConvertLeetcodeArray2BinaryTree(std::string* arr, int len)
{
    return CreateBinaryTreeNodeFromArray(arr, len, 0);
}

// The function is using in Leetcode tree problem
inline TreeNode* ConvertLeetcodeVector2BinaryTree(std::vector<std::string> vec)
{
    TreeNode* node = nullptr;
    int len = vec.size();
    if(len > 0){
        std::string* arr = new std::string[len];
        memset(arr, 0, sizeof(int) * len); 
        for(int i = 0; i < len; i++){ 
            *(arr + i) = vec.at(i); 
        } 
     
        node = CreateBinaryTreeNodeFromArray(arr, len, 0); 
        delete [] arr;
    }

    return node; 
}

inline void CollectAllNodes(TreeNode* node, std::vector<std::vector<TreeNode*>> &vec)
{
    std::vector<TreeNode*> temp;
    if(vec.size() == 0){
        temp.push_back(node);
    }
    else{
        int nullCount = 0;
        int index = vec.size() - 1;
        for(auto e : vec[index]){
            if (e) {
                temp.push_back(e->left);
                if(e->left == nullptr)
                    nullCount = nullCount + 1;

                temp.push_back(e->right);
                if(e->right == nullptr)
                    nullCount = nullCount + 1;
            }
        }

        if(nullCount == temp.size())
            return;
    }
    vec.push_back(temp);

    CollectAllNodes(node, vec);
}

inline void PrintBinaryTree(TreeNode* root)
{
    std::vector<std::vector<TreeNode*>> nodes;
    CollectAllNodes(root, nodes);

    for(auto v : nodes){
        for(auto e : v){
            if(e != nullptr)
                std::cout << e->val << " ";
            else
                std::cout << "n ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

inline std::vector<std::string> ConvertTree2Vector(TreeNode* root)
{
    std::vector<std::string> tree;

    return tree;
}

inline bool IsTwoTreeEqual(TreeNode* l, TreeNode* r)
{
    if (l == nullptr && r == nullptr) {
        return true;
    }
    else if (l == nullptr && r != nullptr ||
             l != nullptr && r == nullptr) {
        return false;
    }
    else if (l->val != r->val) {
        return false;
    }

    bool leftEqual = IsTwoTreeEqual(l->left, r->left);
    bool rightEqual = IsTwoTreeEqual(l->right, r->right);

    return leftEqual & rightEqual;
}

inline void ReleaseTree(TreeNode* &node)
{
    if(node){
        ReleaseTree(node->left);
        ReleaseTree(node->right);
        std::cout << "node [" << node->val << "] deleted" << std::endl;
        delete node;
        node = nullptr;
    }
}

inline TreeNode* CopyTree(TreeNode* root)
{
    if (!root)
        return nullptr;
    
    throw "CopyTree not be implement";
}