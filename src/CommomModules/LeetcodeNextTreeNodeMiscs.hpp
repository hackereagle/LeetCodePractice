#pragma once

#include "LeetcodeTreeMiscs.hpp"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next = nullptr)
        : val(_val), left(_left), right(_right), next(_next) {}
};

inline Node* CreateNextTreeNothingNextWithLeetcodeInputStr(std::string str)
{
    Node* root = nullptr;
    str = RemoveFrontAndEndSquareBracket(str);

    auto createNode = [](std::string val) -> Node* {
        Node* node = nullptr;
        if (val != "null" && val != " null" && 
            val != "" && val != " ") {
            node = new Node(std::stoi(val));
        }
        return node;
    };

    std::string cur;
    if (str.size() > 0) {
        cur = SplitOneData(str);
        root = new Node(std::stoi(cur));

        std::queue<Node*> q;
        q.push(root);
        Node* curNode = nullptr;
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

inline void ReleaseNextTree(Node* &node)
{
    if(node){
		node->next = nullptr;
        ReleaseNextTree(node->left);
        ReleaseNextTree(node->right);
        std::cout << "node [" << node->val << "] deleted" << std::endl;
        delete node;
        node = nullptr;
    }
}

inline std::string ToLeetcodeStr(Node* root)
{
    std::ostringstream ss;

    std::queue<Node*> q;
    q.push(root);
    Node* cur = nullptr;
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

inline std::string ToLeetcodeAnsStr(Node* root)
{
    std::ostringstream ss;

    std::queue<Node*> q;
    q.push(root);
    Node* cur = nullptr;
    size_t idx = 0;
    ss << "[";
    while (q.size() > 0) {
        cur = q.front();
        q.pop();

        if (idx != 0)
            ss << ",";
		
        if (cur) {
            ss << cur->val;

			if (!cur->next)
				ss << ",#";
            
            if (cur->left != nullptr)
                q.push(cur->left);

            if (cur->right != nullptr)
                q.push(cur->right);
        }
        // else {
        //     ss << "null";
        // }
        idx = idx + 1;
    }
    ss << "]";

    return ss.str();    
}