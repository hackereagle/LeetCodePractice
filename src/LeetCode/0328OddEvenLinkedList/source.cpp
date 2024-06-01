#include <iostream>
#include <string>
#include "LeetcodeLinkListMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

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
	
	ListNode* oddEvenList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* cur = head;
        int count = 1;

        ListNode* oddHead = head;
        ListNode* evenHead = nullptr;
        cur = cur->next;

        count = count + 1;
        evenHead = cur;

        cur = cur->next;
        ListNode* oddCur = oddHead;
        ListNode* evenCur = evenHead;
        while (cur) {
            count = count + 1;
            
            if ((count & 1) == 1) {
                oddCur->next = cur;
                oddCur = oddCur->next;
            }
            else {
                evenCur->next = cur;
                evenCur = evenCur->next;
            }
            cur = cur->next;
        }
        evenCur->next = nullptr;

        oddCur->next = evenHead;
        return oddHead;
    }
};

class TestOddEvenList
{
public:
	TestOddEvenList()
	{}

	~TestOddEvenList()
	{}

	void Example1()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[1,2,3,4,5]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[1,3,5,2,4]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		ListNode* result = this->mSolution.oddEvenList(head);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));
	}

	void Example2()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[2,1,3,5,6,4,7]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[2,3,6,7,1,5,4]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		ListNode* result = this->mSolution.oddEvenList(head);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));
	}

	void Example3()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		ListNode* result = this->mSolution.oddEvenList(head);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));
	}

	void Example4()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[1]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[1]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		ListNode* result = this->mSolution.oddEvenList(head);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));
	}

	void Example5()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[10,6,7,8,100,5]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[10,7,100,6,8,5]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		ListNode* result = this->mSolution.oddEvenList(head);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestOddEvenList test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}