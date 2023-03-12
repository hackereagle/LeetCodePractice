#ifndef _REVERSE_NODE_IN_GROUP_TEST_H_
#define _REVERSE_NODE_IN_GROUP_TEST_H_

#include <iostream>
#include <memory>
#include "assert.h"
#include "ReverseNodeInKGroup.hpp"
#include "ListNode.hpp"

class ReverseNodeInKGroupTest
{
public:
    ReverseNodeInKGroupTest(/* args */);
    ~ReverseNodeInKGroupTest();
    void Initialize();
    // Test method
    void Example1Test();
    void Example2Test();
    void Example3Test();

private:
    std::unique_ptr<ReverseNodeInKGroup> mSolution;
    int mAnsLen = 0;
    ListNode* mTestData = nullptr;
    ListNode* mEx1Ans = nullptr;
    ListNode* mEx2Ans = nullptr;
    ListNode* mEx3Ans = nullptr;

    //
    ListNode* CreateTestData();
    ListNode* ConvertIntArr2ListNode(int* arr, int len);
    ListNode* CreateExample1Ans();
    ListNode* CreateExample2Ans();
    ListNode* CreateExample3Ans();
    bool IsListNodeEqual(ListNode* one, ListNode* other, int len);
    void ReleaseListNode(ListNode* list, int len);
};

#endif //_REVERSE_NODE_IN_GROUP_TEST_H_