#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "AssertClass.hpp"
#include "LeetcodeTreeMiscs.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    // Encodes a tree to a single string. 
    std::string serialize(TreeNode* root) { 
        if(!root) { 
         return "null,"; 
        } 
        return std::to_string(root->val)+","+serialize(root->left)+serialize(root->right); 
    } 

    // Decodes your encoded data to tree. 
    TreeNode* deserialize(std::string data) { 
        std::cout << data << std::endl; 
        TreeNode* ret = nullptr; 
        std::queue<std::string> arr = this->SplitString(data, ","); 
        std::cout << arr.size() << std::endl; // debug
        return this->CreateTree(arr); 
    } 

private: 
    std::queue<std::string> SplitString(std::string str, std::string ch){ 
        std::queue<std::string> ret; 
        if(str.size() > 0){ 
            size_t pos = -1; 
            while((pos = str.find(ch)) != std::string::npos){ 
                ret.push(str.substr(0, pos)); 
                str.erase(0, pos + ch.size()); 
            } 
            ret.push(str); 
        } 
        return ret; 
    } 

    TreeNode* CreateTree(std::queue<std::string> &q){ 
        TreeNode* node = nullptr; 
         
        std::string s = q.front(); 
        q.pop(); 
        std::cout << "In CreateTree: " << s << std::endl; // debug
        if(s != "null"){ 
            node = new TreeNode(std::stoi(s)); 
            node->left = this->CreateTree(q); 
            node->right = this->CreateTree(q); 
        } 
         
        return node; 
    }
};

class TestSerializeAndDeserializeBinaryTree
{
public:
	TestSerializeAndDeserializeBinaryTree()
	{}

	~TestSerializeAndDeserializeBinaryTree()
	{}

    void Example1()
    {
        std::cout << "Tree root: [1,2,3,null,null,4,5]" << std::endl;
        std::vector<std::string> temp({"1","2","3","null","null","4","5"});
        TreeNode *root = ConvertLeetcodeVector2BinaryTree(temp);

        TreeNode* result = this->mSolution.deserialize(this->mSolution.serialize(root));
        std::cout << "yo" << std::endl;
        AssertClass::GetInstance().Assert(IsTwoTreeEqual(root, result), "Two tree is equal!");
    }

    void Example2()
    {
        std::cout << "Tree root: []" << std::endl;
        std::vector<std::string> temp;
        TreeNode *root = ConvertLeetcodeVector2BinaryTree(temp);

        TreeNode* result = this->mSolution.deserialize(this->mSolution.serialize(root));
        AssertClass::GetInstance().Assert(IsTwoTreeEqual(root, result), "Two tree is equal!");
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestSerializeAndDeserializeBinaryTree test;
    test.Example1();
    test.Example2();
	getchar();
	return EXIT_SUCCESS;
}