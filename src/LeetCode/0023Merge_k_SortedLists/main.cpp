#include <iostream>
#include <vector>
#include <algorithm>
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

	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* ret = nullptr;
        int len = lists.size(); 
        if(len > 0){ 
            std::sort(lists.begin(), lists.end(), [](ListNode* l, ListNode* r){  
                    if(!l) 
                        return true; 
                    if(!r) 
                        return false; 
                    return l->val < r->val;  
                });  
     
            int count = 0; 
            while(count < len){ 
                count = 0; 
                ListNode* temp = nullptr; 
                for(int i = 0; i < len; i++){ 
                    if(lists[i]){ 
                        if(ret == nullptr){  
                            ret = lists[i]; 
                            lists[i] = lists[i]->next; 
                            ret->next = nullptr; 
                        }  
                        else{ 
                            temp = ret;  
                            while(temp->next && (lists[i]->val > temp->next->val)){ 
                                temp = temp->next; 
                            }  
                            ListNode* _next = temp->next; 
                            temp->next = lists[i]; 
                            lists[i] = lists[i]->next; 
                            temp->next->next = _next; 
                        }  
                    } 
                    else{ 
                        count = count + 1; 
                    }  
                } 
            } 
        } 
         
        return ret;
    }

private:
};

class TestMergeKLists
{
public:
	TestMergeKLists()
	{}

	~TestMergeKLists()
	{}

	void TestInput_1_4_5_1_3_4_2_6_Output_1_1_2_3_4_4_5_6()
	{
        std::cout << "===== input = [[1, 4, 5], [1, 3, 4], [2, 6]], output = [1, 1, 2, 3, 4, 4, 5, 6] =====" << std::endl;
		int arr[] = {1, 4, 5};
        int arr2[] = {1, 3, 4};
        int arr3[] = {2, 6};
		std::vector<ListNode*> input;
        input.push_back(CONVERT_ARRAY_2_LINK_LIST(arr));
        input.push_back(CONVERT_ARRAY_2_LINK_LIST(arr2));
        input.push_back(CONVERT_ARRAY_2_LINK_LIST(arr3));
        int arr4[] = {1, 1, 2, 3, 4, 4, 5, 6};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr4);

        ListNode* result = mSolution.mergeKLists(input);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        if(input.size() > 0){
            for(int i = 0; i < input.size(); i++){
                ReleaseList(input[i]);
            }
        }
        ReleaseList(ans);
        ReleaseList(result);
	}

	void TestInput_Empty_Output_Empty()
	{
        std::cout << "===== input = [], output = [] =====" << std::endl;
		std::vector<ListNode*> input;
        int arr[] = {};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr);

        ListNode* result = mSolution.mergeKLists(input);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        if(input.size() > 0){
            for(int i = 0; i < input.size(); i++){
                ReleaseList(input[i]);
            }
        }
        ReleaseList(ans);
        ReleaseList(result);
	}

	void TestInput_EmptyList_Output_Empty()
	{
        std::cout << "===== input = [[]], output = [] =====" << std::endl;
		std::vector<ListNode*> input;
        input.push_back(nullptr);
        int arr[] = {};
        ListNode* ans = CONVERT_ARRAY_2_LINK_LIST(arr);

        ListNode* result = mSolution.mergeKLists(input);
        PrintList(result);
        AssertClass::GetInstance().Assert(IsTwoLinkListEqual(result, ans));

        if(input.size() > 0){
            for(int i = 0; i < input.size(); i++){
                ReleaseList(input[i]);
            }
        }
        ReleaseList(ans);
        ReleaseList(result);

	}

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestMergeKLists test;
	test.TestInput_1_4_5_1_3_4_2_6_Output_1_1_2_3_4_4_5_6();
    test.TestInput_Empty_Output_Empty();
    test.TestInput_EmptyList_Output_Empty();
	getchar();
	return EXIT_SUCCESS;
}