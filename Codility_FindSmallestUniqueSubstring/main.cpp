#include <iostream>
#include <memory>
#include <string>
#include "../CommomModules/AssertClass.hpp"
#include "../CommomModules/TimeCounter.hpp"
#include "IFindSmallestUniqueSubstring.hpp"
#include "FindSmallestUniqueSubstring.hpp"

class TestFindSmallestUniqueSubstringClass
{
public:
	TestFindSmallestUniqueSubstringClass(std::string method = "")
	{
		if(method == "first"){
			this->mMethod = "first version";
			this->mSolution = std::make_unique<FindSmallestUniqueSubstring>();
		}
		else{
			// Optimize fault! it not be faster.
			this->mMethod = "Optimize by erasing not unique substring as iterate string version";
			this->mSolution = std::make_unique<FindSmallestUniqueSubstring_OptimalByEraseNotUnique>();
		}
		std::cout << "Method: " << this->mMethod << std::endl;
	}

	~TestFindSmallestUniqueSubstringClass()
	{}

	void TestInput_abaaba_output_2_aa()
	{
		// initialize input
		std::string input = "abaaba";

		// begin test
		std::string result;
		TimeCounter::GetInstance().SetStartCountPoint();
		int len = this->mSolution->Solution(input, result);
		double elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "caculate result: unique substring = " << result << ", len = " << len << std::endl;
		std::cout << "elapsed time = " << elapsed << "ms" << std::endl;

		AssertClass::GetInstance().Assert(len == 2, "TestInput_abaaba_output_2_aa");
		AssertClass::GetInstance().Assert(result == "aa", "result is aa");
	}

	void TestInput_zyzyzyz_output_5_yzyzy()
	{
		// initialize input
		std::string input = "zyzyzyz";

		// begin test
		std::string result;
		TimeCounter::GetInstance().SetStartCountPoint();
		int len = this->mSolution->Solution(input, result);
		double elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "caculate result: unique substring = " << result << ", len = " << len << std::endl;
		std::cout << "elapsed time = " << elapsed << "ms" << std::endl;

		AssertClass::GetInstance().Assert(len == 5, "TestInput_zyzyzyz_output_5_yzyzy");
		AssertClass::GetInstance().Assert(result == "yzyzy", "result is yzyzy");
	}

	void TestInput_aabbbabaaa_output_3_baa()
	{
		// initialize input
		std::string input = "aabbbabaaa";

		// begin test
		std::string result;
		TimeCounter::GetInstance().SetStartCountPoint();
		int len = this->mSolution->Solution(input, result);
		double elapsed = TimeCounter::GetInstance().GetElapsedTime();
		std::cout << "caculate result: unique substring = " << result << ", len = " << len << std::endl;
		std::cout << "elapsed time = " << elapsed << "ms" << std::endl;

		AssertClass::GetInstance().Assert(len == 3, "TestInput_aabbbabaaa_output_3_baa");
		AssertClass::GetInstance().Assert(result == "baa", "result is baa"); // this is not sure answer.
	}

private:
	std::unique_ptr<IFindSmallestUniqueSubstring> mSolution;
	std::string mMethod;
};

int main(int argc, char** argv)
{
	std::unique_ptr<TestFindSmallestUniqueSubstringClass> test = std::make_unique<TestFindSmallestUniqueSubstringClass>("first");
	test->TestInput_abaaba_output_2_aa();
	test->TestInput_zyzyzyz_output_5_yzyzy();
	test->TestInput_aabbbabaaa_output_3_baa();
	getchar();
	return EXIT_SUCCESS;
}