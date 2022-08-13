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

	ListNode* RemoveNthFromEnd(ListNode* head, int n)
	{
		std::vector<ListNode*> addrTable;
        ListNode** ptr = &head;
        while(*ptr){
            addrTable.push_back(*ptr);
            ptr = &(*ptr)->next;
        }
        
        int len = addrTable.size();
		if(n == len){
			if(len > 1)
				head = addrTable[0]->next;
			else
				head = nullptr;
            delete addrTable[0];
		}
		else if(n == 1){
			addrTable[len - 2]->next = nullptr;
            delete addrTable[len - 1];
		}
        else if(n < len){
			int targetIdx = len - n;
            int preNodeIdx = targetIdx - 1;
            int nextNodeIdx = targetIdx + 1;
			addrTable[preNodeIdx]->next = addrTable [nextNodeIdx];
            delete addrTable[targetIdx];
        }

		return head;
	}

private:
};

class TestRemoveNthFromEnd
{
public:
	TestRemoveNthFromEnd()
	{}

	~TestRemoveNthFromEnd()
	{}
	
	void TestInput_1_2_3_4_5_n_2_Output_1_2_3_5()
	{
		int arr[] = {1, 2, 3, 4, 5};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
		int arr2[] = {1, 2, 3, 5};
		ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr2);

		ListNode* result = mSolution.RemoveNthFromEnd(input, 2);
		PrintList(result);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(input);
		ReleaseList(ans);
	}

	void TestInput_1_n_1_Output_Empty()
	{
		int arr[] = {1};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
		ListNode* ans = nullptr;

		ListNode* result = mSolution.RemoveNthFromEnd(input, 1);
		PrintList(result);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(input);
		ReleaseList(ans);
	}

	void TestInput_1_2_n_1_Output_1()
	{
		int arr[] = {1, 2};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
		int arr2[] = {1};
		ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr2);

		ListNode* result = mSolution.RemoveNthFromEnd(input, 1);
		PrintList(result);

		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

		ReleaseList(input);
		ReleaseList(ans);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestRemoveNthFromEnd test;
	test.TestInput_1_2_3_4_5_n_2_Output_1_2_3_5();
	test.TestInput_1_n_1_Output_Empty();
	test.TestInput_1_2_n_1_Output_1();
	getchar();
	return EXIT_SUCCESS;
}