#include <memory>
#include <iostream>
#include "OperationTimes.hpp"
#include "../CommomModules/AssertClass.hpp"
#include "../CommomModules/TimeCounter.hpp"

class TestOperationTimesClass
{
public:
	TestOperationTimesClass() 
	{
		this->mSolution = std::make_unique<OperationTimes>();
	}

	~TestOperationTimesClass() {}

	void TestInput_011100_Output_28()
	{
		// Initialize input
		std::string input = "011100";

		// Begin testing
		int times = 0;
		TimeCounter::GetInstance().SetStartCountPoint();
		times = this->mSolution->Solution(input);
		int elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "times: " << times << std::endl;
		std::cout << "elapsed time: " << elapsed << std::endl;

		AssertClass::GetInstance().Assert(times == 28, "TestInput_011100_Output_28");
		AssertClass::GetInstance().Assert(elapsed <= 6 && elapsed > 0, "Computing time in 6s.");
	}

	void TestInput_Consist1Repeatd400000Times_Output_799999()
	{
		// Initialize input
		std::string input = std::string(400000, '1');

		// Begin testing
		int times = 0;
		TimeCounter::GetInstance().SetStartCountPoint();
		times = this->mSolution->Solution(input);
		int elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "times: " << times << std::endl;
		std::cout << "elapsed time: " << elapsed << std::endl;

		AssertClass::GetInstance().Assert(times == 28, "TestInput_Consist1Repeatd400000Times_Output_799999");
		AssertClass::GetInstance().Assert(elapsed <= 6 && elapsed > 0, "Computing time in 6s.");
	}

private:
	std::unique_ptr<OperationTimes> mSolution;

};

int main(int argc, char** argv)
{
	std::unique_ptr<TestOperationTimesClass> test = std::make_unique<TestOperationTimesClass>();
	test->TestInput_011100_Output_28();
	test->TestInput_Consist1Repeatd400000Times_Output_799999();

	getchar();
	return EXIT_SUCCESS;
}