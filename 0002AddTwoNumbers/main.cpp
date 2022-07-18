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
        while(l1->next != nullptr | l2->next != nullptr){
            ListNode *temp = new ListNode(0);
            if(l1->next != nullptr & l2->next != nullptr){
                temp->val = carry > 0 ? l1->val + l2->val + 1 : l1->val + l2->val;
                if(temp->val > 10){
                    temp->val = temp->val - 10;
                    carry = 1;
                }
                else
                    carry = 0;
            }
            else if(l1->next != nullptr){
                temp->val = carry > 0 ? l1->val + 1 : l1->val;
                if(temp->val > 10){ 
                    temp->val = temp->val - 10; 
                    carry = 1; 
                } 
                else 
                    carry = 0;
            }
            else if(l2->next != nullptr){ 
                temp->val = carry > 0 ? l2->val + 1 : l2->val; 
                if(temp->val > 10){ 
                    temp->val = temp->val - 10; 
                    carry = 1; 
                } 
                else 
                    carry = 0;
            }

            cur->next = temp;
            cur = cur->next;
        }
        
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

	void TestInput_2_4_3_And_5_6_7_Output_7_0_8()
	{
		int arr[] = {2, 4, 3};
		ListNode* input1 = ConvertArray2LinkList(arr);
		PrintList(input1);
	}

	void TestInput_0_And_0_Output_0()
	{

	}

	void TestInput_9_9_9_9_9_9_9_And_9_9_9_9_Output_8_9_9_9_0_0_0_1()
	{

	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestLAddTwoNumbers test;
	test.TestInput_2_4_3_And_5_6_7_Output_7_0_8();
	getchar();
	return EXIT_SUCCESS;
}