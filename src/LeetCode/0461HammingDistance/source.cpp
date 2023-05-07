#include <iostream>
#include <string>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int hammingDistance(int x, int y) {
		int count = 0;

		int mask = 1;
		int bit_x = 0;
		int bit_y = 0;
		while (x != 0 || y != 0) {
			bit_x = x & mask;
			bit_y = y & mask;

			if (bit_x ^ bit_y)
				count = count + 1;
			
			x = x >> 1;
			y = y >> 1;
		}

		return count;
	}
};

class TestHammingDistance
{
public:
	TestHammingDistance()
	{}

	~TestHammingDistance()
	{}

	void Example1()
	{
		int x = 1;
		int y = 4;
		int expectedOutput = 2;
		std::cout << "===== Test input: x = " << x << ", y = " << y << ", output: " << expectedOutput << " =====" << std::endl;

		int result = this->mSolution.hammingDistance(x, y);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		int x = 3;
		int y = 1;
		int expectedOutput = 1;
		std::cout << "===== Test input: x = " << x << ", y = " << y << ", output: " << expectedOutput << " =====" << std::endl;

		int result = this->mSolution.hammingDistance(x, y);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		int x = 13;
		int y = 2;
		int expectedOutput = 4;
		std::cout << "===== Test input: x = " << x << ", y = " << y << ", output: " << expectedOutput << " =====" << std::endl;

		int result = this->mSolution.hammingDistance(x, y);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		int x = 192;
		int y = 3;
		int expectedOutput = 4;
		std::cout << "===== Test input: x = " << x << ", y = " << y << ", output: " << expectedOutput << " =====" << std::endl;

		int result = this->mSolution.hammingDistance(x, y);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		int x = 2147483647; // 2^31 - 1
		int y = 1;
		int expectedOutput = 30;
		std::cout << "===== Test input: x = " << x << ", y = " << y << ", output: " << expectedOutput << " =====" << std::endl;

		int result = this->mSolution.hammingDistance(x, y);

		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestHammingDistance test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	getchar();
	return EXIT_SUCCESS;
}