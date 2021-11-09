#include <iostream>
#include <memory>
#include <vector>
#include "../CommomModules/AssertClass.hpp"
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

	void TestInput_8843_Output_0()
	{
		// initialize input
		std::vector<int> input{8, 8, 4, 3};

		// begin test
		int amp = this->mSolution->Solution(input, 2);

		AssertClass::GetInstance().Assert(amp == 0, "TestInput_8843_Output_0");
	}

	void TestInput_351398_Output_1()
	{
		// initialize input
		std::vector<int> input{3, 5, 1, 3, 9, 8};

		// begin test
		int amp = this->mSolution->Solution(input, 4);

		AssertClass::GetInstance().Assert(amp == 1, "TestInput_351398_Output_1");
	}

private:
	std::unique_ptr<FindMinAmplitude> mSolution;

};

int main(int argc, char** argv)
{
	std::unique_ptr<TestFindMiniAmplitudeClass> test = std::make_unique<TestFindMiniAmplitudeClass>();
	test->TestInput_53613_Output_2();
	test->TestInput_8843_Output_0();
	test->TestInput_351398_Output_1();

	getchar();
	return EXIT_SUCCESS;
}