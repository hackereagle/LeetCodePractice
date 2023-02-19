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
	
	bool isValid(std::string s) {
		bool valid = true;
		std::stack<char> parentheses;
		for (auto c : s) {
			if (c == '(' || c == '[' || c == '{') {
				parentheses.push(c);
			}
			else {
				if (c == ')') {
					if (parentheses.empty() || parentheses.top() != '(') {
						valid = false;
						break;
					}
					parentheses.pop();
				}
				else if (c == ']') {
					if (parentheses.empty() || parentheses.top() != '[') {
						valid = false;
						break;
					}
					parentheses.pop();
				}
				else if (c == '}') {
					if (parentheses.empty() || parentheses.top() != '{') {
						valid = false;
						break;
					}
					parentheses.pop();
				}
			}
		}

		if (!parentheses.empty()) {
			valid = false;
		}

		return valid;
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
		std::string input = "()";
		std::cout << "===== Test input \"" << input << "\", output true =====" << std::endl;

		bool reslut = this->mSolution.isValid(input);

		AssertClass::GetInstance().Assert(reslut == true);
	}

	void Example2()
	{
		std::string input = "()[]{}";
		std::cout << "===== Test input \"" << input << "\", output true =====" << std::endl;

		bool reslut = this->mSolution.isValid(input);

		AssertClass::GetInstance().Assert(reslut == true);
	}

	void Example3()
	{
		std::string input = "(]";
		std::cout << "===== Test input \"" << input << "\", output false =====" << std::endl;

		bool reslut = this->mSolution.isValid(input);

		AssertClass::GetInstance().Assert(reslut == false);
	}

	void Example4()
	{
		std::string input = "]";
		std::cout << "===== Test input \"" << input << "\", output false =====" << std::endl;

		bool reslut = this->mSolution.isValid(input);

		AssertClass::GetInstance().Assert(reslut == false);
	}

	void Example5()
	{
		std::string input = "(())";
		std::cout << "===== Test input \"" << input << "\", output true =====" << std::endl;

		bool reslut = this->mSolution.isValid(input);

		AssertClass::GetInstance().Assert(reslut == true);
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
	getchar();
	return EXIT_SUCCESS;
}