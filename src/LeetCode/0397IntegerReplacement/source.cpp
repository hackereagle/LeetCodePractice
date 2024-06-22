#include <iostream>
#include <string>
#include <unordered_map>
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	~Solution()
	{}
	
	Solution()
	{
		_dp[0] = 0;
		_dp[1] = 0;
		_dp[2] = 1;
	}

	int integerReplacement(int n) {
		if (_dp.find(n) != _dp.end())
			return _dp[n];

		int ret = 0;
		if ((n & 1) == 0) {
			ret = integerReplacement(n >> 1) + 1;
		}
		else {
			if (n < std::numeric_limits<int>::max())
				ret = std::min(integerReplacement(n - 1), integerReplacement(n + 1));
			else
				ret = std::min(integerReplacement(n - 1), 31);
			ret = ret + 1;
		}
		_dp[n] = ret;

		return ret;
	}

private:
	std::unordered_map<int, int> _dp;
};

class TestIntegerReplacement
{
public:
	TestIntegerReplacement()
	{}

	~TestIntegerReplacement()
	{}

	void Example1()
	{
		// ARRANGE
		int n = 8;
		int expectedOutput = 3;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.integerReplacement(n);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int n = 7;
		int expectedOutput = 4;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.integerReplacement(n);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		int n = 4;
		int expectedOutput = 2;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.integerReplacement(n);
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
	TestIntegerReplacement test;
	test.Example1();
	test.Example2();
	test.Example3();
	getchar();
	return EXIT_SUCCESS;
}