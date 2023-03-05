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
	
	int calculate(std::string s) {
		int result = 0;

		std::stack<std::pair<int, int>> resultStash; // sum, sign
		size_t len = s.size();
		std::string::iterator p = s.begin();
		int sign = 1;
		for (int i = 0; i < len; i++) {
			//std::cout << "in " << i << "-th, character = " << *(p + i) << std::endl;
			if (*(p + i) >= '0') {
				int num = 0;
				while (i < len && *(p + i) >= '0') {
					num = (num * 10) + (*(p + i) - '0');
					i++;
				}
				//std::cout << "num = " << num << ", factor = " << factor << std::endl;
				result = result + (sign * num);

				sign = 1;
				i--;
			}
			else if (*(p + i) == '+' || *(p + i) == '-'){
				sign = *(p + i) == '-' ? -1 : 1;
			}
			else if (*(p + i) == '(') {
				resultStash.push(std::pair<int, int>(result, sign));
				result = 0;
				sign = 1;
			}
			else if (*(p + i) == ')') {
				std::pair<int, int> lastResult = resultStash.top();
				resultStash.pop();

				result = lastResult.first + (result * lastResult.second);
			}
		}

		return result;
	}
};

class TestIsValid
{
public:
	TestIsValid()
	{}

	~TestIsValid()
	{}

	void Example1()
	{
		std::string input = "1 + 1";
		int expected = 2;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example2()
	{
		std::string input = " 2-1 + 2 ";
		int expected = 3;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example3()
	{
		std::string input = "(1+(4+5+2)-3)+(6+8)";
		int expected = 23;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example4()
	{
		std::string input = "(1 + (2 + (3 + 4)))";
		int expected = 10;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example5()
	{
		std::string input = "-(1 + 2) + 3";
		int expected = 0;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example6()
	{
		std::string input = "3+(-(1+4)+8)+9";
		int expected = 15;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example7()
	{
		std::string input = "1-(     -2)";
		int expected = 3;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example8()
	{
		std::string input = "(1-(3-4))";
		int expected = 2;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

	void Example9()
	{
		std::string input = "(6)-(8)-(7)+(1+(6))";
		int expected = -2;
		std::cout << "===== Test input \"" << input << "\", output" << expected << "=====" << std::endl;

		int reslut = this->mSolution.calculate(input);

		AssertClass::GetInstance().Assert(reslut == expected);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsValid test;
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