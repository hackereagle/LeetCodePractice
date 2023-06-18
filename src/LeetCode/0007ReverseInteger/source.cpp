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
	
	int reverse(int x) {
		int ret = 0;

		int remain = 0;
		int dig = 0;
		while (x != 0) {
			if (dig == 9 && (ret < -214748364 || ret > 214748364)) {
				ret = 0;
				break;
			}
			ret = ret * 10;

			remain = x % 10;
			ret = ret + remain;

			x = x / 10;
			dig = dig + 1;
		}

		return ret;
	}
};

class TestReverse
{
public:
	TestReverse()
	{}

	~TestReverse()
	{}

	void Example1()
	{
		int x = 123;
		int expected = 321;
		std::cout << "===== Test x = " << x << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.reverse(x);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example2()
	{
		int x = -123;
		int expected = -321;
		std::cout << "===== Test x = " << x << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.reverse(x);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example3()
	{
		int x = 120;
		int expected = 21;
		std::cout << "===== Test x = " << x << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.reverse(x);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example4()
	{
		int x = 463847412;
		int expected = 214748364;
		std::cout << "===== Test x = " << x << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.reverse(x);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example5()
	{
		int x = 2147483647;
		int expected = 0;
		std::cout << "===== Test x = " << x << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.reverse(x);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example6()
	{
		int x = -2143847412;
		int expected = -2147483412;
		std::cout << "===== Test x = " << x << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.reverse(x);

		AssertClass::GetInstance().Assert(result == expected);
	}

	void Example7()
	{
		int x = 1463847412;
		int expected = 2147483641;
		std::cout << "===== Test x = " << x << ", output = " << expected << " =====" << std::endl;

		int result = this->mSolution.reverse(x);

		AssertClass::GetInstance().Assert(result == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestReverse test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	getchar();
	return EXIT_SUCCESS;
}