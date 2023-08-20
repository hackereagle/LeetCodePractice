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
	
	bool isValid(std::string s) {
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
		// ARRANGE
		std::string input = "()";
		std::cout << "===== Test input " << input << ", output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.isValid(input);

		// ASSERT
		AssertClass::GetInstance().Assert(result == true);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestIsValid test;
	test.Example1();
	getchar();
	return EXIT_SUCCESS;
}