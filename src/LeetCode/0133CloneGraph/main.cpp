#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeGraphMiscs.hpp"

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution
{
public:
	Solution() 
    { 
        memset((void*)&this->mNodes[0], 0, sizeof(Node*) * 100); 
    }

    ~Solution() 
    { 
        /*for(int i = 0; i < 100; i++){ 
            if(this->mNodes[i]){ 
                delete this->mNodes[i]; 
                this->mNodes[i] = nullptr; 
            } 
        }*/ 
    }

    Node* cloneGraph(Node* node) { 
        Node* ret = nullptr; 
        if(node){ 
            ret = this->mNodes[node->val - 1]; 
            if(!ret){ 
                ret = new Node(); 
                ret->val = node->val; 
                this->mNodes[node->val - 1] = ret; 
                 
                for(auto n : node->neighbors){ 
                    Node* newNode = cloneGraph(n); 
                    ret->neighbors.push_back(newNode); 
                } 
            } 
        } 
        return ret; 
    } 
private: 
    Node* mNodes[100];

private:
};

class TestCloneGraph
{
public:
	TestCloneGraph()
	{}

	~TestCloneGraph()
	{}

	void TestInput_2_4_1_3_2_4_1_3_Output()
	{
        std::cout << "===== input = [[2,4], [1,3], [2,4], [1, 3]], output = [[2,4], [1,3], [2,4], [1, 3]] =====" << std::endl;
		int arr[] = {1, 2, 2, 1};
		Node* input = nullptr;

        Node* result = mSolution.cloneGraph(input);
        //AssertClass::GetInstance().Assert(result == ans);

        //ReleaseList(input);
	}

	void TestInput_Node_Empty_Output()
	{
        std::cout << "===== input = [[]], output = [[]] =====" << std::endl;
		int arr[] = {1, 2, 2, 1};
		Node* input = nullptr;

        Node* result = mSolution.cloneGraph(input);
        //AssertClass::GetInstance().Assert(result == ans);

        //ReleaseList(input);
	}

	void TestInput_Empty_Graph_Output()
	{
        std::cout << "===== input = [], output = [] =====" << std::endl;
		int arr[] = {1, 2, 2, 1};
		Node* input = nullptr;

        Node* result = mSolution.cloneGraph(input);
        //AssertClass::GetInstance().Assert(result == ans);

        //ReleaseList(input);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestCloneGraph test;
	test.TestInput_2_4_1_3_2_4_1_3_Output();
    test.TestInput_Node_Empty_Output();
    test.TestInput_Empty_Graph_Output();
	getchar();
	return EXIT_SUCCESS;
}