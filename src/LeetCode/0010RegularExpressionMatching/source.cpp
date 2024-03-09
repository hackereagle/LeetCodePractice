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
	
	bool isMatch(std::string s, std::string p) {
		return IsMatch(s, 0, p, 0);
	}

private:
	bool IsMatch(std::string &s, int si, std::string &p, int pi)
	{
		if (p.empty())
			return s.empty();

		/*if ((pi >= p.size() && si < s.size()) ||
			(pi < p.size() && si >= s.size()))
			return false;*/

		if (pi >= p.size() && si >= s.size())
			return true;

		bool firstMatch = (si < s.size()) && (p[pi] == s[si] || p[pi] == '.');
		if (((pi + 1) < p.size()) && p[pi + 1] == '*')
			return (firstMatch && IsMatch(s, si + 1, p, pi)) || 
					IsMatch(s, si, p, pi + 2);
		else {
			return firstMatch && IsMatch(s, si + 1, p, pi + 1);
		}
			
	}
};

class TestIsMatch
{
public:
	TestIsMatch()
	{}

	~TestIsMatch()
	{}

	void Example1()
	{
		// ARRANGE
		std::string s = "aa";
		std::string p = "a";
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", p = " << p << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isMatch(s, p);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example2()
	{
		// ARRANGE
		std::string s = "aa";
		std::string p = "a*";
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", p = " << p << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isMatch(s, p);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example3()
	{
		// ARRANGE
		std::string s = "ab";
		std::string p = ".*";
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", p = " << p << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isMatch(s, p);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example4()
	{
		// ARRANGE
		std::string s = "aab";
		std::string p = "c*a*b";
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", p = " << p << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isMatch(s, p);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example5()
	{
		// ARRANGE
		std::string s = "";
		std::string p = ".*.*";
		bool expectedOutput = true;
		std::cout << "===== Test s = " << s << ", p = " << p << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isMatch(s, p);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example6()
	{
		// ARRANGE
		std::string s = "hgdfabmckorabjc";
		std::string p = "*ab.c";
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", p = " << p << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isMatch(s, p);
		stopWatch.Stop();
		std::cout << "elapsed time = " << stopWatch.GetElapsed() << " ms\n" << std::endl;

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

	void Example7()
	{
		// ARRANGE
		std::string s = "hgdfabmuckorabjgc";
		std::string p = "ab.c";
		bool expectedOutput = false;
		std::cout << "===== Test s = " << s << ", p = " << p << "; output " << BOOL_TO_STR(expectedOutput) << " =====" << std::endl;

		// ACT
		StopWatch stopWatch;
		stopWatch.Start();
		bool result = this->mSolution.isMatch(s, p);
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
	TestIsMatch test;
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