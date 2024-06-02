#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
		int start = 0;
		int len = gas.size();
		int remain = 0;
		int total = 0;
		int curTotal = 0;
		for (int i = 0; i < len; i++) {
			remain = gas[i] - cost[i];
			total = total + remain;
			curTotal = curTotal + remain;
			if (curTotal < 0) {
				start = i + 1;
				curTotal = 0;
			}
		}

		if (total < 0) 
			start = -1;
		

		return start;
	}
};

class TestIsValid
{
public:
	TestIsValid()
	{}

	~TestIsValid()
	{}

	void Example1()
	{
		// ARRANGE
		std::vector<int> gas({1,2,3,4,5});
		std::vector<int> cost({3,4,5,1,2});
		int expectedOutput = 3;
		std::cout << "===== Test gas = " << Vector2Str(gas) << ", cost = " << Vector2Str(cost) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.canCompleteCircuit(gas, cost);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::vector<int> gas({2,3,4});
		std::vector<int> cost({3,4,3});
		int expectedOutput = -1;
		std::cout << "===== Test gas = " << Vector2Str(gas) << ", cost = " << Vector2Str(cost) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.canCompleteCircuit(gas, cost);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::vector<int> gas({2});
		std::vector<int> cost({2});
		int expectedOutput = 0;
		std::cout << "===== Test gas = " << Vector2Str(gas) << ", cost = " << Vector2Str(cost) << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.canCompleteCircuit(gas, cost);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsValid test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}