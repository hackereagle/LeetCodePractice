#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeLinkListMiscs.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}

	ListNode* rotateRight(ListNode* head, int k) {
        if(!head) 
            return nullptr;

        ListNode* ret = head; 
        ListNode* end = head; 
        int length = 1; 
        while(end->next){ 
            end = end->next; 
            length =length + 1; 
        } 
        std::cout << "len = " << length << std::endl; 
        if(length > 1){ 
            int targetNum = k % length; 
            int remainNum = length - targetNum;  
            std::cout << "targetNum = " << targetNum << ", remainNum = " << remainNum << std::endl; 
             
            if(remainNum < length){ 
                ListNode* newEnd = head; 
                while(remainNum){ 
                    newEnd = ret; 
                    ret = ret->next; 
                    remainNum = remainNum - 1; 
                } 
                end->next = head; 
                newEnd->next = nullptr; 
            } 
            else{ 
                ret = head; 
            } 
        } 
        return ret;
    }

private:
};

class TestRotateRight
{
public:
	TestRotateRight()
	{}

	~TestRotateRight()
	{}

	void TestInput_1_2_3_4_5_k_2_Output_4_5_1_2_3()
	{
        std::cout << "===== head = [1, 2, 3, 4, 5], k = 2, output = [4, 5, 1, 2, 3] =====" << std::endl;
		int arr[] = {1, 2, 3, 4, 5};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
        int arr2[] = {4, 5, 1, 2, 3};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr2);
        int k = 2;

        ListNode* result = mSolution.rotateRight(input, k);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(ans);
        ReleaseList(result);
	}

	void TestInput_0_1_2_k_4_Output_2_0_1()
	{
        std::cout << "===== head = [0, 1, 2], k = 4, output = [2, 0, 1] =====" << std::endl;
		int arr[] = {0, 1, 2};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
        int arr2[] = {2, 0, 1};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr2);
        int k = 4;

        ListNode* result = mSolution.rotateRight(input, k);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(ans);
        ReleaseList(result);
	}

	void TestInput_1_2_k_2_Output_1_2()
	{
        std::cout << "===== head = [1, 2], k = 2, output = [1, 2] =====" << std::endl;
		int arr[] = {1, 2};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
        int arr2[] = {1, 2};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr2);
        int k = 2;

        ListNode* result = mSolution.rotateRight(input, k);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(ans);
        ReleaseList(result);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestRotateRight test;
	test.TestInput_1_2_3_4_5_k_2_Output_4_5_1_2_3();
    test.TestInput_0_1_2_k_4_Output_2_0_1();
    test.TestInput_1_2_k_2_Output_1_2();
	getchar();
	return EXIT_SUCCESS;
}