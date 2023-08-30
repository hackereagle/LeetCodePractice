#pragma once

#include <queue>
#include "MyPriorityQueue.hpp"
#include "AssertClass.hpp"


class MyPriorityQueueTest
{
public:
	MyPriorityQueueTest()
	{}

	~MyPriorityQueueTest()
	{}

	void TestSameResultWithCppStlPriorityQueue_Default()
	{
		std::cout << "===== TestSameResultWithCppStlPriorityQueue_Default =====" << std::endl;
		// ARRANGE
		int data[6] {10, 29, 38, 48, 60, 90};

		// ACT
		std::priority_queue<int> pq;
		MyPriorityQueue mpq;
		for (int i = 0; i < 6; i++) {
			pq.push(data[i]);
			mpq.Push(data[i]);
		}

		// ASSERT
		int pqNum = 0, mpqNum = 0;
		for (int i = 0; i < 6; i++) {
			pqNum = pq.top();
			pq.pop();
			mpqNum = mpq.Top();
			mpq.Pop();
			std::cout << pqNum << ", " << mpqNum << std::endl;
			AssertClass::GetInstance().Assert(pqNum == mpqNum);
		}
	}

	void TestSameResultWithCppStlPriorityQueue_Greater()
	{
		std::cout << "\n\n===== TestSameResultWithCppStlPriorityQueue_Greater =====" << std::endl;
		// ARRANGE
		int data[6] {10, 29, 38, 48, 60, 90};

		// ACT
		std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
		MyPriorityQueue mpq = MyPriorityQueue(std::greater<int>());
		for (int i = 0; i < 6; i++) {
			pq.push(data[i]);
			mpq.Push(data[i]);
		}

		// ASSERT
		int pqNum = 0, mpqNum = 0;
		for (int i = 0; i < 6; i++) {
			pqNum = pq.top();
			pq.pop();
			mpqNum = mpq.Top();
			mpq.Pop();
			std::cout << pqNum << ", " << mpqNum << std::endl;
			AssertClass::GetInstance().Assert(pqNum == mpqNum);
		}
	}
};