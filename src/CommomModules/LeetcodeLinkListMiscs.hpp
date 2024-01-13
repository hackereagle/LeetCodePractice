#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "StringMiscs.hpp"

#define CONVERT_ARRAY_2_LINK_LIST(arr) ConvertArrayToLinkList((arr), sizeof((arr)) / sizeof((arr)[0]))

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline std::string List2Str(ListNode *head)
{
	std::ostringstream ss;

	ListNode **disp = &head;
	ss << "[";
	if(*disp){
		ss << (*disp)->val;
		*disp = (*disp)->next;
		while(*disp){
			ss << ", " << (*disp)->val;
			*disp = (*disp)->next;
		}
	}
	ss << "]";
	return ss.str();
}

inline void PrintList(ListNode *head)
{
	std::cout << List2Str(head) << std::endl;
}

inline ListNode* ConvertVector2LinkList(std::vector<int> arr)
{
	ListNode *head = nullptr;
	ListNode **it = &head;
	if(arr.size() > 0){
		for(std::vector<int>::iterator b = arr.begin(), e = arr.end(); b != e; b++){
			if(!*it)
				*it = new ListNode(*b);
			else{
				(*it)->next = new ListNode(*b);
				it = &(*it)->next;
			}
		}
	}
	return head;
}

inline ListNode* ConvertArrayToLinkList(int arr[], int count)
{
	ListNode *head = nullptr;
	ListNode **it = &head;
	if(count > 0){
		for(int i = 0; i < count; i++){
			if(!*it)
				*it = new ListNode(*(arr + i));
			else{
				(*it)->next = new ListNode(*(arr + i));
				it = &(*it)->next;
			}
		}
	}
	return head;
}

inline ListNode* CreateListFromLeetcodeString(std::string str)
{
	std::string arr = RemoveFrontAndEndSquareBracket(str);

	ListNode* head = nullptr;
	if (str.size() > 0) {
		std::vector<std::string> vec = SplitString(arr, ",");
		std::vector<int> vecInt;
		for (auto &e : vec) {
			vecInt.push_back(std::stoi(e));
		}
		head = ConvertVector2LinkList(vecInt);
	}
	
	return head;
}

inline bool IsTwoLinkListEqual(ListNode* l1, ListNode* l2)
{
	bool isEqual = true;
	ListNode** ptr1 = &l1;
	ListNode** ptr2 = &l2;
	while(*ptr1 != nullptr & *ptr2 != nullptr){
		if((*ptr1)->val != (*ptr2)->val){
			isEqual = false;
			break;
		}
		ptr1 = &(*ptr1)->next;
		ptr2 = &(*ptr2)->next;
	}

	if((*ptr1) != nullptr | (*ptr2) != nullptr)
		isEqual = false;

	return isEqual;
}

inline void ReleaseList(ListNode* &head)
{
	if(!head)
		return;

	ListNode* cur = head;
	while(cur != nullptr){
		ListNode* temp = cur->next;
		if(cur != nullptr){
			cur->next = nullptr;
			delete cur;
			cur = nullptr;
		}
		cur = temp;
	}
}

inline ListNode* CopyListNode(ListNode* head)
{
	ListNode* ret = nullptr;
	if (head) {
		ret = new ListNode(head->val);

		ListNode* cur = ret;
		head = head->next;
		while (head) {
			cur->next = new ListNode(head->val);

			head = head->next;
			cur = cur->next;
		}
	}
	return ret;
}