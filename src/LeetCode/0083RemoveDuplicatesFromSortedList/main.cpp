#include <iostream>
#include <vector>
#include "AssertClass.hpp"
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
class Solution {
public:
    Solution() 
	{
    }

    ~Solution() 
	{
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        for (ListNode* cur = head, *next = head; cur;) {
            //std::cout << cur->val << " "; // debug
            next = cur->next;

            if (next && cur->val == next->val) {
                cur->next = next->next;
                delete next;
                next = cur;
            }
            else{
                cur = cur->next;
            }
        }

        return head;
    }
};

class TestDeleteDuplicates
{
public:
	TestDeleteDuplicates()
	{}

	~TestDeleteDuplicates()
	{}
	
	void Example1()
	{
		int input[] = {1,1,2};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(input);
		int ansArr[] = {1,2};
		ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(ansArr);
		std::cout << "===== input head = " << List2Str(head) << ", expected output = " << List2Str(ans) << " =====" << std::endl;

		ListNode* result = this->mSolution.deleteDuplicates(head);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(head);
		ReleaseList(ans);
	}

	void Example2()
	{
		int input[] = {1,1,2,3,3};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(input);
		int ansArr[] = {1,2,3};
		ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(ansArr);
		std::cout << "===== input head = " << List2Str(head) << ", expected output = " << List2Str(ans) << " =====" << std::endl;

		ListNode* result = this->mSolution.deleteDuplicates(head);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(head);
		ReleaseList(ans);
	}

	void TestOneElement()
	{
		int input[] = {1};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(input);
		int ansArr[] = {1};
		ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(ansArr);
		std::cout << "===== Test only one element: input head = " << List2Str(head) << ", expected output = " << List2Str(ans) << " =====" << std::endl;

		ListNode* result = this->mSolution.deleteDuplicates(head);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(head);
		ReleaseList(ans);
	}

	void TestAllSameEle()
	{
		int input[] = {1,1,1,1,1};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(input);
		int ansArr[] = {1};
		ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(ansArr);
		std::cout << "===== Test all same element: input head = " << List2Str(head) << ", expected output = " << List2Str(ans) << " =====" << std::endl;

		ListNode* result = this->mSolution.deleteDuplicates(head);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(head);
		ReleaseList(ans);
	}

	void TestEmpytArray()
	{
		int input[] = {};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(input);
		int ansArr[] = {};
		ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(ansArr);
		std::cout << "===== Test empyt array: = " << List2Str(head) << ", expected output = " << List2Str(ans) << " =====" << std::endl;

		ListNode* result = this->mSolution.deleteDuplicates(head);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(head);
		ReleaseList(ans);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestDeleteDuplicates test;
	test.Example1();
	test.Example2();
	test.TestOneElement();
	test.TestAllSameEle();
	test.TestEmpytArray();
	getchar();
	return EXIT_SUCCESS;
}