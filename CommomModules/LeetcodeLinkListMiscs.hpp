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
	if(!*disp){
		std::cout << (*disp)->val;
		*disp = (*disp)->next;
		while(!*disp){
			std::cout << ", " << (*disp)->val;
			*disp = (*disp)->next;
		}
		std::cout << "]" << std::endl;;
	}
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