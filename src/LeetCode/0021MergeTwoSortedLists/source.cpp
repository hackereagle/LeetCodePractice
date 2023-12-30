#include <iostream>
#include <string>
#include "LeetcodeLinkListMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = nullptr;

        if (!list1 && !list2)
            return ret;

        if (!list1) {
            ret = list2;
            return ret;
        }

        if (!list2) {
            ret = list1;
            return ret;
        }

        ListNode* another = nullptr;
        if (list1->val < list2->val) {
            ret = list1;
            another = list2;
        }
        else {
            ret = list2;
            another = list1;
        }

        ListNode* cur = ret;
        ListNode* pre = nullptr;
        while(cur && another) {
            if (another->val >= cur->val) {
                pre = cur;
                cur = cur->next;
            }
            else {
                pre->next = another;
                another = another->next;
                pre->next->next = cur;
                pre = pre->next;
            }
        }

        if (!cur) {
            pre->next = another;
        }

        return ret;
    }
};

class TestMergeTwoLists
{
public:
	TestMergeTwoLists()
	{}

	~TestMergeTwoLists()
	{}

	void Example1()
	{
		// ARRANGE
		ListNode* list1 = ConvertVector2LinkList({1,2,4});
		ListNode* list2 = ConvertVector2LinkList({1,3,4});
		ListNode* expectedOutput = ConvertVector2LinkList({1,1,2,3,4,4});
		std::cout << "===== Test input: list1 = " << List2Str(list1) << ", list2 = " << List2Str(list2) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.mergeTwoLists(list1, list2);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		// CLEANUP
		ReleaseList(result);
		ReleaseList(expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		ListNode* list1 = ConvertVector2LinkList({});
		ListNode* list2 = ConvertVector2LinkList({});
		ListNode* expectedOutput = ConvertVector2LinkList({});
		std::cout << "===== Test input: list1 = " << List2Str(list1) << ", list2 = " << List2Str(list2) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.mergeTwoLists(list1, list2);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		// CLEANUP
		ReleaseList(result);
		ReleaseList(expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		ListNode* list1 = ConvertVector2LinkList({});
		ListNode* list2 = ConvertVector2LinkList({0});
		ListNode* expectedOutput = ConvertVector2LinkList({0});
		std::cout << "===== Test input: list1 = " << List2Str(list1) << ", list2 = " << List2Str(list2) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.mergeTwoLists(list1, list2);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		// CLEANUP
		ReleaseList(result);
		ReleaseList(expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		ListNode* list1 = ConvertVector2LinkList({1,2,6,8});
		ListNode* list2 = ConvertVector2LinkList({0,3,5,9,10});
		ListNode* expectedOutput = ConvertVector2LinkList({0,1,2,3,5,6,8,9,10});
		std::cout << "===== Test input: list1 = " << List2Str(list1) << ", list2 = " << List2Str(list2) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.mergeTwoLists(list1, list2);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		// CLEANUP
		ReleaseList(result);
		ReleaseList(expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		ListNode* list1 = ConvertVector2LinkList({1,2,6,8});
		ListNode* list2 = ConvertVector2LinkList({0,9,10});
		ListNode* expectedOutput = ConvertVector2LinkList({0,1,2,6,8,9,10});
		std::cout << "===== Test input: list1 = " << List2Str(list1) << ", list2 = " << List2Str(list2) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.mergeTwoLists(list1, list2);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		// CLEANUP
		ReleaseList(result);
		ReleaseList(expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		ListNode* list1 = ConvertVector2LinkList({1,2,6,8});
		ListNode* list2 = ConvertVector2LinkList({0,0,0});
		ListNode* expectedOutput = ConvertVector2LinkList({0,0,0,1,2,6,8});
		std::cout << "===== Test input: list1 = " << List2Str(list1) << ", list2 = " << List2Str(list2) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.mergeTwoLists(list1, list2);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		// CLEANUP
		ReleaseList(result);
		ReleaseList(expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestMergeTwoLists test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}