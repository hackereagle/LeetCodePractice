#include <iostream>
#include <string>
#include "LeetcodeLinkListMiscs.hpp"
#include "LeetcodeTreeMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}

	TreeNode* sortedListToBST(ListNode* head) {
		if (!head)
			return nullptr;

		ListNode* end = FindEnd(head);
		TreeNode* root = ConvertList2Tree(head, end);
		return root;
	}

private:
	ListNode* FindEnd(ListNode* head)
	{
		while (head && head->next) {
			head = head->next;
		}

		return head;
	}

	TreeNode* ConvertList2Tree(ListNode* head, ListNode* end)
	{
		//PrintListRange(head, end);
		if (!head)
			return nullptr;

		if (head == end)
			return new TreeNode(head->val);

		ListNode* faster = head;
		ListNode* slower = head;
		ListNode* beforeSlower = nullptr;
		while ((faster && faster != end) &&
			   (faster->next && faster->next != end)) {
			faster = faster->next->next;
			beforeSlower = slower;
			slower = slower->next;
		}

		TreeNode* root = nullptr;
		//std::cout << "head = " << ListNode2Str(head) << ", end = " << ListNode2Str(end) << ", slower = " << ListNode2Str(slower) << ", beforeSlower = " << ListNode2Str(beforeSlower) << ", faster = " << ListNode2Str(faster) << std::endl;
		if (!beforeSlower) {
			root = new TreeNode(slower->next->val);
			root->left = new TreeNode(slower->val);
		}
		else {
			root = new TreeNode(slower->val);
			root->left = ConvertList2Tree(head, beforeSlower);
			root->right = ConvertList2Tree(slower->next, end);
		}

		return root;
	}

	void PrintListRange(ListNode* start, ListNode* end)
	{
		if (start && end) {
			std::cout << "[";
			while (start != end) {
				std::cout << start->val << " ";
				start = start->next;
			}
			std::cout << end->val << "]" << std::endl;
		}
		else if (start && !end) {
			std::cout << "start = " << start->val << ", end = nullptr" << std::endl;
		}
		else if (!start && end) {
			std::cout << "start = nullptr, end = " << end->val << std::endl;
		}
		else
			std::cout << "[]" << std::endl;
	}

	std::string ListNode2Str(ListNode* node)
	{
		std::string res;
		if (node)
			res = std::to_string(node->val);
		else
			res = "nullptr";
		return res;
	}
};

class TestSortedListToBST
{
public:
	TestSortedListToBST()
	{}

	~TestSortedListToBST()
	{}

	void Example1()
	{
		int arr[] = {-10,-3,0,5,9};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(arr);
		TreeNode* expected = CreateTreeLeetcodeInputStr("[0,-3,9,-10,null,5]");
		std::cout << "===== Test head = " << List2Str(head) << ", output = " << ToLeetcodeStr(expected) << " =====" << std::endl;

		TreeNode* result = this->mSolution.sortedListToBST(head);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expected, result));
		ReleaseList(head);
		ReleaseTree(expected);
		ReleaseTree(result);
	}

	void Example2()
	{
		int arr[] = {};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(arr);
		TreeNode* expected = CreateTreeLeetcodeInputStr("[]");
		std::cout << "===== Test head = " << List2Str(head) << ", output = " << ToLeetcodeStr(expected) << " =====" << std::endl;

		TreeNode* result = this->mSolution.sortedListToBST(head);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expected, result));
		ReleaseList(head);
		ReleaseTree(expected);
		ReleaseTree(result);
	}

	void Example3()
	{
		int arr[] = {-10,-3,5,9};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(arr);
		TreeNode* expected = CreateTreeLeetcodeInputStr("[-3,-10,9,null,null,5]");
		std::cout << "===== Test head = " << List2Str(head) << ", output = " << ToLeetcodeStr(expected) << " =====" << std::endl;

		TreeNode* result = this->mSolution.sortedListToBST(head);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expected, result));
		ReleaseList(head);
		ReleaseTree(expected);
		ReleaseTree(result);
	}

	void Example4()
	{
		int arr[] = {1,2,3,4,5,6,7,8,9};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(arr);
		TreeNode* expected = CreateTreeLeetcodeInputStr("[5,2,7,1,4,6,9,null,null,3,null,null,null,8]");
		std::cout << "===== Test head = " << List2Str(head) << ", output = " << ToLeetcodeStr(expected) << " =====" << std::endl;

		TreeNode* result = this->mSolution.sortedListToBST(head);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expected, result));
		ReleaseList(head);
		ReleaseTree(expected);
		ReleaseTree(result);
	}

	void Example5()
	{
		int arr[] = {0,1,2,3,4,5,6,7,8,9};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(arr);
		TreeNode* expected = CreateTreeLeetcodeInputStr("[4,1,7,0,3,6,9,null,null,2,null,5,null,8]");
		std::cout << "===== Test head = " << List2Str(head) << ", output = " << ToLeetcodeStr(expected) << " =====" << std::endl;

		TreeNode* result = this->mSolution.sortedListToBST(head);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expected, result));
		ReleaseList(head);
		ReleaseTree(expected);
		ReleaseTree(result);
	}

	void Example6()
	{
		int arr[] = {0,1,2,3,4,5,6};
		ListNode* head = CONVERT_ARRAY_2_LINK_LIST(arr);
		TreeNode* expected = CreateTreeLeetcodeInputStr("[3,1,5,0,2,4,6]");
		std::cout << "===== Test head = " << List2Str(head) << ", output = " << ToLeetcodeStr(expected) << " =====" << std::endl;

		TreeNode* result = this->mSolution.sortedListToBST(head);

		AssertClass::GetInstance().Assert(IsTwoTreeEqual(expected, result));
		ReleaseList(head);
		ReleaseTree(expected);
		ReleaseTree(result);
	}

private:
	Solution mSolution;
};


int main(int argc, char** argv)
{
	TestSortedListToBST test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	getchar();
	return EXIT_SUCCESS;
}