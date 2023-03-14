#pragma once

#include <vector>
#include <string>
#include "LTestTuple.hpp"

class LeetcodeTester
{
public:
	LeetcodeTester()
	{}

	~LeetcodeTester()
	{}

	void Test(std::string input)
	{}

	void TestMultipleCase(std::string)
	{}

protected:
	virtual std::vecto<LTestTuple>& ParseInput(std::string input) = 0;
	virtual bool IsInputReasonable(std::vector<LTestTuple> &params) = 0;
	virtual LTestTuple ExecuteAlgorithm(std::vector<LTestTuple> &params) = 0;
	virtual void AssertAlgorithm(LTestTuple result, std::string expected) = 0;

private:
	void PrintTestingInform(std::vector<LTestTuple> &params)
	{

	}

};