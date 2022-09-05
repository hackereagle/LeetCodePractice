#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeLinkListMiscs.hpp"

class Solution
{
public:
	~Solution()
	{}

	Solution()
    {
    }

    ListNode* swapPairs(ListNode* head) {
        return helper(nullptr, head);; 
    } 
private: 
    ListNode* helper(ListNode* pre, ListNode* cur) 
    { 
        if(!cur){ 
            return nullptr; 
        } 
             
        ListNode* temp = cur; 
        if(!cur->next) 
            return cur; 
        cur = cur->next;  
        temp->next = cur->next;  
        cur->next = temp; 
         
        temp->next = helper(temp, temp->next); 
         
        return cur; 
    }
};

class TestSwapPairs
{
public:
	TestSwapPairs()
	{}

	~TestSwapPairs()
	{}

    void Test_Input_1_2_3_4_Output_2_1_3_4()
    {
        std::cout << "========= Test input [1, 2, 3, 4] and output [2, 1, 4, 3] =========" << std::endl;
        int n = 1;

    }

    void Test_Input_Empty_Output_Empty()
    {
        std::cout << "========= Test input [] and output [] =========" << std::endl;
        int n = 1;

    }

    void Test_Input_1_Output_1()
    {
        std::cout << "========= Test input [1] and output [1] =========" << std::endl;
        int n = 1;

    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestSwapPairs test;
    test.Test_Input_1_2_3_4_Output_2_1_3_4();
    test.Test_Input_Empty_Output_Empty();
    test.Test_Input_1_Output_1();
	getchar();
	return EXIT_SUCCESS;
}