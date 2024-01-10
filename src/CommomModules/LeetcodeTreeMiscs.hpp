#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <string.h>
#include <queue>
#include "StringMiscs.hpp"

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

inline TreeNode* CreateTreeLeetcodeInputStr(std::string str)
{
    TreeNode* root = nullptr;
    str = RemoveFrontAndEndSquareBracket(str);

    auto createNode = [](std::string val) -> TreeNode* {
        TreeNode* node = nullptr;
        if (val != "null" && val != " null" && 
            val != "" && val != " ") {
            node = new TreeNode(std::stoi(val));
        }
        return node;
    };

    std::string cur;
    if (str.size() > 0) {
        cur = SplitOneData(str);
        root = new TreeNode(std::stoi(cur));

        std::queue<TreeNode*> q;
        q.push(root);
        TreeNode* curNode = nullptr;
        std::string val;
        while(q.size() && str.size()) {
            curNode = q.front();
            q.pop();

            if (curNode) {
                val = SplitOneData(str);
                curNode->left = createNode(val);
                if (curNode->left) q.push(curNode->left);

                val = SplitOneData(str);
                curNode->right = createNode(val);
                if (curNode->right) q.push(curNode->right);
            }
        }
    }
    else std::cout << "no create" << std::endl;

    return root;
}

enum ConvertMethod : int
{
    WithArrayRepretation,
    WithLeetcodeStr,
};

// The function is using in Leetcode tree problem
inline TreeNode* ConvertLeetcodeArray2BinaryTree(std::string* arr, int len, ConvertMethod method = ConvertMethod::WithLeetcodeStr)
{
    TreeNode* root = nullptr;
    if (ConvertMethod::WithArrayRepretation == method) {
        std::cout << "\e[0;31m" << "WARNING!!! Using array representation may be causing problem. Because leetcode string and array are using BFS to create BST." << std::endl;
        root = CreateBinaryTreeNodeFromArray(arr, len, 0);
    }
    else {
        std::ostringstream ss;
        for (int i = 0; i < len; i++){
            if (i != len - 1)
                ss << *(arr + i) << ",";
            else
                ss << *(arr + i);
        }

        std::string str = ss.str();
        root = CreateTreeLeetcodeInputStr(str);
    }
    
    return root;
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

inline std::string ToLeetcodeStr(TreeNode* root)
{
    std::ostringstream ss;

    std::queue<TreeNode*> q;
    q.push(root);
    TreeNode* cur = nullptr;
    size_t idx = 0;
    ss << "[";
    while (q.size() > 0) {
        cur = q.front();
        q.pop();

        if (idx != 0)
            ss << ",";

        if (cur) {
            ss << cur->val;
            
            if (cur->left != nullptr)
                q.push(cur->left);

            if (cur->right != nullptr)
                q.push(cur->right);
        }
        else {
            ss << "null";
        }
        idx = idx + 1;
    }
    ss << "]";

    return ss.str();    
}

inline TreeNode* CopyTree(TreeNode* root)
{
    if (!root)
        return nullptr;
    
    throw "CopyTree not be implement";
}

// Display tree feature
typedef struct _DispTreeNodeInfon
{
    TreeNode* Node = nullptr;
    int Index = -1;

    _DispTreeNodeInfon(TreeNode* n, int idx) : Node(n), Index(idx) { }
}DispTreeNodeInfon;

inline void CollectAllNodes(TreeNode* node, std::vector<std::vector<DispTreeNodeInfon>> &vec, int level)
{
    // std::vector<TreeNode*> temp;
    std::vector<DispTreeNodeInfon> temp;
    if(vec.size() == 0){
        temp.push_back(DispTreeNodeInfon(node, 1));
    }
    else{
        int nullCount = 0;
        int index = vec.size() - 1;
        for(auto e : vec[index]){
            if (e.Node) {
                temp.push_back(DispTreeNodeInfon(e.Node->left, e.Index * 2));
                if(e.Node->left == nullptr)
                    nullCount = nullCount + 1;

                temp.push_back(DispTreeNodeInfon(e.Node->right, (e.Index * 2) + 1));
                if(e.Node->right == nullptr)
                    nullCount = nullCount + 1;
            }
        }

        if(nullCount == temp.size())
            return;
    }
    vec.push_back(temp);

    CollectAllNodes(node, vec, level + 1);
}

inline void PrintBinaryTree(TreeNode* root)
{
    std::vector<std::vector<DispTreeNodeInfon>> nodes;
    CollectAllNodes(root, nodes, 0);

    for(auto v : nodes){
        for(auto e : v){
            if(e.Node != nullptr)
                std::cout << e.Node->val << " ";
            else
                std::cout << "n ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}