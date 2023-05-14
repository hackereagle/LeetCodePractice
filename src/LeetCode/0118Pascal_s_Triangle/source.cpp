#include <iostream>
#include <string>
#include <vector>
#include "VectorMiscs.hpp"
#include "AssertClass.hpp"

class Solution
{
public:
	Solution()
	{
		_dp = std::vector<std::vector<int>>(30, std::vector<int>());
		_dp[0] = std::vector<int>({1});
		_dp[1] = std::vector<int>({1, 1});
	}

	~Solution()
	{}
	
	std::vector<std::vector<int>> generate(int numRows) {
		std::vector<std::vector<int>> ret;

		for (int i = 0; i < numRows; i++) {
			if (_dp[i].size() == 0) {
				_dp[i] = CreatePascalTriangleRow(_dp, i);
			}

			ret.push_back(_dp[i]);
		}

		return ret;
	}

private:
	std::vector<std::vector<int>> _dp;

	std::vector<int> CreatePascalTriangleRow(std::vector<std::vector<int>> &dp, int n)
	{
		std::vector<int> ret(dp[n - 1].size() + 1, 1);

		for (int i = 1; i < ret.size() - 1; i++) {
			ret[i] = dp[n - 1][i] + dp[n - 1][i - 1];
		}

		return ret;
	}
};

class TestGenerate
{
public:
	TestGenerate()
	{}

	~TestGenerate()
	{}

	void Example1()
	{
		int numRows = 5;
		std::vector<std::vector<int>> expected({{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}});
		std::cout << "===== Test numRows = " << numRows << ", output = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.generate(numRows);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

	void Example2()
	{
		int numRows = 1;
		std::vector<std::vector<int>> expected({{1}});
		std::cout << "===== Test numRows = " << numRows << ", output = " << Vector2Str(expected) << " =====" << std::endl;

		std::vector<std::vector<int>> result = this->mSolution.generate(numRows);

		AssertClass::GetInstance().Assert(IsTwoVectorEqual(result, expected));
	}

private:
	Solution mSolution;
};

int main(int argc, char** argv)
{
	TestGenerate test;
	test.Example1();
	test.Example2();
	getchar();
	return EXIT_SUCCESS;
}