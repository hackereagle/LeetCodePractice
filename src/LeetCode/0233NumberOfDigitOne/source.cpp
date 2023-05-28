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
	
	int countDigitOne(int n) {
		int count = 0;

		int64 dig = 0;
		int times = 0;
		int remain = 0;
		for (int64 pos = 1; pos <= n; pos = pos * 10) {
			dig = pos * static_cast<int64>(10);
			times = n / dig;
			count = count + (times * pos);

			remain = n % dig;
			if (remain >= (2 * pos))
				count = count + pos;
			else if (remain >= pos)
				count = count + remain - pos + 1;

			//std::cout << "pos = " << pos << ", dig = " << dig << ", times = " << times << ", remain = " << remain << std::endl;
		}

		return count;
	}

private:
	typedef long long int int64;
};

class TestCountDigitOne
{
public:
	TestCountDigitOne()
	{}

	~TestCountDigitOne()
	{}

	void Example1()
	{
		int n = 13;
		int expected = 6;
		std::cout << "===== Test n = " << n << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.countDigitOne(n);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		int n = 0;
		int expected = 0;
		std::cout << "===== Test n = " << n << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.countDigitOne(n);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		int n = 100;
		int expected = 21;
		std::cout << "===== Test n = " << n << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.countDigitOne(n);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		int n = 10000;
		int expected = 4001;
		std::cout << "===== Test n = " << n << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.countDigitOne(n);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestCountDigitOne test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	getchar();
	return EXIT_SUCCESS;
}