#include <iostream>
#include <string>
#include "MyPriorityQueueTest.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{}

	~Solution()
	{}
	
	bool isValid(std::string s) {
		return false;
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
		bool expectedOutput = true;
		std::cout << "===== Test input " << input << "; output true =====" << std::endl;

		// ACT
		bool result = this->mSolution.isValid(input);

		// ASSERT
		AssertClass::GetInstance().Assert(result == expectedOutput);
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	MyPriorityQueueTest myPriorityQueueTest;	
	myPriorityQueueTest.TestSameResultWithCppStlPriorityQueue_Default();
	myPriorityQueueTest.TestSameResultWithCppStlPriorityQueue_Greater();
	myPriorityQueueTest.TestPriorityQueueEmpty();
	myPriorityQueueTest.TestPriorityQueueEmptyAfterPop();
	myPriorityQueueTest.TestPriorityQueueAfterEmpty();

	// TestIsValid test;
	// test.Example1();
	getchar();
	return EXIT_SUCCESS;
}