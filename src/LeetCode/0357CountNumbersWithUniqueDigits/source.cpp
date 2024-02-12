#include <iostream>
#include <string>
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{
		memset(_dp, -1, sizeof(int) * 9);
		_dp[0] = 1;
		_dp[1] = 10;
	}

	~Solution()
	{}

	int countNumbersWithUniqueDigits(int n) {
		if (_dp[n] != -1) {
			return _dp[n];
		}

		_dp[n] = 9;
		for (int i = 1; i < n; i++) {
			_dp[n] = _dp[n] * (10 - i);
		}

		_dp[n] = _dp[n] + countNumbersWithUniqueDigits(n - 1);
		
		return _dp[n];
	}

private:
	int _dp[9];
};

class TestCountNumbersWithUniqueDigits
{
public:
	TestCountNumbersWithUniqueDigits()
	{}

	~TestCountNumbersWithUniqueDigits()
	{}

	void Example1()
	{
		// ARRANGE
		int n = 2;
		int expectedOutput = 91;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.countNumbersWithUniqueDigits(n);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int n = 0;
		int expectedOutput = 1;
		std::cout << "===== Test n = " << n << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.countNumbersWithUniqueDigits(n);
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
	TestCountNumbersWithUniqueDigits test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}