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
	
	int myAtoi(std::string s) {
		//std::cout << "input = " << s << std::endl; // debug
		long long int ret = 0;

		std::string numBeginStr = EliminateLeadWhitespace(s);
		//std::cout << "after eliminated lead whitespace = " << numBeginStr << std::endl; // debug

		size_t len = numBeginStr.size();
		int i = 0;
		int sign = 1;
		if (IsSign(numBeginStr[0])) {
			if (numBeginStr[0] == '-')
				sign = -1;

			i = i + 1;
		}

		long long int upperLimit = static_cast<long long int>(std::numeric_limits<int>::max()) + 1;
		while (i < len && IsNumber(numBeginStr[i])) {
			ret = (ret * 10) + static_cast<int>(numBeginStr[i] - '0');
			i = i + 1;

			if (ret >= upperLimit)
				break;
		}

		ret = ret * sign;

		if (ret >= upperLimit)
			ret = std::numeric_limits<int>::max();
		else if (ret <= std::numeric_limits<int>::min())
			ret = std::numeric_limits<int>::min();

		return ret;
	}

private:
	std::string EliminateLeadWhitespace(std::string &s)
	{
		std::string ret;

		int i = 0;
		size_t len = s.size();
		while(i < len && s[i] == ' ') {
			i = i + 1;
		}

		ret = s.substr(i);
		return ret;
	}

	bool IsNumber(char c)
	{
		return c >= '0' && c <= '9';
	}

	bool IsSign(char c)
	{
		return c == '-' || c == '+';
	}

	bool IsSignAndNextCharIsNum(char cur, char next)
	{
		return IsSign(cur) && IsNumber(next);
	}
};

class TestMyAtoi
{
public:
	TestMyAtoi()
	{}

	~TestMyAtoi()
	{}

	void Example1()
	{
		// ARRANGE
		std::string s = "42";
		int expectedOutput = 42;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::string s = "   -42";
		int expectedOutput = -42;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::string s = "4193 with words";
		int expectedOutput = 4193;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::string s = "153151-   ";
		int expectedOutput = 153151;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		std::string s = "adgjg asdkjg dfaj";
		int expectedOutput = 0;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		std::string s = "3987097898";
		int expectedOutput = 2147483647;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example7()
	{
		// ARRANGE
		std::string s = "-3987097898";
		int expectedOutput = -2147483648;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example8()
	{
		// ARRANGE
		std::string s = "000000- 00999";
		int expectedOutput = 0;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example9()
	{
		// ARRANGE
		std::string s = "abdaegaewta+999";
		int expectedOutput = 0;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example10()
	{
		// ARRANGE
		std::string s = "-  153153";
		int expectedOutput = 0;
		std::cout << "===== Test s = " << s << "; output = " << expectedOutput << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		int result = this->mSolution.myAtoi(s);
		std::cout << "result = " << result << std::endl;
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
	TestMyAtoi test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	test.Example9();
	test.Example10();
	getchar();
	return EXIT_SUCCESS;
}