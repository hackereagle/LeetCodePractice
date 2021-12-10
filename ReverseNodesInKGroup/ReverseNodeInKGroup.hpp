#ifndef _H_REVERSE_NODES_IN_K_GROUP_
#define _H_REVERSE_NODES_IN_K_GROUP_

#include <iostream>
#include "ListNode.hpp"

class ReverseNodeInKGroup
{
public:
    ReverseNodeInKGroup();
    ~ReverseNodeInKGroup();
    ListNode* reverseKGroup(ListNode* head, int k);

private:
    ListNode* reverseKElements(ListNode* head, ListNode* last, int k);
};


#endif //_H_REVERSE_NODES_IN_K_GROUP_