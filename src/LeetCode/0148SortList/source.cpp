#include <iostream>
#include <string>
#include <vector>
#include "LeetcodeLinkListMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		//std::cout << CreateLeadingTabs() << List2Str(head) << std::endl; // debug
		ListNode* leftList = nullptr;
		ListNode* rightList = nullptr;
		SeparateTo2List(head, leftList, rightList);
		
		//this->_hierarchy = this->_hierarchy + 1; // debug
		leftList = sortList(leftList);
		rightList = sortList(rightList);
		//this->_hierarchy = this->_hierarchy - 1; // debug

		//std::cout << CreateLeadingTabs() << "left = " << List2Str(leftList) << ", right = " << List2Str(rightList) << std::endl; // debug
		ListNode* newList = MergeTwoSortedLidt(leftList, rightList);
		//std::cout << CreateLeadingTabs() << "after merge: " << List2Str(newList) << std::endl; // debug

		return newList;
	}

private:
	int _hierarchy = 0;

	void SeparateTo2List(ListNode* head, ListNode* &left, ListNode* &right)
	{
		left = head;
		right = head;
		ListNode* fastPtr = head;
		ListNode* leftEnd = nullptr;

		while (fastPtr && fastPtr->next) {
			leftEnd = right;
			right = right->next;
			fastPtr = fastPtr->next->next;
		}
		leftEnd->next = nullptr;
	}

	ListNode* MergeTwoSortedLidt(ListNode* leftList, ListNode* rightList)
	{
		ListNode* ret = nullptr;
		ListNode* cur = nullptr;
		ListNode* one = nullptr;
		ListNode* another = nullptr;
		if (leftList->val > rightList->val) {
			ret = rightList;
			one = rightList;
			another = leftList;
		}
		else {
			ret = leftList;
			one = leftList;
			another = rightList;
		}

		cur = one;
		one = one->next;

		while (one && another) {
			if (one->val > another->val) {
				cur->next = another;
				another = another->next;
			}
			else {
				cur->next = one;
				one = one->next;
			}
			cur = cur->next;
		}
		
		if (another) {
			cur->next = another;
		}
		else {
			cur->next = one;
		}
	
		return ret;
	}

	// Here codes are for debug
	std::string CreateLeadingTabs()
	{
		std::ostringstream ss;
		for (int i = 0; i < this->_hierarchy; i++)
			ss << "\t";
		return ss.str();
	}

	std::string List2Str(ListNode* head)
	{
		std::ostringstream ss;
		ss << "[";
		while (head) {
			ss << head->val << " ";
			head = head->next;
		}
		ss << "]";
		return ss.str();
	}

	std::string GetListValue(ListNode* node)
	{
		if (node)
			return std::to_string(node->val);
		else
			return "null";
	}
};

class TestSortList
{
public:
	TestSortList()
	{}

	~TestSortList()
	{}

	void Example1()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[4,2,1,3]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[1,2,3,4]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.sortList(head);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		ReleaseList(head);
		ReleaseList(expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[-1,5,3,4,0]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[-1,0,3,4,5]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.sortList(head);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		ReleaseList(head);
		ReleaseList(expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.sortList(head);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		ReleaseList(head);
		ReleaseList(expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[-20,30,-10,40]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[-20,-10,30,40]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.sortList(head);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		ReleaseList(head);
		ReleaseList(expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[80]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[80]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.sortList(head);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		ReleaseList(head);
		ReleaseList(expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[90,100]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[90,100]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.sortList(head);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		ReleaseList(head);
		ReleaseList(expectedOutput);
	}

	void Example7()
	{
		// ARRANGE
		ListNode* head = CreateListFromLeetcodeString("[3,2,1]");
		ListNode* expectedOutput = CreateListFromLeetcodeString("[1,2,3]");
		std::cout << "===== Test head = " << List2Str(head) << "; output = " << List2Str(expectedOutput) << " =====" << std::endl;

		// ACT
		ListNode* result = this->mSolution.sortList(head);

		// ASSERT
		AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, expectedOutput));

		ReleaseList(head);
		ReleaseList(expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestSortList test;
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