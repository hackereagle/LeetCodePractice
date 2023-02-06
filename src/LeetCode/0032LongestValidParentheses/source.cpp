#include <iostream>
#include <string>
#include <stack>
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	int longestValidParentheses(std::string s) {
		int longestCount = 0;

		std::stack<ParenInfon> singleParenthesesStack;
		size_t len = s.size();
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {
				singleParenthesesStack.push(ParenInfon(s[i], i));
			}
			else if (s[i] == ')') {
				//std::cout << "empty() = " << singleParenthesesStack.empty() << ", top = " << (singleParenthesesStack.empty() == false ? singleParenthesesStack.top().C : 0) << std::endl; // debug
				if (!singleParenthesesStack.empty() && singleParenthesesStack.top().C == '(') {
					singleParenthesesStack.pop();
				}
				else {
					singleParenthesesStack.push(ParenInfon(s[i], i));
				}
			}
		}

		if (singleParenthesesStack.empty()) {
			longestCount = len;
		}
		else {
			int tempCount = 0, index = 0;
			while (!singleParenthesesStack.empty()) {
				index = singleParenthesesStack.top().Indx; singleParenthesesStack.pop();
				tempCount = len - index - 1;
				len = index;
				longestCount = longestCount < tempCount ? tempCount : longestCount;
				//std::cout << "index = " << index << ", tempCount = " << tempCount << ", after change len = " << len << ", longestCount = " << longestCount << std::endl; // debug
			}

			longestCount = longestCount < len ? len : longestCount;
			//std::cout << "index = " << index << ", tempCount = " << tempCount << ", after change len = " << len << ", longestCount = " << longestCount << std::endl; // debug
		}

		return longestCount;
	}

private:
	typedef struct parenInfon
	{
		char C = (char)0;
		int Indx = -1;

		parenInfon(char c, int indx) : C(c), Indx(indx) {}
	}ParenInfon;
};

class TestThreeSum
{
public:
	TestThreeSum()
	{}

	~TestThreeSum()
	{}

	void Example1()
	{
		std::string input = "(()";
		int expectedOutput = 2;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example2()
	{
		std::string input = ")()())";
		int expectedOutput = 4;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example3()
	{
		std::string input = "";
		int expectedOutput = 0;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example4()
	{
		std::string input = "(()())";
		int expectedOutput = 6;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example5()
	{
		std::string input = "(()()))";
		int expectedOutput = 6;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example6()
	{
		std::string input = "(()()))()";
		int expectedOutput = 6;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example7()
	{
		std::string input = "((()())";
		int expectedOutput = 6;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example8()
	{
		std::string input = "(()()())((()()()()()))()()";
		int expectedOutput = 26;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

	void Example9()
	{
		std::string input = "((()()()()()))";
		int expectedOutput = 14;
		std::cout << "===== Test input \"" << input << "\", expected output" << expectedOutput << " =====" << std::endl;

		int reslut = this->mSolution.longestValidParentheses(input);

		AssertClass::GetInstance().Assert(reslut == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestThreeSum test;
	test.Example1();
	test.Example2();
	test.Example3();
	test.Example4();
	test.Example5();
	test.Example6();
	test.Example7();
	test.Example8();
	test.Example9();
	getchar();
	return EXIT_SUCCESS;
}