#include <iostream>
#include <memory>
#include <vector>
#include "AssertClass.hpp"
#include "FindMinAmplitude.hpp"

class TestFindMiniAmplitudeClass
{
public:
	TestFindMiniAmplitudeClass()
	{
		this->mSolution = std::make_unique<FindMinAmplitude>();
	}

	~TestFindMiniAmplitudeClass()
	{}

	void TestInput_53613_Output_2()
	{
		// initialize input
		std::vector<int> input{5, 3, 6, 1, 3};

		// begin test
		int amp = this->mSolution->Solution(input, 2);

		AssertClass::GetInstance().Assert(amp == 2, "TestInput_53613_Output_2");
	}

private:
	std::unique_ptr<FindMinAmplitude> mSolution;

};

int main(int argc, char** argv)
{
	std::unique_ptr<TestFindMiniAmplitudeClass> test = std::make_unique<TestFindMiniAmplitudeClass>();
	test->TestInput_53613_Output_2();

	getchar();
	return EXIT_SUCCESS;
}