#include <iostream>
#include <vector>
#include <stack>
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

	bool isPalindrome(ListNode* head) 
	{
        bool ret = true; 
        std::stack<int> reversNodes; 
        ListNode* cur = head; 
        while(cur){ 
            reversNodes.push(cur->val); 
            cur = cur->next; 
        }  
        cur = head; 
        while(cur){ 
            if(reversNodes.top() != cur->val){ 
                ret = false; 
                break; 
            } 
            reversNodes.pop(); 
            cur = cur->next; 
        } 
         
        return ret;
    }

private:
};

class TestIsPalindrome
{
public:
	TestIsPalindrome()
	{}

	~TestIsPalindrome()
	{}

	void TestInput_1_2_2_1_Output_true()
	{
        std::cout << "===== [1, 2, 2, 1], output = true =====" << std::endl;
		int arr[] = {1, 2, 2, 1};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
        bool ans = true;

        bool result = mSolution.isPalindrome(input);
        AssertClass::GetInstance().Assert(result == ans);

        ReleaseList(input);
	}

	void TestInput_1_2_Output_false()
	{
        std::cout << "===== [1, 2], output = false =====" << std::endl;
		int arr[] = {1, 2};
		ListNode* input = CONVERT_ARRAY_2_LINK_LIST(arr);
        bool ans = false;

        bool result = mSolution.isPalindrome(input);
        AssertClass::GetInstance().Assert(result == ans);

        ReleaseList(input);
	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestIsPalindrome test;
	test.TestInput_1_2_2_1_Output_true();
    test.TestInput_1_2_Output_false();
	getchar();
	return EXIT_SUCCESS;
}