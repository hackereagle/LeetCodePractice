#include <iostream>
#include <memory>
#include <string>
#include "AssertClass.hpp"
#include "FindSmallestUniqueSubstring.hpp"

class TestFindSmallestUniqueSubstringClass
{
public:
	TestFindSmallestUniqueSubstringClass()
	{
		this->mSolution = std::make_unique<FindSmallestUniqueSubstring>();
	}

	~TestFindSmallestUniqueSubstringClass()
	{}

	void TestInput_abaaba_output_2_aa()
	{
		// initialize input
		std::string input = "abaaba";

		// begin test
		std::string result;
		int len = this->mSolution->Solution(input, result);

		AssertClass::GetInstance().Assert(len == 2, "TestInput_abaaba_output_2_aa");
		AssertClass::GetInstance().Assert(result == "aa", "result is aa");
	}

private:
	std::unique_ptr<FindSmallestUniqueSubstring> mSolution;

};

int main(int argc, char** argv)
{
	std::cout << "Hello World" << std::endl;
	getchar();
	return EXIT_SUCCESS;
}