#include <iostream>
#include <memory>
#include <string>
#include "Roman2IntegerSolution.hpp"
#include "../../CommomModules/AssertClass.hpp"

class Roman2IntegerSolutionTesting
{
public:
	Roman2IntegerSolutionTesting()
	{
		this->mSolution = std::make_unique<Roman2IntegerSolution>();
	}

	void TestInput_III_Output_3()
	{
		// initialize testing data
		std::string input = "III";
		int expectedOutput = 3;

		// testing
		int result = this->mSolution->romanToInt(input);
		AssertClass::GetInstance().Assert(result == 3, "TestInput_III_Output_3");
	}

	void TestInput_IV_Output_4()
	{
		// initialize testing data
		std::string input = "IV";
		int expectedOutput = 4;

		// testing
		int result = this->mSolution->romanToInt(input);
		AssertClass::GetInstance().Assert(result == 4, "TestInput_IV_Output_4");
	}

	void TestInput_IX_Output_9()
	{
		// initialize testing data
		std::string input = "IX";
		int expectedOutput = 9;

		// testing
		int result = this->mSolution->romanToInt(input);
		AssertClass::GetInstance().Assert(result == 9, "TestInput_IX_Output_9");
	}

	void TestInput_LVIII_Output_58()
	{
		// initialize testing data
		std::string input = "LVIII";
		int expectedOutput = 58;

		// testing
		int result = this->mSolution->romanToInt(input);
		AssertClass::GetInstance().Assert(result == 58, "TestInput_LVIII_Output_58");
	}

	void TestInput_MCMXCIV_Output_1994()
	{
		// initialize testing data
		std::string input = "MCMXCIV";
		int expectedOutput = 1994;

		// testing
		int result = this->mSolution->romanToInt(input);
		AssertClass::GetInstance().Assert(result == 1994, "TestInput_MCMXCIV_Output_1994");
	}

private:
	std::unique_ptr<Roman2IntegerSolution> mSolution;
};

int main(int argc, char** argv)
{
	std::unique_ptr<Roman2IntegerSolutionTesting> test = std::make_unique<Roman2IntegerSolutionTesting>();
	test->TestInput_III_Output_3();
	test->TestInput_IV_Output_4();
	test->TestInput_IX_Output_9();
	test->TestInput_LVIII_Output_58();
	test->TestInput_MCMXCIV_Output_1994();

	getchar();
	return EXIT_SUCCESS;
}