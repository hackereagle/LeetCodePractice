#include <iostream>
#include "ListNode.hpp"
#include <memory>
#include "ReverseNodeInKGroup.hpp"

ListNode* CreateTestData()
{
    ListNode* data = nullptr;
    ListNode* temp = nullptr;

    for(int i = 1; i < 6; i++){
        data = new ListNode(i);
        if(i > 1){
            temp->next = data;
            temp = data;
        }
        else {
            temp = data;
        }
    }

    return data;
}

bool IsListNodeEqual(ListNode* one, ListNode* other, int len)
{
    for(int i = 0; i < len; i++){
        
    }
}

void Example1Test(std::unique_ptr<ReverseNodeInKGroup>& obj, ListNode* data)
{
    obj->reverseKGroup(data, 2);

    // make answer
    ListNode *ans = new ListNode();
}

int main(int argc, char** argv)
{
    std::unique_ptr<ReverseNodeInKGroup> solution = std::make_unique<ReverseNodeInKGroup>();
    ListNode* data = CreateTestData();

    Example1Test(solution, data);

    // release data
    ListNode* temp;
    for(int i = 0; i < 5; i++){
        temp = data->next;
        data->next = nullptr;
        delete data;
        data = temp;
    }

    getchar();
    return EXIT_SUCCESS;
}