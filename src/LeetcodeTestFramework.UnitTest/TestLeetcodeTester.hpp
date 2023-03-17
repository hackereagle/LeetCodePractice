#pragma once

#include <string>
#include <vector>
#include "StringMiscs.hpp"
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"
#include "LeetcodeTester.hpp"

/*
class Solution
{
public:
	int calculateProblem(std::vector<int> &param2, int param1)
	{
		std::cout << "Calculate problem" << std::endl;
		return 1;
	}
};

class CalculateProblemTest : public LeetcodeTester
{

	virtual std::vector<LTestTuple>& ParseInput(std::string input) override
	{
		std::vector<std::string> params = SplitString(input, "\n");

		std::vector<LTestTuple> ret;
		ret.push_back(LTestTuple(ConvertStringToVector(params[0]), "input1"));
		ret.push_back(LTestTuple(std::stoi(params[1]), "input2"));

		return ret;
	}

	virtual bool IsInputReasonable(std::vector<LTestTuple> &params) override
	{
		std::vector<int> param1 = params[1].GetInt1DArray();
		int param2 = params[0].GetIntValue();

		return param2 < 10;
	}

	virtual LTestTuple ExecuteAlgorithm(std::vector<LTestTuple> &params) override
	{
		std::vector<int> param1 = params[1].GetInt1DArray();
		int param2 = params[0].GetIntValue();

		int result = this->mSolution.calculateProblem(param1, param2);

		LTestTuple ret(result, "Result");
		return ret;
	}

	virtual void AssertAlgorithm(LTestTuple result, std::string expected) override
	{
		int r = result.GetIntValue();
		int exp = std::stoi(expected);

		AssertClass::GetInstance().Assert(r == exp, "In CalculateProblemTest assert");
	}

private:
	Solution mSolution;
};
*/