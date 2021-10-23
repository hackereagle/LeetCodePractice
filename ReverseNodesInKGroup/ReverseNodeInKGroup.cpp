#include "ReverseNodeInKGroup.hpp"

ReverseNodeInKGroup::ReverseNodeInKGroup()
{
}

ReverseNodeInKGroup::~ReverseNodeInKGroup()
{
}

ListNode* ReverseNodeInKGroup::reverseKGroup(ListNode* head, int k)
{
    ListNode* result = nullptr;
    if(k > 1 && head != nullptr){

    }
}

ListNode* ReverseNodeInKGroup::reverseKElements(ListNode* head, int k)
{
    ListNode* result = nullptr;
    if(k > 1 && head != nullptr){
        ListNode* _head = head;
        ListNode* currentNode = nullptr;
        ListNode* preNode = nullptr;
        ListNode* nextNode = nullptr;

        preNode = head;
        currentNode = head->next;
        nextNode = currentNode->next;
        for(int i = 1; i < k; i++){
            currentNode->next = preNode;

            // update data
            if(currentNode->next != nullptr){
                preNode = currentNode;
                currentNode = nextNode;
                nextNode = currentNode->next;
            }
            else{
                std::cout << "k is bigger than list length" << std::endl;
                break;
            }
        }

        // Connect head node to k+1 th node.
        if(currentNode != nullptr){
            _head->next = currentNode;
        }
        
        result = preNode;
    }
    else{
        if(k < 0)
            std::cout << "WARNING! k less zero!" << std::endl;
        result = head;
    }
    return result;

}