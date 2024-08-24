#include <iostream>
#include <string>
#include "OtherMiscs.hpp"
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool isUgly(int n) {
		if (n == 0)
			return false;

		if (n == 1)
			return true;

		/*if (n > 5 && ((n & 1) != 0))
			return false;*/
		
		int num = RemoveTwoFactor(n);
		//std::cout << "After removed 2, num = " << num << std::endl; // debug
		num = RemoveFactor(num, 3);
		//std::cout << "After removed 3, num = " << num << std::endl; // debug
		num = RemoveFactor(num, 5);
		//std::cout << "After removed 5, num = " << num << std::endl; // debug

		if (num != 1)
			return false;
		else
			return true;
	}

private:
	int RemoveTwoFactor(int n)
	{
		while ((n & 1) == 0) {
			n = n >> 1;
			//std::cout << "\t" << n << std::endl; // debug
		}

		return n;
	}

	int RemoveFactor(int n, int factor)
	{
		if (n == 1)
			return 1;

		while ((n % factor) == 0) {
			n = n / factor;
			//std::cout << "\t" << n << std::endl; // debug
		}

		return n;
	}
};

class TestIsUgly
{
public:
	TestIsUgly()
	{}

	~TestIsUgly()
	{}

	void Example1()
	{
		// ARRANGE
		int n = 6;
		bool expectedOutput = true;
		std::cout << "===== Test n = " << n << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isUgly(n);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int n = 1;
		bool expectedOutput = true;
		std::cout << "===== Test n = " << n << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isUgly(n);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		int n = 14;
		bool expectedOutput = false;
		std::cout << "===== Test n = " << n << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isUgly(n);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		int n = 0;
		bool expectedOutput = false;
		std::cout << "===== Test n = " << n << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isUgly(n);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		int n = 9;
		bool expectedOutput = true;
		std::cout << "===== Test n = " << n << "; output = " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isUgly(n);
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
	TestIsUgly test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}