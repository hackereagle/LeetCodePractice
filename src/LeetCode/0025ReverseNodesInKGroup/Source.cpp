#include <iostream>
#include "LeetcodeLinkListMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	ListNode* reverseKGroup(ListNode* head, int k) { 
		//std::cout << "===== head = " << head << ", k = " << k << std::endl; // debug
		//this->PrintListWithAddress(head); // debug
		if (!head)
			return head;

		ListNode* ret = nullptr;

		ListNode* cur = head;
		ListNode* end = cur;
		ListNode* groupHead = nullptr;
		ListNode* groupTail = nullptr;
		ListNode* lastGroupTail = nullptr;
		while (end != nullptr) {
			int count = 1;
			while (end != nullptr && count < k) {
				if (end->next)
					count = count + 1;
				end = end->next;
			}
			//std::cout << "end = " << end << std::endl; // debug
	
			//std::cout << "count = " << count << std::endl; // debug
			if (count != k)
				break;
	
			groupTail = cur;
			ListNode* last = cur;
			ListNode* next = cur->next;
			//std::cout << "begin reverse element in group" << std::endl; // debug
			while (cur != end) {
				// arrange position
				cur = next;
				if (!cur) 
					break;
				next = cur->next;
				//std::cout << "\tcur = " << cur << ", next = " << next << ", last" << last << std::endl;  // debug
				
				// begin reverse
				cur->next = last; 
				last = cur;
			}
			
			if (groupHead == nullptr) {
				ret = cur;
				groupHead = cur;
			}
			else {
				groupHead = cur;
				lastGroupTail->next = groupHead;
			}
			groupTail->next = next;
			lastGroupTail = groupTail;
			//std::cout << "groupHead = " << groupHead << ", groupTail = " << groupTail << ", lastGroupTail = " << lastGroupTail << std::endl; // debug

			cur = next;
			end = cur;
		}
		
		//this->PrintList(ret); // debug
		return ret;
	}

private: 
	void PrintList(ListNode* head) 
	{ 
		std::cout << "["; 
		while (head) { 
			std::cout << " " << head->val; 
			head = head->next; 
		} 
		std::cout << "]" << std::endl; 
	}

	void PrintListWithAddress(ListNode* head) 
	{ 
		std::cout << "["; 
		while (head) { 
			std::cout << " " << head; 
			head = head->next; 
		} 
		std::cout << "]" << std::endl; 
	}
};

class TestReverseKGroup
{
public:
	TestReverseKGroup()
	{}

	~TestReverseKGroup()
	{}

	void Example1()
	{
        // arrange
        ListNode* head = ConvertVector2LinkList({1, 2, 3, 4, 5});
        int k = 3;
        ListNode* expected = ConvertVector2LinkList({3, 2, 1, 4, 5});
		std::cout << "===== Test input " << List2Str(head) << ", k = " << k << ". output = " << List2Str(expected) << " =====" << std::endl;

        // action
		ListNode *result = this->mSolution.reverseKGroup(head, k);

        // assert
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expected));

        ReleaseList(head);
        ReleaseList(expected);
	}

	void Example2()
	{
        // arrange
        ListNode* head = ConvertVector2LinkList({1, 2, 3, 4, 5});
        int k = 1;
        ListNode* expected = ConvertVector2LinkList({1, 2, 3, 4, 5});
		std::cout << "===== Test input " << List2Str(head) << ", k = " << k << ". output = " << List2Str(expected) << " =====" << std::endl;

        // action
		ListNode *result = this->mSolution.reverseKGroup(head, k);

        // assert
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expected));

        ReleaseList(head);
        ReleaseList(expected);
	}

	void Example3()
	{
        // arrange
        ListNode* head = ConvertVector2LinkList({1});
        int k = 1;
        ListNode* expected = ConvertVector2LinkList({1});
		std::cout << "===== Test input " << List2Str(head) << ", k = " << k << ". output = " << List2Str(expected) << " =====" << std::endl;

        // action
		ListNode *result = this->mSolution.reverseKGroup(head, k);

        // assert
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expected));

        ReleaseList(head);
        ReleaseList(expected);
	}

	void Example4()
	{
        // arrange
        ListNode* head = ConvertVector2LinkList({1, 2, 3, 4, 5, 6});
        int k = 2;
        ListNode* expected = ConvertVector2LinkList({2, 1, 4 , 3, 6, 5});
		std::cout << "===== Test input " << List2Str(head) << ", k = " << k << ". output = " << List2Str(expected) << " =====" << std::endl;

        // action
		ListNode *result = this->mSolution.reverseKGroup(head, k);

        // assert
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expected));

        ReleaseList(head);
        ReleaseList(expected);
	}

	void Example5()
	{
        // arrange
        ListNode* head = ConvertVector2LinkList({1, 2, 3, 4, 5, 6, 7});
        int k = 2;
        ListNode* expected = ConvertVector2LinkList({2, 1, 4 , 3, 6, 5, 7});
		std::cout << "===== Test input " << List2Str(head) << ", k = " << k << ". output = " << List2Str(expected) << " =====" << std::endl;

        // action
		ListNode *result = this->mSolution.reverseKGroup(head, k);

        // assert
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expected));

        ReleaseList(head);
        ReleaseList(expected);
	}

	void Example6()
	{
        // arrange
        ListNode* head = ConvertVector2LinkList({100});
        int k = 1;
        ListNode* expected = ConvertVector2LinkList({100});
		std::cout << "===== Test input " << List2Str(head) << ", k = " << k << ". output = " << List2Str(expected) << " =====" << std::endl;

        // action
		ListNode *result = this->mSolution.reverseKGroup(head, k);

        // assert
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expected));

        ReleaseList(head);
        ReleaseList(expected);
	}

	void Example7()
	{
        // arrange
        ListNode* head = ConvertVector2LinkList({1, 2, 3, 4, 5});
        int k = 5;
        ListNode* expected = ConvertVector2LinkList({5, 4, 3, 2, 1});
		std::cout << "===== Test input " << List2Str(head) << ", k = " << k << ". output = " << List2Str(expected) << " =====" << std::endl;

        // action
		ListNode *result = this->mSolution.reverseKGroup(head, k);

        // assert
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expected));

        ReleaseList(head);
        ReleaseList(expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestReverseKGroup test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	getchar();
	return EXIT_SUCCESS;
}