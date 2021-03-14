#include "ReverseNodeInKGroupTest.hpp"
#include <chrono>

ReverseNodeInKGroupTest::ReverseNodeInKGroupTest(/* args */)
{
}

ReverseNodeInKGroupTest::~ReverseNodeInKGroupTest()
{
    ReleaseListNode(this->mEx1Ans, this->mAnsLen);
    ReleaseListNode(this->mEx2Ans, this->mAnsLen);
    ReleaseListNode(this->mEx3Ans, 1);
} 

void ReverseNodeInKGroupTest::ReleaseListNode(ListNode* head, int len)
{
    ListNode* next = nullptr;
    for(int i = 0; i < len; i++){
        if(head != nullptr){
            next = head->next;

            delete head;
            head = next;
        }
    }
}

void ReverseNodeInKGroupTest::Initialize()
{
    this->mAnsLen = 5;
    this->mEx1Ans = CreateExample1Ans();
    this->mEx2Ans = CreateExample2Ans();
    this->mEx3Ans = CreateExample3Ans();
}

ListNode* ReverseNodeInKGroupTest::CreateTestData()
{
    ListNode* data = new ListNode(1);

    ListNode* currentNode = data;
    ListNode* newNode = nullptr;
    for(int i = 2; i < this->mAnsLen + 1; i++){
        newNode = new ListNode(i);
        currentNode->next = newNode;

        currentNode = newNode;
    }

    return data;
}

ListNode* ReverseNodeInKGroupTest::ConvertIntArr2ListNode(int* arr, int len)
{
    ListNode* ans = nullptr;
    if(arr != nullptr && len > 0){
        ans = new ListNode(*(arr));

        if(len > 1){
            ListNode* currentNode = ans;
            ListNode* newNode = nullptr;
            for(int i = 0; i < this->mAnsLen - 1; i++){
                newNode = new ListNode(*(arr + i + 1));
                currentNode->next = newNode;

                currentNode = newNode;
            }
        }
    }

    return ans;
}

ListNode* ReverseNodeInKGroupTest::CreateExample1Ans()
{
    // make Example1Test answer
    int* ansVal = new int[this->mAnsLen]{2, 1, 4, 3, 5};
    return ConvertIntArr2ListNode(ansVal, this->mAnsLen);
}

ListNode* ReverseNodeInKGroupTest::CreateExample2Ans()
{
    // make Example2Test answer
    int* ansVal = new int[this->mAnsLen]{3, 2, 1, 4, 5};
    return ConvertIntArr2ListNode(ansVal, this->mAnsLen);
}

ListNode* ReverseNodeInKGroupTest::CreateExample3Ans()
{
    // make Example3Test anser
    int* ansVal = new int[1]{1};
    return ConvertIntArr2ListNode(ansVal, 1);
}

bool ReverseNodeInKGroupTest::IsListNodeEqual(ListNode* one, ListNode* other, int len)
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

void ReverseNodeInKGroupTest::Example1Test()
{
    this->mTestData = CreateTestData();

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    ListNode* result = mSolution->reverseKGroup(this->mTestData, 2);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    assert(IsListNodeEqual(this->mEx1Ans, result, this->mAnsLen) == true);
    // std::cout << "\033[1;32mGreen! Example1 test OK!" << " Spend time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us"<< std::endl;
    std::cout << "Green! Example1 test OK!" << " Spend time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us"<< std::endl;

    ReleaseListNode(this->mTestData, this->mAnsLen);
}

void ReverseNodeInKGroupTest::Example2Test()
{
    this->mTestData = CreateTestData();

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    ListNode* result = mSolution->reverseKGroup(this->mTestData, 3);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    assert(IsListNodeEqual(this->mEx2Ans, result, this->mAnsLen) == true);
    std::cout << "Green! Example2 test OK!" << " Spend time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us"<< std::endl;

    ReleaseListNode(this->mTestData, this->mAnsLen);
}

void ReverseNodeInKGroupTest::Example3Test()
{
    this->mTestData = new ListNode(1);

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    ListNode* result = mSolution->reverseKGroup(this->mTestData, 1);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    assert(IsListNodeEqual(this->mEx3Ans, result, 1) == true);
    std::cout << "Green! Example3 test OK!" << " Spend time = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " us"<< std::endl;

    ReleaseListNode(this->mTestData, 1);
}