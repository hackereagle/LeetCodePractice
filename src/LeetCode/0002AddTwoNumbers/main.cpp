#include <iostream>
#include <vector>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"
#include "LeetcodeLinkListMiscs.hpp"


class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}

	ListNode* AddTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int carry = 0;
        ListNode head = ListNode(0);
        ListNode *cur = &head;
        while(l1 != nullptr | l2 != nullptr){
            ListNode *temp = new ListNode(0);
            if(l1 != nullptr & l2 != nullptr){
                temp->val = carry > 0 ? l1->val + l2->val + 1 : l1->val + l2->val;
                if(temp->val > 9){
                    temp->val = temp->val - 10;
                    carry = 1;
                }
                else
                    carry = 0;
                
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != nullptr){
                temp->val = carry > 0 ? l1->val + 1 : l1->val;
                if(temp->val > 9){ 
                    temp->val = temp->val - 10; 
                    carry = 1; 
                } 
                else 
                    carry = 0;
                l1 = l1->next;
            }
            else if(l2 != nullptr){ 
                temp->val = carry > 0 ? l2->val + 1 : l2->val; 
                if(temp->val > 9){ 
                    temp->val = temp->val - 10; 
                    carry = 1; 
                } 
                else 
                    carry = 0;
                l2 = l2->next;
            }

            cur->next = temp;
            cur = cur->next;

        }

        if(carry > 0)
            cur->next = new ListNode(1);
        
        return head.next;
	}

private:
};

class TestLAddTwoNumbers
{
public:
	TestLAddTwoNumbers()
	{}

	~TestLAddTwoNumbers()
	{}

	void TestInput_2_4_3_And_5_6_4_Output_7_0_8()
	{
		int arr[] = {2, 4, 3};
		ListNode* input1 = CONVERT_ARRAY_2_LINK_LIST(arr);
		int arr2[] = {5, 6, 4};
		ListNode* input2 = CONVERT_ARRAY_2_LINK_LIST(arr2);
        int arr3[] = {7, 0, 8};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr3);

        ListNode* result = mSolution.AddTwoNumbers(input1, input2);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(input1);
        ReleaseList(input2);
        ReleaseList(ans);
        ReleaseList(result);
	}

	void TestInput_0_And_0_Output_0()
	{
		int arr[] = {0};
		ListNode* input1 = CONVERT_ARRAY_2_LINK_LIST(arr);
		int arr2[] = {0};
		ListNode* input2 = CONVERT_ARRAY_2_LINK_LIST(arr2);
        int arr3[] = {0};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr3);

        ListNode* result = mSolution.AddTwoNumbers(input1, input2);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(input1);
        ReleaseList(input2);
        ReleaseList(ans);
        ReleaseList(result);

	}

	void TestInput_9_9_9_9_9_9_9_And_9_9_9_9_Output_8_9_9_9_0_0_0_1()
	{
		int arr[] = {9, 9, 9, 9, 9, 9, 9};
		ListNode* input1 = CONVERT_ARRAY_2_LINK_LIST(arr);
		int arr2[] = {9, 9, 9, 9};
		ListNode* input2 = CONVERT_ARRAY_2_LINK_LIST(arr2);
        int arr3[] = {8, 9, 9, 9, 0, 0, 0, 1};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr3);

        ListNode* result = mSolution.AddTwoNumbers(input1, input2);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(input1);
        ReleaseList(input2);
        ReleaseList(ans);
        ReleaseList(result);

	}

	void TestInput_Empty_And_Empty_Output_Empty()
	{
		ListNode* input1 = nullptr;
		ListNode* input2 = nullptr;
        ListNode* ans = nullptr;

        ListNode* result = mSolution.AddTwoNumbers(input1, input2);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(result);
	}

	void TestInput_Empty_And_1_2_3_Output_1_2_3()
	{
		ListNode* input1 = nullptr;
		int arr2[] = {1, 2, 3};
		ListNode* input2 = CONVERT_ARRAY_2_LINK_LIST(arr2);
        int arr3[] = {1, 2, 3};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr3);

        ListNode* result = mSolution.AddTwoNumbers(input1, input2);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        ReleaseList(input2);
        ReleaseList(ans);
        ReleaseList(result);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestLAddTwoNumbers test;
	test.TestInput_2_4_3_And_5_6_4_Output_7_0_8();
    test.TestInput_0_And_0_Output_0();
    test.TestInput_9_9_9_9_9_9_9_And_9_9_9_9_Output_8_9_9_9_0_0_0_1();
    test.TestInput_Empty_And_Empty_Output_Empty();
    test.TestInput_Empty_And_1_2_3_Output_1_2_3();
	getchar();
	return EXIT_SUCCESS;
}