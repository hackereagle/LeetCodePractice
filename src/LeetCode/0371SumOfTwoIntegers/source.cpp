#include <iostream>
#include <string>
#include "StopWatch.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int getSum(int a, int b) {
		int result = 0;

		int carrier = 0;
		int aBit = 0, bBit = 0;
		int mask = 0;
		for (int i = 0; i < 32; i++) {
			mask = 1 << i;

			aBit = a & mask;
			bBit = b & mask;
			//std::cout << "mask = " << mask << ", aBit = " << aBit << ", bBit = " << bBit ; // debug

			result = result | ((aBit ^ bBit) ^ carrier);
			carrier = (aBit & bBit) | (aBit & carrier) | (bBit & carrier);
			carrier = carrier << 1;
			//std::cout << ", result = " << result << ", carrier = " << carrier << std::endl; // debug
		}
		return result;
	}
};

class TestGetSum
{
public:
	TestGetSum()
	{}

	~TestGetSum()
	{}

	void Example1()
	{
		// ARRANGE
		int a = 1, b = 2;
		int expectedOutput = 3;
		std::cout << "===== Test a = " << a << ", b = " << b << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.getSum(a, b);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		int a = 2, b = 3;
		int expectedOutput = 5;
		std::cout << "===== Test a = " << a << ", b = " << b << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.getSum(a, b);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		int a = -12, b = -8;
		int expectedOutput = -20;
		std::cout << "===== Test a = " << a << ", b = " << b << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.getSum(a, b);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		int a = -1, b = 0;
		int expectedOutput = -1;
		std::cout << "===== Test a = " << a << ", b = " << b << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.getSum(a, b);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		int a = 5, b = -8;
		int expectedOutput = -3;
		std::cout << "===== Test a = " << a << ", b = " << b << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.getSum(a, b);
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
	TestGetSum test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}