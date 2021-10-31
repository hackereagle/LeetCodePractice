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

	void TestInput_011100_Output_7()
	{
		// Initialize input
		std::string input = "011100";

		// Begin testing
		int times = 0;
		TimeCounter::GetInstance().SetStartCountPoint();
		times = this->mSolution->Solution(input);
		int elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "times: " << times << std::endl;
		std::cout << "elapsed time: " << elapsed << "ms" << std::endl;

		AssertClass::GetInstance().Assert(times == 7, "TestInput_011100_Output_28");
		AssertClass::GetInstance().Assert(elapsed <= 6.0 && elapsed >= 0, "Computing time in 6ms.");
	}

	void TestInput_111_Output_5()
	{
		// Initialize input
		std::string input = "111";

		// Begin testing
		int times = 0;
		TimeCounter::GetInstance().SetStartCountPoint();
		times = this->mSolution->Solution(input);
		int elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "times: " << times << std::endl;
		std::cout << "elapsed time: " << elapsed << "ms" << std::endl;

		AssertClass::GetInstance().Assert(times == 5, "TestInput_111_Output_5");
		AssertClass::GetInstance().Assert(elapsed <= 6.0 && elapsed >= 0, "Computing time in 6ms.");
	}

	void TestInput_1111010101111_Output_22()
	{
		// Initialize input
		std::string input = "1111010101111";

		// Begin testing
		int times = 0;
		TimeCounter::GetInstance().SetStartCountPoint();
		times = this->mSolution->Solution(input);
		int elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "times: " << times << std::endl;
		std::cout << "elapsed time: " << elapsed << "ms" << std::endl;

		AssertClass::GetInstance().Assert(times == 22, "TestInput_1111010101111_Output_22");
		AssertClass::GetInstance().Assert(elapsed <= 6.0 && elapsed >= 0, "Computing time in 6ms.");
	}

	void TestInput_Consist1Repeatd400000Times_Output_799999()
	{
		// Initialize input
		std::string input = std::string(400000, '1');

		// Begin testing
		int times = 0;
		TimeCounter::GetInstance().SetStartCountPoint();
		times = this->mSolution->Solution(input);
		double elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "times: " << times << std::endl;
		std::cout << "elapsed time: " << elapsed << "ms" << std::endl;

		AssertClass::GetInstance().Assert(times == 799999, "TestInput_Consist1Repeatd400000Times_Output_799999");
		AssertClass::GetInstance().Assert(elapsed <= 6.0 && elapsed >= 0, "Computing time in 6ms.");
	}

private:
	std::unique_ptr<OperationTimes> mSolution;

};

int main(int argc, char** argv)
{
	std::unique_ptr<TestOperationTimesClass> test = std::make_unique<TestOperationTimesClass>();
	test->TestInput_011100_Output_7();
	test->TestInput_111_Output_5();
	test->TestInput_1111010101111_Output_22();
	test->TestInput_Consist1Repeatd400000Times_Output_799999();

	getchar();
	return EXIT_SUCCESS;
}