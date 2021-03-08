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
    bool IsEqual = true;
    ListNode* _one = one;
    ListNode* _other = other;
    for(int i = 0; i < len; i++){
        if(_one->val != _other->val) {
            IsEqual = false;
            break;
        }

        _one = _one->next;
        _other = _other->next;
    }

    return IsEqual;
}

void Example1Test(std::unique_ptr<ReverseNodeInKGroup>& obj, ListNode* data)
{
    ListNode* result = obj->reverseKGroup(data, 2);

    // make Example1Test answer
    int len = 5;
    int* ansVal = new int[len]{2, 1, 3, 4, 5};
    ListNode* ans = new ListNode(*(ansVal));
    ListNode* temp = ans;
    for(int i = 0; i < len - 1; i++){
        ans->next = new ListNode(*(ansVal + i + 1));
        ans = ans->next;
    }

    if(IsListNodeEqual(ans, result, len)){
        std::cout << "Example1 is OK" << std::endl;
    }
    else{
        std::cout << "Example1 is FAIL" << std::endl;
    }
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