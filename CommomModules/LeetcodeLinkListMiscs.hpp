#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline void PrintList(ListNode *head)
{
	ListNode **disp = &head;
	std::cout << "[";
	if(*disp){
		std::cout << (*disp)->val;
		*disp = (*disp)->next;
		while(*disp){
			std::cout << ", " << (*disp)->val;
			*disp = (*disp)->next;
		}
	}
	std::cout << "]" << std::endl;;
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

inline ListNode* ConvertArray2LinkList(int* arr)
{
	ListNode *head = nullptr;
	ListNode **it = &head;
	int len = sizeof(arr) / sizeof(int);
	if(len > 0){
		for(int i = 0; i < len; i++){
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

inline bool IsTwoLinkListEqual(ListNode* l1, ListNode* l2)
{
	bool isEqual = true;
	ListNode** ptr1 = &l1;
	ListNode** ptr2 = &l2;
	while(*ptr1 != nullptr & *ptr2 != nullptr){
		if((*ptr1)->val != (*ptr2)->val)
			isEqual = false;
		ptr1 = &(*ptr1)->next;
		ptr1 = &(*ptr1)->next;
	}

	if((*ptr1)->next != nullptr | (*ptr2)->next != nullptr)
		isEqual = false;

	return isEqual;
}

inline void ReleaseList(ListNode* &head)
{
	ListNode* cur = head;
	while(cur != nullptr){
		ListNode* temp = cur->next;
		if(temp != nullptr)
			delete temp;
		cur = temp;
	}
}