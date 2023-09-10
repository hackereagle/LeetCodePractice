#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "VectorMiscs.hpp"
#include "MyPriorityQueueTest.hpp"
#include "AssertClass.hpp"

#define USING_SELF_DEF_PQ 1

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
	#ifdef USING_SELF_DEF_PQ
		MyPriorityQueue pq = MyPriorityQueue(std::greater<int>());
	#else
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	#endif
        for (auto r : matrix) {
            for (auto c : r) {
	#ifdef USING_SELF_DEF_PQ
				pq.Push(c);
	#else
                pq.push(c);
	#endif
            }
        }

        int ret = 0;
        while(k >= 1) {
	#ifdef USING_SELF_DEF_PQ
			ret = pq.Top();
			pq.Pop();
	#else
            ret = pq.top();
            pq.pop();
	#endif
            //std::cout << ret << " "; // debug
            k = k - 1;
        }
        //std::cout << std::endl; // debug

        return ret;
    }
};

class TestKthSmallest
{
public:
	TestKthSmallest()
	{}

	~TestKthSmallest()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{1,5,9},{10,11,13},{12,13,15}});
		int k = 8;
		int expectedOutput = 13;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", k = " << k << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.kthSmallest(matrix, k);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}
	
	void Example2()
	{
		// ARRANGE
		std::vector<std::vector<int>> matrix({{-5}});
		int k = 1;
		int expectedOutput = -5;
		std::cout << "===== Test matrix = " << Vector2Str(matrix) << ", k = " << k << "; output " << expectedOutput << " =====" << std::endl;

		// ACT
		int result = this->mSolution.kthSmallest(matrix, k);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	// MyPriorityQueueTest myPriorityQueueTest;	
	// myPriorityQueueTest.TestSameResultWithCppStlPriorityQueue_Default();
	// myPriorityQueueTest.TestSameResultWithCppStlPriorityQueue_Greater();
	// myPriorityQueueTest.TestPriorityQueueEmpty();
	// myPriorityQueueTest.TestPriorityQueueEmptyAfterPop();
	// myPriorityQueueTest.TestPriorityQueueAfterEmpty();

	TestKthSmallest test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}