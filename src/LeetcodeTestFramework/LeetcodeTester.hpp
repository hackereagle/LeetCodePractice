#pragma once

#include <vector>
#include <string>
#include "StopWatch.hpp"
#include "LTestTuple.hpp"

class LeetcodeTester
{
public:
	LeetcodeTester()
	{}

	~LeetcodeTester()
	{}

	void Test(std::string input, std::string expected)
	{
		// Arrange
		std::vector<LTestTuple> params = this->ParseInput(input);

		if (this->IsInputReasonable(params)) {
			this->PrintTestingInform(params, expected);

			// Action
			StopWatch sw;
			sw.Start();
			LTestTuple result = this->ExecuteAlgorithm(params);
			sw.Stop();
			std::cout << "Total elapsed time = " << sw.GetElapsed() << std::endl;

			// Assert
			this->AssertAlgorithm(result, expected);
		}
		else {
			throw "There is problem in input!";
		}
	}

	void TestMultipleCase(std::string)
	{}

protected:
	virtual std::vector<LTestTuple>& ParseInput(std::string input) = 0; // 
	virtual bool IsInputReasonable(std::vector<LTestTuple> &params) = 0;
	virtual LTestTuple ExecuteAlgorithm(std::vector<LTestTuple> &params) = 0;
	virtual void AssertAlgorithm(LTestTuple result, std::string expected) = 0;

private:
	void PrintTestingInform(std::vector<LTestTuple> &params, std::string &expected)
	{
		std::cout << "===== Test case: ";
		size_t len = params.size();
		for (int i = 0; i < len; i++) {
			if (i != 0)
				std::cout << ", ";

			std::cout << params[i].GetParameterName() << " = " << GetParameterValueWithString(params[i]);
		}
		std::cout << ". Expected = " << expected;

		std::cout << " =====" << std::endl;
	}


};